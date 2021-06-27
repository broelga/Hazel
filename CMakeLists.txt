cmake_minimum_required(VERSION 3.19)
set(PROJECT_NAME Marble)
set(CMAKE_CXX_STANDARD 17)
project(${PROJECT_NAME})

# EXE_NAME is need for debug compiling. Rename if desired.
# GLFW creates PROJECT_NAME dir inside cmake-build-debug which
# causes naming conflict when creating PROJECT_NAME exe.
set(EXE_NAME "Marbled")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/Marble/src/")
set(PLATFORM_DIR "${CMAKE_SOURCE_DIR}/Marble/Platform")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/Marble/vendors")

if (MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()

## Project
set(SOURCES
        Sandbox/src/Sandbox.cpp
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
        ${LIB_DIR}/spdlog/include
        Sandbox/src)

add_executable(${EXE_NAME} ${SOURCES})

# Cotire (Handles precompiling)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)
set_target_properties(${EXE_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${SRC_DIR}/mrblpch.h")
cotire(${EXE_NAME})

# GLFW
set(GLFW_DIR "${LIB_DIR}/GLFW")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${EXE_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${EXE_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${EXE_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# Glad
set(GLAD_DIR "${LIB_DIR}/Glad")
add_library("Glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("Glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${EXE_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${EXE_NAME} "Glad" "${CMAKE_DL_LIBS}")

if (MSVC)
    if (${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message("\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set '${PROJECT_NAME}' as StartUp Project in Visual Studio.\n")
    else ()
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    endif ()
endif ()
