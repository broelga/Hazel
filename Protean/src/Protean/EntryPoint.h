#pragma once

int main(int argc, char **argv) {
  Protean::Log::Init();
  PT_CORE_WARN("Initialized Log!");
  int a = 5;
  PT_INFO("Hello! Var={0}", a);

  auto app = Protean::CreateApplication();
  app->Run();
  delete app;
}

