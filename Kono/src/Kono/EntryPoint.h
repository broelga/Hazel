#pragma once

int main(int argc, char **argv) {
    Kono::Log::Init();
    KN_CORE_WARN("Initialized Log!");
    int a = 5;
    KN_INFO("Hello! Var={0}", a);

    auto app = Kono::CreateApplication();
    app->Run();
    delete app;
}

