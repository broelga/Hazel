#pragma once

#ifdef KN_PLATFORM_WINDOWS
#ifdef KN_BUILD_DLL
#define KN_API __declspec(dllexport)
#else
#define KN_API __declspec(dllimport)
#endif
#else
#define KN_API
#endif

#ifdef KN_ENABLE_ASSERTS
#define KN_ASSERT(x, ...) { if(!x)) { KN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define KN_CORE_ASSERT(x, ...) { if(!x)) { KN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define KN_ASSERT(x, ...)
#define KN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

