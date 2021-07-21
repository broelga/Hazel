#include "hzpch.h"
#include "Application.h"

#include "Core.h"
#include "Hazel/Log.h"


#include <glad/glad.h>

namespace Hazel {

    Application *Application::s_Instance = nullptr;

    Application::Application() {

        HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushLayer(m_ImGuiLayer);


        glGenVertexArrays(1, &m_VertexArray);
        glBindVertexArray(m_VertexArray);

        glGenBuffers(1, &m_VertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

        float vertices[3 * 3] = {
                -0.5f, -0.5f, 0.0f, // Left side of the screen
                0.5f, -0.5f, 0.0f, // Right right of the screen
                0.0f, 0.5f, 0.0f // Top of screen
        };

        // Upload vertices to GPU
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0); // Enable index 0 of our data
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                              nullptr); // Describing data for OpenGL shader at index 0

        glGenBuffers(1, &m_IndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

        unsigned int indices[3] = {0, 1, 2};
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Provide source code to OpenGL
        /** @param a_Position the position of @vertices
         * adding to a_Position will change the location of vertices */
        // `R` (raw_characters) precursor allows you to write multi-line string
        std::string vertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;

            out vec3 v_Position;

            void main() {
                v_Position = a_Position;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        // (1.0f, 0.0f, 0.0f) == Red
        // (1.0f, 0.5f, 0.15f) == Orange
        std::string fragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            void main() {
                color = vec4(v_Position * 0.5 + 0.5, 1.0); // This moves color range from [-1,1] to [0,1] range
            }
        )";

        // Use std::reset to reset the shader
        m_Shader.reset(new Shader(vertexSrc, fragmentSrc));

    }

    Application::~Application() {}

    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer) {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
            (*--it)->OnEvent(e);
            if (e.Handled()) {
                break;
            }
        }
    }

    void Application::Run() {
        while (m_Running) {
            GLenum e = glGetError();
            if (e > 0) {
                HZ_CORE_ERROR("OpenGL error: {0}", e);
            }

            // Background color
            glClearColor(0.2f, 0.1f, 0.2f, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glBindVertexArray(m_VertexArray);
            m_Shader->Bind();
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

            for (Layer *layer : m_LayerStack) {
                layer->OnUpdate();
            }

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_LayerStack) {
                layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent(&e)) {
        m_Running = false;
        return true;
    }
}




