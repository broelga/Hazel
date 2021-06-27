#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Marble {

    class MRBL_API Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };
} // End Marble namespace

// Core log macros
#define MRBL_CORE_TRACE(...)    ::Marble::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MRBL_CORE_INFO(...)     ::Marble::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MRBL_CORE_WARN(...)     ::Marble::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MRBL_CORE_ERROR(...)    ::Marble::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MRBL_CORE_FATAL(...)    ::Marble::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MRBL_TRACE(...)         ::Marble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MRBL_INFO(...)          ::Marble::Log::GetClientLogger()->info(__VA_ARGS__)
#define MRBL_WARN(...)          ::Marble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MRBL_ERROR(...)         ::Marble::Log::GetClientLogger()->error(__VA_ARGS__)
#define MRBL_FATAL(...)         ::Marble::Log::GetClientLogger()->fatal(__VA_ARGS__)
