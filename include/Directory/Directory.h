#pragma once 

#include "ScrewExtend_API.h"

#include <vector>
#include <string>
#include <tuple>

#include <sys/stat.h>

namespace ScrewExtend
{
	class Directory
	{
	//static 
	public:

		ScrewExtend_API static bool isDirectoryPathValid(const char* directoryPath, const char* _functionName, bool isError = true);
		
		ScrewExtend_API static bool Create(const char* directoryPath,bool force = false);

		ScrewExtend_API static std::tuple<bool, struct stat> GetDirectoryInfo(const char* directoryPath);
		ScrewExtend_API static std::string GetParentDirectoryFromPath(const char * directoryPath);
		ScrewExtend_API static std::vector<std::string> GetChildDirectoryPath(const char * directoryPath);
		ScrewExtend_API static std::vector<std::string> GetChildFilePath(const char * directoryPath);
		//ScrewExtend_API static inline std::vector<std::string> WalkChildDirectory(const char * directoryPath);
		//ScrewExtend_API static inline std::vector<std::string> WalkChildFile(const char * directoryPath);

	private:
		ScrewExtend_API static Directory& Get();

	// class is singleton 
	public:
		ScrewExtend_API Directory(Directory&) = delete;

	private:
		ScrewExtend_API Directory();
		ScrewExtend_API virtual ~Directory();

	private:

	};
}