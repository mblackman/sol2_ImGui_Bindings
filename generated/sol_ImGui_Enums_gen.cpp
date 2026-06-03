// GENERATED FILE -- DO NOT EDIT BY HAND.
// Produced by codegen/generate.py from codegen/metadata/dcimgui.json.
// Regenerate with the `regen-bindings` CMake target; see CONTRIBUTING.md.

#include "sol_ImGui.h"

namespace sol_ImGui {
namespace {

struct EnumEntry { const char* name; long long value; };

void RegisterEnum(sol::state& lua, const char* enum_name,
                  const EnumEntry* entries, std::size_t count) {
  sol::table t = lua.create_named_table(enum_name);
  for (std::size_t i = 0; i < count; ++i) t[entries[i].name] = entries[i].value;
}

}  // namespace

static void InitEnum_ImDrawFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImDrawFlags_None)},
      {"Closed", static_cast<long long>(ImDrawFlags_Closed)},
      {"RoundCornersTopLeft", static_cast<long long>(ImDrawFlags_RoundCornersTopLeft)},
      {"RoundCornersTopRight", static_cast<long long>(ImDrawFlags_RoundCornersTopRight)},
      {"RoundCornersBottomLeft", static_cast<long long>(ImDrawFlags_RoundCornersBottomLeft)},
      {"RoundCornersBottomRight", static_cast<long long>(ImDrawFlags_RoundCornersBottomRight)},
      {"RoundCornersNone", static_cast<long long>(ImDrawFlags_RoundCornersNone)},
      {"RoundCornersTop", static_cast<long long>(ImDrawFlags_RoundCornersTop)},
      {"RoundCornersBottom", static_cast<long long>(ImDrawFlags_RoundCornersBottom)},
      {"RoundCornersLeft", static_cast<long long>(ImDrawFlags_RoundCornersLeft)},
      {"RoundCornersRight", static_cast<long long>(ImDrawFlags_RoundCornersRight)},
      {"RoundCornersAll", static_cast<long long>(ImDrawFlags_RoundCornersAll)}};
  RegisterEnum(lua, "ImDrawFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImDrawListFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImDrawListFlags_None)},
      {"AntiAliasedLines", static_cast<long long>(ImDrawListFlags_AntiAliasedLines)},
      {"AntiAliasedLinesUseTex", static_cast<long long>(ImDrawListFlags_AntiAliasedLinesUseTex)},
      {"AntiAliasedFill", static_cast<long long>(ImDrawListFlags_AntiAliasedFill)},
      {"AllowVtxOffset", static_cast<long long>(ImDrawListFlags_AllowVtxOffset)}};
  RegisterEnum(lua, "ImDrawListFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImFontAtlasFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImFontAtlasFlags_None)},
      {"NoPowerOfTwoHeight", static_cast<long long>(ImFontAtlasFlags_NoPowerOfTwoHeight)},
      {"NoMouseCursors", static_cast<long long>(ImFontAtlasFlags_NoMouseCursors)},
      {"NoBakedLines", static_cast<long long>(ImFontAtlasFlags_NoBakedLines)}};
  RegisterEnum(lua, "ImFontAtlasFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImFontFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImFontFlags_None)},
      {"NoLoadError", static_cast<long long>(ImFontFlags_NoLoadError)},
      {"NoLoadGlyphs", static_cast<long long>(ImFontFlags_NoLoadGlyphs)},
      {"LockBakedSizes", static_cast<long long>(ImFontFlags_LockBakedSizes)}};
  RegisterEnum(lua, "ImFontFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiBackendFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiBackendFlags_None)},
      {"HasGamepad", static_cast<long long>(ImGuiBackendFlags_HasGamepad)},
      {"HasMouseCursors", static_cast<long long>(ImGuiBackendFlags_HasMouseCursors)},
      {"HasSetMousePos", static_cast<long long>(ImGuiBackendFlags_HasSetMousePos)},
      {"RendererHasVtxOffset", static_cast<long long>(ImGuiBackendFlags_RendererHasVtxOffset)},
      {"RendererHasTextures", static_cast<long long>(ImGuiBackendFlags_RendererHasTextures)},
      {"RendererHasViewports", static_cast<long long>(ImGuiBackendFlags_RendererHasViewports)},
      {"PlatformHasViewports", static_cast<long long>(ImGuiBackendFlags_PlatformHasViewports)},
      {"HasMouseHoveredViewport", static_cast<long long>(ImGuiBackendFlags_HasMouseHoveredViewport)},
      {"HasParentViewport", static_cast<long long>(ImGuiBackendFlags_HasParentViewport)}};
  RegisterEnum(lua, "ImGuiBackendFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiButtonFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiButtonFlags_None)},
      {"MouseButtonLeft", static_cast<long long>(ImGuiButtonFlags_MouseButtonLeft)},
      {"MouseButtonRight", static_cast<long long>(ImGuiButtonFlags_MouseButtonRight)},
      {"MouseButtonMiddle", static_cast<long long>(ImGuiButtonFlags_MouseButtonMiddle)},
      {"EnableNav", static_cast<long long>(ImGuiButtonFlags_EnableNav)},
      {"AllowOverlap", static_cast<long long>(ImGuiButtonFlags_AllowOverlap)}};
  RegisterEnum(lua, "ImGuiButtonFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiChildFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiChildFlags_None)},
      {"Borders", static_cast<long long>(ImGuiChildFlags_Borders)},
      {"AlwaysUseWindowPadding", static_cast<long long>(ImGuiChildFlags_AlwaysUseWindowPadding)},
      {"ResizeX", static_cast<long long>(ImGuiChildFlags_ResizeX)},
      {"ResizeY", static_cast<long long>(ImGuiChildFlags_ResizeY)},
      {"AutoResizeX", static_cast<long long>(ImGuiChildFlags_AutoResizeX)},
      {"AutoResizeY", static_cast<long long>(ImGuiChildFlags_AutoResizeY)},
      {"AlwaysAutoResize", static_cast<long long>(ImGuiChildFlags_AlwaysAutoResize)},
      {"FrameStyle", static_cast<long long>(ImGuiChildFlags_FrameStyle)},
      {"NavFlattened", static_cast<long long>(ImGuiChildFlags_NavFlattened)}};
  RegisterEnum(lua, "ImGuiChildFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiCol(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"Text", static_cast<long long>(ImGuiCol_Text)},
      {"TextDisabled", static_cast<long long>(ImGuiCol_TextDisabled)},
      {"WindowBg", static_cast<long long>(ImGuiCol_WindowBg)},
      {"ChildBg", static_cast<long long>(ImGuiCol_ChildBg)},
      {"PopupBg", static_cast<long long>(ImGuiCol_PopupBg)},
      {"Border", static_cast<long long>(ImGuiCol_Border)},
      {"BorderShadow", static_cast<long long>(ImGuiCol_BorderShadow)},
      {"FrameBg", static_cast<long long>(ImGuiCol_FrameBg)},
      {"FrameBgHovered", static_cast<long long>(ImGuiCol_FrameBgHovered)},
      {"FrameBgActive", static_cast<long long>(ImGuiCol_FrameBgActive)},
      {"TitleBg", static_cast<long long>(ImGuiCol_TitleBg)},
      {"TitleBgActive", static_cast<long long>(ImGuiCol_TitleBgActive)},
      {"TitleBgCollapsed", static_cast<long long>(ImGuiCol_TitleBgCollapsed)},
      {"MenuBarBg", static_cast<long long>(ImGuiCol_MenuBarBg)},
      {"ScrollbarBg", static_cast<long long>(ImGuiCol_ScrollbarBg)},
      {"ScrollbarGrab", static_cast<long long>(ImGuiCol_ScrollbarGrab)},
      {"ScrollbarGrabHovered", static_cast<long long>(ImGuiCol_ScrollbarGrabHovered)},
      {"ScrollbarGrabActive", static_cast<long long>(ImGuiCol_ScrollbarGrabActive)},
      {"CheckMark", static_cast<long long>(ImGuiCol_CheckMark)},
      {"SliderGrab", static_cast<long long>(ImGuiCol_SliderGrab)},
      {"SliderGrabActive", static_cast<long long>(ImGuiCol_SliderGrabActive)},
      {"Button", static_cast<long long>(ImGuiCol_Button)},
      {"ButtonHovered", static_cast<long long>(ImGuiCol_ButtonHovered)},
      {"ButtonActive", static_cast<long long>(ImGuiCol_ButtonActive)},
      {"Header", static_cast<long long>(ImGuiCol_Header)},
      {"HeaderHovered", static_cast<long long>(ImGuiCol_HeaderHovered)},
      {"HeaderActive", static_cast<long long>(ImGuiCol_HeaderActive)},
      {"Separator", static_cast<long long>(ImGuiCol_Separator)},
      {"SeparatorHovered", static_cast<long long>(ImGuiCol_SeparatorHovered)},
      {"SeparatorActive", static_cast<long long>(ImGuiCol_SeparatorActive)},
      {"ResizeGrip", static_cast<long long>(ImGuiCol_ResizeGrip)},
      {"ResizeGripHovered", static_cast<long long>(ImGuiCol_ResizeGripHovered)},
      {"ResizeGripActive", static_cast<long long>(ImGuiCol_ResizeGripActive)},
      {"InputTextCursor", static_cast<long long>(ImGuiCol_InputTextCursor)},
      {"TabHovered", static_cast<long long>(ImGuiCol_TabHovered)},
      {"Tab", static_cast<long long>(ImGuiCol_Tab)},
      {"TabSelected", static_cast<long long>(ImGuiCol_TabSelected)},
      {"TabSelectedOverline", static_cast<long long>(ImGuiCol_TabSelectedOverline)},
      {"TabDimmed", static_cast<long long>(ImGuiCol_TabDimmed)},
      {"TabDimmedSelected", static_cast<long long>(ImGuiCol_TabDimmedSelected)},
      {"TabDimmedSelectedOverline", static_cast<long long>(ImGuiCol_TabDimmedSelectedOverline)},
      {"DockingPreview", static_cast<long long>(ImGuiCol_DockingPreview)},
      {"DockingEmptyBg", static_cast<long long>(ImGuiCol_DockingEmptyBg)},
      {"PlotLines", static_cast<long long>(ImGuiCol_PlotLines)},
      {"PlotLinesHovered", static_cast<long long>(ImGuiCol_PlotLinesHovered)},
      {"PlotHistogram", static_cast<long long>(ImGuiCol_PlotHistogram)},
      {"PlotHistogramHovered", static_cast<long long>(ImGuiCol_PlotHistogramHovered)},
      {"TableHeaderBg", static_cast<long long>(ImGuiCol_TableHeaderBg)},
      {"TableBorderStrong", static_cast<long long>(ImGuiCol_TableBorderStrong)},
      {"TableBorderLight", static_cast<long long>(ImGuiCol_TableBorderLight)},
      {"TableRowBg", static_cast<long long>(ImGuiCol_TableRowBg)},
      {"TableRowBgAlt", static_cast<long long>(ImGuiCol_TableRowBgAlt)},
      {"TextLink", static_cast<long long>(ImGuiCol_TextLink)},
      {"TextSelectedBg", static_cast<long long>(ImGuiCol_TextSelectedBg)},
      {"TreeLines", static_cast<long long>(ImGuiCol_TreeLines)},
      {"DragDropTarget", static_cast<long long>(ImGuiCol_DragDropTarget)},
      {"DragDropTargetBg", static_cast<long long>(ImGuiCol_DragDropTargetBg)},
      {"UnsavedMarker", static_cast<long long>(ImGuiCol_UnsavedMarker)},
      {"NavCursor", static_cast<long long>(ImGuiCol_NavCursor)},
      {"NavWindowingHighlight", static_cast<long long>(ImGuiCol_NavWindowingHighlight)},
      {"NavWindowingDimBg", static_cast<long long>(ImGuiCol_NavWindowingDimBg)},
      {"ModalWindowDimBg", static_cast<long long>(ImGuiCol_ModalWindowDimBg)},
      {"COUNT", static_cast<long long>(ImGuiCol_COUNT)},
      {"TabActive", static_cast<long long>(ImGuiCol_TabActive)},
      {"TabUnfocused", static_cast<long long>(ImGuiCol_TabUnfocused)},
      {"TabUnfocusedActive", static_cast<long long>(ImGuiCol_TabUnfocusedActive)},
      {"NavHighlight", static_cast<long long>(ImGuiCol_NavHighlight)}};
  RegisterEnum(lua, "ImGuiCol", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiColorEditFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiColorEditFlags_None)},
      {"NoAlpha", static_cast<long long>(ImGuiColorEditFlags_NoAlpha)},
      {"NoPicker", static_cast<long long>(ImGuiColorEditFlags_NoPicker)},
      {"NoOptions", static_cast<long long>(ImGuiColorEditFlags_NoOptions)},
      {"NoSmallPreview", static_cast<long long>(ImGuiColorEditFlags_NoSmallPreview)},
      {"NoInputs", static_cast<long long>(ImGuiColorEditFlags_NoInputs)},
      {"NoTooltip", static_cast<long long>(ImGuiColorEditFlags_NoTooltip)},
      {"NoLabel", static_cast<long long>(ImGuiColorEditFlags_NoLabel)},
      {"NoSidePreview", static_cast<long long>(ImGuiColorEditFlags_NoSidePreview)},
      {"NoDragDrop", static_cast<long long>(ImGuiColorEditFlags_NoDragDrop)},
      {"NoBorder", static_cast<long long>(ImGuiColorEditFlags_NoBorder)},
      {"NoColorMarkers", static_cast<long long>(ImGuiColorEditFlags_NoColorMarkers)},
      {"AlphaOpaque", static_cast<long long>(ImGuiColorEditFlags_AlphaOpaque)},
      {"AlphaNoBg", static_cast<long long>(ImGuiColorEditFlags_AlphaNoBg)},
      {"AlphaPreviewHalf", static_cast<long long>(ImGuiColorEditFlags_AlphaPreviewHalf)},
      {"AlphaBar", static_cast<long long>(ImGuiColorEditFlags_AlphaBar)},
      {"HDR", static_cast<long long>(ImGuiColorEditFlags_HDR)},
      {"DisplayRGB", static_cast<long long>(ImGuiColorEditFlags_DisplayRGB)},
      {"DisplayHSV", static_cast<long long>(ImGuiColorEditFlags_DisplayHSV)},
      {"DisplayHex", static_cast<long long>(ImGuiColorEditFlags_DisplayHex)},
      {"Uint8", static_cast<long long>(ImGuiColorEditFlags_Uint8)},
      {"Float", static_cast<long long>(ImGuiColorEditFlags_Float)},
      {"PickerHueBar", static_cast<long long>(ImGuiColorEditFlags_PickerHueBar)},
      {"PickerHueWheel", static_cast<long long>(ImGuiColorEditFlags_PickerHueWheel)},
      {"InputRGB", static_cast<long long>(ImGuiColorEditFlags_InputRGB)},
      {"InputHSV", static_cast<long long>(ImGuiColorEditFlags_InputHSV)},
      {"AlphaPreview", static_cast<long long>(ImGuiColorEditFlags_AlphaPreview)}};
  RegisterEnum(lua, "ImGuiColorEditFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiComboFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiComboFlags_None)},
      {"PopupAlignLeft", static_cast<long long>(ImGuiComboFlags_PopupAlignLeft)},
      {"HeightSmall", static_cast<long long>(ImGuiComboFlags_HeightSmall)},
      {"HeightRegular", static_cast<long long>(ImGuiComboFlags_HeightRegular)},
      {"HeightLarge", static_cast<long long>(ImGuiComboFlags_HeightLarge)},
      {"HeightLargest", static_cast<long long>(ImGuiComboFlags_HeightLargest)},
      {"NoArrowButton", static_cast<long long>(ImGuiComboFlags_NoArrowButton)},
      {"NoPreview", static_cast<long long>(ImGuiComboFlags_NoPreview)},
      {"WidthFitPreview", static_cast<long long>(ImGuiComboFlags_WidthFitPreview)}};
  RegisterEnum(lua, "ImGuiComboFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiCond(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiCond_None)},
      {"Always", static_cast<long long>(ImGuiCond_Always)},
      {"Once", static_cast<long long>(ImGuiCond_Once)},
      {"FirstUseEver", static_cast<long long>(ImGuiCond_FirstUseEver)},
      {"Appearing", static_cast<long long>(ImGuiCond_Appearing)}};
  RegisterEnum(lua, "ImGuiCond", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiConfigFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiConfigFlags_None)},
      {"NavEnableKeyboard", static_cast<long long>(ImGuiConfigFlags_NavEnableKeyboard)},
      {"NavEnableGamepad", static_cast<long long>(ImGuiConfigFlags_NavEnableGamepad)},
      {"NoMouse", static_cast<long long>(ImGuiConfigFlags_NoMouse)},
      {"NoMouseCursorChange", static_cast<long long>(ImGuiConfigFlags_NoMouseCursorChange)},
      {"NoKeyboard", static_cast<long long>(ImGuiConfigFlags_NoKeyboard)},
      {"DockingEnable", static_cast<long long>(ImGuiConfigFlags_DockingEnable)},
      {"ViewportsEnable", static_cast<long long>(ImGuiConfigFlags_ViewportsEnable)},
      {"IsSRGB", static_cast<long long>(ImGuiConfigFlags_IsSRGB)},
      {"IsTouchScreen", static_cast<long long>(ImGuiConfigFlags_IsTouchScreen)},
      {"NavEnableSetMousePos", static_cast<long long>(ImGuiConfigFlags_NavEnableSetMousePos)},
      {"NavNoCaptureKeyboard", static_cast<long long>(ImGuiConfigFlags_NavNoCaptureKeyboard)},
      {"DpiEnableScaleFonts", static_cast<long long>(ImGuiConfigFlags_DpiEnableScaleFonts)},
      {"DpiEnableScaleViewports", static_cast<long long>(ImGuiConfigFlags_DpiEnableScaleViewports)}};
  RegisterEnum(lua, "ImGuiConfigFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiDataType(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"S8", static_cast<long long>(ImGuiDataType_S8)},
      {"U8", static_cast<long long>(ImGuiDataType_U8)},
      {"S16", static_cast<long long>(ImGuiDataType_S16)},
      {"U16", static_cast<long long>(ImGuiDataType_U16)},
      {"S32", static_cast<long long>(ImGuiDataType_S32)},
      {"U32", static_cast<long long>(ImGuiDataType_U32)},
      {"S64", static_cast<long long>(ImGuiDataType_S64)},
      {"U64", static_cast<long long>(ImGuiDataType_U64)},
      {"Float", static_cast<long long>(ImGuiDataType_Float)},
      {"Double", static_cast<long long>(ImGuiDataType_Double)},
      {"Bool", static_cast<long long>(ImGuiDataType_Bool)},
      {"String", static_cast<long long>(ImGuiDataType_String)},
      {"COUNT", static_cast<long long>(ImGuiDataType_COUNT)}};
  RegisterEnum(lua, "ImGuiDataType", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiDir(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_None", static_cast<long long>(ImGuiDir_None)},
      {"_Left", static_cast<long long>(ImGuiDir_Left)},
      {"_Right", static_cast<long long>(ImGuiDir_Right)},
      {"_Up", static_cast<long long>(ImGuiDir_Up)},
      {"_Down", static_cast<long long>(ImGuiDir_Down)},
      {"_COUNT", static_cast<long long>(ImGuiDir_COUNT)}};
  RegisterEnum(lua, "ImGuiDir", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiDockNodeFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiDockNodeFlags_None)},
      {"KeepAliveOnly", static_cast<long long>(ImGuiDockNodeFlags_KeepAliveOnly)},
      {"NoDockingOverCentralNode", static_cast<long long>(ImGuiDockNodeFlags_NoDockingOverCentralNode)},
      {"PassthruCentralNode", static_cast<long long>(ImGuiDockNodeFlags_PassthruCentralNode)},
      {"NoDockingSplit", static_cast<long long>(ImGuiDockNodeFlags_NoDockingSplit)},
      {"NoResize", static_cast<long long>(ImGuiDockNodeFlags_NoResize)},
      {"AutoHideTabBar", static_cast<long long>(ImGuiDockNodeFlags_AutoHideTabBar)},
      {"NoUndocking", static_cast<long long>(ImGuiDockNodeFlags_NoUndocking)},
      {"NoSplit", static_cast<long long>(ImGuiDockNodeFlags_NoSplit)},
      {"NoDockingInCentralNode", static_cast<long long>(ImGuiDockNodeFlags_NoDockingInCentralNode)}};
  RegisterEnum(lua, "ImGuiDockNodeFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiDragDropFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiDragDropFlags_None)},
      {"SourceNoPreviewTooltip", static_cast<long long>(ImGuiDragDropFlags_SourceNoPreviewTooltip)},
      {"SourceNoDisableHover", static_cast<long long>(ImGuiDragDropFlags_SourceNoDisableHover)},
      {"SourceNoHoldToOpenOthers", static_cast<long long>(ImGuiDragDropFlags_SourceNoHoldToOpenOthers)},
      {"SourceAllowNullID", static_cast<long long>(ImGuiDragDropFlags_SourceAllowNullID)},
      {"SourceExtern", static_cast<long long>(ImGuiDragDropFlags_SourceExtern)},
      {"PayloadAutoExpire", static_cast<long long>(ImGuiDragDropFlags_PayloadAutoExpire)},
      {"PayloadNoCrossContext", static_cast<long long>(ImGuiDragDropFlags_PayloadNoCrossContext)},
      {"PayloadNoCrossProcess", static_cast<long long>(ImGuiDragDropFlags_PayloadNoCrossProcess)},
      {"AcceptBeforeDelivery", static_cast<long long>(ImGuiDragDropFlags_AcceptBeforeDelivery)},
      {"AcceptNoDrawDefaultRect", static_cast<long long>(ImGuiDragDropFlags_AcceptNoDrawDefaultRect)},
      {"AcceptNoPreviewTooltip", static_cast<long long>(ImGuiDragDropFlags_AcceptNoPreviewTooltip)},
      {"AcceptDrawAsHovered", static_cast<long long>(ImGuiDragDropFlags_AcceptDrawAsHovered)},
      {"AcceptPeekOnly", static_cast<long long>(ImGuiDragDropFlags_AcceptPeekOnly)},
      {"SourceAutoExpirePayload", static_cast<long long>(ImGuiDragDropFlags_SourceAutoExpirePayload)}};
  RegisterEnum(lua, "ImGuiDragDropFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiFocusedFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiFocusedFlags_None)},
      {"ChildWindows", static_cast<long long>(ImGuiFocusedFlags_ChildWindows)},
      {"RootWindow", static_cast<long long>(ImGuiFocusedFlags_RootWindow)},
      {"AnyWindow", static_cast<long long>(ImGuiFocusedFlags_AnyWindow)},
      {"NoPopupHierarchy", static_cast<long long>(ImGuiFocusedFlags_NoPopupHierarchy)},
      {"DockHierarchy", static_cast<long long>(ImGuiFocusedFlags_DockHierarchy)},
      {"RootAndChildWindows", static_cast<long long>(ImGuiFocusedFlags_RootAndChildWindows)}};
  RegisterEnum(lua, "ImGuiFocusedFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiHoveredFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiHoveredFlags_None)},
      {"ChildWindows", static_cast<long long>(ImGuiHoveredFlags_ChildWindows)},
      {"RootWindow", static_cast<long long>(ImGuiHoveredFlags_RootWindow)},
      {"AnyWindow", static_cast<long long>(ImGuiHoveredFlags_AnyWindow)},
      {"NoPopupHierarchy", static_cast<long long>(ImGuiHoveredFlags_NoPopupHierarchy)},
      {"DockHierarchy", static_cast<long long>(ImGuiHoveredFlags_DockHierarchy)},
      {"AllowWhenBlockedByPopup", static_cast<long long>(ImGuiHoveredFlags_AllowWhenBlockedByPopup)},
      {"AllowWhenBlockedByActiveItem", static_cast<long long>(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem)},
      {"AllowWhenOverlappedByItem", static_cast<long long>(ImGuiHoveredFlags_AllowWhenOverlappedByItem)},
      {"AllowWhenOverlappedByWindow", static_cast<long long>(ImGuiHoveredFlags_AllowWhenOverlappedByWindow)},
      {"AllowWhenDisabled", static_cast<long long>(ImGuiHoveredFlags_AllowWhenDisabled)},
      {"NoNavOverride", static_cast<long long>(ImGuiHoveredFlags_NoNavOverride)},
      {"AllowWhenOverlapped", static_cast<long long>(ImGuiHoveredFlags_AllowWhenOverlapped)},
      {"RectOnly", static_cast<long long>(ImGuiHoveredFlags_RectOnly)},
      {"RootAndChildWindows", static_cast<long long>(ImGuiHoveredFlags_RootAndChildWindows)},
      {"ForTooltip", static_cast<long long>(ImGuiHoveredFlags_ForTooltip)},
      {"Stationary", static_cast<long long>(ImGuiHoveredFlags_Stationary)},
      {"DelayNone", static_cast<long long>(ImGuiHoveredFlags_DelayNone)},
      {"DelayShort", static_cast<long long>(ImGuiHoveredFlags_DelayShort)},
      {"DelayNormal", static_cast<long long>(ImGuiHoveredFlags_DelayNormal)},
      {"NoSharedDelay", static_cast<long long>(ImGuiHoveredFlags_NoSharedDelay)}};
  RegisterEnum(lua, "ImGuiHoveredFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiInputFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiInputFlags_None)},
      {"Repeat", static_cast<long long>(ImGuiInputFlags_Repeat)},
      {"RouteActive", static_cast<long long>(ImGuiInputFlags_RouteActive)},
      {"RouteFocused", static_cast<long long>(ImGuiInputFlags_RouteFocused)},
      {"RouteGlobal", static_cast<long long>(ImGuiInputFlags_RouteGlobal)},
      {"RouteAlways", static_cast<long long>(ImGuiInputFlags_RouteAlways)},
      {"RouteOverFocused", static_cast<long long>(ImGuiInputFlags_RouteOverFocused)},
      {"RouteOverActive", static_cast<long long>(ImGuiInputFlags_RouteOverActive)},
      {"RouteUnlessBgFocused", static_cast<long long>(ImGuiInputFlags_RouteUnlessBgFocused)},
      {"RouteFromRootWindow", static_cast<long long>(ImGuiInputFlags_RouteFromRootWindow)},
      {"Tooltip", static_cast<long long>(ImGuiInputFlags_Tooltip)}};
  RegisterEnum(lua, "ImGuiInputFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiInputTextFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiInputTextFlags_None)},
      {"CharsDecimal", static_cast<long long>(ImGuiInputTextFlags_CharsDecimal)},
      {"CharsHexadecimal", static_cast<long long>(ImGuiInputTextFlags_CharsHexadecimal)},
      {"CharsScientific", static_cast<long long>(ImGuiInputTextFlags_CharsScientific)},
      {"CharsUppercase", static_cast<long long>(ImGuiInputTextFlags_CharsUppercase)},
      {"CharsNoBlank", static_cast<long long>(ImGuiInputTextFlags_CharsNoBlank)},
      {"AllowTabInput", static_cast<long long>(ImGuiInputTextFlags_AllowTabInput)},
      {"EnterReturnsTrue", static_cast<long long>(ImGuiInputTextFlags_EnterReturnsTrue)},
      {"EscapeClearsAll", static_cast<long long>(ImGuiInputTextFlags_EscapeClearsAll)},
      {"CtrlEnterForNewLine", static_cast<long long>(ImGuiInputTextFlags_CtrlEnterForNewLine)},
      {"ReadOnly", static_cast<long long>(ImGuiInputTextFlags_ReadOnly)},
      {"Password", static_cast<long long>(ImGuiInputTextFlags_Password)},
      {"AlwaysOverwrite", static_cast<long long>(ImGuiInputTextFlags_AlwaysOverwrite)},
      {"AutoSelectAll", static_cast<long long>(ImGuiInputTextFlags_AutoSelectAll)},
      {"ParseEmptyRefVal", static_cast<long long>(ImGuiInputTextFlags_ParseEmptyRefVal)},
      {"DisplayEmptyRefVal", static_cast<long long>(ImGuiInputTextFlags_DisplayEmptyRefVal)},
      {"NoHorizontalScroll", static_cast<long long>(ImGuiInputTextFlags_NoHorizontalScroll)},
      {"NoUndoRedo", static_cast<long long>(ImGuiInputTextFlags_NoUndoRedo)},
      {"ElideLeft", static_cast<long long>(ImGuiInputTextFlags_ElideLeft)},
      {"CallbackCompletion", static_cast<long long>(ImGuiInputTextFlags_CallbackCompletion)},
      {"CallbackHistory", static_cast<long long>(ImGuiInputTextFlags_CallbackHistory)},
      {"CallbackAlways", static_cast<long long>(ImGuiInputTextFlags_CallbackAlways)},
      {"CallbackCharFilter", static_cast<long long>(ImGuiInputTextFlags_CallbackCharFilter)},
      {"CallbackResize", static_cast<long long>(ImGuiInputTextFlags_CallbackResize)},
      {"CallbackEdit", static_cast<long long>(ImGuiInputTextFlags_CallbackEdit)},
      {"WordWrap", static_cast<long long>(ImGuiInputTextFlags_WordWrap)}};
  RegisterEnum(lua, "ImGuiInputTextFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiItemFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiItemFlags_None)},
      {"NoTabStop", static_cast<long long>(ImGuiItemFlags_NoTabStop)},
      {"NoNav", static_cast<long long>(ImGuiItemFlags_NoNav)},
      {"NoNavDefaultFocus", static_cast<long long>(ImGuiItemFlags_NoNavDefaultFocus)},
      {"ButtonRepeat", static_cast<long long>(ImGuiItemFlags_ButtonRepeat)},
      {"AutoClosePopups", static_cast<long long>(ImGuiItemFlags_AutoClosePopups)},
      {"AllowDuplicateId", static_cast<long long>(ImGuiItemFlags_AllowDuplicateId)},
      {"Disabled", static_cast<long long>(ImGuiItemFlags_Disabled)}};
  RegisterEnum(lua, "ImGuiItemFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiKey(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_None", static_cast<long long>(ImGuiKey_None)},
      {"_NamedKey_BEGIN", static_cast<long long>(ImGuiKey_NamedKey_BEGIN)},
      {"_Tab", static_cast<long long>(ImGuiKey_Tab)},
      {"_LeftArrow", static_cast<long long>(ImGuiKey_LeftArrow)},
      {"_RightArrow", static_cast<long long>(ImGuiKey_RightArrow)},
      {"_UpArrow", static_cast<long long>(ImGuiKey_UpArrow)},
      {"_DownArrow", static_cast<long long>(ImGuiKey_DownArrow)},
      {"_PageUp", static_cast<long long>(ImGuiKey_PageUp)},
      {"_PageDown", static_cast<long long>(ImGuiKey_PageDown)},
      {"_Home", static_cast<long long>(ImGuiKey_Home)},
      {"_End", static_cast<long long>(ImGuiKey_End)},
      {"_Insert", static_cast<long long>(ImGuiKey_Insert)},
      {"_Delete", static_cast<long long>(ImGuiKey_Delete)},
      {"_Backspace", static_cast<long long>(ImGuiKey_Backspace)},
      {"_Space", static_cast<long long>(ImGuiKey_Space)},
      {"_Enter", static_cast<long long>(ImGuiKey_Enter)},
      {"_Escape", static_cast<long long>(ImGuiKey_Escape)},
      {"_LeftCtrl", static_cast<long long>(ImGuiKey_LeftCtrl)},
      {"_LeftShift", static_cast<long long>(ImGuiKey_LeftShift)},
      {"_LeftAlt", static_cast<long long>(ImGuiKey_LeftAlt)},
      {"_LeftSuper", static_cast<long long>(ImGuiKey_LeftSuper)},
      {"_RightCtrl", static_cast<long long>(ImGuiKey_RightCtrl)},
      {"_RightShift", static_cast<long long>(ImGuiKey_RightShift)},
      {"_RightAlt", static_cast<long long>(ImGuiKey_RightAlt)},
      {"_RightSuper", static_cast<long long>(ImGuiKey_RightSuper)},
      {"_Menu", static_cast<long long>(ImGuiKey_Menu)},
      {"_0", static_cast<long long>(ImGuiKey_0)},
      {"_1", static_cast<long long>(ImGuiKey_1)},
      {"_2", static_cast<long long>(ImGuiKey_2)},
      {"_3", static_cast<long long>(ImGuiKey_3)},
      {"_4", static_cast<long long>(ImGuiKey_4)},
      {"_5", static_cast<long long>(ImGuiKey_5)},
      {"_6", static_cast<long long>(ImGuiKey_6)},
      {"_7", static_cast<long long>(ImGuiKey_7)},
      {"_8", static_cast<long long>(ImGuiKey_8)},
      {"_9", static_cast<long long>(ImGuiKey_9)},
      {"_A", static_cast<long long>(ImGuiKey_A)},
      {"_B", static_cast<long long>(ImGuiKey_B)},
      {"_C", static_cast<long long>(ImGuiKey_C)},
      {"_D", static_cast<long long>(ImGuiKey_D)},
      {"_E", static_cast<long long>(ImGuiKey_E)},
      {"_F", static_cast<long long>(ImGuiKey_F)},
      {"_G", static_cast<long long>(ImGuiKey_G)},
      {"_H", static_cast<long long>(ImGuiKey_H)},
      {"_I", static_cast<long long>(ImGuiKey_I)},
      {"_J", static_cast<long long>(ImGuiKey_J)},
      {"_K", static_cast<long long>(ImGuiKey_K)},
      {"_L", static_cast<long long>(ImGuiKey_L)},
      {"_M", static_cast<long long>(ImGuiKey_M)},
      {"_N", static_cast<long long>(ImGuiKey_N)},
      {"_O", static_cast<long long>(ImGuiKey_O)},
      {"_P", static_cast<long long>(ImGuiKey_P)},
      {"_Q", static_cast<long long>(ImGuiKey_Q)},
      {"_R", static_cast<long long>(ImGuiKey_R)},
      {"_S", static_cast<long long>(ImGuiKey_S)},
      {"_T", static_cast<long long>(ImGuiKey_T)},
      {"_U", static_cast<long long>(ImGuiKey_U)},
      {"_V", static_cast<long long>(ImGuiKey_V)},
      {"_W", static_cast<long long>(ImGuiKey_W)},
      {"_X", static_cast<long long>(ImGuiKey_X)},
      {"_Y", static_cast<long long>(ImGuiKey_Y)},
      {"_Z", static_cast<long long>(ImGuiKey_Z)},
      {"_F1", static_cast<long long>(ImGuiKey_F1)},
      {"_F2", static_cast<long long>(ImGuiKey_F2)},
      {"_F3", static_cast<long long>(ImGuiKey_F3)},
      {"_F4", static_cast<long long>(ImGuiKey_F4)},
      {"_F5", static_cast<long long>(ImGuiKey_F5)},
      {"_F6", static_cast<long long>(ImGuiKey_F6)},
      {"_F7", static_cast<long long>(ImGuiKey_F7)},
      {"_F8", static_cast<long long>(ImGuiKey_F8)},
      {"_F9", static_cast<long long>(ImGuiKey_F9)},
      {"_F10", static_cast<long long>(ImGuiKey_F10)},
      {"_F11", static_cast<long long>(ImGuiKey_F11)},
      {"_F12", static_cast<long long>(ImGuiKey_F12)},
      {"_F13", static_cast<long long>(ImGuiKey_F13)},
      {"_F14", static_cast<long long>(ImGuiKey_F14)},
      {"_F15", static_cast<long long>(ImGuiKey_F15)},
      {"_F16", static_cast<long long>(ImGuiKey_F16)},
      {"_F17", static_cast<long long>(ImGuiKey_F17)},
      {"_F18", static_cast<long long>(ImGuiKey_F18)},
      {"_F19", static_cast<long long>(ImGuiKey_F19)},
      {"_F20", static_cast<long long>(ImGuiKey_F20)},
      {"_F21", static_cast<long long>(ImGuiKey_F21)},
      {"_F22", static_cast<long long>(ImGuiKey_F22)},
      {"_F23", static_cast<long long>(ImGuiKey_F23)},
      {"_F24", static_cast<long long>(ImGuiKey_F24)},
      {"_Apostrophe", static_cast<long long>(ImGuiKey_Apostrophe)},
      {"_Comma", static_cast<long long>(ImGuiKey_Comma)},
      {"_Minus", static_cast<long long>(ImGuiKey_Minus)},
      {"_Period", static_cast<long long>(ImGuiKey_Period)},
      {"_Slash", static_cast<long long>(ImGuiKey_Slash)},
      {"_Semicolon", static_cast<long long>(ImGuiKey_Semicolon)},
      {"_Equal", static_cast<long long>(ImGuiKey_Equal)},
      {"_LeftBracket", static_cast<long long>(ImGuiKey_LeftBracket)},
      {"_Backslash", static_cast<long long>(ImGuiKey_Backslash)},
      {"_RightBracket", static_cast<long long>(ImGuiKey_RightBracket)},
      {"_GraveAccent", static_cast<long long>(ImGuiKey_GraveAccent)},
      {"_CapsLock", static_cast<long long>(ImGuiKey_CapsLock)},
      {"_ScrollLock", static_cast<long long>(ImGuiKey_ScrollLock)},
      {"_NumLock", static_cast<long long>(ImGuiKey_NumLock)},
      {"_PrintScreen", static_cast<long long>(ImGuiKey_PrintScreen)},
      {"_Pause", static_cast<long long>(ImGuiKey_Pause)},
      {"_Keypad0", static_cast<long long>(ImGuiKey_Keypad0)},
      {"_Keypad1", static_cast<long long>(ImGuiKey_Keypad1)},
      {"_Keypad2", static_cast<long long>(ImGuiKey_Keypad2)},
      {"_Keypad3", static_cast<long long>(ImGuiKey_Keypad3)},
      {"_Keypad4", static_cast<long long>(ImGuiKey_Keypad4)},
      {"_Keypad5", static_cast<long long>(ImGuiKey_Keypad5)},
      {"_Keypad6", static_cast<long long>(ImGuiKey_Keypad6)},
      {"_Keypad7", static_cast<long long>(ImGuiKey_Keypad7)},
      {"_Keypad8", static_cast<long long>(ImGuiKey_Keypad8)},
      {"_Keypad9", static_cast<long long>(ImGuiKey_Keypad9)},
      {"_KeypadDecimal", static_cast<long long>(ImGuiKey_KeypadDecimal)},
      {"_KeypadDivide", static_cast<long long>(ImGuiKey_KeypadDivide)},
      {"_KeypadMultiply", static_cast<long long>(ImGuiKey_KeypadMultiply)},
      {"_KeypadSubtract", static_cast<long long>(ImGuiKey_KeypadSubtract)},
      {"_KeypadAdd", static_cast<long long>(ImGuiKey_KeypadAdd)},
      {"_KeypadEnter", static_cast<long long>(ImGuiKey_KeypadEnter)},
      {"_KeypadEqual", static_cast<long long>(ImGuiKey_KeypadEqual)},
      {"_AppBack", static_cast<long long>(ImGuiKey_AppBack)},
      {"_AppForward", static_cast<long long>(ImGuiKey_AppForward)},
      {"_Oem102", static_cast<long long>(ImGuiKey_Oem102)},
      {"_GamepadStart", static_cast<long long>(ImGuiKey_GamepadStart)},
      {"_GamepadBack", static_cast<long long>(ImGuiKey_GamepadBack)},
      {"_GamepadFaceLeft", static_cast<long long>(ImGuiKey_GamepadFaceLeft)},
      {"_GamepadFaceRight", static_cast<long long>(ImGuiKey_GamepadFaceRight)},
      {"_GamepadFaceUp", static_cast<long long>(ImGuiKey_GamepadFaceUp)},
      {"_GamepadFaceDown", static_cast<long long>(ImGuiKey_GamepadFaceDown)},
      {"_GamepadDpadLeft", static_cast<long long>(ImGuiKey_GamepadDpadLeft)},
      {"_GamepadDpadRight", static_cast<long long>(ImGuiKey_GamepadDpadRight)},
      {"_GamepadDpadUp", static_cast<long long>(ImGuiKey_GamepadDpadUp)},
      {"_GamepadDpadDown", static_cast<long long>(ImGuiKey_GamepadDpadDown)},
      {"_GamepadL1", static_cast<long long>(ImGuiKey_GamepadL1)},
      {"_GamepadR1", static_cast<long long>(ImGuiKey_GamepadR1)},
      {"_GamepadL2", static_cast<long long>(ImGuiKey_GamepadL2)},
      {"_GamepadR2", static_cast<long long>(ImGuiKey_GamepadR2)},
      {"_GamepadL3", static_cast<long long>(ImGuiKey_GamepadL3)},
      {"_GamepadR3", static_cast<long long>(ImGuiKey_GamepadR3)},
      {"_GamepadLStickLeft", static_cast<long long>(ImGuiKey_GamepadLStickLeft)},
      {"_GamepadLStickRight", static_cast<long long>(ImGuiKey_GamepadLStickRight)},
      {"_GamepadLStickUp", static_cast<long long>(ImGuiKey_GamepadLStickUp)},
      {"_GamepadLStickDown", static_cast<long long>(ImGuiKey_GamepadLStickDown)},
      {"_GamepadRStickLeft", static_cast<long long>(ImGuiKey_GamepadRStickLeft)},
      {"_GamepadRStickRight", static_cast<long long>(ImGuiKey_GamepadRStickRight)},
      {"_GamepadRStickUp", static_cast<long long>(ImGuiKey_GamepadRStickUp)},
      {"_GamepadRStickDown", static_cast<long long>(ImGuiKey_GamepadRStickDown)},
      {"_MouseLeft", static_cast<long long>(ImGuiKey_MouseLeft)},
      {"_MouseRight", static_cast<long long>(ImGuiKey_MouseRight)},
      {"_MouseMiddle", static_cast<long long>(ImGuiKey_MouseMiddle)},
      {"_MouseX1", static_cast<long long>(ImGuiKey_MouseX1)},
      {"_MouseX2", static_cast<long long>(ImGuiKey_MouseX2)},
      {"_MouseWheelX", static_cast<long long>(ImGuiKey_MouseWheelX)},
      {"_MouseWheelY", static_cast<long long>(ImGuiKey_MouseWheelY)},
      {"ImGuiMod_None", static_cast<long long>(ImGuiMod_None)},
      {"ImGuiMod_Ctrl", static_cast<long long>(ImGuiMod_Ctrl)},
      {"ImGuiMod_Shift", static_cast<long long>(ImGuiMod_Shift)},
      {"ImGuiMod_Alt", static_cast<long long>(ImGuiMod_Alt)},
      {"ImGuiMod_Super", static_cast<long long>(ImGuiMod_Super)},
      {"_COUNT", static_cast<long long>(ImGuiKey_COUNT)},
      {"ImGuiMod_Shortcut", static_cast<long long>(ImGuiMod_Shortcut)}};
  RegisterEnum(lua, "ImGuiKey", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiListClipperFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiListClipperFlags_None)},
      {"NoSetTableRowCounters", static_cast<long long>(ImGuiListClipperFlags_NoSetTableRowCounters)}};
  RegisterEnum(lua, "ImGuiListClipperFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiMouseButton(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"Left", static_cast<long long>(ImGuiMouseButton_Left)},
      {"Right", static_cast<long long>(ImGuiMouseButton_Right)},
      {"Middle", static_cast<long long>(ImGuiMouseButton_Middle)},
      {"COUNT", static_cast<long long>(ImGuiMouseButton_COUNT)}};
  RegisterEnum(lua, "ImGuiMouseButton", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiMouseCursor(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiMouseCursor_None)},
      {"Arrow", static_cast<long long>(ImGuiMouseCursor_Arrow)},
      {"TextInput", static_cast<long long>(ImGuiMouseCursor_TextInput)},
      {"ResizeAll", static_cast<long long>(ImGuiMouseCursor_ResizeAll)},
      {"ResizeNS", static_cast<long long>(ImGuiMouseCursor_ResizeNS)},
      {"ResizeEW", static_cast<long long>(ImGuiMouseCursor_ResizeEW)},
      {"ResizeNESW", static_cast<long long>(ImGuiMouseCursor_ResizeNESW)},
      {"ResizeNWSE", static_cast<long long>(ImGuiMouseCursor_ResizeNWSE)},
      {"Hand", static_cast<long long>(ImGuiMouseCursor_Hand)},
      {"Wait", static_cast<long long>(ImGuiMouseCursor_Wait)},
      {"Progress", static_cast<long long>(ImGuiMouseCursor_Progress)},
      {"NotAllowed", static_cast<long long>(ImGuiMouseCursor_NotAllowed)},
      {"COUNT", static_cast<long long>(ImGuiMouseCursor_COUNT)}};
  RegisterEnum(lua, "ImGuiMouseCursor", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiMouseSource(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_Mouse", static_cast<long long>(ImGuiMouseSource_Mouse)},
      {"_TouchScreen", static_cast<long long>(ImGuiMouseSource_TouchScreen)},
      {"_Pen", static_cast<long long>(ImGuiMouseSource_Pen)},
      {"_COUNT", static_cast<long long>(ImGuiMouseSource_COUNT)}};
  RegisterEnum(lua, "ImGuiMouseSource", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiMultiSelectFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiMultiSelectFlags_None)},
      {"SingleSelect", static_cast<long long>(ImGuiMultiSelectFlags_SingleSelect)},
      {"NoSelectAll", static_cast<long long>(ImGuiMultiSelectFlags_NoSelectAll)},
      {"NoRangeSelect", static_cast<long long>(ImGuiMultiSelectFlags_NoRangeSelect)},
      {"NoAutoSelect", static_cast<long long>(ImGuiMultiSelectFlags_NoAutoSelect)},
      {"NoAutoClear", static_cast<long long>(ImGuiMultiSelectFlags_NoAutoClear)},
      {"NoAutoClearOnReselect", static_cast<long long>(ImGuiMultiSelectFlags_NoAutoClearOnReselect)},
      {"BoxSelect1d", static_cast<long long>(ImGuiMultiSelectFlags_BoxSelect1d)},
      {"BoxSelect2d", static_cast<long long>(ImGuiMultiSelectFlags_BoxSelect2d)},
      {"BoxSelectNoScroll", static_cast<long long>(ImGuiMultiSelectFlags_BoxSelectNoScroll)},
      {"ClearOnEscape", static_cast<long long>(ImGuiMultiSelectFlags_ClearOnEscape)},
      {"ClearOnClickVoid", static_cast<long long>(ImGuiMultiSelectFlags_ClearOnClickVoid)},
      {"ScopeWindow", static_cast<long long>(ImGuiMultiSelectFlags_ScopeWindow)},
      {"ScopeRect", static_cast<long long>(ImGuiMultiSelectFlags_ScopeRect)},
      {"SelectOnAuto", static_cast<long long>(ImGuiMultiSelectFlags_SelectOnAuto)},
      {"SelectOnClickAlways", static_cast<long long>(ImGuiMultiSelectFlags_SelectOnClickAlways)},
      {"SelectOnClickRelease", static_cast<long long>(ImGuiMultiSelectFlags_SelectOnClickRelease)},
      {"NavWrapX", static_cast<long long>(ImGuiMultiSelectFlags_NavWrapX)},
      {"NoSelectOnRightClick", static_cast<long long>(ImGuiMultiSelectFlags_NoSelectOnRightClick)},
      {"SelectOnClick", static_cast<long long>(ImGuiMultiSelectFlags_SelectOnClick)}};
  RegisterEnum(lua, "ImGuiMultiSelectFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiPopupFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiPopupFlags_None)},
      {"MouseButtonLeft", static_cast<long long>(ImGuiPopupFlags_MouseButtonLeft)},
      {"MouseButtonRight", static_cast<long long>(ImGuiPopupFlags_MouseButtonRight)},
      {"MouseButtonMiddle", static_cast<long long>(ImGuiPopupFlags_MouseButtonMiddle)},
      {"NoReopen", static_cast<long long>(ImGuiPopupFlags_NoReopen)},
      {"NoOpenOverExistingPopup", static_cast<long long>(ImGuiPopupFlags_NoOpenOverExistingPopup)},
      {"NoOpenOverItems", static_cast<long long>(ImGuiPopupFlags_NoOpenOverItems)},
      {"AnyPopupId", static_cast<long long>(ImGuiPopupFlags_AnyPopupId)},
      {"AnyPopupLevel", static_cast<long long>(ImGuiPopupFlags_AnyPopupLevel)},
      {"AnyPopup", static_cast<long long>(ImGuiPopupFlags_AnyPopup)}};
  RegisterEnum(lua, "ImGuiPopupFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiSelectableFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiSelectableFlags_None)},
      {"NoAutoClosePopups", static_cast<long long>(ImGuiSelectableFlags_NoAutoClosePopups)},
      {"SpanAllColumns", static_cast<long long>(ImGuiSelectableFlags_SpanAllColumns)},
      {"AllowDoubleClick", static_cast<long long>(ImGuiSelectableFlags_AllowDoubleClick)},
      {"Disabled", static_cast<long long>(ImGuiSelectableFlags_Disabled)},
      {"AllowOverlap", static_cast<long long>(ImGuiSelectableFlags_AllowOverlap)},
      {"Highlight", static_cast<long long>(ImGuiSelectableFlags_Highlight)},
      {"SelectOnNav", static_cast<long long>(ImGuiSelectableFlags_SelectOnNav)},
      {"DontClosePopups", static_cast<long long>(ImGuiSelectableFlags_DontClosePopups)}};
  RegisterEnum(lua, "ImGuiSelectableFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiSelectionRequestType(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_None", static_cast<long long>(ImGuiSelectionRequestType_None)},
      {"_SetAll", static_cast<long long>(ImGuiSelectionRequestType_SetAll)},
      {"_SetRange", static_cast<long long>(ImGuiSelectionRequestType_SetRange)}};
  RegisterEnum(lua, "ImGuiSelectionRequestType", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiSliderFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiSliderFlags_None)},
      {"Logarithmic", static_cast<long long>(ImGuiSliderFlags_Logarithmic)},
      {"NoRoundToFormat", static_cast<long long>(ImGuiSliderFlags_NoRoundToFormat)},
      {"NoInput", static_cast<long long>(ImGuiSliderFlags_NoInput)},
      {"WrapAround", static_cast<long long>(ImGuiSliderFlags_WrapAround)},
      {"ClampOnInput", static_cast<long long>(ImGuiSliderFlags_ClampOnInput)},
      {"ClampZeroRange", static_cast<long long>(ImGuiSliderFlags_ClampZeroRange)},
      {"NoSpeedTweaks", static_cast<long long>(ImGuiSliderFlags_NoSpeedTweaks)},
      {"ColorMarkers", static_cast<long long>(ImGuiSliderFlags_ColorMarkers)},
      {"AlwaysClamp", static_cast<long long>(ImGuiSliderFlags_AlwaysClamp)}};
  RegisterEnum(lua, "ImGuiSliderFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiSortDirection(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_None", static_cast<long long>(ImGuiSortDirection_None)},
      {"_Ascending", static_cast<long long>(ImGuiSortDirection_Ascending)},
      {"_Descending", static_cast<long long>(ImGuiSortDirection_Descending)}};
  RegisterEnum(lua, "ImGuiSortDirection", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiStyleVar(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"Alpha", static_cast<long long>(ImGuiStyleVar_Alpha)},
      {"DisabledAlpha", static_cast<long long>(ImGuiStyleVar_DisabledAlpha)},
      {"WindowPadding", static_cast<long long>(ImGuiStyleVar_WindowPadding)},
      {"WindowRounding", static_cast<long long>(ImGuiStyleVar_WindowRounding)},
      {"WindowBorderSize", static_cast<long long>(ImGuiStyleVar_WindowBorderSize)},
      {"WindowMinSize", static_cast<long long>(ImGuiStyleVar_WindowMinSize)},
      {"WindowTitleAlign", static_cast<long long>(ImGuiStyleVar_WindowTitleAlign)},
      {"ChildRounding", static_cast<long long>(ImGuiStyleVar_ChildRounding)},
      {"ChildBorderSize", static_cast<long long>(ImGuiStyleVar_ChildBorderSize)},
      {"PopupRounding", static_cast<long long>(ImGuiStyleVar_PopupRounding)},
      {"PopupBorderSize", static_cast<long long>(ImGuiStyleVar_PopupBorderSize)},
      {"FramePadding", static_cast<long long>(ImGuiStyleVar_FramePadding)},
      {"FrameRounding", static_cast<long long>(ImGuiStyleVar_FrameRounding)},
      {"FrameBorderSize", static_cast<long long>(ImGuiStyleVar_FrameBorderSize)},
      {"ItemSpacing", static_cast<long long>(ImGuiStyleVar_ItemSpacing)},
      {"ItemInnerSpacing", static_cast<long long>(ImGuiStyleVar_ItemInnerSpacing)},
      {"IndentSpacing", static_cast<long long>(ImGuiStyleVar_IndentSpacing)},
      {"CellPadding", static_cast<long long>(ImGuiStyleVar_CellPadding)},
      {"ScrollbarSize", static_cast<long long>(ImGuiStyleVar_ScrollbarSize)},
      {"ScrollbarRounding", static_cast<long long>(ImGuiStyleVar_ScrollbarRounding)},
      {"ScrollbarPadding", static_cast<long long>(ImGuiStyleVar_ScrollbarPadding)},
      {"GrabMinSize", static_cast<long long>(ImGuiStyleVar_GrabMinSize)},
      {"GrabRounding", static_cast<long long>(ImGuiStyleVar_GrabRounding)},
      {"ImageRounding", static_cast<long long>(ImGuiStyleVar_ImageRounding)},
      {"ImageBorderSize", static_cast<long long>(ImGuiStyleVar_ImageBorderSize)},
      {"TabRounding", static_cast<long long>(ImGuiStyleVar_TabRounding)},
      {"TabBorderSize", static_cast<long long>(ImGuiStyleVar_TabBorderSize)},
      {"TabMinWidthBase", static_cast<long long>(ImGuiStyleVar_TabMinWidthBase)},
      {"TabMinWidthShrink", static_cast<long long>(ImGuiStyleVar_TabMinWidthShrink)},
      {"TabBarBorderSize", static_cast<long long>(ImGuiStyleVar_TabBarBorderSize)},
      {"TabBarOverlineSize", static_cast<long long>(ImGuiStyleVar_TabBarOverlineSize)},
      {"TableAngledHeadersAngle", static_cast<long long>(ImGuiStyleVar_TableAngledHeadersAngle)},
      {"TableAngledHeadersTextAlign", static_cast<long long>(ImGuiStyleVar_TableAngledHeadersTextAlign)},
      {"TreeLinesSize", static_cast<long long>(ImGuiStyleVar_TreeLinesSize)},
      {"TreeLinesRounding", static_cast<long long>(ImGuiStyleVar_TreeLinesRounding)},
      {"ButtonTextAlign", static_cast<long long>(ImGuiStyleVar_ButtonTextAlign)},
      {"SelectableTextAlign", static_cast<long long>(ImGuiStyleVar_SelectableTextAlign)},
      {"SeparatorSize", static_cast<long long>(ImGuiStyleVar_SeparatorSize)},
      {"SeparatorTextBorderSize", static_cast<long long>(ImGuiStyleVar_SeparatorTextBorderSize)},
      {"SeparatorTextAlign", static_cast<long long>(ImGuiStyleVar_SeparatorTextAlign)},
      {"SeparatorTextPadding", static_cast<long long>(ImGuiStyleVar_SeparatorTextPadding)},
      {"DockingSeparatorSize", static_cast<long long>(ImGuiStyleVar_DockingSeparatorSize)},
      {"COUNT", static_cast<long long>(ImGuiStyleVar_COUNT)}};
  RegisterEnum(lua, "ImGuiStyleVar", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTabBarFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTabBarFlags_None)},
      {"Reorderable", static_cast<long long>(ImGuiTabBarFlags_Reorderable)},
      {"AutoSelectNewTabs", static_cast<long long>(ImGuiTabBarFlags_AutoSelectNewTabs)},
      {"TabListPopupButton", static_cast<long long>(ImGuiTabBarFlags_TabListPopupButton)},
      {"NoCloseWithMiddleMouseButton", static_cast<long long>(ImGuiTabBarFlags_NoCloseWithMiddleMouseButton)},
      {"NoTabListScrollingButtons", static_cast<long long>(ImGuiTabBarFlags_NoTabListScrollingButtons)},
      {"NoTooltip", static_cast<long long>(ImGuiTabBarFlags_NoTooltip)},
      {"DrawSelectedOverline", static_cast<long long>(ImGuiTabBarFlags_DrawSelectedOverline)},
      {"FittingPolicyMixed", static_cast<long long>(ImGuiTabBarFlags_FittingPolicyMixed)},
      {"FittingPolicyShrink", static_cast<long long>(ImGuiTabBarFlags_FittingPolicyShrink)},
      {"FittingPolicyScroll", static_cast<long long>(ImGuiTabBarFlags_FittingPolicyScroll)},
      {"FittingPolicyResizeDown", static_cast<long long>(ImGuiTabBarFlags_FittingPolicyResizeDown)}};
  RegisterEnum(lua, "ImGuiTabBarFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTabItemFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTabItemFlags_None)},
      {"UnsavedDocument", static_cast<long long>(ImGuiTabItemFlags_UnsavedDocument)},
      {"SetSelected", static_cast<long long>(ImGuiTabItemFlags_SetSelected)},
      {"NoCloseWithMiddleMouseButton", static_cast<long long>(ImGuiTabItemFlags_NoCloseWithMiddleMouseButton)},
      {"NoPushId", static_cast<long long>(ImGuiTabItemFlags_NoPushId)},
      {"NoTooltip", static_cast<long long>(ImGuiTabItemFlags_NoTooltip)},
      {"NoReorder", static_cast<long long>(ImGuiTabItemFlags_NoReorder)},
      {"Leading", static_cast<long long>(ImGuiTabItemFlags_Leading)},
      {"Trailing", static_cast<long long>(ImGuiTabItemFlags_Trailing)},
      {"NoAssumedClosure", static_cast<long long>(ImGuiTabItemFlags_NoAssumedClosure)}};
  RegisterEnum(lua, "ImGuiTabItemFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTableBgTarget(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTableBgTarget_None)},
      {"RowBg0", static_cast<long long>(ImGuiTableBgTarget_RowBg0)},
      {"RowBg1", static_cast<long long>(ImGuiTableBgTarget_RowBg1)},
      {"CellBg", static_cast<long long>(ImGuiTableBgTarget_CellBg)}};
  RegisterEnum(lua, "ImGuiTableBgTarget", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTableColumnFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTableColumnFlags_None)},
      {"Disabled", static_cast<long long>(ImGuiTableColumnFlags_Disabled)},
      {"DefaultHide", static_cast<long long>(ImGuiTableColumnFlags_DefaultHide)},
      {"DefaultSort", static_cast<long long>(ImGuiTableColumnFlags_DefaultSort)},
      {"WidthStretch", static_cast<long long>(ImGuiTableColumnFlags_WidthStretch)},
      {"WidthFixed", static_cast<long long>(ImGuiTableColumnFlags_WidthFixed)},
      {"NoResize", static_cast<long long>(ImGuiTableColumnFlags_NoResize)},
      {"NoReorder", static_cast<long long>(ImGuiTableColumnFlags_NoReorder)},
      {"NoHide", static_cast<long long>(ImGuiTableColumnFlags_NoHide)},
      {"NoClip", static_cast<long long>(ImGuiTableColumnFlags_NoClip)},
      {"NoSort", static_cast<long long>(ImGuiTableColumnFlags_NoSort)},
      {"NoSortAscending", static_cast<long long>(ImGuiTableColumnFlags_NoSortAscending)},
      {"NoSortDescending", static_cast<long long>(ImGuiTableColumnFlags_NoSortDescending)},
      {"NoHeaderLabel", static_cast<long long>(ImGuiTableColumnFlags_NoHeaderLabel)},
      {"NoHeaderWidth", static_cast<long long>(ImGuiTableColumnFlags_NoHeaderWidth)},
      {"PreferSortAscending", static_cast<long long>(ImGuiTableColumnFlags_PreferSortAscending)},
      {"PreferSortDescending", static_cast<long long>(ImGuiTableColumnFlags_PreferSortDescending)},
      {"IndentEnable", static_cast<long long>(ImGuiTableColumnFlags_IndentEnable)},
      {"IndentDisable", static_cast<long long>(ImGuiTableColumnFlags_IndentDisable)},
      {"AngledHeader", static_cast<long long>(ImGuiTableColumnFlags_AngledHeader)},
      {"IsEnabled", static_cast<long long>(ImGuiTableColumnFlags_IsEnabled)},
      {"IsVisible", static_cast<long long>(ImGuiTableColumnFlags_IsVisible)},
      {"IsSorted", static_cast<long long>(ImGuiTableColumnFlags_IsSorted)},
      {"IsHovered", static_cast<long long>(ImGuiTableColumnFlags_IsHovered)}};
  RegisterEnum(lua, "ImGuiTableColumnFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTableFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTableFlags_None)},
      {"Resizable", static_cast<long long>(ImGuiTableFlags_Resizable)},
      {"Reorderable", static_cast<long long>(ImGuiTableFlags_Reorderable)},
      {"Hideable", static_cast<long long>(ImGuiTableFlags_Hideable)},
      {"Sortable", static_cast<long long>(ImGuiTableFlags_Sortable)},
      {"NoSavedSettings", static_cast<long long>(ImGuiTableFlags_NoSavedSettings)},
      {"ContextMenuInBody", static_cast<long long>(ImGuiTableFlags_ContextMenuInBody)},
      {"RowBg", static_cast<long long>(ImGuiTableFlags_RowBg)},
      {"BordersInnerH", static_cast<long long>(ImGuiTableFlags_BordersInnerH)},
      {"BordersOuterH", static_cast<long long>(ImGuiTableFlags_BordersOuterH)},
      {"BordersInnerV", static_cast<long long>(ImGuiTableFlags_BordersInnerV)},
      {"BordersOuterV", static_cast<long long>(ImGuiTableFlags_BordersOuterV)},
      {"BordersH", static_cast<long long>(ImGuiTableFlags_BordersH)},
      {"BordersV", static_cast<long long>(ImGuiTableFlags_BordersV)},
      {"BordersInner", static_cast<long long>(ImGuiTableFlags_BordersInner)},
      {"BordersOuter", static_cast<long long>(ImGuiTableFlags_BordersOuter)},
      {"Borders", static_cast<long long>(ImGuiTableFlags_Borders)},
      {"NoBordersInBody", static_cast<long long>(ImGuiTableFlags_NoBordersInBody)},
      {"NoBordersInBodyUntilResize", static_cast<long long>(ImGuiTableFlags_NoBordersInBodyUntilResize)},
      {"SizingFixedFit", static_cast<long long>(ImGuiTableFlags_SizingFixedFit)},
      {"SizingFixedSame", static_cast<long long>(ImGuiTableFlags_SizingFixedSame)},
      {"SizingStretchProp", static_cast<long long>(ImGuiTableFlags_SizingStretchProp)},
      {"SizingStretchSame", static_cast<long long>(ImGuiTableFlags_SizingStretchSame)},
      {"NoHostExtendX", static_cast<long long>(ImGuiTableFlags_NoHostExtendX)},
      {"NoHostExtendY", static_cast<long long>(ImGuiTableFlags_NoHostExtendY)},
      {"NoKeepColumnsVisible", static_cast<long long>(ImGuiTableFlags_NoKeepColumnsVisible)},
      {"PreciseWidths", static_cast<long long>(ImGuiTableFlags_PreciseWidths)},
      {"NoClip", static_cast<long long>(ImGuiTableFlags_NoClip)},
      {"PadOuterX", static_cast<long long>(ImGuiTableFlags_PadOuterX)},
      {"NoPadOuterX", static_cast<long long>(ImGuiTableFlags_NoPadOuterX)},
      {"NoPadInnerX", static_cast<long long>(ImGuiTableFlags_NoPadInnerX)},
      {"ScrollX", static_cast<long long>(ImGuiTableFlags_ScrollX)},
      {"ScrollY", static_cast<long long>(ImGuiTableFlags_ScrollY)},
      {"SortMulti", static_cast<long long>(ImGuiTableFlags_SortMulti)},
      {"SortTristate", static_cast<long long>(ImGuiTableFlags_SortTristate)},
      {"HighlightHoveredColumn", static_cast<long long>(ImGuiTableFlags_HighlightHoveredColumn)}};
  RegisterEnum(lua, "ImGuiTableFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTableRowFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTableRowFlags_None)},
      {"Headers", static_cast<long long>(ImGuiTableRowFlags_Headers)}};
  RegisterEnum(lua, "ImGuiTableRowFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiTreeNodeFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiTreeNodeFlags_None)},
      {"Selected", static_cast<long long>(ImGuiTreeNodeFlags_Selected)},
      {"Framed", static_cast<long long>(ImGuiTreeNodeFlags_Framed)},
      {"AllowOverlap", static_cast<long long>(ImGuiTreeNodeFlags_AllowOverlap)},
      {"NoTreePushOnOpen", static_cast<long long>(ImGuiTreeNodeFlags_NoTreePushOnOpen)},
      {"NoAutoOpenOnLog", static_cast<long long>(ImGuiTreeNodeFlags_NoAutoOpenOnLog)},
      {"DefaultOpen", static_cast<long long>(ImGuiTreeNodeFlags_DefaultOpen)},
      {"OpenOnDoubleClick", static_cast<long long>(ImGuiTreeNodeFlags_OpenOnDoubleClick)},
      {"OpenOnArrow", static_cast<long long>(ImGuiTreeNodeFlags_OpenOnArrow)},
      {"Leaf", static_cast<long long>(ImGuiTreeNodeFlags_Leaf)},
      {"Bullet", static_cast<long long>(ImGuiTreeNodeFlags_Bullet)},
      {"FramePadding", static_cast<long long>(ImGuiTreeNodeFlags_FramePadding)},
      {"SpanAvailWidth", static_cast<long long>(ImGuiTreeNodeFlags_SpanAvailWidth)},
      {"SpanFullWidth", static_cast<long long>(ImGuiTreeNodeFlags_SpanFullWidth)},
      {"SpanLabelWidth", static_cast<long long>(ImGuiTreeNodeFlags_SpanLabelWidth)},
      {"SpanAllColumns", static_cast<long long>(ImGuiTreeNodeFlags_SpanAllColumns)},
      {"LabelSpanAllColumns", static_cast<long long>(ImGuiTreeNodeFlags_LabelSpanAllColumns)},
      {"NavLeftJumpsToParent", static_cast<long long>(ImGuiTreeNodeFlags_NavLeftJumpsToParent)},
      {"CollapsingHeader", static_cast<long long>(ImGuiTreeNodeFlags_CollapsingHeader)},
      {"DrawLinesNone", static_cast<long long>(ImGuiTreeNodeFlags_DrawLinesNone)},
      {"DrawLinesFull", static_cast<long long>(ImGuiTreeNodeFlags_DrawLinesFull)},
      {"DrawLinesToNodes", static_cast<long long>(ImGuiTreeNodeFlags_DrawLinesToNodes)},
      {"NavLeftJumpsBackHere", static_cast<long long>(ImGuiTreeNodeFlags_NavLeftJumpsBackHere)},
      {"SpanTextWidth", static_cast<long long>(ImGuiTreeNodeFlags_SpanTextWidth)}};
  RegisterEnum(lua, "ImGuiTreeNodeFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiViewportFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiViewportFlags_None)},
      {"IsPlatformWindow", static_cast<long long>(ImGuiViewportFlags_IsPlatformWindow)},
      {"IsPlatformMonitor", static_cast<long long>(ImGuiViewportFlags_IsPlatformMonitor)},
      {"OwnedByApp", static_cast<long long>(ImGuiViewportFlags_OwnedByApp)},
      {"NoDecoration", static_cast<long long>(ImGuiViewportFlags_NoDecoration)},
      {"NoTaskBarIcon", static_cast<long long>(ImGuiViewportFlags_NoTaskBarIcon)},
      {"NoFocusOnAppearing", static_cast<long long>(ImGuiViewportFlags_NoFocusOnAppearing)},
      {"NoFocusOnClick", static_cast<long long>(ImGuiViewportFlags_NoFocusOnClick)},
      {"NoInputs", static_cast<long long>(ImGuiViewportFlags_NoInputs)},
      {"NoRendererClear", static_cast<long long>(ImGuiViewportFlags_NoRendererClear)},
      {"NoAutoMerge", static_cast<long long>(ImGuiViewportFlags_NoAutoMerge)},
      {"TopMost", static_cast<long long>(ImGuiViewportFlags_TopMost)},
      {"CanHostOtherWindows", static_cast<long long>(ImGuiViewportFlags_CanHostOtherWindows)},
      {"IsMinimized", static_cast<long long>(ImGuiViewportFlags_IsMinimized)},
      {"IsFocused", static_cast<long long>(ImGuiViewportFlags_IsFocused)}};
  RegisterEnum(lua, "ImGuiViewportFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImGuiWindowFlags(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"None", static_cast<long long>(ImGuiWindowFlags_None)},
      {"NoTitleBar", static_cast<long long>(ImGuiWindowFlags_NoTitleBar)},
      {"NoResize", static_cast<long long>(ImGuiWindowFlags_NoResize)},
      {"NoMove", static_cast<long long>(ImGuiWindowFlags_NoMove)},
      {"NoScrollbar", static_cast<long long>(ImGuiWindowFlags_NoScrollbar)},
      {"NoScrollWithMouse", static_cast<long long>(ImGuiWindowFlags_NoScrollWithMouse)},
      {"NoCollapse", static_cast<long long>(ImGuiWindowFlags_NoCollapse)},
      {"AlwaysAutoResize", static_cast<long long>(ImGuiWindowFlags_AlwaysAutoResize)},
      {"NoBackground", static_cast<long long>(ImGuiWindowFlags_NoBackground)},
      {"NoSavedSettings", static_cast<long long>(ImGuiWindowFlags_NoSavedSettings)},
      {"NoMouseInputs", static_cast<long long>(ImGuiWindowFlags_NoMouseInputs)},
      {"MenuBar", static_cast<long long>(ImGuiWindowFlags_MenuBar)},
      {"HorizontalScrollbar", static_cast<long long>(ImGuiWindowFlags_HorizontalScrollbar)},
      {"NoFocusOnAppearing", static_cast<long long>(ImGuiWindowFlags_NoFocusOnAppearing)},
      {"NoBringToFrontOnFocus", static_cast<long long>(ImGuiWindowFlags_NoBringToFrontOnFocus)},
      {"AlwaysVerticalScrollbar", static_cast<long long>(ImGuiWindowFlags_AlwaysVerticalScrollbar)},
      {"AlwaysHorizontalScrollbar", static_cast<long long>(ImGuiWindowFlags_AlwaysHorizontalScrollbar)},
      {"NoNavInputs", static_cast<long long>(ImGuiWindowFlags_NoNavInputs)},
      {"NoNavFocus", static_cast<long long>(ImGuiWindowFlags_NoNavFocus)},
      {"UnsavedDocument", static_cast<long long>(ImGuiWindowFlags_UnsavedDocument)},
      {"NoDocking", static_cast<long long>(ImGuiWindowFlags_NoDocking)},
      {"NoNav", static_cast<long long>(ImGuiWindowFlags_NoNav)},
      {"NoDecoration", static_cast<long long>(ImGuiWindowFlags_NoDecoration)},
      {"NoInputs", static_cast<long long>(ImGuiWindowFlags_NoInputs)}};
  RegisterEnum(lua, "ImGuiWindowFlags", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImTextureFormat(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_RGBA32", static_cast<long long>(ImTextureFormat_RGBA32)},
      {"_Alpha8", static_cast<long long>(ImTextureFormat_Alpha8)}};
  RegisterEnum(lua, "ImTextureFormat", entries, sizeof(entries) / sizeof(entries[0]));
}

static void InitEnum_ImTextureStatus(sol::state& lua) {
  static const EnumEntry entries[] = {
      {"_OK", static_cast<long long>(ImTextureStatus_OK)},
      {"_Destroyed", static_cast<long long>(ImTextureStatus_Destroyed)},
      {"_WantCreate", static_cast<long long>(ImTextureStatus_WantCreate)},
      {"_WantUpdates", static_cast<long long>(ImTextureStatus_WantUpdates)},
      {"_WantDestroy", static_cast<long long>(ImTextureStatus_WantDestroy)}};
  RegisterEnum(lua, "ImTextureStatus", entries, sizeof(entries) / sizeof(entries[0]));
}

void InitEnums(sol::state& lua) {
  InitEnum_ImDrawFlags(lua);
  InitEnum_ImDrawListFlags(lua);
  InitEnum_ImFontAtlasFlags(lua);
  InitEnum_ImFontFlags(lua);
  InitEnum_ImGuiBackendFlags(lua);
  InitEnum_ImGuiButtonFlags(lua);
  InitEnum_ImGuiChildFlags(lua);
  InitEnum_ImGuiCol(lua);
  InitEnum_ImGuiColorEditFlags(lua);
  InitEnum_ImGuiComboFlags(lua);
  InitEnum_ImGuiCond(lua);
  InitEnum_ImGuiConfigFlags(lua);
  InitEnum_ImGuiDataType(lua);
  InitEnum_ImGuiDir(lua);
  InitEnum_ImGuiDockNodeFlags(lua);
  InitEnum_ImGuiDragDropFlags(lua);
  InitEnum_ImGuiFocusedFlags(lua);
  InitEnum_ImGuiHoveredFlags(lua);
  InitEnum_ImGuiInputFlags(lua);
  InitEnum_ImGuiInputTextFlags(lua);
  InitEnum_ImGuiItemFlags(lua);
  InitEnum_ImGuiKey(lua);
  InitEnum_ImGuiListClipperFlags(lua);
  InitEnum_ImGuiMouseButton(lua);
  InitEnum_ImGuiMouseCursor(lua);
  InitEnum_ImGuiMouseSource(lua);
  InitEnum_ImGuiMultiSelectFlags(lua);
  InitEnum_ImGuiPopupFlags(lua);
  InitEnum_ImGuiSelectableFlags(lua);
  InitEnum_ImGuiSelectionRequestType(lua);
  InitEnum_ImGuiSliderFlags(lua);
  InitEnum_ImGuiSortDirection(lua);
  InitEnum_ImGuiStyleVar(lua);
  InitEnum_ImGuiTabBarFlags(lua);
  InitEnum_ImGuiTabItemFlags(lua);
  InitEnum_ImGuiTableBgTarget(lua);
  InitEnum_ImGuiTableColumnFlags(lua);
  InitEnum_ImGuiTableFlags(lua);
  InitEnum_ImGuiTableRowFlags(lua);
  InitEnum_ImGuiTreeNodeFlags(lua);
  InitEnum_ImGuiViewportFlags(lua);
  InitEnum_ImGuiWindowFlags(lua);
  InitEnum_ImTextureFormat(lua);
  InitEnum_ImTextureStatus(lua);
}
}  // namespace sol_ImGui
