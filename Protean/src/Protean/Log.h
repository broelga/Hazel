#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Protean {

  class PT_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

  };
} // End Protean namespace

// Core log macros
#define PT_CORE_TRACE(...)    ::Protean::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PT_CORE_INFO(...)     ::Protean::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PT_CORE_WARN(...)     ::Protean::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PT_CORE_ERROR(...)    ::Protean::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PT_CORE_FATAL(...)    ::Protean::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PT_TRACE(...)         ::Protean::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PT_INFO(...)          ::Protean::Log::GetClientLogger()->info(__VA_ARGS__)
#define PT_WARN(...)          ::Protean::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PT_ERROR(...)         ::Protean::Log::GetClientLogger()->error(__VA_ARGS__)
#define PT_FATAL(...)         ::Protean::Log::GetClientLogger()->fatal(__VA_ARGS__)
