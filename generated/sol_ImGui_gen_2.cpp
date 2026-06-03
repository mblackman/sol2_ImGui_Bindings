// GENERATED FILE -- DO NOT EDIT BY HAND.
// Produced by codegen/generate.py from codegen/metadata/dcimgui.json.
// Regenerate with the `regen-bindings` CMake target; see CONTRIBUTING.md.

#include "sol_ImGui.h"

namespace sol_ImGui {
namespace {

bool BeginCombo(const std::string& label, const std::string& preview_value, sol::optional<ImGuiComboFlags> flags) {
  ImGuiComboFlags flags_v = static_cast<ImGuiComboFlags>(flags.value_or(0));
  auto ret = ImGui::BeginCombo(label.c_str(), preview_value.c_str(), flags_v);
  return ret;
}

bool BeginDragDropTarget() {
  auto ret = ImGui::BeginDragDropTarget();
  return ret;
}

bool BeginListBox(const std::string& label, sol::optional<ImVec2> size) {
  ImVec2 size_v = size.value_or(ImVec2(0, 0));
  auto ret = ImGui::BeginListBox(label.c_str(), size_v);
  return ret;
}

bool BeginMenuBar() {
  auto ret = ImGui::BeginMenuBar();
  return ret;
}

bool BeginPopupContextVoid(sol::optional<std::string> str_id, sol::optional<ImGuiPopupFlags> popup_flags) {
  std::string str_id_v = str_id.value_or(std::string());
  ImGuiPopupFlags popup_flags_v = static_cast<ImGuiPopupFlags>(popup_flags.value_or(0));
  auto ret = ImGui::BeginPopupContextVoid(str_id_v.c_str(), popup_flags_v);
  return ret;
}

bool BeginTable(const std::string& str_id, int columns, sol::optional<ImGuiTableFlags> flags, sol::optional<ImVec2> outer_size, sol::optional<float> inner_width) {
  ImGuiTableFlags flags_v = static_cast<ImGuiTableFlags>(flags.value_or(0));
  ImVec2 outer_size_v = outer_size.value_or(ImVec2(0.0f, 0.0f));
  float inner_width_v = inner_width.value_or(0.0f);
  auto ret = ImGui::BeginTable(str_id.c_str(), columns, flags_v, outer_size_v, inner_width_v);
  return ret;
}

bool Button(const std::string& label, sol::optional<ImVec2> size) {
  ImVec2 size_v = size.value_or(ImVec2(0, 0));
  auto ret = ImGui::Button(label.c_str(), size_v);
  return ret;
}

std::tuple<bool, bool> Checkbox(const std::string& label, bool v) {
  bool v_v = v;
  auto ret = ImGui::Checkbox(label.c_str(), &v_v);
  return std::make_tuple(v_v, ret);
}

ImU32 ColorConvertFloat4ToU32(const ImVec4& in) {
  auto ret = ImGui::ColorConvertFloat4ToU32(in);
  return ret;
}

ImVec4 ColorConvertU32ToFloat4(ImU32 in) {
  auto ret = ImGui::ColorConvertU32ToFloat4(static_cast<ImU32>(in));
  return ret;
}

void DebugFlashStyleColor(ImGuiCol idx) {
  ImGui::DebugFlashStyleColor(static_cast<ImGuiCol>(idx));
}

void DestroyPlatformWindows() {
  ImGui::DestroyPlatformWindows();
}

std::tuple<int, bool> DragInt(const std::string& label, int v, sol::optional<float> v_speed, sol::optional<int> v_min, sol::optional<int> v_max, sol::optional<std::string> format, sol::optional<ImGuiSliderFlags> flags) {
  int v_v = v;
  float v_speed_v = v_speed.value_or(1.0f);
  int v_min_v = v_min.value_or(0);
  int v_max_v = v_max.value_or(0);
  std::string format_v = format.value_or(std::string("%d"));
  ImGuiSliderFlags flags_v = static_cast<ImGuiSliderFlags>(flags.value_or(0));
  auto ret = ImGui::DragInt(label.c_str(), &v_v, v_speed_v, v_min_v, v_max_v, format_v.c_str(), flags_v);
  return std::make_tuple(v_v, ret);
}

void End() {
  ImGui::End();
}

void EndDisabled() {
  ImGui::EndDisabled();
}

void EndFrame() {
  ImGui::EndFrame();
}

void EndMainMenuBar() {
  ImGui::EndMainMenuBar();
}

void EndPopup() {
  ImGui::EndPopup();
}

void EndTable() {
  ImGui::EndTable();
}

int GetColumnIndex() {
  auto ret = ImGui::GetColumnIndex();
  return ret;
}

int GetColumnsCount() {
  auto ret = ImGui::GetColumnsCount();
  return ret;
}

ImVec2 GetCursorPos() {
  auto ret = ImGui::GetCursorPos();
  return ret;
}

ImVec2 GetCursorScreenPos() {
  auto ret = ImGui::GetCursorScreenPos();
  return ret;
}

ImVec2 GetFontTexUvWhitePixel() {
  auto ret = ImGui::GetFontTexUvWhitePixel();
  return ret;
}

float GetFrameHeightWithSpacing() {
  auto ret = ImGui::GetFrameHeightWithSpacing();
  return ret;
}

ImVec2 GetItemRectMax() {
  auto ret = ImGui::GetItemRectMax();
  return ret;
}

std::string GetKeyName(ImGuiKey key) {
  const char* ret = ImGui::GetKeyName(static_cast<ImGuiKey>(key));
  return std::string(ret ? ret : "");
}

ImGuiMouseCursor GetMouseCursor() {
  auto ret = ImGui::GetMouseCursor();
  return ret;
}

ImVec2 GetMousePosOnOpeningCurrentPopup() {
  auto ret = ImGui::GetMousePosOnOpeningCurrentPopup();
  return ret;
}

float GetScrollX() {
  auto ret = ImGui::GetScrollX();
  return ret;
}

float GetTextLineHeight() {
  auto ret = ImGui::GetTextLineHeight();
  return ret;
}

float GetTreeNodeToLabelSpacing() {
  auto ret = ImGui::GetTreeNodeToLabelSpacing();
  return ret;
}

ImVec2 GetWindowContentRegionMin() {
  auto ret = ImGui::GetWindowContentRegionMin();
  return ret;
}

float GetWindowHeight() {
  auto ret = ImGui::GetWindowHeight();
  return ret;
}

float GetWindowWidth() {
  auto ret = ImGui::GetWindowWidth();
  return ret;
}

std::tuple<float, bool> InputFloat(const std::string& label, float v, sol::optional<float> step, sol::optional<float> step_fast, sol::optional<std::string> format, sol::optional<ImGuiInputTextFlags> flags) {
  float v_v = v;
  float step_v = step.value_or(0.0f);
  float step_fast_v = step_fast.value_or(0.0f);
  std::string format_v = format.value_or(std::string("%.3f"));
  ImGuiInputTextFlags flags_v = static_cast<ImGuiInputTextFlags>(flags.value_or(0));
  auto ret = ImGui::InputFloat(label.c_str(), &v_v, step_v, step_fast_v, format_v.c_str(), flags_v);
  return std::make_tuple(v_v, ret);
}

bool IsAnyItemActive() {
  auto ret = ImGui::IsAnyItemActive();
  return ret;
}

bool IsAnyMouseDown() {
  auto ret = ImGui::IsAnyMouseDown();
  return ret;
}

bool IsItemClicked(sol::optional<ImGuiMouseButton> mouse_button) {
  ImGuiMouseButton mouse_button_v = static_cast<ImGuiMouseButton>(mouse_button.value_or(0));
  auto ret = ImGui::IsItemClicked(mouse_button_v);
  return ret;
}

bool IsItemEdited() {
  auto ret = ImGui::IsItemEdited();
  return ret;
}

bool IsItemToggledOpen() {
  auto ret = ImGui::IsItemToggledOpen();
  return ret;
}

bool IsKeyChordPressed(ImGuiKeyChord key_chord) {
  auto ret = ImGui::IsKeyChordPressed(static_cast<ImGuiKeyChord>(key_chord));
  return ret;
}

bool IsKeyReleased(ImGuiKey key) {
  auto ret = ImGui::IsKeyReleased(static_cast<ImGuiKey>(key));
  return ret;
}

bool IsMouseDown(ImGuiMouseButton button) {
  auto ret = ImGui::IsMouseDown(static_cast<ImGuiMouseButton>(button));
  return ret;
}

bool IsMouseReleased(ImGuiMouseButton button) {
  auto ret = ImGui::IsMouseReleased(static_cast<ImGuiMouseButton>(button));
  return ret;
}

bool IsWindowAppearing() {
  auto ret = ImGui::IsWindowAppearing();
  return ret;
}

bool IsWindowFocused(sol::optional<ImGuiFocusedFlags> flags) {
  ImGuiFocusedFlags flags_v = static_cast<ImGuiFocusedFlags>(flags.value_or(0));
  auto ret = ImGui::IsWindowFocused(flags_v);
  return ret;
}

void LoadIniSettingsFromMemory(const std::string& ini_data, sol::optional<size_t> ini_size) {
  size_t ini_size_v = static_cast<size_t>(ini_size.value_or(0));
  ImGui::LoadIniSettingsFromMemory(ini_data.c_str(), ini_size_v);
}

void LogToClipboard(sol::optional<int> auto_open_depth) {
  int auto_open_depth_v = auto_open_depth.value_or(-1);
  ImGui::LogToClipboard(auto_open_depth_v);
}

void NewFrame() {
  ImGui::NewFrame();
}

void OpenPopupOnItemClick(sol::optional<std::string> str_id, sol::optional<ImGuiPopupFlags> popup_flags) {
  std::string str_id_v = str_id.value_or(std::string());
  ImGuiPopupFlags popup_flags_v = static_cast<ImGuiPopupFlags>(popup_flags.value_or(0));
  ImGui::OpenPopupOnItemClick(str_id_v.c_str(), popup_flags_v);
}

void PopFont() {
  ImGui::PopFont();
}

void PopItemWidth() {
  ImGui::PopItemWidth();
}

void PopTabStop() {
  ImGui::PopTabStop();
}

void PushButtonRepeat(bool repeat) {
  ImGui::PushButtonRepeat(repeat);
}

void PushItemWidth(float item_width) {
  ImGui::PushItemWidth(item_width);
}

void PushTabStop(bool tab_stop) {
  ImGui::PushTabStop(tab_stop);
}

void ResetMouseDragDelta(sol::optional<ImGuiMouseButton> button) {
  ImGuiMouseButton button_v = static_cast<ImGuiMouseButton>(button.value_or(0));
  ImGui::ResetMouseDragDelta(button_v);
}

void Separator() {
  ImGui::Separator();
}

void SetColorEditOptions(ImGuiColorEditFlags flags) {
  ImGui::SetColorEditOptions(static_cast<ImGuiColorEditFlags>(flags));
}

void SetCursorPos(const ImVec2& local_pos) {
  ImGui::SetCursorPos(local_pos);
}

void SetCursorScreenPos(const ImVec2& pos) {
  ImGui::SetCursorScreenPos(pos);
}

void SetKeyboardFocusHere(sol::optional<int> offset) {
  int offset_v = offset.value_or(0);
  ImGui::SetKeyboardFocusHere(offset_v);
}

void SetNextFrameWantCaptureKeyboard(bool want_capture_keyboard) {
  ImGui::SetNextFrameWantCaptureKeyboard(want_capture_keyboard);
}

void SetNextItemOpen(bool is_open, sol::optional<ImGuiCond> cond) {
  ImGuiCond cond_v = static_cast<ImGuiCond>(cond.value_or(0));
  ImGui::SetNextItemOpen(is_open, cond_v);
}

void SetNextItemWidth(float item_width) {
  ImGui::SetNextItemWidth(item_width);
}

void SetNextWindowContentSize(const ImVec2& size) {
  ImGui::SetNextWindowContentSize(size);
}

void SetNextWindowPos(const ImVec2& pos, sol::optional<ImGuiCond> cond, sol::optional<ImVec2> pivot) {
  ImGuiCond cond_v = static_cast<ImGuiCond>(cond.value_or(0));
  ImVec2 pivot_v = pivot.value_or(ImVec2(0, 0));
  ImGui::SetNextWindowPos(pos, cond_v, pivot_v);
}

void SetNextWindowViewport(ImGuiID viewport_id) {
  ImGui::SetNextWindowViewport(static_cast<ImGuiID>(viewport_id));
}

void SetScrollHereX(sol::optional<float> center_x_ratio) {
  float center_x_ratio_v = center_x_ratio.value_or(0.5f);
  ImGui::SetScrollHereX(center_x_ratio_v);
}

void SetScrollY(float scroll_y) {
  ImGui::SetScrollY(scroll_y);
}

bool Shortcut(ImGuiKeyChord key_chord, sol::optional<ImGuiInputFlags> flags) {
  ImGuiInputFlags flags_v = static_cast<ImGuiInputFlags>(flags.value_or(0));
  auto ret = ImGui::Shortcut(static_cast<ImGuiKeyChord>(key_chord), flags_v);
  return ret;
}

void ShowUserGuide() {
  ImGui::ShowUserGuide();
}

std::tuple<int, bool> SliderInt(const std::string& label, int v, int v_min, int v_max, sol::optional<std::string> format, sol::optional<ImGuiSliderFlags> flags) {
  int v_v = v;
  std::string format_v = format.value_or(std::string("%d"));
  ImGuiSliderFlags flags_v = static_cast<ImGuiSliderFlags>(flags.value_or(0));
  auto ret = ImGui::SliderInt(label.c_str(), &v_v, v_min, v_max, format_v.c_str(), flags_v);
  return std::make_tuple(v_v, ret);
}

bool TabItemButton(const std::string& label, sol::optional<ImGuiTabItemFlags> flags) {
  ImGuiTabItemFlags flags_v = static_cast<ImGuiTabItemFlags>(flags.value_or(0));
  auto ret = ImGui::TabItemButton(label.c_str(), flags_v);
  return ret;
}

ImGuiTableColumnFlags TableGetColumnFlags(sol::optional<int> column_n) {
  int column_n_v = column_n.value_or(-1);
  auto ret = ImGui::TableGetColumnFlags(column_n_v);
  return ret;
}

int TableGetHoveredColumn() {
  auto ret = ImGui::TableGetHoveredColumn();
  return ret;
}

void TableHeadersRow() {
  ImGui::TableHeadersRow();
}

void TableSetBgColor(ImGuiTableBgTarget target, ImU32 color, sol::optional<int> column_n) {
  int column_n_v = column_n.value_or(-1);
  ImGui::TableSetBgColor(static_cast<ImGuiTableBgTarget>(target), static_cast<ImU32>(color), column_n_v);
}

void TableSetupColumn(const std::string& label, sol::optional<ImGuiTableColumnFlags> flags, sol::optional<float> init_width_or_weight, sol::optional<ImGuiID> user_id) {
  ImGuiTableColumnFlags flags_v = static_cast<ImGuiTableColumnFlags>(flags.value_or(0));
  float init_width_or_weight_v = init_width_or_weight.value_or(0.0f);
  ImGuiID user_id_v = static_cast<ImGuiID>(user_id.value_or(0));
  ImGui::TableSetupColumn(label.c_str(), flags_v, init_width_or_weight_v, user_id_v);
}

bool TextLinkOpenURL(const std::string& label, sol::optional<std::string> url) {
  std::string url_v = url.value_or(std::string());
  auto ret = ImGui::TextLinkOpenURL(label.c_str(), url_v.c_str());
  return ret;
}

void TreePop() {
  ImGui::TreePop();
}

std::tuple<float, bool> VSliderFloat(const std::string& label, const ImVec2& size, float v, float v_min, float v_max, sol::optional<std::string> format, sol::optional<ImGuiSliderFlags> flags) {
  float v_v = v;
  std::string format_v = format.value_or(std::string("%.3f"));
  ImGuiSliderFlags flags_v = static_cast<ImGuiSliderFlags>(flags.value_or(0));
  auto ret = ImGui::VSliderFloat(label.c_str(), size, &v_v, v_min, v_max, format_v.c_str(), flags_v);
  return std::make_tuple(v_v, ret);
}

}  // namespace

void InitGenerated_2(sol::table& t) {
  t.set_function("BeginCombo", BeginCombo);
  t.set_function("BeginDragDropTarget", BeginDragDropTarget);
  t.set_function("BeginListBox", BeginListBox);
  t.set_function("BeginMenuBar", BeginMenuBar);
  t.set_function("BeginPopupContextVoid", BeginPopupContextVoid);
  t.set_function("BeginTable", BeginTable);
  t.set_function("Button", Button);
  t.set_function("Checkbox", Checkbox);
  t.set_function("ColorConvertFloat4ToU32", ColorConvertFloat4ToU32);
  t.set_function("ColorConvertU32ToFloat4", ColorConvertU32ToFloat4);
  t.set_function("DebugFlashStyleColor", DebugFlashStyleColor);
  t.set_function("DestroyPlatformWindows", DestroyPlatformWindows);
  t.set_function("DragInt", DragInt);
  t.set_function("End", End);
  t.set_function("EndDisabled", EndDisabled);
  t.set_function("EndFrame", EndFrame);
  t.set_function("EndMainMenuBar", EndMainMenuBar);
  t.set_function("EndPopup", EndPopup);
  t.set_function("EndTable", EndTable);
  t.set_function("GetColumnIndex", GetColumnIndex);
  t.set_function("GetColumnsCount", GetColumnsCount);
  t.set_function("GetCursorPos", GetCursorPos);
  t.set_function("GetCursorScreenPos", GetCursorScreenPos);
  t.set_function("GetFontTexUvWhitePixel", GetFontTexUvWhitePixel);
  t.set_function("GetFrameHeightWithSpacing", GetFrameHeightWithSpacing);
  t.set_function("GetItemRectMax", GetItemRectMax);
  t.set_function("GetKeyName", GetKeyName);
  t.set_function("GetMouseCursor", GetMouseCursor);
  t.set_function("GetMousePosOnOpeningCurrentPopup", GetMousePosOnOpeningCurrentPopup);
  t.set_function("GetScrollX", GetScrollX);
  t.set_function("GetTextLineHeight", GetTextLineHeight);
  t.set_function("GetTreeNodeToLabelSpacing", GetTreeNodeToLabelSpacing);
  t.set_function("GetWindowContentRegionMin", GetWindowContentRegionMin);
  t.set_function("GetWindowHeight", GetWindowHeight);
  t.set_function("GetWindowWidth", GetWindowWidth);
  t.set_function("InputFloat", InputFloat);
  t.set_function("IsAnyItemActive", IsAnyItemActive);
  t.set_function("IsAnyMouseDown", IsAnyMouseDown);
  t.set_function("IsItemClicked", IsItemClicked);
  t.set_function("IsItemEdited", IsItemEdited);
  t.set_function("IsItemToggledOpen", IsItemToggledOpen);
  t.set_function("IsKeyChordPressed", IsKeyChordPressed);
  t.set_function("IsKeyReleased", IsKeyReleased);
  t.set_function("IsMouseDown", IsMouseDown);
  t.set_function("IsMouseReleased", IsMouseReleased);
  t.set_function("IsWindowAppearing", IsWindowAppearing);
  t.set_function("IsWindowFocused", IsWindowFocused);
  t.set_function("LoadIniSettingsFromMemory", LoadIniSettingsFromMemory);
  t.set_function("LogToClipboard", LogToClipboard);
  t.set_function("NewFrame", NewFrame);
  t.set_function("OpenPopupOnItemClick", OpenPopupOnItemClick);
  t.set_function("PopFont", PopFont);
  t.set_function("PopItemWidth", PopItemWidth);
  t.set_function("PopTabStop", PopTabStop);
  t.set_function("PushButtonRepeat", PushButtonRepeat);
  t.set_function("PushItemWidth", PushItemWidth);
  t.set_function("PushTabStop", PushTabStop);
  t.set_function("ResetMouseDragDelta", ResetMouseDragDelta);
  t.set_function("Separator", Separator);
  t.set_function("SetColorEditOptions", SetColorEditOptions);
  t.set_function("SetCursorPos", SetCursorPos);
  t.set_function("SetCursorScreenPos", SetCursorScreenPos);
  t.set_function("SetKeyboardFocusHere", SetKeyboardFocusHere);
  t.set_function("SetNextFrameWantCaptureKeyboard", SetNextFrameWantCaptureKeyboard);
  t.set_function("SetNextItemOpen", SetNextItemOpen);
  t.set_function("SetNextItemWidth", SetNextItemWidth);
  t.set_function("SetNextWindowContentSize", SetNextWindowContentSize);
  t.set_function("SetNextWindowPos", SetNextWindowPos);
  t.set_function("SetNextWindowViewport", SetNextWindowViewport);
  t.set_function("SetScrollHereX", SetScrollHereX);
  t.set_function("SetScrollY", SetScrollY);
  t.set_function("Shortcut", Shortcut);
  t.set_function("ShowUserGuide", ShowUserGuide);
  t.set_function("SliderInt", SliderInt);
  t.set_function("TabItemButton", TabItemButton);
  t.set_function("TableGetColumnFlags", TableGetColumnFlags);
  t.set_function("TableGetHoveredColumn", TableGetHoveredColumn);
  t.set_function("TableHeadersRow", TableHeadersRow);
  t.set_function("TableSetBgColor", TableSetBgColor);
  t.set_function("TableSetupColumn", TableSetupColumn);
  t.set_function("TextLinkOpenURL", TextLinkOpenURL);
  t.set_function("TreePop", TreePop);
  t.set_function("VSliderFloat", VSliderFloat);
}
}  // namespace sol_ImGui
