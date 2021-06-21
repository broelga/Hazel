
#include <Protean.h>

namespace Protean {
class Sandbox : public Protean::Application {
public:
  Sandbox() {}
  ~Sandbox() {}
};

Protean::Application *CreateApplication() {
  return new Sandbox();
}
}