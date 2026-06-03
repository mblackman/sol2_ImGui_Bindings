#include "sol_ImGui.h"

namespace sol_ImGui {
void Init(sol::state& lua) {
    InitEnums(lua);
    RegisterVecTypes(lua);

    sol::table imGuiTable = lua.create_named_table("ImGui");
    InitGenerated(imGuiTable);
    InitManual(imGuiTable);
}
}  // namespace sol_ImGui
