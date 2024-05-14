#include "Trace/Trace.h"

#include "Trace/Trace_Config.h"
#include "Directory/Directory.h"
#include "File/File.h"

#include "Clock/Clock.h"

#include <format>
#include <filesystem>
#include <iostream>
#include <process.h>

#include <thread>
#include <chrono>

namespace ScrewExtend
{
	Trace::Trace()
		:m_ProfileCount(0)
	{
		if(!Directory::isDirectoryPathValid(SCREW_EXTEND_TRACE_FOLDER,false))
		{
			Directory::Create(SCREW_EXTEND_TRACE_FOLDER, true);
		}
	}

	Trace::~Trace()
	{
		if (m_fstream.is_open() || m_fstreamSession != nullptr)
		{
			EndSession();
		}
	}

	Trace& Trace::Get()
	{
		static Trace instance;
		return instance;
	}

	void Trace::BeginSession()
	{
		if (!m_fstream.is_open() || m_fstreamSession == nullptr)
		{
			char* filename = new char();
			Clock::GetCurrentTime_sys_simple(filename);

			long long highres = 0;
			Clock::GetCurrentTime_sys(highres);

			std::filesystem::path filepath(std::format("{0}/{1}-{2}.json", SCREW_EXTEND_TRACE_FOLDER, filename,highres));

			if (Open(filepath.string().c_str(), true) == 0)
			{
				WriteHeader();
			}
		}
	}

	void Trace::EndSession()
	{
		if (m_fstreamSession != nullptr)
		{
			WriteFooter();
			m_fstream.close();
			delete m_fstreamSession;
			m_fstreamSession = nullptr;
		}
	}

	void Trace::WriteProfile(const ProfileResult& result)
	{
		if (m_ProfileCount++ > 0)
			m_fstream << ",";

		std::string name = result.RecordName;
		std::replace(name.begin(), name.end(), '"', '\'');

		m_fstream << "{\n";
		m_fstream << "\"cat\":\"function\",\n";
		m_fstream << "\"dur\":" << (result.End - result.Start) << ",\n";
		m_fstream << "\"name\":\"" << name << "\",\n";
		m_fstream << "\"ph\":\"X\",\n";
		m_fstream << "\"pid\":" << _getpid() << ",\n";
		m_fstream << "\"tid\":" << result.ThreadID << ",\n";
		m_fstream << "\"ts\":" << result.Start;
		m_fstream << "}";

		m_fstream.flush();
	}

	void Trace::WriteHeader()
	{
		m_fstream << "{\"otherData\": {},\"traceEvents\":[\n";
		m_fstream.flush();
	}

	void Trace::WriteFooter() {
		m_fstream << R"(]})";
		m_fstream.flush();
	}

	void Trace::Start()
	{
		Get().BeginSession();
	}

	void Trace::Stop()
	{
		Get().EndSession();
	}

	void Trace::Record(const ProfileResult& result)
	{
		if (Get().m_fstreamSession != nullptr && Get().m_fstream.is_open())
		{
			Get().WriteProfile(result);
		}
	}


}