#pragma once

#include "SE_API.h"

#include "spdlog/spdlog.h"

namespace ScrewExtend
{
	class Message
	{
	public:
		SE_API Message();
		SE_API virtual ~Message();

	public:
		SE_API static void Init();

		SE_API static std::shared_ptr<spdlog::logger>& GetTerminalMessager() ;
		SE_API static std::shared_ptr<spdlog::logger>& GetClientMessager();

	private:
		inline static std::shared_ptr<spdlog::logger> m_TerminalMessager;
		inline static std::shared_ptr<spdlog::logger> m_ClientMessager;
	};
}