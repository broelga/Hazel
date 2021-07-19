#include "knpch.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECIATION
#endif

#define IMGUI_IMPL_OPENGL_LOADER_GLAD

#include "backends/imgui_impl_opengl3.cpp"
#include "backends/imgui_impl_glfw.cpp"