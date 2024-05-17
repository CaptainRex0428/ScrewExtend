#include "Log/Log.h"

namespace ScrewExtend
{
	Log::Log()
		:m_Tag("")
	{
	}

	Log::Log(std::string _tag)
		:m_Tag(_tag)
	{
	}

	Log::Log(std::string _tag,std::string filepath)
		:m_Tag(_tag),File(filepath)
	{
		Open(true);
	}

	Log::~Log()
	{
	}

	int Log::SetTag(std::string _tag)
	{
		if (m_Tag.empty())
		{
			m_Tag = _tag;

			return 0;
		}

		return -1;
	}
	
	bool Log::Write(std::string Content, LogLevel _level)
	{
		if (!m_Tag.empty())
		{
			std::string level;
			
			switch (_level)
			{
			case ScrewExtend::Trace:
				level = "Trace";
				break;
			case ScrewExtend::Debug:
				level = "Debug";
				break;
			case ScrewExtend::Info:
				level = "Info";
				break;
			case ScrewExtend::Warning:
				level = "Warning";
				break;
			case ScrewExtend::Error:
				level = "Error";
				break;
			case ScrewExtend::Critical:
				level = "Critical";
				break;
			default:
				level = "Undefined";
				break;
			}

			std::string ContentResult = std::format("[{0}] [{1}] [{2}]:{3}", GetCurrentTime_sys_profile().m_time_str, m_Tag, level, Content);
			return File::Write(ContentResult);
		}

		return false;
	}

	bool Log::Write(std::string Content)
	{
		return false;
	}
	SE_API void Log::Clear()
	{
		return;
	}
}