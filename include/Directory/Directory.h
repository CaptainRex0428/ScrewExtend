#pragma once 

#include "SE_API.h"

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

namespace ScrewExtend
{
	class Directory
	{
	//static 
	public:

		SE_API static bool isDirectoryPathValid(std::string directoryPath);
		
		SE_API static bool Create(std::string directoryPath,bool force = false);

		SE_API static int Walk(std::string directoryPath, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion = false);
		SE_API static int Walk(std::string directoryPath, bool clear, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion = false);
		
		SE_API static std::string GetParentPath(std::string directoryPath);

	private:
		SE_API static Directory& Get();

	// class is singleton 
	public:
		SE_API Directory(Directory&) = delete;

	private:
		SE_API Directory();
		SE_API virtual ~Directory();

	};
}