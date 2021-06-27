#include <Marble.h>

class ExampleLayer : public Marble::Layer {
public:
    ExampleLayer()
            : Layer("Example") {}

    void OnUpdate() override {
        MRBL_INFO("ExampleLayer::Update");
    }

    void OnEvent(Marble::Event &event) override {
        MRBL_TRACE("{0}", event);
    }
};


namespace Marble {
    class Sandbox : public Marble::Application {
    public:
        Sandbox() {
            PushLayer(new ExampleLayer());
        }

        ~Sandbox() {}
    };

    Marble::Application *CreateApplication() {
        return new Sandbox();
    }
}