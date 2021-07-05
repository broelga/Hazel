set(_IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(_IMGUI_EXAMPLE_DIR "${_IMGUI_DIR}/examples/example_glfw_opengl3")
set(GLFW_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
set(GLFW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/GLFW/include")

set(_IMGUI_SOURCES
        "${_IMGUI_DIR}/imgui_draw.cpp"
        "${_IMGUI_DIR}/imgui.cpp"
        "${_IMGUI_DIR}/imgui_demo.cpp"
        "${_IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
        )

set(_IMGUI_HEADERS
        "${_IMGUI_DIR}/imgui.h"
        "${_IMGUI_DIR}/imconfig.h"
        "${_IMGUI_DIR}/imstb_rectpack.h"
        "${_IMGUI_DIR}/imstb_truetype.h"
        "${_IMGUI_DIR}/imgui_internal.h"
        "${_IMGUI_DIR}/imstb_textedit.h"
        "${_IMGUI_DIR}/backends/imgui_impl_glfw.h"
        )


add_library(imgui STATIC
        "${_IMGUI_HEADERS}"
        "${_IMGUI_SOURCES}"
        )


target_include_directories(imgui PUBLIC
        "$<BUILD_INTERFACE:${_IMGUI_DIR}>"
        "$<BUILD_INTERFACE:${_IMGUI_EXAMPLE_DIR}>"
        "$<BUILD_INTERFACE:${GLFW_INCLUDE_DIR}>"
        )
