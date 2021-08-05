#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
    ExampleLayer();
    virtual void OnUpdate(Hazel::Timestep ts) override;

    virtual void OnImGuiRender() override;

    virtual void OnEvent(Hazel::Event &event) override;

private:
    std::shared_ptr<Hazel::Shader> m_Shader;
    std::shared_ptr<Hazel::VertexArray> m_VertexArray;

    std::shared_ptr<Hazel::Shader> m_FlatColorShader;
    std::shared_ptr<Hazel::VertexArray> m_SquareVA;

    Hazel::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraMoveSpeed = 0.45f;

    float m_CameraRotation = 0.0f;
    float m_CameraRotationSpeed = 30.0f;

    glm::vec3 m_SquareColor = {0.2f, 0.3f, 0.8f};

};