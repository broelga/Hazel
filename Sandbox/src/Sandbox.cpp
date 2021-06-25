#include <Marble.h>

namespace Marble {
    class Sandbox : public Marble::Application {
    public:
        Sandbox() {}

        ~Sandbox() {}
    };

    Marble::Application *CreateApplication() {
        return new Sandbox();
    }
}