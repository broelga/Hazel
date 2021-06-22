//
#include "Application.h"

#include "Protean/Events/ApplicationEvent.h"
#include "Protean/Log.h"

namespace Protean {

  Application::Application() {}
  Application::~Application() {}

  void Application::Run() {
	WindowResizeEvent e(1280, 720);
	if (e.isInCategory(EventCategoryApplication)) {
	  PT_TRACE(e);
	}
	if (e.isInCategory(EventCategoryInput)) {
	  PT_ERROR(e);
	}
	if (e.isInCategory(EventCategoryApplication)) {
	  PT_CORE_ERROR(e);
	}

	while (true) {
	}
  }

}




