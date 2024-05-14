#include "Sandbox.h"

#include <Windows.h>

namespace ScrewSandbox
{
	Sandbox::Sandbox()
		:m_isRunning(false)
	{}

	Sandbox::~Sandbox()
	{}

	Sandbox& Sandbox::Get()
	{
		static Sandbox instance;
		return instance;
	}

	int Sandbox::Init()
	{
		ScrewExtend::Message::Init();
		auto result = ScrewExtend::GlobalClock::Init();



		ScrewExtend::Trace::Start();

		Get().m_isRunning = true;

		return result;
	}

	void Sandbox::RunLoop()
	{
		double loopFrame = 0;

		while (Get().m_isRunning)
		{
			SCREW_EXTEND_TIMER_TRACE_STORE(loopFrame);
			Sleep(1);

			std::cout << loopFrame << "ms" << std::endl;

			if (Get().PullEvents() != 0 || Get().Update() != 0)
			{
				return;
			};
			
			Get().Output();
		}
	}

	void Sandbox::ShutDown()
	{
		if (Get().m_isRunning)
		{
			Get().m_isRunning = false;
		}

		ScrewExtend::Trace::Stop();
	}

	int Sandbox::PullEvents()
	{
		SCREW_EXTEND_TIMER_TRACE_NSTORE();

		Sleep(300);

		return 0;
	}

	int Sandbox::Update()
	{
		SCREW_EXTEND_TIMER_TRACE_NSTORE();

		Sleep(300);

		return 0;
	}

	int Sandbox::Output()
	{
		SCREW_EXTEND_TIMER_TRACE_NSTORE();

		Sleep(300);

		return 0;
	}

}