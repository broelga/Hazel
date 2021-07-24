cmake_minimum_required(VERSION 3.19)
project(Hazel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 0) # Enable for more verbose CMake output

# -----------------------------------------------------------------
# Variables
# -----------------------------------------------------------------
set(TARGET_NAME "SandboxHazel")
set(SANDBOX_SOURCE_DIR "Sandbox/src")
set(PROJECT_SOURCE_DIR "${PROJECT_NAME}/src")
set(VENDOR_DIR "${PROJECT_NAME}/vendor")

# Vendor/Libraries
set(SPDLOG "${VENDOR_DIR}/spdlog")
set(GLAD "${VENDOR_DIR}/Glad")
set(IMGUI "${VENDOR_DIR}/imgui")
set(GLM "${VENDOR_DIR}/glm")

# -----------------------------------------------------------------
# Project
# -----------------------------------------------------------------
set(SANDBOX_SOURCES "${SANDBOX_SOURCE_DIR}/Sandbox.cpp")
file(GLOB_RECURSE PROJECT_SOURCES
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

set(VENDOR_SOURCES
        "${SPDLOG}/include/spdlog/spdlog.h" # For logging
        "${IMGUI}/imconfig.h"
        "${IMGUI}/imgui.cpp"
        "${IMGUI}/imgui_draw.cpp"
        "${IMGUI}/imgui_widgets.cpp"
        "${IMGUI}/imgui_tables.cpp"
        "${IMGUI}/imgui_demo.cpp"
        )

# -----------------------------------------------------------------
# Create executable
# -----------------------------------------------------------------
add_executable(${TARGET_NAME}
        "${SANDBOX_SOURCES}"
        "${PROJECT_SOURCES}"
        "${VENDOR_SOURCES}"
        )

target_include_directories(${TARGET_NAME} PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${VENDOR_DIR}"
        )

find_package(glfw3 3.3 REQUIRED)
add_subdirectory(${SPDLOG})
add_subdirectory(${GLAD})
add_subdirectory(${GLM})
add_subdirectory(${VENDOR_DIR}) # For GLFW/ImGui

target_link_libraries(${TARGET_NAME} PUBLIC
        "spdlog"
        "Glad"
        "glfw"
        "glm"
        "imgui"
        )

target_compile_definitions(${TARGET_NAME} PRIVATE
        "GLFW_INCLUDE_NONE" # Do not include OpenGL loader
        )

target_precompile_headers(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/hzpch.h")



