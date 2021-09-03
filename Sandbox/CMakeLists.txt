cmake_minimum_required(VERSION 3.20)
project(HazelSandbox)
set(CMAKE_CXX_STANDARD 17)

###################################################################
# Local variables
###################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(PROJECT_DIR "${CMAKE_CURRENT_LIST_DIR} ")
set(PROJECT_SOURCE_DIR "${PROJECT_DIR}/src")
set(PROJECT_ASSETS_DIR "${PROJECT_DIR}/assets")

# Libraries
set(HAZEL_DIR "${CMAKE_SOURCE_DIR}/Hazel")
set(HAZEL_LIB_DIR "${CMAKE_BINARY_DIR}/Hazel")

###################################################################
# Target sources and create executable
###################################################################
file(GLOB_RECURSE PROJECT_SOURCES
        "src/*.h"
        "src/*.cpp"
        )

list(APPEND PROJECT_SOURCES
        # Include glad w/ executable for linker
        "${HAZEL_DIR}/vendor/Glad/src/glad.c"
        "${HAZEL_DIR}/vendor/Glad/include/glad/glad.h"
        )

# Create executable
add_executable(${PROJECT_NAME} "${PROJECT_SOURCES}")

# Link libraries
target_link_libraries(${PROJECT_NAME} "Hazel")

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_ASSETS_DIR}"
        "${PROJECT_SOURCE_DIR}"

        "${HAZEL_LIB_DIR}/src"
        "${HAZEL_LIB_DIR}/vendor"
        )

###################################################################
# Copy executable dependencies to CMake runtime output directory
###################################################################
if (WIN32)
    # Copy library dlls -------------------------------------------
    file(GLOB_RECURSE LIB_DLLS
            "${HAZEL_LIB_DIR}/*.dll"
            )

    foreach (dll ${LIB_DLLS})
        file(COPY ${dll}
                DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach (dll)
    # -------------------------------------------------------------
endif ()

add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
        )

add_dependencies(${PROJECT_NAME} copy_assets)
# -----------------------------------------------------------------