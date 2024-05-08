#include "Log/Log.h"

#include <iostream>

#include "spdlog/sinks/stdout_color_sinks.h"

#define SCREW_LOG_PATTERN "%^[%T] %n: %v%$"

namespace ScrewExtend
{
	std::shared_ptr<spdlog::logger> Log::s_TerminalLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	Log::Log()
	{
	};

	Log::~Log()
	{
	}

	void Log::Init()
	{
		spdlog::set_pattern(SCREW_LOG_PATTERN);

		s_TerminalLogger = spdlog::stderr_color_mt("Terminal");
		s_TerminalLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("Client");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	inline std::shared_ptr<spdlog::logger>& Log::GetTerminalLogger()
	{
		return s_TerminalLogger; 
	}

	inline std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return s_ClientLogger; 
	}

	void Print()
	{
		std::cout << "Screw Log LINKED!!!" << std::endl;
	}


}