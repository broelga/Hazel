#pragma once

#include "RendererAPI.h"

namespace Hazel {

    class RenderCommand {
    public:
        inline static void Init() { s_RendererAPI->Init(); }

        inline static void SetClearColor(const glm::vec4 &color) {
            s_RendererAPI->SetClearColor(color);
        };

        inline static void Clear() {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed(const Ref<VertexArray> &vertexArray) {
            s_RendererAPI->DrawIndexed(vertexArray);
        }

        /* Print glError, if any. */
        static void GetError();

    private:
        static RendererAPI *s_RendererAPI;
    };

}