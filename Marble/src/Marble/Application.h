#pragma once

#include "Core.h"
#include "Events//Event.h"
#include "Window.h"

#define GL_SILENCE_DEPRECATION

namespace Marble {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

// To be defined by CLIENT
    Application *CreateApplication();
}

