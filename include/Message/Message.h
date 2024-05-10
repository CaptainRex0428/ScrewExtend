#pragma once

#include "ScrewExtend_API.h"

#include "spdlog/spdlog.h"

namespace ScrewExtend
{
	class ScrewExtend_API Message
	{
	public:
		Message();
		~Message();

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetTerminalMessager() ;
		inline static std::shared_ptr<spdlog::logger>& GetClientMessager();

	private:
		static std::shared_ptr<spdlog::logger> m_TerminalMessager;
		static std::shared_ptr<spdlog::logger> m_ClientMessager;
	};
}