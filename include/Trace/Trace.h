#pragma once

#include "ScrewExtend_API.h"
#include "File/File.h"

#include <string>
#include <fstream>

namespace ScrewExtend
{
	struct ProfileResult
	{
		std::string RecordName;
		long long Start, End;
		size_t ThreadID;
	};

	class Trace
	{
	public:
		ScrewExtend_API Trace(Trace&) = delete;

		ScrewExtend_API static void Start();
		ScrewExtend_API static void Stop();
		ScrewExtend_API static void Record(const ProfileResult& result);

	private:

		ScrewExtend_API Trace();
		ScrewExtend_API virtual ~Trace();

		ScrewExtend_API static Trace& Get();

		ScrewExtend_API void BeginSession();
		ScrewExtend_API void EndSession();
		ScrewExtend_API void WriteProfile(const ProfileResult& result);
		ScrewExtend_API void WriteHeader();
		ScrewExtend_API void WriteFooter();

	private:
		File* m_traceFile;
		bool m_isRecording;
		int m_ProfileCount;
	};

}