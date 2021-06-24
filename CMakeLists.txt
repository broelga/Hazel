cmake_minimum_required(VERSION 3.19)
project(Marble)

set(CMAKE_CXX_STANDARD 17)




## Submodules

# Cotire
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)

# OpenGL / GLFW
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(Marble/vendor/GLFW/include)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(Marble/vendor/GLFW)




if (MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()




## Project
include_directories(
        Marble/src
        Marble/vendor/spdlog/include
        Sandbox/src)

add_executable(Marbled
        Sandbox/src/Sandbox.cpp
        Marble/src/Marble/Core.h Marble/src/Marble/Application.cpp
        Marble/src/Marble/Application.h Marble/src/Marble.h
        Marble/src/Marble/EntryPoint.h
        Marble/src/Marble/Log.h
        Marble/src/Marble/Log.cpp
        Marble/src/Marble/Events/ApplicationEvent.h Marble/src/Marble/Events/Event.h
        Marble/src/Marble/Events/KeyEvent.h Marble/src/Marble/Events/MouseEvent.h)

## Links
target_link_libraries(Marbled glfw ${GLFW_LIBRARIES})



## Precompiled headers
set_target_properties(Marbled PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "Marble/src/mrblpch.h")
cotire(Marbled)




if (MSVC)
    if (${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message("\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'Marbled' as StartUp Project in Visual Studio.\n")
    else ()
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Marbled)
    endif ()
endif ()

### Submodules:
#
## Cotire
#set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
#include(cotire)
#
## GLFW Library
#add_subdirectory(Marble/vendor/GLFW)
#set(glfw3_DIR "cmake-build-debug/Marble/vendor/GLFW/src/")
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#find_package(glfw3 3.1.2 REQUIRED)
#
### Project
#include_directories(
#        Marble/src
#        Marble/vendor/spdlog/include
#        Sandbox/src
#        Marble/vendor/GLFW/include)
#
#add_executable(
#        Marble
#        Sandbox/src/Sandbox.cpp
#        Marble/src/Marble/Core.h Marble/src/Marble/Application.cpp
#        Marble/src/Marble/Application.h Marble/src/Marble.h
#        Marble/src/Marble/EntryPoint.h
#        Marble/src/Marble/Log.h
#        Marble/src/Marble/Log.cpp
#        Marble/src/Marble/Events/ApplicationEvent.h Marble/src/Marble/Events/Event.h
#        Marble/src/Marble/Events/KeyEvent.h Marble/src/Marble/Events/MouseEvent.h)
#
### Library links
#target_link_libraries(Marble glfw)
#
### Handles precompiled headers
#set_target_properties(Marble PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "Marble/src/ptpch.h")
#cotire(Marble)
