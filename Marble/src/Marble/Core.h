#pragma once

#ifdef MRBL_PLATFORM_WINDOWS
#ifdef MRBL_BUILD_DLL
#define MRBL_API __declspec(dllexport)
#else
#define MRBL_API __declspec(dllimport)
#endif
#else
#define MRBL_API
#endif

#ifdef MRBL_ENABLE_ASSERTS
#define MRBL_ASSERT(x, ...) { if(!x)) { MRBL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define MRBL_CORE_ASSERT(x, ...) { if(!x)) { MRBL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define MRBL_ASSERT(x, ...)
#define MRBL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

