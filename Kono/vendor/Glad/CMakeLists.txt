cmake_minimum_required(VERSION 3.0)
project(Glad C CXX)

add_library(Glad include/glad/glad.h src/glad.c)
set(GLAD_SOURCES src/)
set(CMK ${CMAKE_CURRENT_BINARY_DIR}/glad-config.cmake)
set(CMK_TARGETS ${CMAKE_CURRENT_LIST_DIR}/cmake-build-debug/glad-targets.cmake)
set(GLAD_INSTALL ON)

target_include_directories(Glad
        INTERFACE
        $<BUILD_INTERFACE:${ROOT}>
        $<INSTALL_INTERFACE:include>
        Glad PUBLIC include/)


file(WRITE ${CMK} "include(${CMK_TARGETS})\n")