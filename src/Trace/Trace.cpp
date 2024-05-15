#include "Trace/Trace.h"

#include "Trace/Trace_Config.h"
#include "Directory/Directory.h"
#include "File/File.h"

#include "Message/Message.h"
#include "Message/Message_Micro.h"

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
		:m_ProfileCount(0), m_isRecording(false),m_traceFile(nullptr)
	{
	}

	Trace::~Trace()
	{
		if(m_isRecording)
		{
			Stop();
		}
	}

	Trace& Trace::Get()
	{
		static Trace instance;
		return instance;
	}

	void Trace::BeginSession()
	{
		if (!m_isRecording)
		{
			char* filename = new char();
			Clock::GetCurrentTime_sys_simple(filename);

			long long highres = 0;
			Clock::GetCurrentTime_sys(highres);

			std::string _path = std::format("{0}/{1}-{2}.json", SCREW_EXTEND_TRACE_FOLDER, filename, highres);
			
			m_traceFile = new File(_path);

			if (m_traceFile->Open(true) == 0)
			{
				SE_MESSAGE_TERMINAL_DEBUG("Trace Started.");
				m_isRecording = true;

				WriteHeader();
				
				return;
			}

			m_traceFile->Close();
			delete m_traceFile;
			m_traceFile = nullptr;
		}
	}

	void Trace::EndSession()
	{
		if (m_isRecording) 
		{
			WriteFooter();

			m_traceFile->Close();
			delete m_traceFile;
			m_traceFile = nullptr;

			m_isRecording = false;
		}
	}

	void Trace::WriteProfile(const ProfileResult& result)
	{
		if (!m_isRecording)
		{
			return;
		}

		if (m_ProfileCount++ > 0)
			m_traceFile->Write(",");

		std::string name = result.RecordName;
		std::replace(name.begin(), name.end(), '"', '\'');

		m_traceFile->Write("{");
		m_traceFile->Write("\"cat\":\"function\",");
		m_traceFile->Write(std::format("\"dur\":{0},", std::to_string(result.End - result.Start)));
		m_traceFile->Write(std::format("\"name\":\"{0}\",", name));
		m_traceFile->Write("\"ph\":\"X\",");
		m_traceFile->Write(std::format("\"pid\":{0},",std::to_string(_getpid())));
		m_traceFile->Write(std::format("\"tid\":{0},", std::to_string(result.ThreadID)));
		m_traceFile->Write(std::format("\"ts\":{0}", std::to_string(result.Start)));
		m_traceFile->Write("}");
	}

	void Trace::WriteHeader()
	{
		if (m_isRecording) 
		{
			m_traceFile->Write(R"({"otherData": {},"traceEvents":[)");
		}
	}

	void Trace::WriteFooter() {
		if (m_isRecording) 
		{
			m_traceFile->Write(R"(]})");
		}
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
		if (Get().m_isRecording)
		{
			Get().WriteProfile(result);
		}
	}
}