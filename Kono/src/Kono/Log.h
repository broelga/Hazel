#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Kono {

    class KN_API Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };
} // End Kono namespace

// Core log macros
#define KN_CORE_TRACE(...)    ::Kono::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KN_CORE_INFO(...)     ::Kono::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KN_CORE_WARN(...)     ::Kono::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KN_CORE_ERROR(...)    ::Kono::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KN_CORE_FATAL(...)    ::Kono::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KN_TRACE(...)         ::Kono::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KN_INFO(...)          ::Kono::Log::GetClientLogger()->info(__VA_ARGS__)
#define KN_WARN(...)          ::Kono::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KN_ERROR(...)         ::Kono::Log::GetClientLogger()->error(__VA_ARGS__)
#define KN_FATAL(...)         ::Kono::Log::GetClientLogger()->fatal(__VA_ARGS__)
