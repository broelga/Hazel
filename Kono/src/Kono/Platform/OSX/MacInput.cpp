#include "knpch.h"
#include "MacInput.h"

#include "Kono/Application.h"

#include <GLFW/glfw3.h>

namespace Kono {

    Input* Input::s_Instance = new MacInput;

    bool MacInput::IsKeyPressedImpl(int keycode) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);

        // Check if this key is currently pressed
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacInput::IsMouseButtonImpl(const int button) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> MacInput::GetMousePositionImpl() {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {static_cast<float>(xpos), static_cast<float>(ypos)};
    }

    float MacInput::GetMouseXImpl() {
        auto[x, y] = GetMousePositionImpl();
        return x;
    }


    float MacInput::GetMouseYImpl() {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }

}