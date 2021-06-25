#pragma once

int main(int argc, char **argv) {
    Marble::Log::Init();
    MRBL_CORE_WARN("Initialized Log!");
    int a = 5;
    MRBL_INFO("Hello! Var={0}", a);

    auto app = Marble::CreateApplication();
    app->Run();
    delete app;
}

