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
		ScrewExtend_API static bool isDirectoryPathValid(const char* directoryPath, bool isError = true);
		
		ScrewExtend_API static bool Create(const char* directoryPath,bool force = false);

		ScrewExtend_API static int Walk(const char* directoryPath, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion = false);
		ScrewExtend_API static int Walk(const char* directoryPath, bool clear, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion = false);

		ScrewExtend_API static std::tuple<bool, struct stat> GetDirectoryInfo(const char* directoryPath);   
		ScrewExtend_API static std::string GetParentPath(const char * directoryPath);


	private:
		ScrewExtend_API static Directory& Get();

		ScrewExtend_API static struct stat GetDirectoryStat(const char* directoryPath);

	// class is singleton 
	public:
		ScrewExtend_API Directory(Directory&) = delete;

	private:
		ScrewExtend_API Directory();
		ScrewExtend_API virtual ~Directory();

	};
}