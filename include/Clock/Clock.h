#pragma once

#include "SE_API.h"

#include <iostream>
#include <chrono>

#include "Clock/Clock_Define.h"
#include "Clock/Clock_Config.h"

namespace ScrewExtend {

	struct ClockProfile
	{
		const tm * m_time;
		std::string m_time_str;
		CHRONO_STEADY_CLOCK::time_point m_time_highres;
	};

	// Clock is singleton
	class Clock {

	public:
		SE_API Clock(Clock&) = delete;

		SE_API static const tm* GetCurrentTime_sys();
		SE_API static const ClockProfile GetCurrentTime_sys_profile(const char* _timepattern = SE_TIME_STRING_PATTERN_CORE);

		SE_API static const tm* GetCurrentTime_gm();;
		SE_API static const ClockProfile GetCurrentTime_gm_profile(const char* _timepattern = SE_TIME_STRING_PATTERN_CORE);;

		SE_API static const CHRONO_STEADY_CLOCK::time_point GetCurrentTime_HighRes();
		
	protected:
		SE_API Clock();
		SE_API virtual ~Clock();

		SE_API static Clock& Get();

		SE_API static const time_t GetCurrentTime_time_t();
		
	};

	
}