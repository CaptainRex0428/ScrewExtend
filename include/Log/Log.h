#pragma once

#include "ScrewExtend_API.h"

#include "spdlog/spdlog.h"

namespace ScrewExtend
{
	class ScrewExtend_API Log
	{
	public:
		Log();
		~Log();

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetTerminalLogger() ;
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_TerminalLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

	void ScrewExtend_API Print();
}