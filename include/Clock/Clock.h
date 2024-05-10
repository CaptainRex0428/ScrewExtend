#pragma once

#include <iostream>
#include <chrono>

#include "ScrewExtend_API.h"

namespace ScrewExtend {

	enum ScrewExtend_API ClockUnit
	{
		micro = 0,
		milli = 1
	};

	// Clock is singleton
	class ScrewExtend_API Clock {

	public:
		Clock(Clock&) = delete;

		/*static const char* generate_systime_format_now(const char* format = "%Y%m%d%H%M%S", int maxLength = 20);
		static const char* convert_systime_String(std::chrono::high_resolution_clock::time_point timeSource = std::chrono::high_resolution_clock::now());
		static long long int convert_systime_format_longlong(std::chrono::high_resolution_clock::time_point timeSource = std::chrono::high_resolution_clock::now(), ClockUnit unit = micro);
		static long long int convert_filetime_format_longlong(const FILETIME* filetime);*/

	//private:

		Clock() = default;
		~Clock() = default;

		static Clock& Get();

		inline time_t GetCurrentTime_time_t();
		inline tm* GetCurrentTime_tm_local();
		inline tm* GetCurrentTime_tm_gm();
		inline std::chrono::steady_clock::time_point GetCurrentTime_HighRes();

		// const char* I_generate_systime_format_now(const char* format, int maxLength);
		/*const char* I_convert_systime_format_longlong(std::chrono::high_resolution_clock::time_point timeSource);*/
	};
}