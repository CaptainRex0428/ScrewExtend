#pragma once

#define SCREW_EXTEND_SLASH "------------------"
#define SCREW_EXTEND_SLASH_TILTE_PATTERN "{0}{1} START--[{2:.2f}{3}]{0}"
#define SCREW_EXTEND_SLASH_FOOTER_PATTERN "{0}{1} END----[{2:.2f}{3}]{0}"

#ifdef SCREW_EXTEND_DEBUG_DETAIL
#define SCREW_EXTEND_DEBUG_FUNCTION_TYPE __FUNCSIG__
#else
#define SCREW_EXTEND_DEBUG_FUNCTION_TYPE __FUNCTION__
#endif