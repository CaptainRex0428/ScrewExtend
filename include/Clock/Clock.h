#pragma once

#include <iostream>
#include <chrono>

#include "ScrewExtend_API.h"

namespace ScrewExtend {

	// Clock is singleton
	class ScrewExtend_API Clock {

	public:
		Clock(Clock&) = delete;

		static inline tm* GetCurrentTime_sys();
		static inline tm* GetCurrentTime_sys(long long& timeRecord);
		static inline tm* GetCurrentTime_sys(char* timeRecord,bool isFull = false);

		static inline tm* GetCurrentTime_gm();
		static inline tm* GetCurrentTime_gm(long long& timeRecord);
		static inline tm* GetCurrentTime_gm(char* timeRecord, bool isFull = false);

		static inline std::chrono::steady_clock::time_point GetCurrentTime_HighRes();
		
	private:
		Clock() = default;
		~Clock() = default;

		static Clock& Get();

		static inline time_t GetCurrentTime_time_t();
	};
}