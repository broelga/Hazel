#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
    ExampleLayer();
    virtual void OnUpdate(Hazel::Timestep ts) override;

    virtual void OnImGuiRender() override;

    virtual void OnEvent(Hazel::Event &e) override;

private:
    Hazel::ShaderLibrary m_ShaderLibrary;
    Hazel::Ref<Hazel::Shader> m_Shader;
    Hazel::Ref<Hazel::VertexArray> m_VertexArray;

    Hazel::Ref<Hazel::Shader> m_FlatColorShader;
    Hazel::Ref<Hazel::VertexArray> m_SquareVA;

    Hazel::Ref<Hazel::Texture2D> m_Texture, m_BLogoTexture;

    Hazel::OrthographicCameraController m_CameraController;
    float m_CameraSpeed = 1.0f;

    glm::vec3 m_SquareColor = {0.2f, 0.3f, 0.8f};

};