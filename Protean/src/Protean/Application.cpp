//
// Created by Joel Thomas on 6/17/21.
//

#include "Application.h"

#include "Protean/Events/ApplicationEvent.h"
#include "Protean/Log.h"

namespace Protean {

Application::Application() {}
Application::~Application() {}

[[noreturn]] void Application::Run() {
  WindowResizeEvent e(1280, 720);
  if (e.isInCategory(EventCategoryApplication)) {
	PT_TRACE(e);
  }
  if (e.isInCategory(EventCategoryInput)) {
	PT_TRACE(e);
  }

  while (true);
}

}




