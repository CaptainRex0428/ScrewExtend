//
// Created by rvo04 on 2024/3/31.
//

#include "Clock/Clock.h"

#include "Message/Message.h"
#include "SE_Config.h"

#include <windows.h>
#include <minwindef.h>

namespace ScrewExtend {

	// Definitions

	Clock::Clock()
	{
	}

	Clock::~Clock()
	{
	}

	Clock& Clock::Get() {
		static Clock instance;
		return instance;
	}

	const time_t Clock::GetCurrentTime_time_t() {
		return CHRONO_SYSTEM_CLOCK::to_time_t(CHRONO_SYSTEM_CLOCK::now());
	}

	const tm* Clock::GetCurrentTime_sys() {
		auto time = GetCurrentTime_time_t();
		return localtime(&time);
	}

	const ClockProfile Clock::GetCurrentTime_sys_profile(const char * _timepattern)
	{
		const tm* s_time = GetCurrentTime_sys();
		
		char s_time_str[SE_MAX_TIME_STRING_SIZE];
		strftime(s_time_str, SE_MAX_TIME_STRING_SIZE, _timepattern, s_time);

		CHRONO_STEADY_CLOCK::time_point s_time_point = GetCurrentTime_HighRes();
		
		return {s_time,s_time_str, s_time_point};
	}

	const tm* Clock::GetCurrentTime_gm() {
		auto time = GetCurrentTime_time_t();
		return gmtime(&time);
	}

	const ClockProfile Clock::GetCurrentTime_gm_profile(const char* _timepattern)
	{
		const tm* s_time = GetCurrentTime_gm();

		char s_time_str[SE_MAX_TIME_STRING_SIZE];
		strftime(s_time_str, SE_MAX_TIME_STRING_SIZE, _timepattern, s_time);

		CHRONO_STEADY_CLOCK::time_point s_time_point = GetCurrentTime_HighRes();

		return { s_time,s_time_str, s_time_point };
	}

	const std::chrono::steady_clock::time_point Clock::GetCurrentTime_HighRes()
	{
		return CHRONO_HIGHRES_CLOCK::now();
	}
	
}