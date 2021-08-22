#include "OrthographicCameraController.h"

#include "Hazel/Core/Input.h"
#include "Hazel/Core/KeyCodes.h"
#include "Hazel/Core/MouseButtonCodes.h"

namespace Hazel {

    OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
            : m_AspectRatio(aspectRatio),
              m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel),
              m_Rotation(rotation) {
    }

    void OrthographicCameraController::OnUpdate(Timestep ts) {
        if (Input::IsKeyPressed(HZ_KEY_A)) {
            m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
        } else if (Hazel::Input::IsKeyPressed(HZ_KEY_D)) {
            m_CameraPosition.x += m_CameraTranslationSpeed * ts;
        }
        if (Input::IsKeyPressed(HZ_KEY_S)) {
            m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
        } else if (Hazel::Input::IsKeyPressed(HZ_KEY_W)) {
            m_CameraPosition.y += m_CameraTranslationSpeed * ts;
        }

        if (m_Rotation) {
            if (Input::IsKeyPressed(HZ_KEY_Q)) {
                m_CameraRotation -= m_CameraRotationSpeed * ts;
            }
            if (Hazel::Input::IsKeyPressed(HZ_KEY_E)) {
                m_CameraRotation += m_CameraRotationSpeed * ts;
            }

            m_Camera.SetRotation(m_CameraRotation);
        }

        // Reset camera
        if (Hazel::Input::IsKeyPressed(HZ_KEY_0) || Hazel::Input::IsMouseButtonPressed(HZ_MOUSE_BUTTON_MIDDLE)) {
            m_CameraPosition.x = 0.0f;
            m_CameraPosition.y = 0.0f;
            m_ZoomLevel = 1.0f;
            m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel,
                                   m_ZoomLevel);
        }

        m_Camera.SetPosition(m_CameraPosition);

        m_CameraTranslationSpeed = m_ZoomLevel;
    }

    void OrthographicCameraController::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnWindowResize));
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent &e) {
        m_ZoomLevel -= e.GetYOffset();
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f); // Clamp zoom
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);

        return false;
    }

    bool OrthographicCameraController::OnWindowResize(WindowResizeEvent &e) {
        m_ZoomLevel = (float) e.GetWidth() / (float) e.GetHeight();
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);

        return false;
    }

}
