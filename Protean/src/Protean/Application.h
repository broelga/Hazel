//
// Created by Joel Thomas on 6/17/21.
//

#pragma once

namespace Protean {

class Application {
public:
  Application();
  virtual ~Application();

  [[noreturn]] void Run();
};

// To be defined by CLIENT
Application *CreateApplication();
}

