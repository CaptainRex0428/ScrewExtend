#pragma once

#include <iostream>
#include <chrono>

#include "ScrewExtend_API.h"

namespace ScrewExtend {

	// Clock is singleton
	class Clock {

	public:
		Clock(Clock&) = delete;

		ScrewExtend_API static tm* GetCurrentTime_sys();
		ScrewExtend_API static tm* GetCurrentTime_sys(long long& timeRecord);
		ScrewExtend_API static tm* GetCurrentTime_sys(char* timeRecord,bool isFull = false);

		ScrewExtend_API static tm* GetCurrentTime_gm();
		ScrewExtend_API static tm* GetCurrentTime_gm(long long& timeRecord);
		ScrewExtend_API static tm* GetCurrentTime_gm(char* timeRecord, bool isFull = false);

		ScrewExtend_API static std::chrono::steady_clock::time_point GetCurrentTime_HighRes();
		
	private:
		ScrewExtend_API Clock() = default;
		ScrewExtend_API virtual ~Clock() = default;

		ScrewExtend_API static Clock& Get();

		ScrewExtend_API static time_t GetCurrentTime_time_t();
	};
}