#pragma once

#include "SE_API.h"

#include "File/File.h"

#include <string>
#include <fstream>
#include <iostream>

namespace ScrewExtend
{
	struct TraceProfile
	{
		std::string RecordName;
		long long Start, End;
		size_t ThreadID;
	};

	class Trace
	{
	public:
		SE_API Trace(Trace&) = delete;

		SE_API static void Start();
		SE_API static void Stop();
		SE_API static void Record(const TraceProfile& result);

	private:

		SE_API Trace();
		SE_API virtual ~Trace();

		SE_API static Trace& Get();

		SE_API void BeginSession();
		SE_API void EndSession();
		SE_API void WriteProfile(const TraceProfile& result);
		SE_API void WriteHeader();
		SE_API void WriteFooter();

	private:
		File* m_traceFile;
		bool m_isRecording;
		int m_ProfileCount;
	};

}