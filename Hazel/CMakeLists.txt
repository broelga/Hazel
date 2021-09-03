cmake_minimum_required(VERSION 3.20)
project(Hazel)
set(CMAKE_CXX_STANDARD 17)

###################################################################
# Local variables
###################################################################
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(PROJECT_VENDOR_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor")

# Vendor/Libraries
set(IMGUI "${PROJECT_VENDOR_DIR}/imgui")
set(GLAD "${PROJECT_VENDOR_DIR}/Glad")
set(GLFW "${PROJECT_VENDOR_DIR}/GLFW")
set(GLM "${PROJECT_VENDOR_DIR}/glm")
set(SPDLOG "${PROJECT_VENDOR_DIR}/spdlog")
set(STB "${PROJECT_VENDOR_DIR}/stb_image")

###################################################################
# Project Sources and add library
###################################################################
file(GLOB_RECURSE PROJECT_SOURCES
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

# Additional project sources (vendors, etc.)
list(APPEND PROJECT_SOURCES
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

# Add library
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_VENDOR_DIR}"
        )

###################################################################
# Libraries
###################################################################
add_subdirectory(${GLFW})
add_subdirectory(${SPDLOG})
add_subdirectory(${GLAD})
add_subdirectory(${GLM})
add_subdirectory(${PROJECT_VENDOR_DIR}) # ImGui

target_link_libraries(${PROJECT_NAME} PUBLIC
        "spdlog"
        "Glad"
        "glfw"
        "glm"
        "imgui"
        )

###################################################################
# Compiler options
###################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE=1)

if (APPLE)
#    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_definitions(${PROJECT_NAME} PUBLIC HZ_DEBUG=1 HZ_PLATFORM_OSX=1)
elseif (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC HZ_DEBUG=1 HZ_PLATFORM_WINDOWS=1 HZ_BUILD_DLL=1 BUILD_SHARED_LIBS=1)
endif ()

###################################################################
# Precompiled header
###################################################################
target_precompile_headers(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/hzpch.h")