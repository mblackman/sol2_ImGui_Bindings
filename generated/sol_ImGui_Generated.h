// GENERATED FILE -- DO NOT EDIT BY HAND.
// Produced by codegen/generate.py from codegen/metadata/dcimgui.json.
// Regenerate with the `regen-bindings` CMake target; see CONTRIBUTING.md.

#pragma once
#include <sol/sol.hpp>

namespace sol_ImGui {
void InitEnums(sol::state& lua);
void InitGenerated_0(sol::table& t);
void InitGenerated_1(sol::table& t);
void InitGenerated_2(sol::table& t);

inline void InitGenerated(sol::table& t) {
  InitGenerated_0(t);
  InitGenerated_1(t);
  InitGenerated_2(t);
}
}  // namespace sol_ImGui
