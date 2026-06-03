// Headless callability smoke test for the sol2 ImGui bindings.
//
// Creates a Lua state and a minimal headless ImGui frame, installs the bindings,
// runs tests/smoke/smoke.lua, and reports the script's pass/fail. This exercises
// the bindings for real (calling functions inside a live ImGui frame and
// checking return shapes), unlike a pure "does the table exist" check.
#include <cstdio>

#include "imgui.h"
#include "sol_ImGui.h"

int main(int argc, char** argv) {
    const char* script = (argc > 1) ? argv[1] : "tests/smoke/smoke.lua";

    // --- minimal headless ImGui context ---
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(1280, 720);
    io.IniFilename = nullptr;  // don't write imgui.ini during the test
    // Build a font atlas as raw bytes so NewFrame() has valid font data without
    // a renderer backend.
    unsigned char* pixels = nullptr;
    int w = 0, h = 0;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h);

    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::string,
                       sol::lib::table, sol::lib::math);
    sol_ImGui::Init(lua);

    ImGui::NewFrame();

    int rc = 0;
    try {
        sol::protected_function_result r = lua.script_file(script);
        if (!r.valid()) {
            sol::error err = r;
            std::fprintf(stderr, "smoke.lua error: %s\n", err.what());
            rc = 1;
        }
    } catch (const std::exception& e) {
        std::fprintf(stderr, "exception: %s\n", e.what());
        rc = 1;
    }

    ImGui::EndFrame();
    ImGui::DestroyContext();

    std::printf(rc == 0 ? "SMOKE: PASS\n" : "SMOKE: FAIL\n");
    return rc;
}
