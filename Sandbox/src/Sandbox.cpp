#include <Kono.h>

class ExampleLayer : public Kono::Layer {
public:
    ExampleLayer()
            : Layer("Example") {}

    void OnUpdate() override { KN_INFO("ExampleLayer::Update"); }

    void OnEvent(Kono::Event &event) override { KN_TRACE("{0}", event); }
};


class Sandbox : public Kono::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
        PushOverlay(new Kono::ImGuiLayer());
    }

    ~Sandbox() {}
};

Kono::Application *Kono::CreateApplication() {
    return new Sandbox();
}
