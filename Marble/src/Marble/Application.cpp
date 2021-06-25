#include "mrblpch.h"
#include "Application.h"

#include "Marble/Events/ApplicationEvent.h"
#include "Marble/Log.h"

namespace Marble {

    Application::Application() {}

    Application::~Application() {}

    void Application::Run() {
        WindowResizeEvent e(1280, 720);
        if (e.isInCategory(EventCategoryApplication)) {
            MRBL_TRACE(e);
        }
        if (e.isInCategory(EventCategoryInput)) {
            MRBL_ERROR(e);
        }
        if (e.isInCategory(EventCategoryApplication)) {
            MRBL_CORE_ERROR(e);
        }

        while (true) {
        }
    }

}




