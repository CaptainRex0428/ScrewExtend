#pragma once

#include <iostream>
#include <chrono>

#include "Clock/Clock_Define.h"
#include "ScrewExtend_API.h"

namespace ScrewExtend {

	// Clock is singleton
	class Clock {

	public:
		ScrewExtend_API Clock(Clock&) = delete;

		ScrewExtend_API static const tm* GetCurrentTime_sys();
		ScrewExtend_API static const tm* GetCurrentTime_sys(long long& timeRecord);
		ScrewExtend_API static const tm* GetCurrentTime_sys(char* timeRecord,bool isFull = false);

		ScrewExtend_API static const tm* GetCurrentTime_sys_simple(char* timeRecord);

		ScrewExtend_API static const tm* GetCurrentTime_gm();
		ScrewExtend_API static const tm* GetCurrentTime_gm(long long& timeRecord);
		ScrewExtend_API static const tm* GetCurrentTime_gm(char* timeRecord, bool isFull = false);

		ScrewExtend_API static const std::chrono::steady_clock::time_point GetCurrentTime_HighRes();
		
	protected:
		ScrewExtend_API Clock();
		ScrewExtend_API virtual ~Clock();

		ScrewExtend_API static Clock& Get();

		ScrewExtend_API static const time_t GetCurrentTime_time_t();
		
	};

	
}