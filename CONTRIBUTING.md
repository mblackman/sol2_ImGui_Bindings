# Contributing / Maintenance

These bindings are **mostly code-generated** from Dear ImGui's own machine-readable
API description. The goal is that bumping ImGui (or sol2) is "regenerate, review
the diff, run the tests" instead of hand-editing thousands of lines.

## Layout

| Path | What it is |
|------|------------|
| `codegen/generate.py` | The generator. Reads `codegen/metadata/dcimgui.json`, writes `generated/`. |
| `codegen/metadata/dcimgui.json` | Committed ImGui API metadata (from `dear_bindings`). |
| `codegen/overrides.toml` | Per-symbol `skip` / `manual` directives. |
| `codegen/fetch_metadata.sh` | Regenerates the metadata JSON from ImGui headers. |
| `generated/` | **Committed, do not edit.** Enum + function bindings + `sources.cmake`. |
| `generated/denylist_report.txt` | Every function the generator left to `manual/`, with the reason. |
| `docs/API.md` | **Generated, do not edit.** Full Lua API reference (drift-checked). |
| `manual/sol_ImGui_Manual.cpp` | Hand-written bindings + the `ImVec2`/`ImVec4` usertypes. |
| `sol_ImGui.{h,cpp}` | Thin public surface: `sol_ImGui::Init(sol::state&)`. |
| `tests/smoke/` | Headless callability test (`ctest`). |

The generated sources are committed, so **consumers build with no Python
dependency**. Python is only needed to regenerate.

## What is generated vs hand-written

The generator binds every public enum and every free `ImGui::` function whose
signature it can express with simple rules: string args, scalar in/out pointers
(returned value-first in a tuple), `ImVec2`/`ImVec4` (as usertypes), enum/flag
ints, and trailing default args (collapsed via `sol::optional`).

It deliberately leaves to `manual/` (see `denylist_report.txt`): text/`varargs`
helpers, `bool* p_open`-style windows (`Begin`, `BeginTabItem`, …), `float[N]`
/`int[N]` array widgets, item lists (`Combo`, `ListBox`), genuine overloads, and
anything touching opaque types (`ImTextureID`, `ImDrawList*`, callbacks, …).

### Documenting hand-written functions

Every function registered in `manual/sol_ImGui_Manual.cpp` must carry one or more
`// @lua <Signature>` comments at its registration, giving the exact Lua-facing
signature(s). The generator reads these to produce accurate entries in
`docs/API.md`, and **fails if a registered manual function has no `// @lua` line**
(or if a `// @lua` names a function that isn't registered). So when you add or
change a manual wrapper, update its `// @lua` line in the same place — that one
line is the entire doc-maintenance cost for the hand-written set. Generated
functions are documented automatically.

### Known intentional gaps
- **Obsolete ImGui functions** (e.g. `BeginChildFrame`, `CaptureMouseFromApp`,
  `PushAllowKeyboardFocus`, `Value`) are not bound — they no longer exist in the
  targeted ImGui version.
- **`GetFont` / `PushFont`** are not bound (they require exposing `ImFont*`).

## Bumping Dear ImGui or sol2

1. Update `vcpkg.json` here (and the engine's `vcpkg.json`) to the new version.
   Keep them in lockstep.
2. Regenerate the metadata from the headers you build against:
   ```sh
   codegen/fetch_metadata.sh <vcpkg_installed>/<triplet>/include
   ```
   If ImGui changed enough that the pinned `dear_bindings` cannot parse it, bump
   `DEAR_BINDINGS_SHA` in `codegen/fetch_metadata.sh`.
3. Regenerate the bindings:
   ```sh
   python codegen/generate.py        # or: cmake --build build --target regen-bindings
   ```
4. Review `git diff`:
   - New functions/enums appear automatically.
   - Read the new entries in `generated/denylist_report.txt`. For each function
     that now needs hand-binding, either implement it in `manual/` and list it
     under `[manual]` in `codegen/overrides.toml`, or accept the deferral.
5. Build and test (Linux + MSVC):
   ```sh
   cmake -B build -S . -DSOL2_IMGUI_BINDINGS_BUILD_TESTS=ON \
     -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
   cmake --build build && ctest --test-dir build --output-on-failure
   ```
6. Commit `generated/` + `codegen/metadata/` together. CI's drift gate
   (`generate.py --check`) must pass.
7. In the engine: bump the submodule pointer, run `LuaApiSmokeTest`, run the
   example `game.lua`.

## CI

`.github/workflows/ci.yml` runs: a host-only **drift gate** (committed
`generated/` must match `generate.py`), then a build + headless smoke test on
gcc, clang, and MSVC (the MSVC leg, built without `/bigobj`, guards the
generated-TU bin-packing).
