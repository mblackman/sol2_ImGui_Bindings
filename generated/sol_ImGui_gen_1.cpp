// GENERATED FILE -- DO NOT EDIT BY HAND.
// Produced by codegen/generate.py from codegen/metadata/dcimgui.json.
// Regenerate with the `regen-bindings` CMake target; see CONTRIBUTING.md.

#include "sol_ImGui.h"

namespace sol_ImGui {
namespace {

bool ArrowButton(const std::string& str_id, ImGuiDir dir) {
  auto ret = ImGui::ArrowButton(str_id.c_str(), static_cast<ImGuiDir>(dir));
  return ret;
}

bool BeginDragDropSource(sol::optional<ImGuiDragDropFlags> flags) {
  ImGuiDragDropFlags flags_v = static_cast<ImGuiDragDropFlags>(flags.value_or(0));
  auto ret = ImGui::BeginDragDropSource(flags_v);
  return ret;
}

bool BeginItemTooltip() {
  auto ret = ImGui::BeginItemTooltip();
  return ret;
}

bool BeginMenu(const std::string& label, sol::optional<bool> enabled) {
  bool enabled_v = enabled.value_or(true);
  auto ret = ImGui::BeginMenu(label.c_str(), enabled_v);
  return ret;
}

bool BeginPopupContextItem(sol::optional<std::string> str_id, sol::optional<ImGuiPopupFlags> popup_flags) {
  std::string str_id_v = str_id.value_or(std::string());
  ImGuiPopupFlags popup_flags_v = static_cast<ImGuiPopupFlags>(popup_flags.value_or(0));
  auto ret = ImGui::BeginPopupContextItem(str_id_v.c_str(), popup_flags_v);
  return ret;
}

bool BeginTabBar(const std::string& str_id, sol::optional<ImGuiTabBarFlags> flags) {
  ImGuiTabBarFlags flags_v = static_cast<ImGuiTabBarFlags>(flags.value_or(0));
  auto ret = ImGui::BeginTabBar(str_id.c_str(), flags_v);
  return ret;
}

void Bullet() {
  ImGui::Bullet();
}

ImVec2 CalcTextSize(const std::string& text, sol::optional<std::string> text_end, sol::optional<bool> hide_text_after_double_hash, sol::optional<float> wrap_width) {
  std::string text_end_v = text_end.value_or(std::string());
  bool hide_text_after_double_hash_v = hide_text_after_double_hash.value_or(false);
  float wrap_width_v = wrap_width.value_or(-1.0f);
  auto ret = ImGui::CalcTextSize(text.c_str(), text_end_v.c_str(), hide_text_after_double_hash_v, wrap_width_v);
  return ret;
}

bool ColorButton(const std::string& desc_id, const ImVec4& col, sol::optional<ImGuiColorEditFlags> flags, sol::optional<ImVec2> size) {
  ImGuiColorEditFlags flags_v = static_cast<ImGuiColorEditFlags>(flags.value_or(0));
  ImVec2 size_v = size.value_or(ImVec2(0, 0));
  auto ret = ImGui::ColorButton(desc_id.c_str(), col, flags_v, size_v);
  return ret;
}

std::tuple<float, float, float> ColorConvertRGBtoHSV(float r, float g, float b, float out_h, float out_s, float out_v) {
  float out_h_v = out_h;
  float out_s_v = out_s;
  float out_v_v = out_v;
  ImGui::ColorConvertRGBtoHSV(r, g, b, out_h_v, out_s_v, out_v_v);
  return std::make_tuple(out_h_v, out_s_v, out_v_v);
}

bool DebugCheckVersionAndDataLayout(const std::string& version_str, size_t sz_io, size_t sz_style, size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx) {
  auto ret = ImGui::DebugCheckVersionAndDataLayout(version_str.c_str(), static_cast<size_t>(sz_io), static_cast<size_t>(sz_style), static_cast<size_t>(sz_vec2), static_cast<size_t>(sz_vec4), static_cast<size_t>(sz_drawvert), static_cast<size_t>(sz_drawidx));
  return ret;
}

void DebugTextEncoding(const std::string& text) {
  ImGui::DebugTextEncoding(text.c_str());
}

std::tuple<float, float, bool> DragFloatRange2(const std::string& label, float v_current_min, float v_current_max, sol::optional<float> v_speed, sol::optional<float> v_min, sol::optional<float> v_max, sol::optional<std::string> format, sol::optional<std::string> format_max, sol::optional<ImGuiSliderFlags> flags) {
  float v_current_min_v = v_current_min;
  float v_current_max_v = v_current_max;
  float v_speed_v = v_speed.value_or(1.0f);
  float v_min_v = v_min.value_or(0.0f);
  float v_max_v = v_max.value_or(0.0f);
  std::string format_v = format.value_or(std::string("%.3f"));
  std::string format_max_v = format_max.value_or(std::string());
  ImGuiSliderFlags flags_v = static_cast<ImGuiSliderFlags>(flags.value_or(0));
  auto ret = ImGui::DragFloatRange2(label.c_str(), &v_current_min_v, &v_current_max_v, v_speed_v, v_min_v, v_max_v, format_v.c_str(), format_max_v.c_str(), flags_v);
  return std::make_tuple(v_current_min_v, v_current_max_v, ret);
}

void Dummy(const ImVec2& size) {
  ImGui::Dummy(size);
}

void EndCombo() {
  ImGui::EndCombo();
}

void EndDragDropTarget() {
  ImGui::EndDragDropTarget();
}

void EndListBox() {
  ImGui::EndListBox();
}

void EndMenuBar() {
  ImGui::EndMenuBar();
}

void EndTabItem() {
  ImGui::EndTabItem();
}

std::string GetClipboardText() {
  const char* ret = ImGui::GetClipboardText();
  return std::string(ret ? ret : "");
}

float GetColumnWidth(sol::optional<int> column_index) {
  int column_index_v = column_index.value_or(-1);
  auto ret = ImGui::GetColumnWidth(column_index_v);
  return ret;
}

ImVec2 GetContentRegionMax() {
  auto ret = ImGui::GetContentRegionMax();
  return ret;
}

float GetCursorPosY() {
  auto ret = ImGui::GetCursorPosY();
  return ret;
}

float GetFontSize() {
  auto ret = ImGui::GetFontSize();
  return ret;
}

float GetFrameHeight() {
  auto ret = ImGui::GetFrameHeight();
  return ret;
}

ImGuiID GetItemID() {
  auto ret = ImGui::GetItemID();
  return ret;
}

ImVec2 GetItemRectSize() {
  auto ret = ImGui::GetItemRectSize();
  return ret;
}

int GetMouseClickedCount(ImGuiMouseButton button) {
  auto ret = ImGui::GetMouseClickedCount(static_cast<ImGuiMouseButton>(button));
  return ret;
}

ImVec2 GetMousePos() {
  auto ret = ImGui::GetMousePos();
  return ret;
}

float GetScrollMaxY() {
  auto ret = ImGui::GetScrollMaxY();
  return ret;
}

std::string GetStyleColorName(ImGuiCol idx) {
  const char* ret = ImGui::GetStyleColorName(static_cast<ImGuiCol>(idx));
  return std::string(ret ? ret : "");
}

double GetTime() {
  auto ret = ImGui::GetTime();
  return ret;
}

ImVec2 GetWindowContentRegionMax() {
  auto ret = ImGui::GetWindowContentRegionMax();
  return ret;
}

float GetWindowDpiScale() {
  auto ret = ImGui::GetWindowDpiScale();
  return ret;
}

ImVec2 GetWindowSize() {
  auto ret = ImGui::GetWindowSize();
  return ret;
}

std::tuple<double, bool> InputDouble(const std::string& label, double v, sol::optional<double> step, sol::optional<double> step_fast, sol::optional<std::string> format, sol::optional<ImGuiInputTextFlags> flags) {
  double v_v = v;
  double step_v = step.value_or(0.0);
  double step_fast_v = step_fast.value_or(0.0);
  std::string format_v = format.value_or(std::string("%.6f"));
  ImGuiInputTextFlags flags_v = static_cast<ImGuiInputTextFlags>(flags.value_or(0));
  auto ret = ImGui::InputDouble(label.c_str(), &v_v, step_v, step_fast_v, format_v.c_str(), flags_v);
  return std::make_tuple(v_v, ret);
}

bool InvisibleButton(const std::string& str_id, const ImVec2& size, sol::optional<ImGuiButtonFlags> flags) {
  ImGuiButtonFlags flags_v = static_cast<ImGuiButtonFlags>(flags.value_or(0));
  auto ret = ImGui::InvisibleButton(str_id.c_str(), size, flags_v);
  return ret;
}

bool IsAnyItemHovered() {
  auto ret = ImGui::IsAnyItemHovered();
  return ret;
}

bool IsItemActive() {
  auto ret = ImGui::IsItemActive();
  return ret;
}

bool IsItemDeactivatedAfterEdit() {
  auto ret = ImGui::IsItemDeactivatedAfterEdit();
  return ret;
}

bool IsItemHovered(sol::optional<ImGuiHoveredFlags> flags) {
  ImGuiHoveredFlags flags_v = static_cast<ImGuiHoveredFlags>(flags.value_or(0));
  auto ret = ImGui::IsItemHovered(flags_v);
  return ret;
}

bool IsItemVisible() {
  auto ret = ImGui::IsItemVisible();
  return ret;
}

bool IsKeyPressed(ImGuiKey key, sol::optional<bool> repeat) {
  bool repeat_v = repeat.value_or(true);
  auto ret = ImGui::IsKeyPressed(static_cast<ImGuiKey>(key), repeat_v);
  return ret;
}

bool IsMouseDoubleClicked(ImGuiMouseButton button) {
  auto ret = ImGui::IsMouseDoubleClicked(static_cast<ImGuiMouseButton>(button));
  return ret;
}

bool IsMouseHoveringRect(const ImVec2& r_min, const ImVec2& r_max, sol::optional<bool> clip) {
  bool clip_v = clip.value_or(true);
  auto ret = ImGui::IsMouseHoveringRect(r_min, r_max, clip_v);
  return ret;
}

bool IsPopupOpen(const std::string& str_id, sol::optional<ImGuiPopupFlags> flags) {
  ImGuiPopupFlags flags_v = static_cast<ImGuiPopupFlags>(flags.value_or(0));
  auto ret = ImGui::IsPopupOpen(str_id.c_str(), flags_v);
  return ret;
}

bool IsWindowDocked() {
  auto ret = ImGui::IsWindowDocked();
  return ret;
}

void LoadIniSettingsFromDisk(const std::string& ini_filename) {
  ImGui::LoadIniSettingsFromDisk(ini_filename.c_str());
}

void LogFinish() {
  ImGui::LogFinish();
}

void LogToTTY(sol::optional<int> auto_open_depth) {
  int auto_open_depth_v = auto_open_depth.value_or(-1);
  ImGui::LogToTTY(auto_open_depth_v);
}

void NextColumn() {
  ImGui::NextColumn();
}

void PopClipRect() {
  ImGui::PopClipRect();
}

void PopItemFlag() {
  ImGui::PopItemFlag();
}

void PopStyleVar(sol::optional<int> count) {
  int count_v = count.value_or(1);
  ImGui::PopStyleVar(count_v);
}

void ProgressBar(float fraction, sol::optional<ImVec2> size_arg, sol::optional<std::string> overlay) {
  ImVec2 size_arg_v = size_arg.value_or(ImVec2(-FLT_MIN, 0));
  std::string overlay_v = overlay.value_or(std::string());
  ImGui::ProgressBar(fraction, size_arg_v, overlay_v.c_str());
}

void PushItemFlag(ImGuiItemFlags option, bool enabled) {
  ImGui::PushItemFlag(static_cast<ImGuiItemFlags>(option), enabled);
}

void PushStyleVarY(ImGuiStyleVar idx, float val_y) {
  ImGui::PushStyleVarY(static_cast<ImGuiStyleVar>(idx), val_y);
}

void Render() {
  ImGui::Render();
}

void SaveIniSettingsToDisk(const std::string& ini_filename) {
  ImGui::SaveIniSettingsToDisk(ini_filename.c_str());
}

void SetClipboardText(const std::string& text) {
  ImGui::SetClipboardText(text.c_str());
}

void SetColumnWidth(int column_index, float width) {
  ImGui::SetColumnWidth(column_index, width);
}

void SetCursorPosY(float local_y) {
  ImGui::SetCursorPosY(local_y);
}

void SetItemKeyOwner(ImGuiKey key) {
  ImGui::SetItemKeyOwner(static_cast<ImGuiKey>(key));
}

void SetNavCursorVisible(bool visible) {
  ImGui::SetNavCursorVisible(visible);
}

void SetNextItemAllowOverlap() {
  ImGui::SetNextItemAllowOverlap();
}

void SetNextItemStorageID(ImGuiID storage_id) {
  ImGui::SetNextItemStorageID(static_cast<ImGuiID>(storage_id));
}

void SetNextWindowCollapsed(bool collapsed, sol::optional<ImGuiCond> cond) {
  ImGuiCond cond_v = static_cast<ImGuiCond>(cond.value_or(0));
  ImGui::SetNextWindowCollapsed(collapsed, cond_v);
}

void SetNextWindowFocus() {
  ImGui::SetNextWindowFocus();
}

void SetNextWindowSize(const ImVec2& size, sol::optional<ImGuiCond> cond) {
  ImGuiCond cond_v = static_cast<ImGuiCond>(cond.value_or(0));
  ImGui::SetNextWindowSize(size, cond_v);
}

void SetScrollFromPosY(float local_y, sol::optional<float> center_y_ratio) {
  float center_y_ratio_v = center_y_ratio.value_or(0.5f);
  ImGui::SetScrollFromPosY(local_y, center_y_ratio_v);
}

void SetScrollX(float scroll_x) {
  ImGui::SetScrollX(scroll_x);
}

void SetWindowFontScale(float scale) {
  ImGui::SetWindowFontScale(scale);
}

bool ShowStyleSelector(const std::string& label) {
  auto ret = ImGui::ShowStyleSelector(label.c_str());
  return ret;
}

std::tuple<float, bool> SliderFloat(const std::string& label, float v, float v_min, float v_max, sol::optional<std::string> format, sol::optional<ImGuiSliderFlags> flags) {
  float v_v = v;
  std::string format_v = format.value_or(std::string("%.3f"));
  ImGuiSliderFlags flags_v = static_cast<ImGuiSliderFlags>(flags.value_or(0));
  auto ret = ImGui::SliderFloat(label.c_str(), &v_v, v_min, v_max, format_v.c_str(), flags_v);
  return std::make_tuple(v_v, ret);
}

void Spacing() {
  ImGui::Spacing();
}

int TableGetColumnCount() {
  auto ret = ImGui::TableGetColumnCount();
  return ret;
}

std::string TableGetColumnName(sol::optional<int> column_n) {
  int column_n_v = column_n.value_or(-1);
  const char* ret = ImGui::TableGetColumnName(column_n_v);
  return std::string(ret ? ret : "");
}

void TableHeader(const std::string& label) {
  ImGui::TableHeader(label.c_str());
}

void TableNextRow(sol::optional<ImGuiTableRowFlags> row_flags, sol::optional<float> min_row_height) {
  ImGuiTableRowFlags row_flags_v = static_cast<ImGuiTableRowFlags>(row_flags.value_or(0));
  float min_row_height_v = min_row_height.value_or(0.0f);
  ImGui::TableNextRow(row_flags_v, min_row_height_v);
}

bool TableSetColumnIndex(int column_n) {
  auto ret = ImGui::TableSetColumnIndex(column_n);
  return ret;
}

bool TextLink(const std::string& label) {
  auto ret = ImGui::TextLink(label.c_str());
  return ret;
}

bool TreeNodeGetOpen(ImGuiID storage_id) {
  auto ret = ImGui::TreeNodeGetOpen(static_cast<ImGuiID>(storage_id));
  return ret;
}

void UpdatePlatformWindows() {
  ImGui::UpdatePlatformWindows();
}

}  // namespace

void InitGenerated_1(sol::table& t) {
  t.set_function("ArrowButton", ArrowButton);
  t.set_function("BeginDragDropSource", BeginDragDropSource);
  t.set_function("BeginItemTooltip", BeginItemTooltip);
  t.set_function("BeginMenu", BeginMenu);
  t.set_function("BeginPopupContextItem", BeginPopupContextItem);
  t.set_function("BeginTabBar", BeginTabBar);
  t.set_function("Bullet", Bullet);
  t.set_function("CalcTextSize", CalcTextSize);
  t.set_function("ColorButton", ColorButton);
  t.set_function("ColorConvertRGBtoHSV", ColorConvertRGBtoHSV);
  t.set_function("DebugCheckVersionAndDataLayout", DebugCheckVersionAndDataLayout);
  t.set_function("DebugTextEncoding", DebugTextEncoding);
  t.set_function("DragFloatRange2", DragFloatRange2);
  t.set_function("Dummy", Dummy);
  t.set_function("EndCombo", EndCombo);
  t.set_function("EndDragDropTarget", EndDragDropTarget);
  t.set_function("EndListBox", EndListBox);
  t.set_function("EndMenuBar", EndMenuBar);
  t.set_function("EndTabItem", EndTabItem);
  t.set_function("GetClipboardText", GetClipboardText);
  t.set_function("GetColumnWidth", GetColumnWidth);
  t.set_function("GetContentRegionMax", GetContentRegionMax);
  t.set_function("GetCursorPosY", GetCursorPosY);
  t.set_function("GetFontSize", GetFontSize);
  t.set_function("GetFrameHeight", GetFrameHeight);
  t.set_function("GetItemID", GetItemID);
  t.set_function("GetItemRectSize", GetItemRectSize);
  t.set_function("GetMouseClickedCount", GetMouseClickedCount);
  t.set_function("GetMousePos", GetMousePos);
  t.set_function("GetScrollMaxY", GetScrollMaxY);
  t.set_function("GetStyleColorName", GetStyleColorName);
  t.set_function("GetTime", GetTime);
  t.set_function("GetWindowContentRegionMax", GetWindowContentRegionMax);
  t.set_function("GetWindowDpiScale", GetWindowDpiScale);
  t.set_function("GetWindowSize", GetWindowSize);
  t.set_function("InputDouble", InputDouble);
  t.set_function("InvisibleButton", InvisibleButton);
  t.set_function("IsAnyItemHovered", IsAnyItemHovered);
  t.set_function("IsItemActive", IsItemActive);
  t.set_function("IsItemDeactivatedAfterEdit", IsItemDeactivatedAfterEdit);
  t.set_function("IsItemHovered", IsItemHovered);
  t.set_function("IsItemVisible", IsItemVisible);
  t.set_function("IsKeyPressed", IsKeyPressed);
  t.set_function("IsMouseDoubleClicked", IsMouseDoubleClicked);
  t.set_function("IsMouseHoveringRect", IsMouseHoveringRect);
  t.set_function("IsPopupOpen", IsPopupOpen);
  t.set_function("IsWindowDocked", IsWindowDocked);
  t.set_function("LoadIniSettingsFromDisk", LoadIniSettingsFromDisk);
  t.set_function("LogFinish", LogFinish);
  t.set_function("LogToTTY", LogToTTY);
  t.set_function("NextColumn", NextColumn);
  t.set_function("PopClipRect", PopClipRect);
  t.set_function("PopItemFlag", PopItemFlag);
  t.set_function("PopStyleVar", PopStyleVar);
  t.set_function("ProgressBar", ProgressBar);
  t.set_function("PushItemFlag", PushItemFlag);
  t.set_function("PushStyleVarY", PushStyleVarY);
  t.set_function("Render", Render);
  t.set_function("SaveIniSettingsToDisk", SaveIniSettingsToDisk);
  t.set_function("SetClipboardText", SetClipboardText);
  t.set_function("SetColumnWidth", SetColumnWidth);
  t.set_function("SetCursorPosY", SetCursorPosY);
  t.set_function("SetItemKeyOwner", SetItemKeyOwner);
  t.set_function("SetNavCursorVisible", SetNavCursorVisible);
  t.set_function("SetNextItemAllowOverlap", SetNextItemAllowOverlap);
  t.set_function("SetNextItemStorageID", SetNextItemStorageID);
  t.set_function("SetNextWindowCollapsed", SetNextWindowCollapsed);
  t.set_function("SetNextWindowFocus", SetNextWindowFocus);
  t.set_function("SetNextWindowSize", SetNextWindowSize);
  t.set_function("SetScrollFromPosY", SetScrollFromPosY);
  t.set_function("SetScrollX", SetScrollX);
  t.set_function("SetWindowFontScale", SetWindowFontScale);
  t.set_function("ShowStyleSelector", ShowStyleSelector);
  t.set_function("SliderFloat", SliderFloat);
  t.set_function("Spacing", Spacing);
  t.set_function("TableGetColumnCount", TableGetColumnCount);
  t.set_function("TableGetColumnName", TableGetColumnName);
  t.set_function("TableHeader", TableHeader);
  t.set_function("TableNextRow", TableNextRow);
  t.set_function("TableSetColumnIndex", TableSetColumnIndex);
  t.set_function("TextLink", TextLink);
  t.set_function("TreeNodeGetOpen", TreeNodeGetOpen);
  t.set_function("UpdatePlatformWindows", UpdatePlatformWindows);
}
}  // namespace sol_ImGui
