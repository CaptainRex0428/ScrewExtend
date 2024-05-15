#pragma once

#include <iostream>
#include <chrono>

#include "Clock/Clock_Define.h"
#include "SE_API.h"

namespace ScrewExtend {

	// Clock is singleton
	class Clock {

	public:
		SE_API Clock(Clock&) = delete;

		SE_API static const tm* GetCurrentTime_sys();
		SE_API static const tm* GetCurrentTime_sys(long long& timeRecord);
		SE_API static const tm* GetCurrentTime_sys(char* timeRecord,bool isFull = false);

		SE_API static const tm* GetCurrentTime_sys_simple(char* timeRecord);

		SE_API static const tm* GetCurrentTime_gm();
		SE_API static const tm* GetCurrentTime_gm(long long& timeRecord);
		SE_API static const tm* GetCurrentTime_gm(char* timeRecord, bool isFull = false);

		SE_API static const std::chrono::steady_clock::time_point GetCurrentTime_HighRes();
		
	protected:
		SE_API Clock();
		SE_API virtual ~Clock();

		SE_API static Clock& Get();

		SE_API static const time_t GetCurrentTime_time_t();
		
	};

	
}