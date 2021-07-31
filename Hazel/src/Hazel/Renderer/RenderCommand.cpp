#pragma once

#include "RenderCommand.h"

#include <Hazel/Platform/OpenGL/OpenGLRendererAPI.h>

#include <glad/glad.h>

namespace Hazel {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

    void RenderCommand::GetError() {
        GLenum e = glGetError();
        if (e > 0) {
            HZ_CORE_ERROR("OpenGL error: {0}", e);
        }
    }

}

