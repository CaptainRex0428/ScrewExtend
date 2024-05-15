#include "Sandbox.h"

#include <Windows.h>
#include "SE_Micro.h"

namespace ScrewSandbox
{
	Sandbox::Sandbox()
		:m_isRunning(false),m_f(nullptr)
	{
	}

	Sandbox::~Sandbox()
	{
		if(m_isRunning == true || m_f != nullptr)
		{
			m_isRunning = false;

			m_f->Close();
			delete m_f;
			m_f = nullptr;
		}
	}

	Sandbox& Sandbox::Get()
	{
		static Sandbox instance;
		return instance;
	}

	int Sandbox::Init()
	{
		ScrewExtend::Message::Init();
		ScrewExtend::GlobalClock::Init();

		Get().m_f = new ScrewExtend::File("./log/GameRun.log");
		Get().m_f->Open(true);
		Get().m_f->Write("Game init");

		Get().m_isRunning = true;

		return 1;
	}

	void Sandbox::RunLoop()
	{
		ScrewExtend::Trace::Start();

		double loopFrame = 0;

		while (Get().m_isRunning)
		{
			SCREW_EXTEND_TIMER_TRACE_STORE(loopFrame);
			
			SE_THREAD_DELAY_MICRO(1);

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


	Entity::Entity()
		:m_fileA(nullptr)
	{}

	Entity::~Entity()
	{
		if (m_fileA != nullptr) 
		{
			m_fileA->Close();

			delete m_fileA;
			m_fileA = nullptr;
		}
	}

	Entity& Entity::Get()
	{
		static Entity instance;
		return instance;
	}

	void Entity::Init(std::string _Path)
	{
		Get().m_fileA = new SE_FILE(_Path);
		Get().m_fileA->Open(true);
	}

	void Entity::write(std::string message)
	{
		if (Get().m_fileA != nullptr) 
		{
			Get().m_fileA->Write(message);
		}
	}

	void Entity::print()
	{
		if (Get().m_fileA != nullptr)
		{
			Get().m_fileA->Print();
		}
	}


}