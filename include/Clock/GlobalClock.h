#pragma once

#include "ScrewExtend_API.h"
#include "Clock.h"

namespace ScrewExtend
{
	class GlobalClock : virtual public Clock
	{
	public:
		ScrewExtend_API GlobalClock(GlobalClock&) = delete;

		ScrewExtend_API static int Init();

		ScrewExtend_API static const tm * GetProcessStartTime();
		ScrewExtend_API static const char * GetProcessStartTime_CHAR();
		ScrewExtend_API static const CHRONO_HIGHRES_CLOCK::time_point * GetProcessStartTime_HIGHRES();

	protected:
		ScrewExtend_API virtual int Initialize();

	private:
		ScrewExtend_API GlobalClock();
		ScrewExtend_API virtual ~GlobalClock() override;

		ScrewExtend_API static GlobalClock& Get();
	
	private:
		bool m_initialized;

		tm* m_processStartTime;
		char* m_processStartTime_CHAR;
		CHRONO_HIGHRES_CLOCK::time_point* m_processStartTime_HIGHRES;

	};
}