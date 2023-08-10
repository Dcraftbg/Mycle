#pragma once
#ifdef MCL_PLATFORM_WINDOWS
	#ifdef MCL_SHARED
		#ifdef MCL_BUILD
			#define	MCLAPI __declspec(dllexport)
		#else
			#define	MCLAPI __declspec(dllimport)
		#endif
	#else
		#error TODO: Handle non-shared lib case! :(
	#endif	

#else
	#error Unhandled platform! Sorry!
#endif


#define BIT(x) (1 << x)
#ifndef MCL_ASSERT
	#include <stdio.h>
	#include <stdlib.h>
	#define MCL_ASSERT(x) if (!(x)) {fprintf(stderr, "Error: Condition " #x " not met!"); exit(1);}
#endif
#ifndef MCL_MASSERT
	#include <stdio.h>
	#include <stdlib.h>
	#define MCL_MASSERT(x, ...) if (!(x)) {fprintf(stderr, "Error: "); fprintf(__VA_ARGS__); exit(1);}
#endif