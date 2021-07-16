#pragma once

#include "Kono/Core.h"

namespace Kono {

    class Input {
    public:
        inline static bool IsKeyPressed( int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

        inline static float IsMouseButtonPressed( int button) { return s_Instance->IsMouseButtonImpl(button); }

        inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

        inline static float GetMouseX(int button) { return s_Instance->GetMouseXImpl(); }

        inline static float GetMouseY( int button) { return s_Instance->GetMouseYImpl(); }

    protected:
        virtual bool IsKeyPressedImpl( int keycode) = 0;

        virtual bool IsMouseButtonImpl( int button) = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
    private:
        static Input *s_Instance;
    };
}