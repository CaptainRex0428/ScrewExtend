#pragma once

#include "SE_API.h"
#include "Log/Log.h"
#include "Message/Message.h"

namespace ScrewExtend 
{
	void MsgLog(std::string Content, Log* logger, LogLevel _Level = ScrewExtend::Trace)
	{
		logger->Write(Content, _Level);

		switch (_Level)
		{
		case ScrewExtend::Trace:
			ScrewExtend::Message::GetClientMessager()->trace(Content);
			break;
		case ScrewExtend::Debug:
			ScrewExtend::Message::GetClientMessager()->debug(Content);
			break;
		case ScrewExtend::Info:
			ScrewExtend::Message::GetClientMessager()->info(Content);
			break;
		case ScrewExtend::Warning:
			ScrewExtend::Message::GetClientMessager()->warn( Content);
			break;
		case ScrewExtend::Error:
			ScrewExtend::Message::GetClientMessager()->error(Content);
			break;
		case ScrewExtend::Critical:
			ScrewExtend::Message::GetClientMessager()->critical(Content);
			break;
		default:
			ScrewExtend::Message::GetClientMessager()->trace(Content);
			break;
		}
	}

	void MsgLog(std::string Content, LogLevel _Level = ScrewExtend::Trace)
	{
		Log* logger = new Log();

		MsgLog(Content, logger, _Level);
	}
}