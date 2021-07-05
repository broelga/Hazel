cmake_minimum_required(VERSION 3.19)
set(CMAKE_VERBOSE_MAKEFILE 0) # Enable for more verbose CMake output
set(CMAKE_MACOSX_RPATH 1)

set(PROJECT_NAME Kono)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)

# Create project config file
configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)


# -----------------------------------------------------------------
# Project variables
# -----------------------------------------------------------------
# Project
set(_TARGET_NAME "${PROJECT_NAME}_app")
set(_SANDBOX_DIR "${CMAKE_SOURCE_DIR}/Sandbox")
set(_APP_DIR "${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}")

# Application
set(_PLATFORM_DIR "${_APP_DIR}/Platform")
set(_SOURCE_DIR "${_APP_DIR}/src")
set(_VENDOR_DIR "${_APP_DIR}/vendor")

# Vendor/Libraries
set(_SPDLOG_DIR "${_VENDOR_DIR}/spdlog")
set(_COTIRE_DIR "${_VENDOR_DIR}/cotire")
set(_GLAD_DIR "${_VENDOR_DIR}/Glad")
set(_GLFW_DIR "${_VENDOR_DIR}/GLFW")
set(_IMGUI_DIR "${_VENDOR_DIR}/imgui")


# -----------------------------------------------------------------
# Output directories
# -----------------------------------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


# -----------------------------------------------------------------
# Project subdirectories
# -----------------------------------------------------------------
if (APPLE)
    # Silence OpenGL depreciation warning
    if (NOT GL_SILENCE_DEPRECIATION)
        add_compile_definitions(GL_SILENCE_DEPRECIATION)
    endif ()
endif (APPLE)

find_package(glfw3 3.3 REQUIRED)
add_subdirectory(${_COTIRE_DIR})
add_subdirectory(${_SPDLOG_DIR})
add_subdirectory(${_GLAD_DIR})
add_subdirectory(${_VENDOR_DIR}) # For GLFW/ImGui


# -----------------------------------------------------------------
# Project sources
# -----------------------------------------------------------------
# Project headers
set(_PROJECT_HEADERS
        # DIR: Kono/src
        "${_SOURCE_DIR}/Kono.h"

        # DIR: Kono/src/Kono
        "${_SOURCE_DIR}/${PROJECT_NAME}/Application.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Core.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/EntryPoint.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Layer.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/LayerStack.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Log.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Window.h"

        # DIR: Kono/src/Kono/Events
        "${_SOURCE_DIR}/${PROJECT_NAME}/Events/ApplicationEvent.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Events/Event.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Events/KeyEvent.h"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Events/MouseEvent.h"

        # DIR: Kono/src/Kono/ImGui
        "${_SOURCE_DIR}/${PROJECT_NAME}/ImGui/ImGuiLayer.h"

        # DIR: Kono/Platform/OSX
        "${_PLATFORM_DIR}/OSX/MacWindow.h"

        # DIR: Kono/Platform/OpenGL
        )


# Project sources
set(_PROJECT_SOURCES
        # DIR: Sandbox
        "${_SANDBOX_DIR}/src/Sandbox.cpp"

        # DIR: Kono/src/Kono
        "${_SOURCE_DIR}/${PROJECT_NAME}/Application.cpp"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Layer.cpp"
        "${_SOURCE_DIR}/${PROJECT_NAME}/LayerStack.cpp"
        "${_SOURCE_DIR}/${PROJECT_NAME}/Log.cpp"

        # DIR: Kono/src/Kono/ImGui
        "${_SOURCE_DIR}/${PROJECT_NAME}/ImGui/ImGuiLayer.cpp"

        # DIR: Kono/Platform/OSX
        "${_PLATFORM_DIR}/OSX/MacWindow.cpp"

        # DIR: Kono/Platform/OpenGL
        )


# ImGui sources
set(_IMGUI_SOURCES
        "${_IMGUI_DIR}/imconfig.h"
        "${_IMGUI_DIR}/imgui.cpp"
        "${_IMGUI_DIR}/imgui_draw.cpp"
        "${_IMGUI_DIR}/imgui_widgets.cpp"
        "${_IMGUI_DIR}/imgui_tables.cpp"
        "${_IMGUI_DIR}/imgui_demo.cpp"
        "${_IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
        "${_IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
        )

# Vendor sources
set(_VENDOR_SOURCES
        "${_SPDLOG_DIR}/include/spdlog/spdlog.h" # For logging
        "${_IMGUI_SOURCES}" # imgui sources
        )


# -----------------------------------------------------------------
# Add sources to project and create executable
# -----------------------------------------------------------------
add_executable(${_TARGET_NAME}
        "${_PROJECT_SOURCES}"
        "${_PROJECT_SOURCES}"
        "${_VENDOR_SOURCES}"
        )


# -----------------------------------------------------------------
# Include directories
# -----------------------------------------------------------------
target_include_directories(${_TARGET_NAME} PUBLIC
        # Project
        "${PROJECT_BINARY_DIR}"
        "${_SOURCE_DIR}"

        # Vendors
        "${_COTIRE_DIR}"
        "${_SPDLOG_DIR}"
        "${_GLFW_DIR}"
        "${_GLAD_DIR}"
        "${_IMGUI_DIR}"
        )


# -----------------------------------------------------------------
# Additional libraries
# -----------------------------------------------------------------
set(_EXTRA_LIBS
        # Vendor libraries
        "spdlog"
        "glfw"
        "Glad"
        "imgui"
        )


# -----------------------------------------------------------------
# Library links
# -----------------------------------------------------------------
target_link_libraries(${_TARGET_NAME} PUBLIC
        "${_EXTRA_LIBS}"
        )


# -----------------------------------------------------------------
# Compiler options
# -----------------------------------------------------------------
target_compile_definitions(${_TARGET_NAME} PRIVATE
        "GLFW_INCLUDE_NONE" # Do not include OpenGL loader
        )


# -----------------------------------------------------------------
# Use Cotire to precompile headers
# -----------------------------------------------------------------
set(CMAKE_MODULE_PATH "${_COTIRE_DIR}/CMake")
include(cotire)

# Add precompiled headers
set(_PROJECT_PCH
        "${_SOURCE_DIR}/knpch.h"
        )

set_target_properties(${_TARGET_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${_PROJECT_PCH}")
cotire(${_TARGET_NAME})


# -----------------------------------------------------------------
# Display debug information upon build
# -----------------------------------------------------------------
set(CMAKE_DEBUG_TARGET_PROPERTIES
        "INCLUDE_DIRECTORIES"
        "COMPILE_DEFINITIONS"
        "POSITION_INDEPENDENT_CODE"
        "CONTAINER_SIZE_REQUIRED"
        "LIB_VERSION"
        )





