#pragma once

#include "Core.h"

#include "Window.h"
#include "Kono/LayerStack.h"
#include "Kono/Events/Event.h"
#include "Kono/Events/ApplicationEvent.h"

#include "ImGui/ImGuiLayer.h"

namespace Kono {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

        inline Window &GetWindow() { return *m_Window; }

        inline static Application &Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application *s_Instance;
    };

// To be defined by CLIENT
    Application *CreateApplication();
}

