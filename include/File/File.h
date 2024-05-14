#pragma once

#include "ScrewExtend_API.h"

#include "ScrewExtend_Config.h"

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <sys/stat.h>

#include <tuple>

namespace ScrewExtend
{
	struct FstreamSession
	{
		std::string SessionName;
	};

	class File
	{
	// static
	public:
		ScrewExtend_API static bool isFilePathValid(const char* filepath, const char* _functionName, bool isError);
		ScrewExtend_API static bool isFilePathValid(const char* filepath, bool isError);

		ScrewExtend_API static bool isContentValid(const char* content, const char* _functionName);
		ScrewExtend_API static bool isContentValid(const char* content);

		ScrewExtend_API static struct stat GetFileStat(const char* filepath);

		ScrewExtend_API std::string static GetFileNameFromPath(const char* filepath);

	// class
	public:
		ScrewExtend_API File();
		ScrewExtend_API File(const char* filepath);
		ScrewExtend_API virtual ~File();

		ScrewExtend_API int Open(bool force = false);
		ScrewExtend_API int Open(const char * filepath, bool force = false);

		ScrewExtend_API int Close();

		ScrewExtend_API bool AppendContent(const char* message);

		ScrewExtend_API void PrintContent();
		ScrewExtend_API void ClearContent();

	protected:
		ScrewExtend_API bool isFilePathValid(const FstreamSession* filesession, const char* _functionName, bool isError = true);

		ScrewExtend_API std::vector<std::string>& GetContent();
		ScrewExtend_API struct stat GetFileStat();
		

	//var
	protected:
		FstreamSession* m_fstreamSession;
		std::fstream m_fstream;
		struct stat m_fileInfo;
	};

}