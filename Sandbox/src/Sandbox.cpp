#include <Kono.h>

class ExampleLayer : public Kono::Layer {
public:
    ExampleLayer()
            : Layer("Example") {}

    void OnUpdate() override {
        KN_INFO("ExampleLayer::Update");
    }

    void OnEvent(Kono::Event &event) override {
        KN_TRACE("{0}", event);
    }
};


namespace Kono {
    class Sandbox : public Kono::Application {
    public:
        Sandbox() {
            PushLayer(new ExampleLayer());
        }

        ~Sandbox() {}
    };

    Kono::Application *CreateApplication() {
        return new Sandbox();
    }
}