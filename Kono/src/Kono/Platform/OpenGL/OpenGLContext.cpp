#include "knpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Kono {

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
            : m_WindowHandle(windowHandle) {
        KN_CORE_ASSERT(windowHandle, "Window Handle is null!")
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        KN_CORE_ASSERT(status, "Failed to initialize Glad!");
    }

    void OpenGLContext::SwapBuffers() {
//        glBegin(GL_TRIANGLES);
//        glEnd();

        glfwSwapBuffers(m_WindowHandle);
    }
}