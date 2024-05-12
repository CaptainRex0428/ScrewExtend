//
// Created by rvo04 on 2024/3/31.
//

#include "Clock/Clock.h"
#include "Clock/Clock_Define.h"
#include "Clock/Clock_Config.h"

#include <windows.h>
#include <minwindef.h>

namespace ScrewExtend {

	Clock& Clock::Get() {
		static Clock instance;
		return instance;
	}

	time_t Clock::GetCurrentTime_time_t() {
		return CHRONO_SYSTEM_CLOCK::to_time_t(CHRONO_SYSTEM_CLOCK::now());
	}

	tm* Clock::GetCurrentTime_sys() {
		auto time = GetCurrentTime_time_t();
		return localtime(&time);
	}

	tm* Clock::GetCurrentTime_sys(long long& timeRecord)
	{
		timeRecord = CHRONO_HIGHRES_CLOCK::now().time_since_epoch().count();
		return GetCurrentTime_sys();
	}

	tm* Clock::GetCurrentTime_sys(char* timeRecord, bool isFull)
	{
		time_t timeT = GetCurrentTime_time_t();
		tm* time = localtime(&timeT);
		strftime(timeRecord, 
				SCREW_EXTEND_MAX_TIME_STRING_SIZE, 
				isFull ? SCREW_EXTEND_TIME_STRING_PATTERN_FULL: SCREW_EXTEND_TIME_STRING_PATTERN_CORE,
				time);
		return time;
	}

	tm* Clock::GetCurrentTime_gm() {
		auto time = GetCurrentTime_time_t();
		return gmtime(&time);
	}

	tm* Clock::GetCurrentTime_gm(long long& timeRecord)
	{
		timeRecord = CHRONO_HIGHRES_CLOCK::now().time_since_epoch().count();
		return GetCurrentTime_gm();
	}

	tm* Clock::GetCurrentTime_gm(char* timeRecord, bool isFull)
	{
		time_t timeT = GetCurrentTime_time_t();
		tm* time = gmtime(&timeT);
		strftime(timeRecord, 
			SCREW_EXTEND_MAX_TIME_STRING_SIZE,
				isFull ? SCREW_EXTEND_TIME_STRING_PATTERN_FULL : SCREW_EXTEND_TIME_STRING_PATTERN_CORE,
				time);
		return time;
	}

	std::chrono::steady_clock::time_point Clock::GetCurrentTime_HighRes()
	{
		return CHRONO_HIGHRES_CLOCK::now();
	};
}