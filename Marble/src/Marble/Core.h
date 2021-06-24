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

#define BIT(x) (1 << x)

