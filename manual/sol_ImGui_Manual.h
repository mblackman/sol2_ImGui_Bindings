#pragma once
// Hand-written bindings for the ImGui functions code generation cannot express
// cleanly: ImVec2/ImVec4 usertypes, text helpers (varargs), output-bool windows
// (Begin/CollapsingHeader p_open), text-input buffers, item-list widgets
// (Combo), and the float[N]/int[N] array widgets. Everything else is generated
// (see generated/). The set of functions left to this file is reported in
// generated/denylist_report.txt each time the generator runs.
#include <sol/sol.hpp>

namespace sol_ImGui {
// Registers the ImVec2/ImVec4 Lua usertypes consumed by generated + manual
// functions. Call once, before installing the function tables.
void RegisterVecTypes(sol::state& lua);

// Registers the hand-written functions into the ImGui table.
void InitManual(sol::table& t);
}  // namespace sol_ImGui
