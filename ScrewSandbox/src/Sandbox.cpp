#include "Sandbox.h"

#include <Windows.h>
#include "ScrewExtend_Micro.h"

namespace ScrewSandbox
{
	Sandbox::Sandbox()
		:m_isRunning(false)
	{
		m_f = new ScrewExtend::File("./log/GameRun.log");
		m_f->Open(true);
	}

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
		Get().m_f->Write("Game init");

		return result;
	}

	void Sandbox::RunLoop()
	{
		double loopFrame = 0;

		while (Get().m_isRunning)
		{
			SCREW_EXTEND_TIMER_TRACE_STORE(loopFrame);
			
			SE_THREAD_DELAY_MICRO(20);

			SE_MESSAGE_TERMINAL_WARN("{:.1f} ms",loopFrame);

			if (Get().PullEvents() != 0 || Get().Update() != 0)
			{
				Get().m_isRunning = false;
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

		SE_THREAD_DELAY_MICRO(3000);

		return 0;
	}

	int Sandbox::Update()
	{
		SCREW_EXTEND_TIMER_TRACE_NSTORE();

		SE_THREAD_DELAY_MICRO(3000);

		return 0;
	}

	int Sandbox::Output()
	{
		SCREW_EXTEND_TIMER_TRACE_NSTORE();

		SE_THREAD_DELAY_MICRO(3000);

		return 0;
	}

}