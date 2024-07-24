#pragma once

#define SE_PRINT_FORMAT_DASH "------------------"
#define SE_PRINT_TILTE_PATTERN "{0}{1} START--[{2:.2f}{3}]{0}"
#define SE_PRINT_FOOTER_PATTERN "{0}{1} END----[{2:.2f}{3}]{0}"

#ifdef SE_DEBUG_DETAIL
#define SE_DEBUG_FUNCTION_DETAIL_OUT __FUNCSIG__
#else
#define SE_DEBUG_FUNCTION_DETAIL_OUT __FUNCTION__
#endif

#define SE_DEBUG_FUNCTION_TYPE_DEFAULT "-NoFuntionRecord-"

#define SE_TIP_FUNCTION_FORCE "Make parameter input <{0}> as <{1}> may help."
#define SE_TIP_VARIABLE_RESET "Variable <{0}> has been reset."

#define SE_DEFAULT_LOG_PATH_REL "./log/Default.log"