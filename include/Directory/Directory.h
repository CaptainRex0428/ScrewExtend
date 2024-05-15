#pragma once 

#include "SE_API.h"

#include <iostream>
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

		SE_API static bool isDirectoryPathValid(const char* directoryPath, const char* _functionName, bool isError = true);
		SE_API static bool isDirectoryPathValid(const char* directoryPath, bool isError = true);
		
		SE_API static bool Create(const char* directoryPath,bool force = false);

		SE_API static int Walk(const char* directoryPath, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion = false);
		SE_API static int Walk(const char* directoryPath, bool clear, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion = false);

		SE_API static std::tuple<bool, struct stat> GetDirectoryInfo(const char* directoryPath);   
		SE_API static std::string GetParentPath(const char * directoryPath);


	private:
		SE_API static Directory& Get();

		SE_API static struct stat GetDirectoryStat(const char* directoryPath);

	// class is singleton 
	public:
		SE_API Directory(Directory&) = delete;

	private:
		SE_API Directory();
		SE_API virtual ~Directory();

	};
}