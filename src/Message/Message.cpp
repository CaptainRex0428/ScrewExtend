#include "Message/Message.h"

#include "ScrewExtend_Micro.h"
#include "Message/Message_Config.h"
#include "Clock/Clock_Config.h"

#include <iostream>

#include "spdlog/sinks/stdout_color_sinks.h"

namespace ScrewExtend
{

	Message::Message()
	{
		std::cout << "M Cons" << std::endl;
	};

	Message::~Message()
	{
		std::cout << "M Dest" << std::endl;
	}

	void Message::Init()
	{
		spdlog::set_pattern(SCREW_EXTEND_MICRO_CONTACT(SCREW_EXTEND_MICRO_CONTACT(SCREW_EXTEND_MESSAGE_PATTERN_HEADER, SCREW_EXTEND_TIME_STRING_PATTERN_CORE), SCREW_EXTEND_MESSAGE_PATTERN_INFO));

		m_TerminalMessager = spdlog::stderr_color_mt("Terminal");
		m_TerminalMessager->set_level(spdlog::level::trace);

		#ifdef _DEBUG
		if (m_TerminalMessager)
		{
			m_TerminalMessager->trace("Screw Message[Terminal] Initialized.");
		}
		#endif

		m_ClientMessager = spdlog::stderr_color_mt("Client");
		m_ClientMessager->set_level(spdlog::level::trace);

		#ifdef _DEBUG
		if (m_ClientMessager)
		{
			m_ClientMessager->trace("Screw Message[Client] Initialized.");
		}
		#endif
	}

	std::shared_ptr<spdlog::logger>& Message::GetTerminalMessager()
	{
		return m_TerminalMessager; 
	}

	std::shared_ptr<spdlog::logger>& Message::GetClientMessager()
	{
		return m_ClientMessager; 
	}
}