#pragma once

#ifdef SCREW_EXTEND_BUILD_DLL_EXPORT
#define ScrewExtend_API __declspec(dllexport)
#else
#ifdef SCREW_EXTEND_BUILD_LIB
#define ScrewExtend_API
#else
#define ScrewExtend_API __declspec(dllimport)
#endif
#endif