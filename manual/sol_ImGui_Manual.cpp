#include "sol_ImGui.h"

// Hand-written bindings. See sol_ImGui_Manual.h for the rationale. These are the
// functions the generator routes to "manual" (output-bool windows, text-input
// buffers, item lists, ImVec usertypes) or to array widgets. Genuine overloads
// and array widgets are added incrementally here; remaining gaps are listed in
// generated/denylist_report.txt.

namespace sol_ImGui {
namespace {

// ---- text helpers (ImGui's varargs collapsed to a plain string) ----
void Text(const std::string& text) { ImGui::Text("%s", text.c_str()); }
void TextColored(const ImVec4& col, const std::string& text) { ImGui::TextColored(col, "%s", text.c_str()); }
void TextDisabled(const std::string& text) { ImGui::TextDisabled("%s", text.c_str()); }
void TextWrapped(const std::string& text) { ImGui::TextWrapped("%s", text.c_str()); }
void LabelText(const std::string& label, const std::string& text) {
    ImGui::LabelText(label.c_str(), "%s", text.c_str());
}
void BulletText(const std::string& text) { ImGui::BulletText("%s", text.c_str()); }
void SetTooltip(const std::string& text) { ImGui::SetTooltip("%s", text.c_str()); }
void SetItemTooltip(const std::string& text) { ImGui::SetItemTooltip("%s", text.c_str()); }

// ---- windows with an optional output "open" bool ----
// Begin(name)            -> bool (should-draw)         [single return]
// Begin(name, open)      -> (open, should-draw)        [open is in/out]
// Begin(name, open, flags) likewise.
bool Begin(const std::string& name) { return ImGui::Begin(name.c_str()); }
std::tuple<bool, bool> BeginOpen(const std::string& name, bool open) {
    bool p_open = open;
    bool draw = ImGui::Begin(name.c_str(), &p_open);
    return {p_open, draw};
}
std::tuple<bool, bool> BeginOpenFlags(const std::string& name, bool open, int flags) {
    bool p_open = open;
    bool draw = ImGui::Begin(name.c_str(), &p_open, flags);
    return {p_open, draw};
}

bool CollapsingHeader(const std::string& label) { return ImGui::CollapsingHeader(label.c_str()); }
bool CollapsingHeaderFlags(const std::string& label, int flags) {
    return ImGui::CollapsingHeader(label.c_str(), flags);
}
std::tuple<bool, bool> CollapsingHeaderVisible(const std::string& label, bool visible, int flags) {
    bool p_visible = visible;
    bool open = ImGui::CollapsingHeader(label.c_str(), &p_visible, flags);
    return {p_visible, open};
}

// ---- child windows (bool-border overloads) ----
bool BeginChild(const std::string& name) {
    return ImGui::BeginChild(name.c_str(), {0, 0}, ImGuiChildFlags_None, 0);
}
bool BeginChildSize(const std::string& name, const ImVec2& size, int child_flags, int window_flags) {
    return ImGui::BeginChild(name.c_str(), size, child_flags, window_flags);
}

// ---- text input (manual buffer management) ----
std::tuple<std::string, bool> InputText(const std::string& label, std::string text, size_t buf_size,
                                        sol::optional<int> flags) {
    std::vector<char> buffer(buf_size);
    strncpy_s(buffer.data(), buf_size, text.c_str(), text.length());
    buffer[std::min(buf_size - 1, text.length())] = '\0';
    bool changed = ImGui::InputText(label.c_str(), buffer.data(), buf_size, flags.value_or(0));
    return {std::string(buffer.data()), changed};
}
std::tuple<std::string, bool> InputTextMultiline(const std::string& label, std::string text, size_t buf_size,
                                                 sol::optional<ImVec2> size, sol::optional<int> flags) {
    std::vector<char> buffer(buf_size);
    strncpy_s(buffer.data(), buf_size, text.c_str(), text.length());
    buffer[std::min(buf_size - 1, text.length())] = '\0';
    bool changed = ImGui::InputTextMultiline(label.c_str(), buffer.data(), buf_size,
                                             size.value_or(ImVec2(0, 0)), flags.value_or(0));
    return {std::string(buffer.data()), changed};
}
std::tuple<std::string, bool> InputTextWithHint(const std::string& label, const std::string& hint, std::string text,
                                                size_t buf_size, sol::optional<int> flags) {
    std::vector<char> buffer(buf_size);
    strncpy_s(buffer.data(), buf_size, text.c_str(), text.length());
    buffer[std::min(buf_size - 1, text.length())] = '\0';
    bool changed = ImGui::InputTextWithHint(label.c_str(), hint.c_str(), buffer.data(), buf_size, flags.value_or(0));
    return {std::string(buffer.data()), changed};
}

// ---- item lists ----
std::tuple<int, bool> Combo(const std::string& label, int current_item, const sol::table& items, int items_count) {
    std::vector<std::string> storage;
    std::vector<const char*> ptrs;
    storage.reserve(items_count);
    ptrs.reserve(items_count);
    for (int i = 1; i <= items_count; ++i) {
        storage.push_back(items.get<std::string>(i));
        ptrs.push_back(storage.back().c_str());
    }
    int idx = current_item - 1;  // Lua is 1-based; ImGui is 0-based
    bool changed = ImGui::Combo(label.c_str(), &idx, ptrs.data(), items_count);
    return {idx + 1, changed};
}

// ---- float[N] / int[N] array widgets ----
template <int N, typename Fn>
std::tuple<sol::as_table_t<std::vector<float>>, bool> FloatArrayWidget(const sol::table& v, Fn&& call) {
    float arr[N] = {0};
    for (int i = 0; i < N; ++i) arr[i] = v.get<float>(i + 1);
    bool used = call(arr);
    std::vector<float> out(arr, arr + N);
    return {sol::as_table(std::move(out)), used};
}
template <int N, typename Fn>
std::tuple<sol::as_table_t<std::vector<int>>, bool> IntArrayWidget(const sol::table& v, Fn&& call) {
    int arr[N] = {0};
    for (int i = 0; i < N; ++i) arr[i] = v.get<int>(i + 1);
    bool used = call(arr);
    std::vector<int> out(arr, arr + N);
    return {sol::as_table(std::move(out)), used};
}

auto DragFloat2(const std::string& l, const sol::table& v, sol::optional<float> speed) {
    float s = speed.value_or(1.0f);
    return FloatArrayWidget<2>(v, [&](float* a) { return ImGui::DragFloat2(l.c_str(), a, s); });
}
auto DragFloat3(const std::string& l, const sol::table& v, sol::optional<float> speed) {
    float s = speed.value_or(1.0f);
    return FloatArrayWidget<3>(v, [&](float* a) { return ImGui::DragFloat3(l.c_str(), a, s); });
}
auto SliderFloat2(const std::string& l, const sol::table& v, float mn, float mx) {
    return FloatArrayWidget<2>(v, [&](float* a) { return ImGui::SliderFloat2(l.c_str(), a, mn, mx); });
}
auto SliderFloat3(const std::string& l, const sol::table& v, float mn, float mx) {
    return FloatArrayWidget<3>(v, [&](float* a) { return ImGui::SliderFloat3(l.c_str(), a, mn, mx); });
}
auto InputFloat2(const std::string& l, const sol::table& v) {
    return FloatArrayWidget<2>(v, [&](float* a) { return ImGui::InputFloat2(l.c_str(), a); });
}
auto InputFloat3(const std::string& l, const sol::table& v) {
    return FloatArrayWidget<3>(v, [&](float* a) { return ImGui::InputFloat3(l.c_str(), a); });
}
auto ColorEdit3(const std::string& l, const sol::table& v, sol::optional<int> flags) {
    int f = flags.value_or(0);
    return FloatArrayWidget<3>(v, [&](float* a) { return ImGui::ColorEdit3(l.c_str(), a, f); });
}
auto ColorEdit4(const std::string& l, const sol::table& v, sol::optional<int> flags) {
    int f = flags.value_or(0);
    return FloatArrayWidget<4>(v, [&](float* a) { return ImGui::ColorEdit4(l.c_str(), a, f); });
}
auto InputInt2(const std::string& l, const sol::table& v) {
    return IntArrayWidget<2>(v, [&](int* a) { return ImGui::InputInt2(l.c_str(), a); });
}
auto InputInt3(const std::string& l, const sol::table& v) {
    return IntArrayWidget<3>(v, [&](int* a) { return ImGui::InputInt3(l.c_str(), a); });
}

// ---- id stack overloads ----
void PushIDStr(const std::string& id) { ImGui::PushID(id.c_str()); }
void PushIDInt(int id) { ImGui::PushID(id); }
int GetIDStr(const std::string& id) { return static_cast<int>(ImGui::GetID(id.c_str())); }

// ---- more array widgets ----
auto DragFloat4(const std::string& l, const sol::table& v, sol::optional<float> speed) {
    float s = speed.value_or(1.0f);
    return FloatArrayWidget<4>(v, [&](float* a) { return ImGui::DragFloat4(l.c_str(), a, s); });
}
auto SliderFloat4(const std::string& l, const sol::table& v, float mn, float mx) {
    return FloatArrayWidget<4>(v, [&](float* a) { return ImGui::SliderFloat4(l.c_str(), a, mn, mx); });
}
auto InputFloat4(const std::string& l, const sol::table& v) {
    return FloatArrayWidget<4>(v, [&](float* a) { return ImGui::InputFloat4(l.c_str(), a); });
}
auto ColorPicker3(const std::string& l, const sol::table& v, sol::optional<int> flags) {
    int f = flags.value_or(0);
    return FloatArrayWidget<3>(v, [&](float* a) { return ImGui::ColorPicker3(l.c_str(), a, f); });
}
auto ColorPicker4(const std::string& l, const sol::table& v, sol::optional<int> flags) {
    int f = flags.value_or(0);
    return FloatArrayWidget<4>(v, [&](float* a) { return ImGui::ColorPicker4(l.c_str(), a, f, nullptr); });
}
auto DragInt2(const std::string& l, const sol::table& v, sol::optional<float> speed) {
    float s = speed.value_or(1.0f);
    return IntArrayWidget<2>(v, [&](int* a) { return ImGui::DragInt2(l.c_str(), a, s); });
}
auto DragInt3(const std::string& l, const sol::table& v, sol::optional<float> speed) {
    float s = speed.value_or(1.0f);
    return IntArrayWidget<3>(v, [&](int* a) { return ImGui::DragInt3(l.c_str(), a, s); });
}
auto DragInt4(const std::string& l, const sol::table& v, sol::optional<float> speed) {
    float s = speed.value_or(1.0f);
    return IntArrayWidget<4>(v, [&](int* a) { return ImGui::DragInt4(l.c_str(), a, s); });
}
auto SliderInt2(const std::string& l, const sol::table& v, int mn, int mx) {
    return IntArrayWidget<2>(v, [&](int* a) { return ImGui::SliderInt2(l.c_str(), a, mn, mx); });
}
auto SliderInt3(const std::string& l, const sol::table& v, int mn, int mx) {
    return IntArrayWidget<3>(v, [&](int* a) { return ImGui::SliderInt3(l.c_str(), a, mn, mx); });
}
auto SliderInt4(const std::string& l, const sol::table& v, int mn, int mx) {
    return IntArrayWidget<4>(v, [&](int* a) { return ImGui::SliderInt4(l.c_str(), a, mn, mx); });
}
auto InputInt4(const std::string& l, const sol::table& v) {
    return IntArrayWidget<4>(v, [&](int* a) { return ImGui::InputInt4(l.c_str(), a); });
}

// ---- windows / popups / tabs with an optional output bool ----
bool BeginPopupModal(const std::string& name) { return ImGui::BeginPopupModal(name.c_str()); }
std::tuple<bool, bool> BeginPopupModalOpen(const std::string& name, bool open, sol::optional<int> flags) {
    bool p_open = open;
    bool draw = ImGui::BeginPopupModal(name.c_str(), &p_open, flags.value_or(0));
    return {p_open, draw};
}
bool BeginTabItem(const std::string& label) { return ImGui::BeginTabItem(label.c_str()); }
std::tuple<bool, bool> BeginTabItemOpen(const std::string& label, bool open, sol::optional<int> flags) {
    bool p_open = open;
    bool visible = ImGui::BeginTabItem(label.c_str(), &p_open, flags.value_or(0));
    return {p_open, visible};
}

// ---- menus / selectables / radio / flags ----
bool MenuItem(const std::string& label) { return ImGui::MenuItem(label.c_str()); }
bool MenuItemShortcut(const std::string& label, const std::string& shortcut) {
    return ImGui::MenuItem(label.c_str(), shortcut.c_str());
}
std::tuple<bool, bool> MenuItemSelected(const std::string& label, const std::string& shortcut, bool selected,
                                        sol::optional<bool> enabled) {
    bool sel = selected;
    bool activated = ImGui::MenuItem(label.c_str(), shortcut.c_str(), &sel, enabled.value_or(true));
    return {sel, activated};
}
bool Selectable(const std::string& label) { return ImGui::Selectable(label.c_str()); }
std::tuple<bool, bool> SelectableToggle(const std::string& label, bool selected, sol::optional<int> flags) {
    bool sel = selected;
    bool pressed = ImGui::Selectable(label.c_str(), &sel, flags.value_or(0));
    return {sel, pressed};
}
bool RadioButton(const std::string& label, bool active) { return ImGui::RadioButton(label.c_str(), active); }
std::tuple<int, bool> RadioButtonGroup(const std::string& label, int v, int v_button) {
    int vv = v;
    bool pressed = ImGui::RadioButton(label.c_str(), &vv, v_button);
    return {vv, pressed};
}
std::tuple<int, bool> CheckboxFlags(const std::string& label, int flags, int flags_value) {
    int f = flags;
    bool pressed = ImGui::CheckboxFlags(label.c_str(), &f, flags_value);
    return {f, pressed};
}

// ---- trees ----
bool TreeNode(const std::string& label) { return ImGui::TreeNode(label.c_str()); }
bool TreeNodeText(const std::string& str_id, const std::string& text) {
    return ImGui::TreeNode(str_id.c_str(), "%s", text.c_str());
}
bool TreeNodeEx(const std::string& label) { return ImGui::TreeNodeEx(label.c_str()); }
bool TreeNodeExFlags(const std::string& label, int flags) { return ImGui::TreeNodeEx(label.c_str(), flags); }
bool TreeNodeExText(const std::string& str_id, int flags, const std::string& text) {
    return ImGui::TreeNodeEx(str_id.c_str(), flags, "%s", text.c_str());
}
void TreePush(const std::string& str_id) { ImGui::TreePush(str_id.c_str()); }

// ---- item lists ----
std::tuple<int, bool> ListBox(const std::string& label, int current_item, const sol::table& items, int items_count,
                              sol::optional<int> height_in_items) {
    std::vector<std::string> storage;
    std::vector<const char*> ptrs;
    storage.reserve(items_count);
    ptrs.reserve(items_count);
    for (int i = 1; i <= items_count; ++i) {
        storage.push_back(items.get<std::string>(i));
        ptrs.push_back(storage.back().c_str());
    }
    int idx = current_item - 1;  // Lua 1-based -> ImGui 0-based
    bool changed = ImGui::ListBox(label.c_str(), &idx, ptrs.data(), items_count, height_in_items.value_or(-1));
    return {idx + 1, changed};
}

// ---- popups ----
void OpenPopup(const std::string& str_id, sol::optional<int> flags) {
    ImGui::OpenPopup(str_id.c_str(), flags.value_or(0));
}

// ---- style stack ----
void PushStyleColor(int idx, const ImVec4& col) { ImGui::PushStyleColor(idx, col); }
void PushStyleColorU32(int idx, unsigned int col) { ImGui::PushStyleColor(idx, static_cast<ImU32>(col)); }
void PushStyleVarF(int idx, float val) { ImGui::PushStyleVar(idx, val); }
void PushStyleVarV(int idx, const ImVec2& val) { ImGui::PushStyleVar(idx, val); }
int GetColorU32Idx(int idx, sol::optional<float> alpha_mul) {
    return static_cast<int>(ImGui::GetColorU32(idx, alpha_mul.value_or(1.0f)));
}
int GetColorU32Vec(const ImVec4& col) { return static_cast<int>(ImGui::GetColorU32(col)); }
ImVec4 GetStyleColorVec4(int idx) { return ImGui::GetStyleColorVec4(idx); }

// ---- window manipulation (current window) ----
void SetWindowPos(const ImVec2& pos, sol::optional<int> cond) { ImGui::SetWindowPos(pos, cond.value_or(0)); }
void SetWindowSize(const ImVec2& size, sol::optional<int> cond) { ImGui::SetWindowSize(size, cond.value_or(0)); }
void SetWindowCollapsed(bool collapsed, sol::optional<int> cond) {
    ImGui::SetWindowCollapsed(collapsed, cond.value_or(0));
}
void SetWindowFocus() { ImGui::SetWindowFocus(); }
void SetNextWindowSizeConstraints(const ImVec2& size_min, const ImVec2& size_max) {
    ImGui::SetNextWindowSizeConstraints(size_min, size_max);
}

// ---- misc ----
unsigned int DockSpace(unsigned int id, sol::optional<ImVec2> size, sol::optional<int> flags) {
    return ImGui::DockSpace(id, size.value_or(ImVec2(0, 0)), flags.value_or(0));
}
bool IsRectVisibleSize(const ImVec2& size) { return ImGui::IsRectVisible(size); }
bool IsRectVisibleRect(const ImVec2& rect_min, const ImVec2& rect_max) {
    return ImGui::IsRectVisible(rect_min, rect_max);
}
bool IsMousePosValid() { return ImGui::IsMousePosValid(); }
bool IsMousePosValidAt(const ImVec2& pos) { return ImGui::IsMousePosValid(&pos); }
void LogText(const std::string& text) { ImGui::LogText("%s", text.c_str()); }

}  // namespace

void RegisterVecTypes(sol::state& lua) {
    // Members are exposed via property lambdas rather than &ImVec2::x member
    // pointers: newer Clang rejects sol2's member-variable binding for these
    // POD vectors (a template substitution failure on `float ImVec2::*`), while
    // property accessors compile identically across GCC/Clang/MSVC.
    lua.new_usertype<ImVec2>(
        "ImVec2", sol::constructors<ImVec2(), ImVec2(float, float)>(),
        "x", sol::property([](const ImVec2& v) { return v.x; }, [](ImVec2& v, float x) { v.x = x; }),
        "y", sol::property([](const ImVec2& v) { return v.y; }, [](ImVec2& v, float y) { v.y = y; }));
    lua.new_usertype<ImVec4>(
        "ImVec4", sol::constructors<ImVec4(), ImVec4(float, float, float, float)>(),
        "x", sol::property([](const ImVec4& v) { return v.x; }, [](ImVec4& v, float x) { v.x = x; }),
        "y", sol::property([](const ImVec4& v) { return v.y; }, [](ImVec4& v, float y) { v.y = y; }),
        "z", sol::property([](const ImVec4& v) { return v.z; }, [](ImVec4& v, float z) { v.z = z; }),
        "w", sol::property([](const ImVec4& v) { return v.w; }, [](ImVec4& v, float w) { v.w = w; }));
}

// Each registration carries one or more `// @lua` lines giving the exact
// Lua-facing signature(s). codegen/generate.py reads these to document the
// hand-written functions accurately, and the drift gate fails if any registered
// function is missing one. Keep them in sync when you change a wrapper.
void InitManual(sol::table& t) {
    // @lua Text(text: string)
    t.set_function("Text", Text);
    // @lua TextColored(col: ImVec4, text: string)
    t.set_function("TextColored", TextColored);
    // @lua TextDisabled(text: string)
    t.set_function("TextDisabled", TextDisabled);
    // @lua TextWrapped(text: string)
    t.set_function("TextWrapped", TextWrapped);
    // @lua LabelText(label: string, text: string)
    t.set_function("LabelText", LabelText);
    // @lua BulletText(text: string)
    t.set_function("BulletText", BulletText);
    // @lua SetTooltip(text: string)
    t.set_function("SetTooltip", SetTooltip);
    // @lua SetItemTooltip(text: string)
    t.set_function("SetItemTooltip", SetItemTooltip);

    // @lua Begin(name: string) -> visible: boolean
    // @lua Begin(name: string, open: boolean [, flags: integer]) -> open: boolean, visible: boolean
    t.set_function("Begin", sol::overload(Begin, BeginOpen, BeginOpenFlags));
    // @lua CollapsingHeader(label: string [, flags: integer]) -> boolean
    // @lua CollapsingHeader(label: string, visible: boolean, flags: integer) -> visible: boolean, open: boolean
    t.set_function("CollapsingHeader",
                   sol::overload(CollapsingHeader, CollapsingHeaderFlags, CollapsingHeaderVisible));
    // @lua BeginChild(name: string) -> boolean
    // @lua BeginChild(name: string, size: ImVec2, child_flags: integer, window_flags: integer) -> boolean
    t.set_function("BeginChild", sol::overload(BeginChild, BeginChildSize));

    // @lua InputText(label: string, text: string, buf_size: integer [, flags: integer]) -> text: string, changed: boolean
    t.set_function("InputText", InputText);
    // @lua InputTextMultiline(label: string, text: string, buf_size: integer [, size: ImVec2, flags: integer]) -> text: string, changed: boolean
    t.set_function("InputTextMultiline", InputTextMultiline);
    // @lua InputTextWithHint(label: string, hint: string, text: string, buf_size: integer [, flags: integer]) -> text: string, changed: boolean
    t.set_function("InputTextWithHint", InputTextWithHint);

    // @lua Combo(label: string, current_item: integer, items: table, items_count: integer) -> current_item: integer, changed: boolean
    t.set_function("Combo", Combo);

    // @lua DragFloat2(label: string, v: table [, v_speed: number]) -> v: table, used: boolean
    t.set_function("DragFloat2", DragFloat2);
    // @lua DragFloat3(label: string, v: table [, v_speed: number]) -> v: table, used: boolean
    t.set_function("DragFloat3", DragFloat3);
    // @lua SliderFloat2(label: string, v: table, v_min: number, v_max: number) -> v: table, used: boolean
    t.set_function("SliderFloat2", SliderFloat2);
    // @lua SliderFloat3(label: string, v: table, v_min: number, v_max: number) -> v: table, used: boolean
    t.set_function("SliderFloat3", SliderFloat3);
    // @lua InputFloat2(label: string, v: table) -> v: table, used: boolean
    t.set_function("InputFloat2", InputFloat2);
    // @lua InputFloat3(label: string, v: table) -> v: table, used: boolean
    t.set_function("InputFloat3", InputFloat3);
    // @lua ColorEdit3(label: string, col: table [, flags: integer]) -> col: table, used: boolean
    t.set_function("ColorEdit3", ColorEdit3);
    // @lua ColorEdit4(label: string, col: table [, flags: integer]) -> col: table, used: boolean
    t.set_function("ColorEdit4", ColorEdit4);
    // @lua InputInt2(label: string, v: table) -> v: table, used: boolean
    t.set_function("InputInt2", InputInt2);
    // @lua InputInt3(label: string, v: table) -> v: table, used: boolean
    t.set_function("InputInt3", InputInt3);

    // @lua PushID(id: string)
    // @lua PushID(id: integer)
    t.set_function("PushID", sol::overload(PushIDStr, PushIDInt));
    // @lua GetID(id: string) -> integer
    t.set_function("GetID", GetIDStr);

    // more array widgets
    // @lua DragFloat4(label: string, v: table [, v_speed: number]) -> v: table, used: boolean
    t.set_function("DragFloat4", DragFloat4);
    // @lua SliderFloat4(label: string, v: table, v_min: number, v_max: number) -> v: table, used: boolean
    t.set_function("SliderFloat4", SliderFloat4);
    // @lua InputFloat4(label: string, v: table) -> v: table, used: boolean
    t.set_function("InputFloat4", InputFloat4);
    // @lua ColorPicker3(label: string, col: table [, flags: integer]) -> col: table, used: boolean
    t.set_function("ColorPicker3", ColorPicker3);
    // @lua ColorPicker4(label: string, col: table [, flags: integer]) -> col: table, used: boolean
    t.set_function("ColorPicker4", ColorPicker4);
    // @lua DragInt2(label: string, v: table [, v_speed: number]) -> v: table, used: boolean
    t.set_function("DragInt2", DragInt2);
    // @lua DragInt3(label: string, v: table [, v_speed: number]) -> v: table, used: boolean
    t.set_function("DragInt3", DragInt3);
    // @lua DragInt4(label: string, v: table [, v_speed: number]) -> v: table, used: boolean
    t.set_function("DragInt4", DragInt4);
    // @lua SliderInt2(label: string, v: table, v_min: integer, v_max: integer) -> v: table, used: boolean
    t.set_function("SliderInt2", SliderInt2);
    // @lua SliderInt3(label: string, v: table, v_min: integer, v_max: integer) -> v: table, used: boolean
    t.set_function("SliderInt3", SliderInt3);
    // @lua SliderInt4(label: string, v: table, v_min: integer, v_max: integer) -> v: table, used: boolean
    t.set_function("SliderInt4", SliderInt4);
    // @lua InputInt4(label: string, v: table) -> v: table, used: boolean
    t.set_function("InputInt4", InputInt4);

    // windows / popups / tabs with optional output bool
    // @lua BeginPopupModal(name: string) -> boolean
    // @lua BeginPopupModal(name: string, open: boolean [, flags: integer]) -> open: boolean, visible: boolean
    t.set_function("BeginPopupModal", sol::overload(BeginPopupModal, BeginPopupModalOpen));
    // @lua BeginTabItem(label: string) -> boolean
    // @lua BeginTabItem(label: string, open: boolean [, flags: integer]) -> open: boolean, visible: boolean
    t.set_function("BeginTabItem", sol::overload(BeginTabItem, BeginTabItemOpen));

    // menus / selectables / radio / flags
    // @lua MenuItem(label: string [, shortcut: string]) -> boolean
    // @lua MenuItem(label: string, shortcut: string, selected: boolean [, enabled: boolean]) -> selected: boolean, activated: boolean
    t.set_function("MenuItem", sol::overload(MenuItem, MenuItemShortcut, MenuItemSelected));
    // @lua Selectable(label: string) -> boolean
    // @lua Selectable(label: string, selected: boolean [, flags: integer]) -> selected: boolean, pressed: boolean
    t.set_function("Selectable", sol::overload(Selectable, SelectableToggle));
    // @lua RadioButton(label: string, active: boolean) -> boolean
    // @lua RadioButton(label: string, v: integer, v_button: integer) -> v: integer, pressed: boolean
    t.set_function("RadioButton", sol::overload(RadioButton, RadioButtonGroup));
    // @lua CheckboxFlags(label: string, flags: integer, flags_value: integer) -> flags: integer, pressed: boolean
    t.set_function("CheckboxFlags", CheckboxFlags);

    // trees
    // @lua TreeNode(label: string) -> boolean
    // @lua TreeNode(str_id: string, text: string) -> boolean
    t.set_function("TreeNode", sol::overload(TreeNode, TreeNodeText));
    // @lua TreeNodeEx(label: string [, flags: integer]) -> boolean
    // @lua TreeNodeEx(str_id: string, flags: integer, text: string) -> boolean
    t.set_function("TreeNodeEx", sol::overload(TreeNodeEx, TreeNodeExFlags, TreeNodeExText));
    // @lua TreePush(str_id: string)
    t.set_function("TreePush", TreePush);

    // item lists / popups
    // @lua ListBox(label: string, current_item: integer, items: table, items_count: integer [, height_in_items: integer]) -> current_item: integer, changed: boolean
    t.set_function("ListBox", ListBox);
    // @lua OpenPopup(str_id: string [, flags: integer])
    t.set_function("OpenPopup", OpenPopup);

    // style stack
    // @lua PushStyleColor(idx: integer, col: ImVec4)
    // @lua PushStyleColor(idx: integer, col: integer)
    t.set_function("PushStyleColor", sol::overload(PushStyleColor, PushStyleColorU32));
    // @lua PushStyleVar(idx: integer, val: number)
    // @lua PushStyleVar(idx: integer, val: ImVec2)
    t.set_function("PushStyleVar", sol::overload(PushStyleVarF, PushStyleVarV));
    // @lua GetColorU32(idx: integer [, alpha_mul: number]) -> integer
    // @lua GetColorU32(col: ImVec4) -> integer
    t.set_function("GetColorU32", sol::overload(GetColorU32Idx, GetColorU32Vec));
    // @lua GetStyleColorVec4(idx: integer) -> ImVec4
    t.set_function("GetStyleColorVec4", GetStyleColorVec4);

    // window manipulation
    // @lua SetWindowPos(pos: ImVec2 [, cond: integer])
    t.set_function("SetWindowPos", SetWindowPos);
    // @lua SetWindowSize(size: ImVec2 [, cond: integer])
    t.set_function("SetWindowSize", SetWindowSize);
    // @lua SetWindowCollapsed(collapsed: boolean [, cond: integer])
    t.set_function("SetWindowCollapsed", SetWindowCollapsed);
    // @lua SetWindowFocus()
    t.set_function("SetWindowFocus", SetWindowFocus);
    // @lua SetNextWindowSizeConstraints(size_min: ImVec2, size_max: ImVec2)
    t.set_function("SetNextWindowSizeConstraints", SetNextWindowSizeConstraints);

    // misc
    // @lua DockSpace(id: integer [, size: ImVec2, flags: integer]) -> integer
    t.set_function("DockSpace", DockSpace);
    // @lua IsRectVisible(size: ImVec2) -> boolean
    // @lua IsRectVisible(rect_min: ImVec2, rect_max: ImVec2) -> boolean
    t.set_function("IsRectVisible", sol::overload(IsRectVisibleSize, IsRectVisibleRect));
    // @lua IsMousePosValid() -> boolean
    // @lua IsMousePosValid(pos: ImVec2) -> boolean
    t.set_function("IsMousePosValid", sol::overload(IsMousePosValid, IsMousePosValidAt));
    // @lua LogText(text: string)
    t.set_function("LogText", LogText);
}
}  // namespace sol_ImGui
