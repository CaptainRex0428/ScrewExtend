#pragma once

#ifdef SCREW_EXTEND_BUILD_DLL_EXPORT
#define SE_API __declspec(dllexport)
#else
#ifdef SCREW_EXTEND_BUILD_LIB
#define SE_API
#else
#define SE_API __declspec(dllimport)
#endif
#endif