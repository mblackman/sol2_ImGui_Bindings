cmake_minimum_required(VERSION 3.15)

project(
        sol2_ImGui_Bindings
        VERSION 1.91.8
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Define the Library Target ---
add_library(sol2_ImGui_Bindings STATIC)
add_library(sol2_ImGui_Bindings::sol2_ImGui_Bindings ALIAS sol2_ImGui_Bindings)

# --- Source Files ---
target_sources(sol2_ImGui_Bindings PRIVATE
        sol_ImGui.cpp
        sol_ImGui_Enums.cpp
        sol_ImGui_Windows.cpp
        sol_ImGui_Input.cpp
        sol_ImGui_Layout.cpp
        sol_ImGui_Popups.cpp
        sol_ImGui_Tables.cpp
        sol_ImGui_Widgets.cpp
        sol_ImGui_Utility.cpp
)

# --- Include Directories ---
target_include_directories(sol2_ImGui_Bindings
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# --- Dependency Management ---
if (NOT TARGET vcpkg::imgui)
    find_package(imgui CONFIG REQUIRED)
endif ()

if (NOT TARGET vcpkg::sol2)
    find_package(sol2 CONFIG REQUIRED)
endif ()

target_link_libraries(sol2_ImGui_Bindings PUBLIC
        imgui::imgui
)

# --- Installation & Package Configuration ---
include(CMakePackageConfigHelpers)

# 1. Configure the main package file. This file will contain the dependency checks.
configure_package_config_file(
        "sol2_ImGui_BindingsConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfig.cmake"
        INSTALL_DESTINATION lib/cmake/sol2_ImGui_Bindings
)

# 2. Generate the package version file. This uses the version from the project() command.
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion # Or ExactVersion if you prefer
)

# 3. Install public headers
install(
        FILES sol_ImGui.h # The public API header
        DESTINATION include
)

# 4. Install the library target and export it to a target-set
install(
        TARGETS sol2_ImGui_Bindings
        EXPORT sol2_ImGui_Bindings_Targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)

# 5. Install the export set and the generated config/version files
install(
        EXPORT sol2_ImGui_Bindings_Targets
        FILE sol2_ImGui_Bindings_Targets.cmake # Note: this file is referenced by Config.cmake
        NAMESPACE sol2_ImGui_Bindings::
        DESTINATION lib/cmake/sol2_ImGui_Bindings
)

install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/sol2_ImGui_BindingsConfigVersion.cmake"
        DESTINATION lib/cmake/sol2_ImGui_Bindings
)