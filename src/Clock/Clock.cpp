//
// Created by rvo04 on 2024/3/31.
//

#include "Clock/Clock.h"
#include "Clock/Clock_Config.h"

#include "Message/Message.h"
#include "ScrewExtend_Config.h"

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

	const tm* Clock::GetCurrentTime_sys(long long& timeRecord)
	{
		timeRecord = CHRONO_HIGHRES_CLOCK::now().time_since_epoch().count();
		return GetCurrentTime_sys();
	}

	const tm* Clock::GetCurrentTime_sys(char* timeRecord, bool isFull)
	{
		time_t timeT = GetCurrentTime_time_t();
		tm* time = localtime(&timeT);
		strftime(timeRecord, 
				SCREW_EXTEND_MAX_TIME_STRING_SIZE, 
				isFull ? SCREW_EXTEND_TIME_STRING_PATTERN_FULL: SCREW_EXTEND_TIME_STRING_PATTERN_CORE,
				time);
		return time;
	}

	ScrewExtend_API const tm* Clock::GetCurrentTime_sys_simple(char* timeRecord)
	{
		time_t timeT = GetCurrentTime_time_t();
		tm* time = localtime(&timeT);
		strftime(timeRecord,
			SCREW_EXTEND_MAX_TIME_STRING_SIZE,
			SCREW_EXTEND_TIME_STRING_PATTERN_FILE,
			time);
		return time;
	}

	const tm* Clock::GetCurrentTime_gm() {
		auto time = GetCurrentTime_time_t();
		return gmtime(&time);
	}

	const tm* Clock::GetCurrentTime_gm(long long& timeRecord)
	{
		timeRecord = CHRONO_HIGHRES_CLOCK::now().time_since_epoch().count();
		return GetCurrentTime_gm();
	}

	const tm* Clock::GetCurrentTime_gm(char* timeRecord, bool isFull)
	{
		time_t timeT = GetCurrentTime_time_t();
		tm* time = gmtime(&timeT);
		strftime(timeRecord, 
			SCREW_EXTEND_MAX_TIME_STRING_SIZE,
				isFull ? SCREW_EXTEND_TIME_STRING_PATTERN_FULL : SCREW_EXTEND_TIME_STRING_PATTERN_CORE,
				time);
		return time;
	}

	const std::chrono::steady_clock::time_point Clock::GetCurrentTime_HighRes()
	{
		return CHRONO_HIGHRES_CLOCK::now();
	}
	
}