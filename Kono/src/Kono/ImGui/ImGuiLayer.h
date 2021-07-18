#pragma once

#include "Kono/Layer.h"

#include "Kono/Events/ApplicationEvent.h"
#include "Kono/Events/MouseEvent.h"
#include "Kono/Events/KeyEvent.h"

namespace Kono {

    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}
