#pragma once

#include "Kono/Renderer/GraphicsContext.h"

class GLFWwindow;

namespace Kono {

    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow *m_WindowHandle;
    };
}