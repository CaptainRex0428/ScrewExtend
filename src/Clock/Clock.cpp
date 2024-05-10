//
// Created by rvo04 on 2024/3/31.
//

#include "Clock/Clock.h"
#include "Clock/Clock_Define.h"

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
				MAX_TIME_STRING_SIZE, 
				isFull ? TIME_STRING_PATTERN_FULL:TIME_STRING_PATTERN_CORE,
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
				MAX_TIME_STRING_SIZE, 
				isFull ? TIME_STRING_PATTERN_FULL : TIME_STRING_PATTERN_CORE,
				time);
		return time;
	}

	std::chrono::steady_clock::time_point Clock::GetCurrentTime_HighRes()
	{
		return CHRONO_HIGHRES_CLOCK::now();
	};

	//const char* Clock::I_generate_systime_format_now(const char* format, int maxLength) {
	//	char* timestring = new char[maxLength];
	//	strftime(timestring, maxLength, format, GetCurrentTime_sys());

	//	return timestring;
	//}


	//const char* Clock::I_convert_systime_format_longlong(std::chrono::high_resolution_clock::time_point timeSource) {
	//	const time_t* timeT = new std::time_t(std::chrono::high_resolution_clock::to_time_t(timeSource));
	//	return ctime(timeT);
	//}

	//const char* Clock::generate_systime_format_now(const char* format, int maxLength) {
	//	return Get().I_generate_systime_format_now(format, maxLength);
	//}

	//const char* Clock::convert_systime_String(std::chrono::high_resolution_clock::time_point timeSource) {
	//	return Get().I_convert_systime_format_longlong(timeSource);
	//}

	//long long int Clock::convert_systime_format_longlong(std::chrono::high_resolution_clock::time_point timeSource, ClockUnit unit) {
	//	return unit ? std::chrono::time_point_cast<std::chrono::milliseconds>(timeSource).time_since_epoch().count() : std::chrono::time_point_cast<std::chrono::microseconds>(timeSource).time_since_epoch().count();
	//}

	//long long int Clock::convert_filetime_format_longlong(const FILETIME* filetime) {

	//	LARGE_INTEGER li;

	//	li.LowPart = (LONG)filetime->dwLowDateTime;
	//	li.HighPart = (LONG)filetime->dwHighDateTime;

	//	return li.QuadPart;
	//}
	//const char* Clock::I_generate_systime_format_now(const char* format, int maxLength) {
	//	char* timestring = new char[maxLength];
	//	strftime(timestring, maxLength, format, GetCurrentTime_sys());

	//	return timestring;
	//}


	//const char* Clock::I_convert_systime_format_longlong(std::chrono::high_resolution_clock::time_point timeSource) {
	//	const time_t* timeT = new std::time_t(std::chrono::high_resolution_clock::to_time_t(timeSource));
	//	return ctime(timeT);
	//}

	//const char* Clock::generate_systime_format_now(const char* format, int maxLength) {
	//	return Get().I_generate_systime_format_now(format, maxLength);
	//}

	//const char* Clock::convert_systime_String(std::chrono::high_resolution_clock::time_point timeSource) {
	//	return Get().I_convert_systime_format_longlong(timeSource);
	//}

	//long long int Clock::convert_systime_format_longlong(std::chrono::high_resolution_clock::time_point timeSource, ClockUnit unit) {
	//	return unit ? std::chrono::time_point_cast<std::chrono::milliseconds>(timeSource).time_since_epoch().count() : std::chrono::time_point_cast<std::chrono::microseconds>(timeSource).time_since_epoch().count();
	//}

	//long long int Clock::convert_filetime_format_longlong(const FILETIME* filetime) {

	//	LARGE_INTEGER li;

	//	li.LowPart = (LONG)filetime->dwLowDateTime;
	//	li.HighPart = (LONG)filetime->dwHighDateTime;

	//	return li.QuadPart;
	//}
}