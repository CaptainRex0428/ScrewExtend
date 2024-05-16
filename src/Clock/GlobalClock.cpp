#include "Clock/GlobalClock.h"

namespace ScrewExtend{
	GlobalClock::GlobalClock()
		:m_initialized(false),m_processStartTime(nullptr)
	{
	}

	GlobalClock::~GlobalClock()
	{
		delete m_processStartTime;
		m_processStartTime = nullptr;
	}

	int GlobalClock::Initialize()
	{
		if(!m_initialized)
		{
			m_processStartTime = new ClockProfile(GetCurrentTime_sys_profile());
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
	
	const ClockProfile * GlobalClock::GetProcessStartTime()
	{
		return Get().m_processStartTime;
	}
}
