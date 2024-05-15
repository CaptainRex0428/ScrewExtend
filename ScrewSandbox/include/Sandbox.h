#pragma once

#include "ScrewExtend.h"

namespace ScrewSandbox
{
	class Sandbox
	{
	public:
		Sandbox();
		~Sandbox();

		Sandbox(Sandbox&) = delete;

		static Sandbox& Get();

		static int Init();
		static void RunLoop();
		static void ShutDown();

	public:
		int PullEvents();
		int Update();
		int Output();

	private:
		bool m_isRunning;
		ScrewExtend::File * m_f;
	};
}