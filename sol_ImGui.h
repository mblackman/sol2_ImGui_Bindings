#pragma once
// Public entry point for the sol2 Dear ImGui bindings.
//
// Most of the binding surface is GENERATED from Dear ImGui metadata (see
// codegen/ and generated/). A small hand-written set lives in manual/ for the
// cases code generation cannot express cleanly (text-input buffers, ImVec2/4
// usertypes, output-bool windows like Begin, array widgets, and genuine
// overloads). Call sol_ImGui::Init(lua) once to install the global `ImGui`
// table, its enums, and the ImVec2/ImVec4 usertypes.
#include "imgui.h"
#include <sol/sol.hpp>
#include <string>
#include <tuple>
#include <vector>
#if !defined(_MSC_VER)
#include <cstring>  // strlen, memcpy
#endif

#include "generated/sol_ImGui_Generated.h"
#include "manual/sol_ImGui_Manual.h"

// strncpy_s polyfill for non-MSVC toolchains (used by the manual text-input
// bindings). MSVC provides strncpy_s natively.
#if !defined(_MSC_VER)
inline int strncpy_s(char* dest, size_t destsz, const char* src, size_t count) {
    if (!dest || destsz == 0 || !src) return 1;  // EINVAL
    size_t src_len = strlen(src);
    size_t len_to_copy = std::min({count, destsz - 1, src_len});
    memcpy(dest, src, len_to_copy);
    dest[len_to_copy] = '\0';
    return 0;
}
#endif

namespace sol_ImGui {
// Installs the ImGui table (enums + generated functions + manual functions and
// the ImVec2/ImVec4 usertypes) into the given Lua state.
void Init(sol::state& lua);
}  // namespace sol_ImGui
