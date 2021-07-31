#include <Hazel.h>

#include "imgui/imgui.h"

class ExampleLayer : public Hazel::Layer {
public:
    ExampleLayer()
            : Layer("Example    ") {
    }

    void OnUpdate() override {
        // Test key and mouse input
//        if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB)) {
//            HZ_TRACE("Tab key is pressed (poll)!");
//        }
//        if (Hazel::Input::IsMouseButtonPressed(HZ_MOUSE_BUTTON_RIGHT)) {
//            HZ_TRACE("Right mouse button is pressed (poll)!");
//        }
    }

    virtual void OnImGuiRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello World!");
        ImGui::End();
    }

    void OnEvent(Hazel::Event &event) override {
        // Test key and mouse events
//        if (event.GetEventType() == Hazel::EventType::KeyPressed) {
//            Hazel::KeyPressedEvent &e = (Hazel::KeyPressedEvent &) event;
//            if (e.GetKeyCode() == HZ_KEY_TAB) {
//                HZ_TRACE("{0}", "Tab key is pressed (event)!");
//            }
//            if ((e.GetKeyCode() == HZ_KEY_LEFT_SHIFT) || (e.GetKeyCode() == HZ_KEY_RIGHT_SHIFT)) {
//                HZ_TRACE("{0}", "Shift key is pressed (event)!");
//            }
//            if ((e.GetKeyCode() == HZ_KEY_LEFT_ALT) || (e.GetKeyCode() == HZ_KEY_RIGHT_ALT)) {
//                HZ_TRACE("{0}", "Alt key is pressed (event)!");
//            }
//            if ((e.GetKeyCode() == HZ_KEY_LEFT_CONTROL) || (e.GetKeyCode() == HZ_KEY_RIGHT_CONTROL)) {
//                HZ_TRACE("{0}", "Control key is pressed (event)!");
//            }
//            if ((e.GetKeyCode() == HZ_KEY_LEFT_SUPER) || (e.GetKeyCode() == HZ_KEY_RIGHT_SUPER)) {
//                HZ_TRACE("{0}", "Super key is pressed (event)!");
//            }
//            HZ_TRACE("{0}", (char) e.GetKeyCode());

//        }
    }
};

class Sandbox : public Hazel::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {}
};

Hazel::Application *Hazel::CreateApplication() {
    return new Sandbox();
}
