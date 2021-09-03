#pragma once

#include <memory> // for std::unique_ptr and std::shared_ptr

#ifdef HZ_PLATFORM_WINDOWS
#ifdef HZ_BUILD_DLL
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif
#else
#define HZ_PLATFORM_OSX
#endif

#if defined(__clang__)
#define DEBUG_BREAK __builtin_debugtrap()
#elif defined(_MSC_VER)
#define DEBUG_BREAK __debugbreak()
#endif

#ifdef HZ_DEBUG
#define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
#define HZ_ASSERT(x, ...) { if(!x) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
#define HZ_CORE_ASSERT(x, ...) { if(!x) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
#else
#define HZ_ASSERT(x, ...)
#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Hazel {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;

}

