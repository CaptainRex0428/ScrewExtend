#pragma once

#include "SE_API.h"
#include "Clock.h"

namespace ScrewExtend
{
	class GlobalClock : virtual public Clock
	{
	public:
		SE_API GlobalClock(GlobalClock&) = delete;

		SE_API static int Init();

		SE_API static const tm * GetProcessStartTime();
		SE_API static const CHRONO_HIGHRES_CLOCK::time_point * GetProcessStartTime_HIGHRES();

	protected:
		SE_API virtual int Initialize();

	private:
		SE_API GlobalClock();
		SE_API virtual ~GlobalClock() override;

		SE_API static GlobalClock& Get();
	
	private:
		bool m_initialized;

		tm* m_processStartTime;
		CHRONO_HIGHRES_CLOCK::time_point* m_processStartTime_HIGHRES;

	};
}