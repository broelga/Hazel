//
// Created by Joel Thomas on 6/17/21.
//

#pragma once

#ifdef PT_PLATFORM_WINDOWS
	#ifdef PT_BUILD_DLL
		#define PT_API __declspec(dllexport)
	#else
		#define PT_API __declspec(dllimport)
	#endif
#else
	#define PT_API
#endif

#define BIT(x) (1 << x)

