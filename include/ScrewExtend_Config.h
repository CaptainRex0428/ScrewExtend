#pragma once

#define SCREW_EXTEND_SLASH "------------------"
#define SCREW_EXTEND_SLASH_TILTE_PATTERN "{0}{1} START--[{2:.2f}{3}]{0}"
#define SCREW_EXTEND_SLASH_FOOTER_PATTERN "{0}{1} END----[{2:.2f}{3}]{0}"

#ifdef SCREW_EXTEND_DEBUG_DETAIL
#define SCREW_EXTEND_DEBUG_FUNCTION_DETAIL true
#else
#define SCREW_EXTEND_DEBUG_FUNCTION_DETAIL false
#endif

#define SCREW_EXTEND_DEBUG_FUNCTION_TYPE_DEFAULT "-NoFuntionRecord-"

#define SCREW_EXTEND_TIP_FUNCTION_FORCE "Make parameter input <{0}> as <{1}> may help."
#define SCREW_EXTEND_TIP_VARIABLE_RESET "Variable <{0}> has been reset."

