cmake_minimum_required(VERSION 3.19)
set(PROJECT_NAME Kono)
set(TARGET_NAME "Sandbox")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 0) # Enable for more verbose CMake output

# -----------------------------------------------------------------
# Variables
# -----------------------------------------------------------------
# Application
set(KONO_SRC_DIR "Kono/src")
set(VENDOR_DIR "Kono/vendor")

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

        "${KONO_SRC_DIR}/Kono.h"
        "${KONO_SRC_DIR}/Kono/Application.h"
        "${KONO_SRC_DIR}/Kono/Application.cpp"
        "${KONO_SRC_DIR}/Kono/Core.h"
        "${KONO_SRC_DIR}/Kono/EntryPoint.h"
        "${KONO_SRC_DIR}/Kono/Input.h"
        "${KONO_SRC_DIR}/Kono/Layer.h"
        "${KONO_SRC_DIR}/Kono/Layer.cpp"
        "${KONO_SRC_DIR}/Kono/Log.h"
        "${KONO_SRC_DIR}/Kono/Log.cpp"
        "${KONO_SRC_DIR}/Kono/LayerStack.cpp"
        "${KONO_SRC_DIR}/Kono/LayerStack.h"
        "${KONO_SRC_DIR}/Kono/Window.h"

        "${KONO_SRC_DIR}/Kono/Events/ApplicationEvent.h"
        "${KONO_SRC_DIR}/Kono/Events/Event.h"
        "${KONO_SRC_DIR}/Kono/Events/KeyEvent.h"
        "${KONO_SRC_DIR}/Kono/Events/MouseEvent.h"

        "${KONO_SRC_DIR}/Kono/ImGui/ImGuiBuild.cpp"
        "${KONO_SRC_DIR}/Kono/ImGui/ImGuiLayer.h"
        "${KONO_SRC_DIR}/Kono/ImGui/ImGuiLayer.cpp"

        "${KONO_SRC_DIR}/Kono/Platform/OSX/MacWindow.h"
        "${KONO_SRC_DIR}/Kono/Platform/OSX/MacWindow.cpp"
        "${KONO_SRC_DIR}/Kono/Platform/OSX/MacInput.cpp"
        "${KONO_SRC_DIR}/Kono/Platform/OSX/MacInput.h"

        "${KONO_SRC_DIR}/Kono/KeyCodes.h"
        "${KONO_SRC_DIR}/Kono/MouseButtonCodes.h"
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
        "${KONO_SRC_DIR}"
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

target_precompile_headers(${TARGET_NAME} PRIVATE "${KONO_SRC_DIR}/knpch.h")

if (APPLE)
    # Silence OpenGL depreciation warning
    if (NOT GL_SILENCE_DEPRECIATION)
        add_compile_definitions(GL_SILENCE_DEPRECIATION)
    endif ()
    set(CMAKE_MACOSX_RPATH 1)
endif ()



