cmake_minimum_required(VERSION 3.19)
project(Protean)

set(CMAKE_CXX_STANDARD 17)

include_directories(Protean/src Protean/vendor/spdlog/include Sandbox/src)

add_executable(Protean
        Sandbox/src/Sandbox.cpp
        Protean/src/Protean/Core.h Protean/src/Protean/Application.cpp
        Protean/src/Protean/Application.h Protean/src/Protean.h
        Protean/src/Protean/EntryPoint.h Protean/src/Protean/Log.cpp
        Protean/src/Protean/Log.h Protean/src/Protean/Events/ApplicationEvent.h Protean/src/Protean/Events/Event.h Protean/src/Protean/Events/KeyEvent.h Protean/src/Protean/Events/MouseEvent.h)
