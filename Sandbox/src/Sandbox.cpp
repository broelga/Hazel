#include <Kono.h>

#include "imgui/imgui.h"

class ExampleLayer : public Kono::Layer {
public:
    ExampleLayer()
            : Layer("Example") {
    }

    void OnUpdate() override {
        // Test key and mouse input
        if (Kono::Input::IsKeyPressed(KN_KEY_TAB)) {
            KN_TRACE("Tab key is pressed (poll)!");
        }
        if (Kono::Input::IsMouseButtonPressed(KN_MOUSE_BUTTON_RIGHT)) {
            KN_TRACE("Right mouse button is pressed (poll)!");
        }
    }

    virtual void OnImGuiRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello World!");
        ImGui::End();
    }

    void OnEvent(Kono::Event &event) override {
        // Test key and mouse events
        if (event.GetEventType() == Kono::EventType::KeyPressed) {
            Kono::KeyPressedEvent &e = (Kono::KeyPressedEvent &) event;
            if (e.GetKeyCode() == KN_KEY_TAB) {
                KN_TRACE("{0}", "Tab key is pressed (event)!");
            }
            if ((e.GetKeyCode() == KN_KEY_LEFT_SHIFT) || (e.GetKeyCode() == KN_KEY_RIGHT_SHIFT)) {
                KN_TRACE("{0}", "Shift key is pressed (event)!");
            }
            if ((e.GetKeyCode() == KN_KEY_LEFT_ALT) || (e.GetKeyCode() == KN_KEY_RIGHT_ALT)) {
                KN_TRACE("{0}", "Alt key is pressed (event)!");
            }
            if ((e.GetKeyCode() == KN_KEY_LEFT_CONTROL) || (e.GetKeyCode() == KN_KEY_RIGHT_CONTROL)) {
                KN_TRACE("{0}", "Control key is pressed (event)!");
            }
            if ((e.GetKeyCode() == KN_KEY_LEFT_SUPER) || (e.GetKeyCode() == KN_KEY_RIGHT_SUPER)) {
                KN_TRACE("{0}", "Super key is pressed (event)!");
            }
            KN_TRACE("{0}", (char) e.GetKeyCode());
        }
    }
};

class Sandbox : public Kono::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {}
};

Kono::Application *Kono::CreateApplication() {
    return new Sandbox();
}
