#include "Clock/GlobalClock.h"

namespace ScrewExtend{
	GlobalClock::GlobalClock()
		:m_initialized(false),m_processStartTime(nullptr),m_processStartTime_HIGHRES(nullptr)
	{
	}

	GlobalClock::~GlobalClock()
	{
		delete m_processStartTime;
		m_processStartTime = nullptr;

		delete m_processStartTime_HIGHRES;
		m_processStartTime_HIGHRES = nullptr;
	}

	int GlobalClock::Initialize()
	{
		if(!m_initialized)
		{
			m_processStartTime_HIGHRES = new CHRONO_HIGHRES_CLOCK::time_point(GetCurrentTime_HighRes());
			m_processStartTime = new tm(*GetCurrentTime_sys());
			m_initialized = true;
		}
		
		return m_initialized;
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
	
	const CHRONO_HIGHRES_CLOCK::time_point* GlobalClock::GetProcessStartTime_HIGHRES()
	{
		return Get().m_processStartTime_HIGHRES;
	}
}
