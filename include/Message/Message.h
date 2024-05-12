#pragma once

#include "ScrewExtend_API.h"

#include "spdlog/spdlog.h"

namespace ScrewExtend
{
	class Message
	{
	public:
		ScrewExtend_API Message();
		ScrewExtend_API virtual ~Message();

	public:
		ScrewExtend_API static void Init();

		ScrewExtend_API static std::shared_ptr<spdlog::logger>& GetTerminalMessager() ;
		ScrewExtend_API static std::shared_ptr<spdlog::logger>& GetClientMessager();

	private:
		inline static std::shared_ptr<spdlog::logger> m_TerminalMessager;
		inline static std::shared_ptr<spdlog::logger> m_ClientMessager;
	};
}