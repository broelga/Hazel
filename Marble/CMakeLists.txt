## -- Use this file for the main application -- ##

set(PROJECT_NAME Marble)
project(${PROJECT_NAME})

# Local variables
set(SRC_DIR "${CMAKE_SOURCE_DIR}/Marble/src")
set(PLATFORM_DIR "${CMAKE_SOURCE_DIR}/Marble/Platform")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/Marble/vendors")

## Project
set(SOURCES
        ../Sandbox/src/Sandbox.cpp
        ${SRC_DIR}/Marble/Application.h
        ${SRC_DIR}/Marble/Core.h ${SRC_DIR}/Marble/Application.cpp
        ${SRC_DIR}/Marble/EntryPoint.h
        ${SRC_DIR}/Marble/Log.h
        ${SRC_DIR}/Marble/Log.cpp
        ${SRC_DIR}/Marble/Events/ApplicationEvent.h ${SRC_DIR}/Marble/Events/Event.h
        ${SRC_DIR}/Marble/Events/KeyEvent.h ${SRC_DIR}/Marble/Events/MouseEvent.h
        ${SRC_DIR}/Marble/Window.h
        ${SRC_DIR}/Marble/Layer.cpp ${SRC_DIR}/Marble/Layer.h
        ${SRC_DIR}/Marble/LayerStack.cpp ${SRC_DIR}/Marble/LayerStack.h
        ${PLATFORM_DIR}/OSX/MacWindow.cpp ${PLATFORM_DIR}/OSX/MacWindow.h)

include_directories(
        ${SRC_DIR}
        ${SRC_DIR}/Marble
        ${LIB_DIR}/spdlog/include) # For logging

add_executable(${PROJECT_NAME}
        ${SOURCES})

# Use Cotire to precompile headers
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
set(COTIRE_DIR ${LIB_DIR}/cotire)
add_subdirectory(${COTIRE_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${SRC_DIR}/mrblpch.h")
include(cotire)
cotire(${PROJECT_NAME})

find_package(glfw3 REQUIRED)
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE") # Do not include OpenGL libs

target_include_directories(${PROJECT_NAME}
        PUBLIC
        external
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        spdlog
        glfw
        Glad
        imgui
#        glm
#        glm_static    # if build with add_subdirectory
        )