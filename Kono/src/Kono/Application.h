#pragma once

#include "Core.h"

#include "Window.h"
#include "Kono/LayerStack.h"
#include "Kono/Events/Event.h"
#include "Kono/Events/ApplicationEvent.h"

namespace Kono {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

// To be defined by CLIENT
    Application *CreateApplication();
}

