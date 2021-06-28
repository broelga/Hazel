cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME Marble)
project(${PROJECT_NAME})

# Windows only
if (MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()

# Add subdirectories to project that contain CMakeFiles to include in build
add_subdirectory(${PROJECT_NAME}/vendors) # needed prior to main application
add_subdirectory(${PROJECT_NAME}) # main application

# Windows only
if (MSVC)
    if (${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message("\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set '${PROJECT_NAME}' as StartUp Project in Visual Studio.\n")
    else ()
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    endif ()
endif ()
