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

		ScrewExtend_API static void Init();

		ScrewExtend_API static const tm* GetCurrentTime_sys();
		ScrewExtend_API static const tm* GetCurrentTime_sys(long long& timeRecord);
		ScrewExtend_API static const tm* GetCurrentTime_sys(char* timeRecord,bool isFull = false);

		ScrewExtend_API static const tm* GetCurrentTime_gm();
		ScrewExtend_API static const tm* GetCurrentTime_gm(long long& timeRecord);
		ScrewExtend_API static const tm* GetCurrentTime_gm(char* timeRecord, bool isFull = false);

		ScrewExtend_API static const std::chrono::steady_clock::time_point GetCurrentTime_HighRes();

		ScrewExtend_API static inline const tm* GetProcessStartTime() { return m_sysStartTime; };
		ScrewExtend_API static inline const char* GetProcessStartTime_CHAR() { return m_sysStartTime_CHAR; };
		ScrewExtend_API static inline const CHRONO_STEADY_CLOCK::time_point* GetProcessStartTime_HIGHRES() { return m_sysStartTime_HIGHRES; };
		
	private:
		ScrewExtend_API Clock();
		ScrewExtend_API virtual ~Clock();

		ScrewExtend_API static Clock& Get();

		ScrewExtend_API static const time_t GetCurrentTime_time_t();

		ScrewExtend_API static void TipUninitialized();

	protected:
		ScrewExtend_API static tm* m_sysStartTime;
		ScrewExtend_API static char* m_sysStartTime_CHAR;
		ScrewExtend_API static CHRONO_STEADY_CLOCK::time_point* m_sysStartTime_HIGHRES;

	private:
		ScrewExtend_API static bool m_initialized;
		
	};

	
}