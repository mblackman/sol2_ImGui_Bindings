# sol2_ImGui_Bindings

Lua bindings for [Dear ImGui](https://github.com/ocornut/imgui) via
[sol2](https://github.com/ThePhD/sol2), for projects embedding **standard
PUC-Lua** (where LuaJIT FFI isn't an option).

The binding surface is generated from Dear ImGui's machine-readable API
description, with a small hand-written file for the cases code generation can't
express cleanly. Updating ImGui is "regenerate, review the diff, run the tests"
(see [`CONTRIBUTING.md`](CONTRIBUTING.md)).

## Usage

```cpp
#include "sol_ImGui.h"

sol::state lua;
lua.open_libraries(sol::lib::base /* , ... */);
sol_ImGui::Init(lua);   // installs the global `ImGui` table, enums, ImVec2/4
```

Then, inside an ImGui frame, from Lua:

```lua
if ImGui.Begin("Tools") then
    ImGui.Text("hello")
    local clicked = ImGui.Button("ok")
    speed = ImGui.SliderFloat("speed", speed, 0.0, 10.0)  -- value-first return
    count = ImGui.InputInt("count", count)
    if ImGui.CollapsingHeader("section") then
        local f = ImGui.ColorEdit4("tint", {1, 1, 1, 1})  -- array widget -> table
    end
end
ImGui.End()
```

Conventions:
- ImGui's output pointers become **value-first tuple returns**:
  `value, used = ImGui.SliderFloat(...)`. Callers that want only the value can
  write `value = ImGui.SliderFloat(...)`.
- `ImVec2`/`ImVec4` are Lua usertypes: `ImVec2.new(x, y)`, `.x`, `.y`.
- Enums are **global tables** of integer constants: `ImGuiWindowFlags.NoTitleBar`,
  `ImGuiCol.Text`, etc.
- `float[N]`/`int[N]` widgets take and return a Lua array (table):
  `xy, used = ImGui.DragFloat2("p", {x, y})`.

See **[`docs/API.md`](docs/API.md)** for the full reference: every bound function
and enum, with signatures and ImGui's own descriptions.

## Integrating into a CMake project

**add_subdirectory / FetchContent** (recommended):
```cmake
add_subdirectory(libs/sol2_ImGui_Bindings)        # or FetchContent, below
target_link_libraries(my_app PRIVATE sol2_ImGui_Bindings::sol2_ImGui_Bindings)
```
To pin a published release with `FetchContent`, point `GIT_TAG` at a release tag
(see [Releases](https://github.com/mblackman/sol2_ImGui_Bindings/releases)):
```cmake
include(FetchContent)
FetchContent_Declare(sol2_ImGui_Bindings
    GIT_REPOSITORY https://github.com/mblackman/sol2_ImGui_Bindings
    GIT_TAG        v1.92.7-1)                       # ImGui version + binding revision
FetchContent_MakeAvailable(sol2_ImGui_Bindings)
```
The library finds `imgui::imgui` and `sol2::sol2` itself (via `find_package`) if
the consumer hasn't already defined them.

**Installed / find_package:**
```cmake
find_package(sol2_ImGui_Bindings CONFIG REQUIRED)
target_link_libraries(my_app PRIVATE sol2_ImGui_Bindings::sol2_ImGui_Bindings)
```
Release tags are `vX.Y.Z-<rev>`, where `X.Y.Z` is the targeted Dear ImGui version
and `-<rev>` is a binding revision (binding-only fixes bump `<rev>` without an
ImGui change). The `-<rev>` lives only in the git tag; CMake `find_package`
version comparisons see just the `X.Y.Z` project version.

Dependencies: Dear ImGui (built with the `docking-experimental` feature for the
docking bindings) and sol2. `vcpkg.json` pins versions known to work.

## What's covered

Every public enum and every free `ImGui::` function the generator can express,
plus a hand-written set for the rest. See [`docs/API.md`](docs/API.md) for the
full list, and `generated/denylist_report.txt` for the functions that are left
out and why.

Not bound: obsolete ImGui functions removed from the targeted version, varargs
`*V` helpers, callbacks, and anything requiring opaque handles (`ImTextureID`,
`ImDrawList*`, `ImFont*`).

## Binary size

sol2 binds via templates, so a large surface costs binary size. The bindings are
split across translation units and compiled with `-ffunction-sections
-fdata-sections` (`/Gy /Gw` on MSVC) so the consumer's linker can drop unused and
fold identical wrappers. To shrink the final binary:

```cmake
set(SOL2_IMGUI_BINDINGS_SIZE_OPT ON)   # builds the bindings with -Os + LTO
# consumer link flags:
#   GCC/Clang: -Wl,--gc-sections  (+ -Wl,--icf=all with lld/gold)  (+ -flto)
#   MSVC:      /OPT:REF /OPT:ICF   (+ /LTCG)
```

## Maintenance

The generator, the ImGui/sol2 bump procedure, and the CI drift gate are
documented in [`CONTRIBUTING.md`](CONTRIBUTING.md). In short: `codegen/generate.py`
reads `codegen/metadata/dcimgui.json` and writes the committed `generated/`
sources and `docs/API.md`; `codegen/generate.py --check` is the drift gate.

A built library targets one ImGui version (the headers it compiles against). To
retarget, regenerate against that version's headers
(`codegen/fetch_metadata.sh <imgui-include-dir>` then `generate.py`) and rebuild;
the generator picks up added/removed functions automatically and reports any new
cases that need a hand-written wrapper.

## License

MIT (see [`LICENSE`](LICENSE)) — original work © 2020 MSeys.
