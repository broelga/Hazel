#pragma once

#include <Marble/Events/ApplicationEvent.h>
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

#define GL_SILENCE_DEPRECATION

namespace Marble {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

// To be defined by CLIENT
    Application *CreateApplication();
}

