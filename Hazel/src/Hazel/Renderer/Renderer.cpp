#include "hzpch.h"
#include "Renderer.h"

#include <glad/glad.h> // for GLenum and glGetError()

namespace Hazel {

    void Renderer::BeginScene() {
    }


    void Renderer::EndScene() {

    }

    void Renderer::Submit(const std::shared_ptr<VertexArray> &vertexArray) {
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }

}
