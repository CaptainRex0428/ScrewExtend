#pragma once

#include "ScrewExtend_API.h"

#include "ScrewExtend_Config.h"

#include <vector>
#include <string>
#include <memory>

#include <sys/stat.h>

#include <tuple>

namespace ScrewExtend
{
	class File
	{

	// static
	public:
		ScrewExtend_API static bool AppendContent(const char * message,const char * filepath);
		ScrewExtend_API static bool ReplaceContent(const char * message_src,const char * message_rpc,const char * filepath);
		ScrewExtend_API static bool UpdateContent(const char * message,const char * filepath);
		ScrewExtend_API static void ClearContent(const char* filepath);
		ScrewExtend_API static void PrintContent(const char* filepath);
		ScrewExtend_API static std::vector<std::string>& GetContent(const char* filepath);

		ScrewExtend_API static bool isFilePathValid(const char* filepath,const char* _functionName, bool isError = true);
		ScrewExtend_API static bool isFilePathValid(const char* filepath, bool isError = true);

		ScrewExtend_API static bool Create(const char* filepath, bool force = false);

		ScrewExtend_API static std::tuple< bool, struct stat > GetFileInfo(const char * filepath);
		ScrewExtend_API static std::string GetFileNameFromPath(const char* filepath);
		ScrewExtend_API static std::string GetFileDirectoyFromPath(const char* filepath);
	
	private:
		ScrewExtend_API static struct stat GetFileStat(const char * filepath);
		
		ScrewExtend_API static bool isMessageValid(const char* message, const char * _functionName);

	// class
	public:
		ScrewExtend_API File(const char * filepath);
		ScrewExtend_API virtual ~File();

		ScrewExtend_API bool AppendContent(const char* message);
		ScrewExtend_API bool ReplaceContent(const char* message_src, const char* message_rpc);
		ScrewExtend_API bool UpdateContent(const char* message);
		ScrewExtend_API void ClearContent();
		ScrewExtend_API void PrintContent();
		ScrewExtend_API std::vector<std::string>& GetContent();

	private:
		std::shared_ptr<char> m_filepath;
		std::tuple< bool , struct stat > m_fileInfo;
	};

}