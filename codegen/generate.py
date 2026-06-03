#!/usr/bin/env python3
"""Generate sol2 Lua bindings for Dear ImGui from dear_bindings metadata.

Reads codegen/metadata/dcimgui.json (produced by codegen/fetch_metadata.sh) and
emits the committed C++ in generated/:

  * sol_ImGui_Enums_gen.cpp  -- InitEnums(sol::state&): every public enum.
  * sol_ImGui_gen_<N>.cpp    -- InitGenerated_<N>(sol::table&): bound functions,
                                bin-packed across translation units to keep each
                                object file small (the historical /bigobj reason).
  * sol_ImGui_Generated.h    -- declarations + InitGenerated(sol::table&).
  * sources.cmake            -- the generated TU list (no CMake GLOB).
  * denylist_report.txt      -- every function NOT bound, with the reason.

The generator never invents values: enum members and casts reference the real
ImGui symbols, so they stay correct across ImGui versions. Functions the simple
rules cannot express (overloads, output bool* p_open, array in/out, text buffers,
opaque pointers, varargs) are reported and left to the hand-written manual/ TU.

Run via the `regen-bindings` CMake target or directly:
    python codegen/generate.py
"""
from __future__ import annotations

import argparse
import json
import math
import tomllib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
META_PATH = HERE / "metadata" / "dcimgui.json"
OVERRIDES_PATH = HERE / "overrides.toml"
GEN_DIR = ROOT / "generated"
DOCS_DIR = ROOT / "docs"
MANUAL_CPP = ROOT / "manual" / "sol_ImGui_Manual.cpp"

FUNCS_PER_TU = 90  # keep each generated object file well under MSVC's /bigobj limit

GENERATED_BANNER = (
    "// GENERATED FILE -- DO NOT EDIT BY HAND.\n"
    "// Produced by codegen/generate.py from codegen/metadata/dcimgui.json.\n"
    "// Regenerate with the `regen-bindings` CMake target; see CONTRIBUTING.md.\n"
)

# ---------------------------------------------------------------------------
# Type classification
# ---------------------------------------------------------------------------

# Builtin C++ scalar types we pass straight through (by value, or as a tuple
# element when they appear as an output pointer).
SCALAR_BUILTINS = {
    "bool", "int", "unsigned int", "float", "double",
    "short", "unsigned short", "char", "unsigned char",
    "long", "unsigned long", "long long", "unsigned long long",
    "size_t", "ImS8", "ImU8", "ImS16", "ImU16", "ImS32", "ImU32",
    "ImS64", "ImU64",
}

# User-defined typedefs that are really integers (flags / ids). Passed from Lua
# as int and static_cast back to the real type for the ImGui call. Enum *types*
# are detected dynamically from the metadata (see ENUM_TYPES) so new enums are
# picked up automatically; this set covers integer typedefs that are not enums.
INT_LIKE_USER = {
    "ImGuiID", "ImU32", "ImS32", "ImGuiKeyChord", "ImWchar", "ImWchar16",
    "size_t",
}

# Populated in main() from the metadata: the set of enum type names (without the
# trailing underscore), e.g. {"ImGuiCol", "ImGuiStyleVar", "ImGuiTableBgTarget"}.
ENUM_TYPES: set[str] = set()

# Opaque / unsupported user types -- any function touching one is left to manual.
OPAQUE_USER_PREFIXES = ("ImDrawList", "ImFont", "ImGuiViewport", "ImGuiStorage",
                        "ImGuiPayload", "ImGuiContext", "ImGuiIO", "ImGuiStyle",
                        "ImGuiTableSortSpecs", "ImGuiWindowClass", "ImGuiInputTextCallback",
                        "ImGuiSizeCallback", "ImGuiMemAllocFunc", "ImGuiMemFreeFunc")
OPAQUE_USER_EXACT = {"ImTextureID", "ImTextureRef", "ImGuiSelectionUserData"}


class Unsupported(Exception):
    """Raised when a function cannot be expressed by the simple generated rules."""


def is_int_like_user(name: str) -> bool:
    """True for user types passed to/from Lua as a plain integer."""
    return name in INT_LIKE_USER or name in ENUM_TYPES


def classify_arg(arg: dict) -> dict:
    """Return a plan dict for one argument, or raise Unsupported."""
    if arg.get("is_varargs"):
        raise Unsupported("varargs")
    t = arg["type"]
    decl = t["declaration"]
    desc = t["description"]
    kind = desc.get("kind")
    name = arg["name"]
    has_default = "default_value" in arg
    default = arg.get("default_value")

    if kind == "Array":
        raise Unsupported(f"array argument ({decl})")

    if kind == "Builtin":
        if decl in SCALAR_BUILTINS or decl in ("bool", "int", "float", "double"):
            return {"role": "in_value", "cpp": decl, "name": name,
                    "has_default": has_default, "default": default}
        raise Unsupported(f"builtin {decl}")

    if kind == "Pointer":
        inner = desc.get("inner_type", {})
        inner_kind = inner.get("kind")
        is_const = "const" in inner.get("storage_classes", [])
        if inner_kind == "Builtin" and inner.get("builtin_type") == "char":
            if is_const:
                return {"role": "in_string", "cpp": "std::string", "name": name,
                        "has_default": has_default, "default": default}
            raise Unsupported("mutable char* buffer (text input)")
        if inner_kind == "Builtin" and inner.get("builtin_type") in (
                "bool", "int", "float", "double", "unsigned int") and not is_const:
            base = inner["builtin_type"]
            # Optional output (default NULL, e.g. Begin's p_open) needs runtime
            # branching on a tuple's arity -> leave to manual.
            if has_default:
                raise Unsupported("optional output pointer (p_open style)")
            # dear_bindings flattens C++ references (float&) to pointers but flags
            # them; we must call the real C++ overload with the matching form.
            return {"role": "out_scalar", "cpp": base, "name": name,
                    "is_reference": desc.get("is_reference", False)}
        raise Unsupported(f"pointer argument ({decl})")

    if kind == "User":
        uname = desc.get("name", decl)
        if uname in ("ImVec2", "ImVec4"):
            return {"role": "in_vec", "cpp": uname, "name": name,
                    "has_default": has_default, "default": default}
        if is_int_like_user(uname):
            return {"role": "in_enum", "cpp": uname, "name": name,
                    "has_default": has_default, "default": default}
        if uname in OPAQUE_USER_EXACT or any(uname.startswith(p) for p in OPAQUE_USER_PREFIXES):
            raise Unsupported(f"opaque user type ({uname})")
        raise Unsupported(f"user type ({uname})")

    raise Unsupported(f"unknown kind {kind} ({decl})")


def classify_return(ret_decl: str, desc: dict) -> dict:
    kind = desc.get("kind")
    if ret_decl == "void":
        return {"role": "void"}
    if kind == "Builtin":
        return {"role": "scalar", "cpp": ret_decl}
    if kind == "Pointer":
        inner = desc.get("inner_type", {})
        if inner.get("builtin_type") == "char" and "const" in inner.get("storage_classes", []):
            return {"role": "string"}
        raise Unsupported(f"pointer return ({ret_decl})")
    if kind == "User":
        uname = desc.get("name", ret_decl)
        if uname in ("ImVec2", "ImVec4"):
            return {"role": "vec", "cpp": uname}
        if is_int_like_user(uname):
            return {"role": "scalar", "cpp": uname}
        raise Unsupported(f"user return ({uname})")
    raise Unsupported(f"unknown return kind {kind} ({ret_decl})")


# ---------------------------------------------------------------------------
# Default-value expression rendering
# ---------------------------------------------------------------------------

def render_default(plan: dict) -> str:
    """C++ expression for an argument's default, typed for sol::optional::value_or."""
    raw = plan["default"]
    role = plan["role"]
    if raw is None:
        raw = "NULL"
    if role == "in_string":
        if raw in ("NULL", "nullptr", "0"):
            return "std::string()"
        return f"std::string({raw})"
    if role == "in_vec":
        return raw  # e.g. ImVec2(0, 0)
    # in_value / in_enum: numeric or symbolic constant, emit verbatim.
    return raw


# ---------------------------------------------------------------------------
# Function wrapper emission
# ---------------------------------------------------------------------------

def lua_name(fn: dict) -> str:
    return fn["original_fully_qualified_name"].split("::", 1)[1]


def plan_function(fn: dict) -> dict:
    """Build a full wrapper plan for a function, or raise Unsupported."""
    arg_plans = [classify_arg(a) for a in fn["arguments"]]
    ret_plan = classify_return(fn["return_type"]["declaration"],
                               fn["return_type"]["description"])
    outs = [p for p in arg_plans if p["role"] == "out_scalar"]
    return {"fn": fn, "args": arg_plans, "ret": ret_plan, "outs": outs}


def emit_wrapper(plan: dict, wrapper_name: str) -> str:
    fn = plan["fn"]
    call = fn["original_fully_qualified_name"]  # ImGui::Foo
    args = plan["args"]
    ret = plan["ret"]
    outs = plan["outs"]

    # ---- Lua-facing parameter list ----
    params = []
    for p in args:
        nm = p["name"]
        role = p["role"]
        if role == "out_scalar":
            params.append(f"{p['cpp']} {nm}")  # in/out seed value, by value
        elif role == "in_string":
            if p["has_default"]:
                params.append(f"sol::optional<std::string> {nm}")
            else:
                params.append(f"const std::string& {nm}")
        elif role == "in_vec":
            if p["has_default"]:
                params.append(f"sol::optional<{p['cpp']}> {nm}")
            else:
                params.append(f"const {p['cpp']}& {nm}")
        else:  # in_value / in_enum
            if p["has_default"]:
                params.append(f"sol::optional<{p['cpp']}> {nm}")
            else:
                params.append(f"{p['cpp']} {nm}")

    # ---- return type ----
    out_types = [p["cpp"] for p in outs]
    tail = []
    if ret["role"] == "scalar":
        tail = ["bool" if ret["cpp"] == "bool" else ret["cpp"]]
    elif ret["role"] == "string":
        tail = ["std::string"]
    elif ret["role"] == "vec":
        tail = [ret["cpp"]]
    ret_elems = out_types + tail
    if not ret_elems:
        ret_type = "void"
    elif len(ret_elems) == 1:
        ret_type = ret_elems[0]
    else:
        ret_type = f"std::tuple<{', '.join(ret_elems)}>"

    # ---- body ----
    lines = [f"{ret_type} {wrapper_name}({', '.join(params)}) {{"]
    call_args = []
    for p in args:
        nm = p["name"]
        role = p["role"]
        if role == "out_scalar":
            lines.append(f"  {p['cpp']} {nm}_v = {nm};")
            call_args.append(f"{nm}_v" if p.get("is_reference") else f"&{nm}_v")
        elif role == "in_string":
            if p["has_default"]:
                lines.append(f"  std::string {nm}_v = {nm}.value_or({render_default(p)});")
                call_args.append(f"{nm}_v.c_str()")
            else:
                call_args.append(f"{nm}.c_str()")
        elif role == "in_vec":
            if p["has_default"]:
                lines.append(f"  {p['cpp']} {nm}_v = {nm}.value_or({render_default(p)});")
                call_args.append(f"{nm}_v")
            else:
                call_args.append(nm)
        elif role == "in_enum":
            if p["has_default"]:
                lines.append(f"  {p['cpp']} {nm}_v = static_cast<{p['cpp']}>({nm}.value_or({render_default(p)}));")
                call_args.append(f"{nm}_v")
            else:
                call_args.append(f"static_cast<{p['cpp']}>({nm})")
        else:  # in_value
            if p["has_default"]:
                lines.append(f"  {p['cpp']} {nm}_v = {nm}.value_or({render_default(p)});")
                call_args.append(f"{nm}_v")
            else:
                call_args.append(nm)

    call_expr = f"{call}({', '.join(call_args)})"
    out_names = [f"{p['name']}_v" for p in outs]
    if ret["role"] == "void":
        lines.append(f"  {call_expr};")
        if out_names:
            lines.append(f"  return {tuple_or_single(out_names)};")
    else:
        if ret["role"] == "string":
            lines.append(f"  const char* ret = {call_expr};")
            ret_val = "std::string(ret ? ret : \"\")"
        else:
            lines.append(f"  auto ret = {call_expr};")
            ret_val = "ret"
        all_returns = out_names + [ret_val]
        lines.append(f"  return {tuple_or_single(all_returns)};")
    lines.append("}")
    return "\n".join(lines)


def tuple_or_single(elems: list[str]) -> str:
    if len(elems) == 1:
        return elems[0]
    return "std::make_tuple(" + ", ".join(elems) + ")"


# ---------------------------------------------------------------------------
# Enum emission
# ---------------------------------------------------------------------------

def enum_lua_name(enum: dict) -> str:
    return enum["name"].rstrip("_")


def emit_enum(enum: dict) -> tuple[str, str]:
    """Return (function_name, function_source) for one enum.

    Uses a static array + a shared RegisterEnum helper rather than sol2's
    variadic new_enum: new_enum instantiates a deep template per member and
    dominated the binding's object size. A plain table filled from an array is a
    fraction of the code for identical Lua-visible behaviour (a global table of
    integer constants).
    """
    lua = enum_lua_name(enum)
    prefix = enum["name"]
    fn_name = f"InitEnum_{lua}"
    rows = []
    for el in enum["elements"]:
        if el.get("is_internal"):
            continue
        member = el["name"]
        short = member[len(prefix):] if member.startswith(prefix) else member
        if not short:
            continue
        rows.append(f'      {{"{short}", static_cast<long long>({member})}}')
    body = ",\n".join(rows)
    src = (f"static void {fn_name}(sol::state& lua) {{\n"
           f"  static const EnumEntry entries[] = {{\n{body}}};\n"
           f'  RegisterEnum(lua, "{lua}", entries, sizeof(entries) / sizeof(entries[0]));\n'
           f"}}\n")
    return fn_name, src


# ---------------------------------------------------------------------------
# API documentation (docs/API.md) -- generated from the same metadata + ImGui's
# own doc comments, restricted to the functions actually bound.
# ---------------------------------------------------------------------------

import re


def _doc_value_type(decl: str, desc: dict) -> str:
    kind = desc.get("kind")
    if kind == "Builtin":
        return "boolean" if decl == "bool" else "number"
    if kind == "User":
        uname = desc.get("name", decl)
        if uname in ("ImVec2", "ImVec4"):
            return uname
        if uname in INT_LIKE_USER or uname in ENUM_TYPES:
            return "integer"
        return uname
    return decl


def render_doc_sig(fn: dict) -> tuple[list[str], list[str]]:
    """Best-effort Lua call signature (params, returns) for documentation.

    Applies the same Lua conventions the bindings use (strings, ImVec2/4
    usertypes, value-first tuple returns, tables for array widgets). Never raises
    -- it documents manual + generated functions uniformly straight from the
    metadata.
    """
    params: list[str] = []
    returns: list[str] = []
    for a in fn["arguments"]:
        if a.get("is_varargs"):
            continue  # collapsed; the preceding format string is the text param
        t = a["type"]
        decl, desc, nm = t["declaration"], t["description"], a["name"]
        kind = desc.get("kind")
        opt = "?" if "default_value" in a else ""
        if kind == "Array":
            params.append(f"{nm}: table{opt}")
            returns.append("table")
            continue
        if kind == "Pointer":
            inner = desc.get("inner_type", {})
            bt = inner.get("builtin_type")
            const = "const" in inner.get("storage_classes", [])
            if bt == "char" and const:
                params.append(f"{nm}: string{opt}")
            elif bt == "char":
                params.append(f"{nm}: string, buf_size: integer")
                returns.append("string")
            elif inner.get("kind") == "Builtin" and bt in ("bool", "int", "float", "double", "unsigned int"):
                lt = "boolean" if bt == "bool" else "number"
                params.append(f"[{nm}: {lt}]" if "default_value" in a else f"{nm}: {lt}")
                returns.append(lt)
            else:
                params.append(f"{nm}: userdata{opt}")
            continue
        params.append(f"{nm}: {_doc_value_type(decl, desc)}{opt}")

    r = fn["return_type"]
    if r["declaration"] != "void":
        rdesc = r["description"]
        if rdesc.get("kind") == "Pointer":
            returns.append("string" if rdesc.get("inner_type", {}).get("builtin_type") == "char" else "userdata")
        else:
            returns.append(_doc_value_type(r["declaration"], rdesc))
    return params, returns


def doc_comment(fn: dict) -> str:
    att = fn.get("comments", {}).get("attached")
    return att.lstrip("/ ").strip() if att else ""


def section_header(fn: dict) -> str | None:
    """A short title-like preceding comment marks a new ImGui section."""
    for line in fn.get("comments", {}).get("preceding", []):
        if line.strip().startswith("// -"):
            continue
        s = line.lstrip("/").strip()
        if (s and s[0].isupper() and not s.endswith(".") and "(" not in s
                and len(s) <= 40 and len(s.split()) <= 6):
            return s
    return None


def imgui_version(meta: dict) -> str:
    for d in meta.get("defines", []):
        if d.get("name") == "IMGUI_VERSION":
            return d.get("content", "").strip().strip('"')
    return "unknown"


def build_docs(meta: dict, canonical: list, bound_names: set, annotations: dict) -> str:
    manual_names = set(annotations)
    all_bound = bound_names | manual_names
    out = [
        "# ImGui Lua API reference\n",
        "<!-- GENERATED by codegen/generate.py from ImGui metadata. DO NOT EDIT. -->",
        f"\nDear ImGui **{imgui_version(meta)}**. Lists every function and enum these "
        "bindings expose to Lua. Regenerated (and drift-checked in CI) on every "
        "ImGui bump.\n",
        "## Conventions\n",
        "- ImGui output pointers become **value-first tuple returns**: "
        "`value, used = ImGui.SliderFloat(...)`.\n"
        "- `?` marks an optional argument (has a default); `[x]` marks an optional "
        "in/out value (e.g. a window's open flag).\n"
        "- `ImVec2`/`ImVec4` are usertypes (`ImVec2.new(x, y)`). `float[N]`/`int[N]` "
        "widgets take and return a Lua array (`table`).\n"
        "- Enums are global tables of integer constants (see [Enums](#enums)).\n"
        "- Functions marked † are hand-written (their exact signatures come from "
        "`manual/sol_ImGui_Manual.cpp`).\n",
        "## Functions\n",
    ]

    # group in metadata (source) order so ImGui's own section headers apply
    groups: dict[str, list] = {}
    order: list[str] = []
    current = "General"
    seen: set[str] = set()
    for fn in canonical:
        hdr = section_header(fn)
        if hdr:
            current = hdr
        nm = lua_name(fn)
        if nm not in all_bound or nm in seen:
            continue
        seen.add(nm)
        if current not in groups:
            groups[current] = []
            order.append(current)
        if nm in bound_names:
            # generated -> precise signature derived from the plan
            params, returns = render_doc_sig(fn)
            sig = f"ImGui.{nm}({', '.join(params)})" + (f" -> {', '.join(returns)}" if returns else "")
            groups[current].append(([(sig, False)], doc_comment(fn)))
        else:
            # hand-written -> authored signature(s) from the @lua annotations
            sigs = [(f"ImGui.{s}", True) for s in annotations[nm]]
            groups[current].append((sigs, doc_comment(fn)))

    for section in order:
        out.append(f"### {section}\n")
        for sigs, comment in groups[section]:
            for i, (sig, is_manual) in enumerate(sigs):
                dagger = " †" if is_manual else ""
                tail = f" — {comment}" if (comment and i == 0) else ""
                out.append(f"- `{sig}`{dagger}{tail}")
        out.append("")

    out.append("## Enums\n")
    for enum in meta["enums"]:
        if enum.get("is_internal"):
            continue
        lua = enum_lua_name(enum)
        members = []
        for el in enum["elements"]:
            if el.get("is_internal"):
                continue
            short = el["name"][len(enum["name"]):] if el["name"].startswith(enum["name"]) else el["name"]
            if not short:
                continue
            c = el.get("comments", {}).get("attached", "")
            c = (" — " + c.lstrip("/ ").strip()) if c else ""
            members.append(f"  - `{lua}.{short}`{c}")
        if members:
            out.append(f"### {lua}\n")
            out.extend(members)
            out.append("")
    return "\n".join(out)


def parse_manual() -> tuple[set, dict]:
    """Return (registered names, {name: [authored Lua signatures]}) from the
    manual TU. Signatures come from `// @lua <Name>(...)` comments next to each
    registration."""
    if not MANUAL_CPP.exists():
        return set(), {}
    text = MANUAL_CPP.read_text()
    registered = set(re.findall(r'set_function\(\s*"([A-Za-z0-9_]+)"', text))
    annotations: dict[str, list[str]] = {}
    for sig in re.findall(r"//\s*@lua\s+(.+)", text):
        sig = sig.strip()
        m = re.match(r"([A-Za-z0-9_]+)\s*\(", sig)
        if m:
            annotations.setdefault(m.group(1), []).append(sig)
    return registered, annotations


# ---------------------------------------------------------------------------
# Main generation
# ---------------------------------------------------------------------------

def load_overrides() -> dict:
    if OVERRIDES_PATH.exists():
        with open(OVERRIDES_PATH, "rb") as f:
            return tomllib.load(f)
    return {}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--metadata", default=str(META_PATH))
    ap.add_argument("--check", action="store_true",
                    help="exit nonzero if generated output would change (CI drift gate)")
    args = ap.parse_args()

    with open(args.metadata, "rb") as f:
        meta = json.load(f)
    # Enum type names (sans trailing "_") drive int-like argument classification.
    global ENUM_TYPES
    ENUM_TYPES = {enum_lua_name(e) for e in meta["enums"]}
    overrides = load_overrides()
    skip = set(overrides.get("skip", {}).get("functions", []))
    manual = set(overrides.get("manual", {}).get("functions", []))

    GEN_DIR.mkdir(exist_ok=True)

    # ---- enums ----
    enum_fns = []
    enum_srcs = []
    for enum in sorted(meta["enums"], key=lambda e: e["name"]):
        if enum.get("is_internal"):
            continue
        fn_name, src = emit_enum(enum)
        enum_fns.append(fn_name)
        enum_srcs.append(src)
    enum_file = [GENERATED_BANNER, '#include "sol_ImGui.h"\n',
                 "namespace sol_ImGui {\nnamespace {\n",
                 "struct EnumEntry { const char* name; long long value; };\n",
                 "void RegisterEnum(sol::state& lua, const char* enum_name,\n"
                 "                  const EnumEntry* entries, std::size_t count) {\n"
                 "  sol::table t = lua.create_named_table(enum_name);\n"
                 "  for (std::size_t i = 0; i < count; ++i) t[entries[i].name] = entries[i].value;\n"
                 "}\n",
                 "}  // namespace\n"]
    enum_file.extend(enum_srcs)
    enum_file.append("void InitEnums(sol::state& lua) {")
    enum_file.extend(f"  {fn}(lua);" for fn in enum_fns)
    enum_file.append("}\n}  // namespace sol_ImGui\n")
    write_if_changed(GEN_DIR / "sol_ImGui_Enums_gen.cpp", "\n".join(enum_file), args.check)

    # ---- functions ----
    # Group by Lua name to detect genuine overloads (multiple canonical entries).
    canonical = [f for f in meta["functions"]
                 if f.get("original_fully_qualified_name", "").startswith("ImGui::")
                 and not f.get("is_default_argument_helper")
                 and not f.get("is_manual_helper")
                 and not f.get("is_internal")
                 and f.get("original_class") is None]
    by_name: dict[str, list] = {}
    for f in canonical:
        by_name.setdefault(lua_name(f), []).append(f)

    bound = []          # (lua_name, wrapper_name, wrapper_src)
    denied = []         # (lua_name, reason)
    for name in sorted(by_name):
        group = by_name[name]
        if name in skip:
            denied.append((name, "override: skip"))
            continue
        if name in manual:
            denied.append((name, "override: manual (hand-written in manual/)"))
            continue
        if len(group) > 1:
            denied.append((name, f"overloaded ({len(group)} signatures) -> manual"))
            continue
        try:
            plan = plan_function(group[0])
        except Unsupported as e:
            denied.append((name, str(e)))
            continue
        wrapper_name = name  # unique within anon namespace per TU
        bound.append((name, wrapper_name, emit_wrapper(plan, wrapper_name)))

    # ---- bin-pack functions into TUs ----
    n_tus = max(1, math.ceil(len(bound) / FUNCS_PER_TU))
    tus: list[list] = [[] for _ in range(n_tus)]
    for i, item in enumerate(bound):
        tus[i % n_tus].append(item)

    tu_files = []
    for k, items in enumerate(tus):
        src = [GENERATED_BANNER, '#include "sol_ImGui.h"\n',
               "namespace sol_ImGui {\nnamespace {\n"]
        for _, _, wsrc in items:
            src.append(wsrc + "\n")
        src.append("}  // namespace\n")
        src.append(f"void InitGenerated_{k}(sol::table& t) {{")
        for lname, wname, _ in items:
            src.append(f'  t.set_function("{lname}", {wname});')
        src.append("}\n}  // namespace sol_ImGui\n")
        fname = f"sol_ImGui_gen_{k}.cpp"
        write_if_changed(GEN_DIR / fname, "\n".join(src), args.check)
        tu_files.append(fname)

    # ---- header ----
    hdr = [GENERATED_BANNER, "#pragma once",
           "#include <sol/sol.hpp>\n", "namespace sol_ImGui {",
           "void InitEnums(sol::state& lua);"]
    for k in range(n_tus):
        hdr.append(f"void InitGenerated_{k}(sol::table& t);")
    hdr.append("\ninline void InitGenerated(sol::table& t) {")
    hdr.extend(f"  InitGenerated_{k}(t);" for k in range(n_tus))
    hdr.append("}\n}  // namespace sol_ImGui\n")
    write_if_changed(GEN_DIR / "sol_ImGui_Generated.h", "\n".join(hdr), args.check)

    # ---- sources.cmake ----
    cmake = [GENERATED_BANNER.replace("//", "#"),
             "set(SOL_IMGUI_GENERATED_SOURCES"]
    cmake.append("    ${CMAKE_CURRENT_SOURCE_DIR}/generated/sol_ImGui_Enums_gen.cpp")
    for fn in tu_files:
        cmake.append(f"    ${{CMAKE_CURRENT_SOURCE_DIR}}/generated/{fn}")
    cmake.append(")\n")
    write_if_changed(GEN_DIR / "sources.cmake", "\n".join(cmake), args.check)

    # ---- denylist report ----
    report = [GENERATED_BANNER,
              f"# {len(bound)} functions generated, {len(denied)} left to manual/denylist.\n"]
    for name, reason in sorted(denied):
        report.append(f"{name}: {reason}")
    write_if_changed(GEN_DIR / "denylist_report.txt", "\n".join(report) + "\n", args.check)

    # ---- API docs ----
    # Hand-written functions must each carry a `// @lua` signature in the manual
    # TU; this gate fails loudly if one is added without documenting it (and
    # catches a stray annotation for a function that isn't registered).
    registered_manual, annotations = parse_manual()
    missing = sorted(registered_manual - set(annotations))
    stray = sorted(set(annotations) - registered_manual)
    if missing or stray:
        if missing:
            print(f"ERROR: manual functions missing a // @lua signature: {', '.join(missing)}")
        if stray:
            print(f"ERROR: // @lua signature for unregistered function(s): {', '.join(stray)}")
        return 1

    DOCS_DIR.mkdir(exist_ok=True)
    bound_names = {n for n, _, _ in bound}
    docs = build_docs(meta, canonical, bound_names, annotations)
    write_if_changed(DOCS_DIR / "API.md", docs, args.check)

    print(f"enums: {len(enum_fns)}  functions bound: {len(bound)}  "
          f"deferred/denied: {len(denied)}  TUs: {n_tus}")
    return 0


_drift = []


def write_if_changed(path: Path, content: str, check: bool) -> None:
    old = path.read_text() if path.exists() else None
    if old == content:
        return
    if check:
        _drift.append(str(path))
        print(f"DRIFT: {path} would change")
        return
    path.write_text(content)


if __name__ == "__main__":
    rc = main()
    if _drift:
        print(f"\n{len(_drift)} file(s) out of date -- run codegen/generate.py and commit.")
        rc = 1
    raise SystemExit(rc)
