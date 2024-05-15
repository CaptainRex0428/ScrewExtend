//
// Created by rvo04 on 2024/3/31.
//

#include "Clock/Clock.h"
#include "Clock/Clock_Config.h"

#include "Message/Message.h"
#include "SE_Config.h"

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

	const tm* Clock::GetCurrentTime_gm() {
		auto time = GetCurrentTime_time_t();
		return gmtime(&time);
	}

	const std::chrono::steady_clock::time_point Clock::GetCurrentTime_HighRes()
	{
		return CHRONO_HIGHRES_CLOCK::now();
	}
	
}