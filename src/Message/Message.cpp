#include "Message/Message.h"

#include <iostream>

#include "spdlog/sinks/stdout_color_sinks.h"

#define SCREW_LOG_PATTERN "%^[%T] %n: %v%$"

namespace ScrewExtend
{
	std::shared_ptr<spdlog::logger> Message::m_TerminalMessager;
	std::shared_ptr<spdlog::logger> Message::m_ClientMessager;

	Message::Message()
	{
	};

	Message::~Message()
	{
	}

	void Message::Init()
	{
		spdlog::set_pattern(SCREW_LOG_PATTERN);

		m_TerminalMessager = spdlog::stderr_color_mt("Terminal");
		m_TerminalMessager->set_level(spdlog::level::trace);

		if (m_TerminalMessager)
		{
			m_TerminalMessager->trace("Screw Message[Terminal] Initialized.");
		}

		m_ClientMessager = spdlog::stderr_color_mt("Client");
		m_ClientMessager->set_level(spdlog::level::trace);

		if (m_ClientMessager)
		{
			m_ClientMessager->trace("Screw Message[Client] Initialized.");
		}
	}

	inline std::shared_ptr<spdlog::logger>& Message::GetTerminalMessager()
	{
		return m_TerminalMessager; 
	}

	inline std::shared_ptr<spdlog::logger>& Message::GetClientMessager()
	{
		return m_ClientMessager; 
	}
}