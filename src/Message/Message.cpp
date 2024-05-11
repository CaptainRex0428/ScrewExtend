#include "Message/Message.h"

#include "ScrewExtend_Micro.h"
#include "Message/Message_Config.h"
#include "Clock/Clock_Config.h"

#include <iostream>

#include "spdlog/sinks/stdout_color_sinks.h"

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
		spdlog::set_pattern(ENGINE_MICRO_CONTACT(ENGINE_MICRO_CONTACT(SCREW_MESSAGE_PATTERN_HEADER, TIME_STRING_PATTERN_CORE), SCREW_MESSAGE_PATTERN_INFO));

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