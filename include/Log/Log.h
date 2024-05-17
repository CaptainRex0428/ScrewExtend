#pragma once

#include "SE_API.h"

#include "File/File.h"
#include "Clock/Clock.h"

namespace ScrewExtend
{
	enum LogLevel
	{
		Trace = 0,
		Debug = 1,
		Info = 2,
		Warning = 3,
		Error = 4,
		Critical = 5
	};

	class Log: virtual public File, virtual public Clock
	{
	public:
		SE_API Log();
		SE_API Log(std::string _tag);
		SE_API Log(std::string _tag,std::string filepath);
		SE_API virtual ~Log();

		SE_API int SetTag(std::string _tag);
	
		SE_API virtual bool Write(std::string Content, LogLevel _level);

	protected:
		SE_API virtual bool Write(std::string Content) override;
		SE_API virtual void Clear() override;

	protected:
		std::string m_Tag;
	};
}