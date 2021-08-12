#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
    ExampleLayer();
    virtual void OnUpdate(Hazel::Timestep ts) override;

    virtual void OnImGuiRender() override;

    virtual void OnEvent(Hazel::Event &event) override;

private:
    Hazel::Ref<Hazel::Shader> m_Shader;
    Hazel::Ref<Hazel::VertexArray> m_VertexArray;

    Hazel::Ref<Hazel::Shader> m_FlatColorShader, m_TextureShader;
    Hazel::Ref<Hazel::VertexArray> m_SquareVA;

    Hazel::Ref<Hazel::Texture2D> m_Texture;

    Hazel::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraMoveSpeed = 0.45f;

    float m_CameraRotation = 0.0f;
    float m_CameraRotationSpeed = 30.0f;

    glm::vec3 m_SquareColor = {0.2f, 0.3f, 0.8f};

};