cmake_minimum_required(VERSION 3.19)
set(PROJECT_NAME "Hazel")
set(TARGET_NAME "SandboxHazel")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 0) # Enable for more verbose CMake output

# -----------------------------------------------------------------
# Variables
# -----------------------------------------------------------------
# Application
set(HAZEL_SRC_DIR "Hazel/src")
set(VENDOR_DIR "Hazel/vendor")

# Vendor/Libraries
set(SPDLOG_DIR "${VENDOR_DIR}/spdlog")
set(GLAD_DIR "${VENDOR_DIR}/Glad")
set(GLFW_DIR "${VENDOR_DIR}/GLFW")
set(IMGUI_DIR "${VENDOR_DIR}/imgui")
set(GLM_DIR "${VENDOR_DIR}/glm")

# -----------------------------------------------------------------
# Project
# -----------------------------------------------------------------
set(PROJECT_SOURCES
        "Sandbox/src/Sandbox.cpp"

        "${HAZEL_SRC_DIR}/Hazel.h"
        "${HAZEL_SRC_DIR}/Hazel/Application.h"
        "${HAZEL_SRC_DIR}/Hazel/Application.cpp"
        "${HAZEL_SRC_DIR}/Hazel/Core.h"
        "${HAZEL_SRC_DIR}/Hazel/EntryPoint.h"
        "${HAZEL_SRC_DIR}/Hazel/Input.h"
        "${HAZEL_SRC_DIR}/Hazel/Layer.h"
        "${HAZEL_SRC_DIR}/Hazel/Layer.cpp"
        "${HAZEL_SRC_DIR}/Hazel/Log.h"
        "${HAZEL_SRC_DIR}/Hazel/Log.cpp"
        "${HAZEL_SRC_DIR}/Hazel/LayerStack.cpp"
        "${HAZEL_SRC_DIR}/Hazel/LayerStack.h"
        "${HAZEL_SRC_DIR}/Hazel/Window.h"
        "${HAZEL_SRC_DIR}/Hazel/KeyCodes.h"
        "${HAZEL_SRC_DIR}/Hazel/MouseButtonCodes.h"

        "${HAZEL_SRC_DIR}/Hazel/Events/ApplicationEvent.h"
        "${HAZEL_SRC_DIR}/Hazel/Events/Event.h"
        "${HAZEL_SRC_DIR}/Hazel/Events/KeyEvent.h"
        "${HAZEL_SRC_DIR}/Hazel/Events/MouseEvent.h"

        "${HAZEL_SRC_DIR}/Hazel/ImGui/ImGuiBuild.cpp"
        "${HAZEL_SRC_DIR}/Hazel/ImGui/ImGuiLayer.h"
        "${HAZEL_SRC_DIR}/Hazel/ImGui/ImGuiLayer.cpp"

        "${HAZEL_SRC_DIR}/Hazel/Platform/OpenGL/OpenGLContext.h"
        "${HAZEL_SRC_DIR}/Hazel/Platform/OpenGL/OpenGLContext.cpp"
        "${HAZEL_SRC_DIR}/Hazel/Platform/OSX/MacWindow.h"
        "${HAZEL_SRC_DIR}/Hazel/Platform/OSX/MacWindow.cpp"
        "${HAZEL_SRC_DIR}/Hazel/Platform/OSX/MacInput.cpp"
        "${HAZEL_SRC_DIR}/Hazel/Platform/OSX/MacInput.h"

        "${HAZEL_SRC_DIR}/Hazel/Renderer/GraphicsContext.h"
        )

set(VENDOR_SOURCES
        "${SPDLOG_DIR}/include/spdlog/spdlog.h" # For logging

        "${IMGUI_DIR}/imconfig.h"
        "${IMGUI_DIR}/imgui.cpp"
        "${IMGUI_DIR}/imgui_draw.cpp"
        "${IMGUI_DIR}/imgui_widgets.cpp"
        "${IMGUI_DIR}/imgui_tables.cpp"
        "${IMGUI_DIR}/imgui_demo.cpp"
        )

# -----------------------------------------------------------------
# Create executable
# -----------------------------------------------------------------
add_executable(${TARGET_NAME}
        "${PROJECT_SOURCES}"
        "${VENDOR_SOURCES}"
        )

target_include_directories(${TARGET_NAME} PUBLIC
        "${HAZEL_SRC_DIR}"
        "${VENDOR_DIR}"
        )

find_package(glfw3 3.3 REQUIRED)
add_subdirectory(${SPDLOG_DIR})
add_subdirectory(${GLAD_DIR})
add_subdirectory(${GLM_DIR})
add_subdirectory(${VENDOR_DIR}) # For GLFW/ImGui

target_link_libraries(${TARGET_NAME} PUBLIC
        "spdlog"
        "Glad"
        "glfw"
        "glm"
        "imgui"
        )

target_compile_definitions(${TARGET_NAME} PRIVATE "GLFW_INCLUDE_NONE") # Do not include OpenGL loader

target_precompile_headers(${TARGET_NAME} PRIVATE "${HAZEL_SRC_DIR}/hzpch.h")



