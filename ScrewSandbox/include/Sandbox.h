#pragma once

#include "ScrewExtend.h"

namespace ScrewSandbox
{
	class Sandbox
	{
	public:
		Sandbox(Sandbox&) = delete;

		static int Init();
		static void RunLoop();
		static void ShutDown();

	public:
		int PullEvents();
		int Update();
		int Output();
	
	private:
		Sandbox();
		~Sandbox();

		static Sandbox& Get() ;

	private:
		bool m_isRunning;
		SE_FILE* m_f;
	};
}