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

	class Trace : virtual public File
	{
	public:
		ScrewExtend_API Trace(Trace&) = delete;

		ScrewExtend_API static void Start();
		ScrewExtend_API static void Stop();
		ScrewExtend_API static void Record(const ProfileResult& result);

		ScrewExtend_API static std::filesystem::path GetTracePathFromTime();

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
		int m_ProfileCount;
	};

}