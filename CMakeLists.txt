cmake_minimum_required(VERSION 3.15)

project(
        sol2_ImGui_Bindings
        VERSION 1.92.7  # tracks the Dear ImGui version the bindings target (see CONTRIBUTING.md)
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Define the Library Target ---
add_library(sol2_ImGui_Bindings STATIC)
add_library(sol2_ImGui_Bindings::sol2_ImGui_Bindings ALIAS sol2_ImGui_Bindings)

# --- Source Files ---
# The bulk of the bindings are generated from Dear ImGui metadata; the list of
# generated translation units lives in generated/sources.cmake (regenerate with
# the regen-bindings target below). The hand-written escape hatch and the public
# entry point are listed explicitly.
include(${CMAKE_CURRENT_SOURCE_DIR}/generated/sources.cmake)

target_sources(sol2_ImGui_Bindings PRIVATE
        sol_ImGui.cpp
        manual/sol_ImGui_Manual.cpp
        ${SOL_IMGUI_GENERATED_SOURCES}
)

# --- Include Directories ---
target_include_directories(sol2_ImGui_Bindings
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# --- Dependency Management ---
if (NOT TARGET imgui::imgui)
    find_package(imgui CONFIG REQUIRED)
endif ()

if (NOT TARGET sol2::sol2)
    find_package(sol2 CONFIG REQUIRED)
endif ()

target_link_libraries(sol2_ImGui_Bindings PUBLIC
        imgui::imgui
        sol2::sol2
)

# --- Binary size ---
# sol2 binds via heavy templates; the generated wrappers are many small, often
# near-identical functions. Put each in its own section so the consumer's linker
# can garbage-collect unused ones and fold identical ones (ICF). This is safe and
# free; the consumer still needs --gc-sections / -Wl,--icf=all (or MSVC
# /OPT:REF,ICF) at final link to benefit. See README "Binary size".
target_compile_options(sol2_ImGui_Bindings PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-ffunction-sections;-fdata-sections>
        $<$<CXX_COMPILER_ID:MSVC>:/Gy;/Gw>
)

# Opt-in: optimize the bindings' own object code for size (-Os / /O1) and enable
# link-time optimization for this target. Off by default so it doesn't fight the
# consumer's chosen optimization level.
option(SOL2_IMGUI_BINDINGS_SIZE_OPT "Build the bindings optimized for size (-Os + LTO)" OFF)
if (SOL2_IMGUI_BINDINGS_SIZE_OPT)
    target_compile_options(sol2_ImGui_Bindings PRIVATE
            $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Os>
            $<$<CXX_COMPILER_ID:MSVC>:/O1>
    )
    include(CheckIPOSupported)
    check_ipo_supported(RESULT _ipo_ok OUTPUT _ipo_msg)
    if (_ipo_ok)
        set_target_properties(sol2_ImGui_Bindings PROPERTIES INTERPROCEDURAL_OPTIMIZATION ON)
    endif ()
endif ()

# --- Code generation (developer-only) ---
# Regenerates generated/ from codegen/metadata/dcimgui.json. Not part of the
# normal build: the generated sources are committed so consumers need no Python.
find_package(Python3 COMPONENTS Interpreter QUIET)
if (Python3_FOUND)
    add_custom_target(regen-bindings
            COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/codegen/generate.py
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Regenerating sol2 ImGui bindings from metadata"
            VERBATIM)

    # Drift gate: fails if the committed generated/ is stale (used by CI).
    add_custom_target(check-bindings
            COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/codegen/generate.py --check
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Checking generated bindings are in sync with metadata"
            VERBATIM)
endif ()

# --- Callability smoke test (opt-in; CI turns this on) ---
# Standalone consumers (and the engine, which adds this as a subdirectory) leave
# it off. CI builds with -DSOL2_IMGUI_BINDINGS_BUILD_TESTS=ON.
option(SOL2_IMGUI_BINDINGS_BUILD_TESTS "Build the headless callability smoke test" OFF)
if (SOL2_IMGUI_BINDINGS_BUILD_TESTS)
    enable_testing()
    find_package(Lua REQUIRED)
    add_executable(sol_imgui_smoke tests/smoke/smoke_main.cpp)
    target_link_libraries(sol_imgui_smoke PRIVATE sol2_ImGui_Bindings ${LUA_LIBRARIES})
    target_include_directories(sol_imgui_smoke PRIVATE ${LUA_INCLUDE_DIR})
    add_test(NAME sol_imgui_smoke
            COMMAND sol_imgui_smoke ${CMAKE_CURRENT_SOURCE_DIR}/tests/smoke/smoke.lua)
endif ()

# --- Install / export (so consumers can find_package this) ---
# On by default only when configured standalone; harmless to leave off when added
# via add_subdirectory()/FetchContent (the alias target is enough there).
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(_sib_install_default ON)
else ()
    set(_sib_install_default OFF)
endif ()
option(SOL2_IMGUI_BINDINGS_INSTALL "Generate install + find_package config" ${_sib_install_default})
if (SOL2_IMGUI_BINDINGS_INSTALL)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)
    # Preserve the sol_ImGui.h -> generated/ , manual/ relative includes on install.
    install(FILES sol_ImGui.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(FILES generated/sol_ImGui_Generated.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/generated)
    install(FILES manual/sol_ImGui_Manual.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/manual)
    install(TARGETS sol2_ImGui_Bindings EXPORT sol2_ImGui_BindingsTargets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
    install(EXPORT sol2_ImGui_BindingsTargets
            NAMESPACE sol2_ImGui_Bindings::
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sol2_ImGui_Bindings)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfigVersion.cmake"
            VERSION ${PROJECT_VERSION} COMPATIBILITY SameMinorVersion)
    # Minimal config: re-find the public deps, then pull in the exported target.
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfig.cmake"
[=[include(CMakeFindDependencyMacro)
find_dependency(imgui CONFIG)
find_dependency(sol2 CONFIG)
include("${CMAKE_CURRENT_LIST_DIR}/sol2_ImGui_BindingsTargets.cmake")
]=])
    install(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfig.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfigVersion.cmake"
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sol2_ImGui_Bindings)
endif ()
