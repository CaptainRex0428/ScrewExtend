#include "Clock/GlobalClock.h"

namespace ScrewExtend{
	GlobalClock::GlobalClock()
		:m_initialized(false),
		m_processStartTime(new tm()),
		m_processStartTime_CHAR(new char()),
		m_processStartTime_HIGHRES(new CHRONO_HIGHRES_CLOCK::time_point())
	{

	}

	GlobalClock::~GlobalClock()
	{
		delete m_processStartTime, m_processStartTime_CHAR, m_processStartTime_HIGHRES;
	}

	int GlobalClock::Initialize()
	{
		if(!m_initialized)
		{
			*m_processStartTime = *GetCurrentTime_sys(m_processStartTime_CHAR);
			*m_processStartTime_HIGHRES = GetCurrentTime_HighRes();
			m_initialized = true;
		}
		
		return this->m_initialized;
	}
	
	GlobalClock& GlobalClock::Get()
	{
		static GlobalClock instance;
		return instance;
	}

	int GlobalClock::Init()
	{
		return Get().Initialize();
	}
	
	const tm* GlobalClock::GetProcessStartTime()
	{
		return Get().m_processStartTime;
	}
	
	const char* GlobalClock::GetProcessStartTime_CHAR()
	{
		return Get().m_processStartTime_CHAR;
	}
	
	const CHRONO_HIGHRES_CLOCK::time_point* GlobalClock::GetProcessStartTime_HIGHRES()
	{
		return Get().m_processStartTime_HIGHRES;
	}
}
