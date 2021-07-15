cmake_minimum_required(VERSION 3.19)
project(imgui)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(IMGUI_EXAMPLE_DIR "${IMGUI_DIR}/examples/example_glfw_opengl3")
set(GLFW_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
set(GLFW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/GLFW/include")

set(IMGUI_SOURCES
        "${IMGUI_DIR}/imgui_draw.cpp"
        "${IMGUI_DIR}/imgui.cpp"
        "${IMGUI_DIR}/imgui_demo.cpp"
        "${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
        )

set(IMGUI_HEADERS
        "${IMGUI_DIR}/imgui.h"
        "${IMGUI_DIR}/imconfig.h"
        "${IMGUI_DIR}/imstb_rectpack.h"
        "${IMGUI_DIR}/imstb_truetype.h"
        "${IMGUI_DIR}/imgui_internal.h"
        "${IMGUI_DIR}/imstb_textedit.h"
        "${IMGUI_DIR}/backends/imgui_impl_glfw.h"
        )

add_library(imgui STATIC
        "${IMGUI_HEADERS}"
        "${IMGUI_SOURCES}"
        )

target_include_directories(imgui PUBLIC
        "$<BUILD_INTERFACE:${IMGUI_DIR}>"
        "$<BUILD_INTERFACE:${IMGUI_EXAMPLE_DIR}>"
        "$<BUILD_INTERFACE:${GLFW_INCLUDE_DIR}>"
        )