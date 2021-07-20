#pragma once

int main(int argc, char **argv) {
    Hazel::Log::Init();
    HZ_CORE_WARN("Initialized Log!");
    int a = 5;
    HZ_INFO("Hello! Var={0}", a);

    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}

