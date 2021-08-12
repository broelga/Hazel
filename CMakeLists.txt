cmake_minimum_required(VERSION 3.20)
project(Hazel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE 0) # Enable for more verbose CMake output

###################################################################
# Local variables
###################################################################
set(PROJECT_SOURCE_DIR "${PROJECT_NAME}/src")
set(PROJECT_VENDOR_DIR "${PROJECT_NAME}/vendor")
set(SANDBOX_DIR "Sandbox")
set(TARGET_NAME "SandboxApp")

# Vendor/Libraries
set(IMGUI "${PROJECT_VENDOR_DIR}/imgui")
set(GLAD "${PROJECT_VENDOR_DIR}/Glad")
set(GLFW "${PROJECT_VENDOR_DIR}/GLFW")
set(GLM "${PROJECT_VENDOR_DIR}/glm")
set(SPDLOG "${PROJECT_VENDOR_DIR}/spdlog")
set(STB "${PROJECT_VENDOR_DIR}/stb_image")

###################################################################
# Target sources and create executable
###################################################################
file(GLOB_RECURSE TARGET_SOURCES
        # Project sources -------------------------
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        # -----------------------------------------

        # Sandbox sources -------------------------
        "${SANDBOX_DIR}/src/*.h"
        "${SANDBOX_DIR}/src/*.cpp"
        # -----------------------------------------
        )

list(APPEND TARGET_SOURCES # Additional project sources
        # Vendor sources --------------------------
        "${IMGUI}/imconfig.h"
        "${IMGUI}/imgui.cpp"
        "${IMGUI}/imgui_draw.cpp"
        "${IMGUI}/imgui_widgets.cpp"
        "${IMGUI}/imgui_tables.cpp"
        "${IMGUI}/imgui_demo.cpp"

        "${SPDLOG}/include/spdlog/spdlog.h" # For logging

        "${STB}/stb_image.h"
        "${STB}/stb_image.cpp"
        # -----------------------------------------
        )

# Create executable
add_executable(${TARGET_NAME} "${TARGET_SOURCES}")

# Include directories
target_include_directories(${TARGET_NAME} PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_VENDOR_DIR}"
        "${SANDBOX_DIR}/src"
        "${SANDBOX_DIR}/assets"
        )

###################################################################
# Copy executable dependencies to CMake binary directory
###################################################################
file(GLOB SANDBOX_TEXTURES
        "${SANDBOX_DIR}/assets/textures/*.png"
        "${SANDBOX_DIR}/assets/textures/*jpg"
        )
# Copy textures
foreach (texture ${SANDBOX_TEXTURES})
    file(COPY "${texture}"
            DESTINATION "${CMAKE_BINARY_DIR}/assets/textures")
endforeach (texture)

###################################################################
# Libraries
###################################################################
find_package(glfw3 3.3 REQUIRED) # Do not use GLFW version 3.4+ due to GLFW_MOUSE_PASSTHROUGH bug.
add_subdirectory(${SPDLOG})
add_subdirectory(${GLAD})
add_subdirectory(${GLM})
add_subdirectory(${PROJECT_VENDOR_DIR}) # ImGui

target_link_libraries(${TARGET_NAME} PUBLIC
        "spdlog"
        "Glad"
        "glfw"
        "glm"
        "imgui"
        )

###################################################################
# Compiler options
###################################################################
target_compile_definitions(${TARGET_NAME} PRIVATE
        "GLFW_INCLUDE_NONE" # Do not include OpenGL loader
        )

###################################################################
# Precompiled header
###################################################################
target_precompile_headers(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/hzpch.h")



