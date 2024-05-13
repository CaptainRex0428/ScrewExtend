#include "Directory/Directory.h"
#include "Directory/Directory_Config.h"
#include "ScrewExtend_Config.h"
#include "ScrewExtend_Micro.h" 
#include "Message/Message.h"

#include <iostream>
#include <filesystem>
#include <direct.h>

namespace ScrewExtend
{
	Directory::Directory()
	{
	}

	Directory::~Directory()
	{
	}

	Directory& Directory::Get()
	{
		static Directory instance;
		return instance;
	}

	struct stat Directory::GetDirectoryStat(const char* directoryPath)
	{
		struct stat statbuf;
		stat(directoryPath, &statbuf);
		return statbuf;
	}

	bool Directory::isDirectoryPathValid(const char* directoryPath, const char* _functionName, bool isError)
	{
		// check the path look like
		std::filesystem::path targetPath(directoryPath);

		if (strcmp(targetPath.extension().string().c_str(),"")!=0)
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_DIRECTORY_PATH_NOT_DIRECTORY_LIKE_ERROR, directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
		#endif
			return false;
		};

		struct stat statbuf;

		//check the path exist
		if (stat(directoryPath, &statbuf) == -1)
		{
		#ifdef _DEBUG
			if (isError)
			{
				Message::GetTerminalMessager()->error(SCREW_EXTEND_DIRECTORY_PATH_NOT_EXIST_ERROR, directoryPath, _functionName);
			}
			else
			{
				Message::GetTerminalMessager()->warn(SCREW_EXTEND_DIRECTORY_PATH_NOT_EXIST_ERROR, directoryPath, _functionName);
			}
		#endif
			return false;
		}

		//check the path stat
		if (!(statbuf.st_mode & S_IFDIR))
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_DIRECTORY_PATH_NOT_DIRECTORY_ERROR, directoryPath, _functionName);
		#endif
			return false;
		}

		return true;
	}

	ScrewExtend_API bool Directory::isDirectoryPathValid(const char* directoryPath, bool isError)
	{
		return isDirectoryPathValid(directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE_DEFAULT, isError);
	}

	ScrewExtend_API bool Directory::Create(const char* directoryPath, bool force)
	{
		if (isDirectoryPathValid(directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE, 0))
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->warn(SCREW_EXTEND_DIRECTORY_PATH_EXIST_ERROR, directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
		#endif
			return false;
		}

		std::filesystem::path targetPath(directoryPath);

		if (_mkdir(directoryPath) == -1)
		{
			if (force)
			{
				std::vector<std::string> directorylist;
				std::filesystem::path BeginPath = targetPath;

				while (true)
				{
					directorylist.push_back(BeginPath.string());
					BeginPath = BeginPath.parent_path();

					if (exists(BeginPath))
					{
						break;
					}
				}

				for (std::vector<std::string>::iterator it = directorylist.end(); it != directorylist.begin(); it--)
				{
					std::string path = *(it - 1);
					int result = _mkdir(path.c_str());
				}
			}
			else
			{
			#ifdef _DEBUG
				Message::GetTerminalMessager()->error(SCREW_EXTEND_DIRECTORY_PARENT_PATH_NOT_EXIST_ERROR, GetParentDirectoryFromPath(directoryPath), SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
				Message::GetTerminalMessager()->error(SCREW_EXTEND_TIP_FUNCTION_FORCE,SCREW_EXTEND_VNAME(force),"true");
			#endif
				return false;
			}
		}

	#ifdef _DEBUG
		Message::GetTerminalMessager()->debug(SCREW_EXTEND_DIRECTORY_CREATED_TIP, directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
	#endif

		return true;
	}

	ScrewExtend_API int Directory::Walk(const char* directoryPath, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion)
	{
		if (!isDirectoryPathValid(directoryPath))
		{
			return -1;
		}

		intptr_t pathHandle;
		struct _finddata_t pathInfo;

		std::string pathTemp;

		if ((pathHandle = _findfirst(pathTemp.assign(directoryPath).append("/*").c_str(), &pathInfo)) != -1)
		{
			do
			{
				if (pathInfo.attrib & _A_SUBDIR)
				{
					if (strcmp(pathInfo.name, ".") != 0 && strcmp(pathInfo.name, "..") != 0)
					{
						folders.push_back(pathTemp.assign(directoryPath).append("/").append(pathInfo.name));
						
						if (recursion) 
						{
							Walk(pathTemp.assign(directoryPath).append("/").append(pathInfo.name).c_str(), files, folders, recursion);
						}
					}
				}
				else
				{
					files.push_back(pathTemp.assign(directoryPath).append("/").append(pathInfo.name));
				}
			} while (_findnext(pathHandle, &pathInfo) == 0);

		}

		return 0;
	}

	ScrewExtend_API int Directory::Walk(const char* directoryPath, bool clear, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion)
	{
		if (clear)
		{
			files.clear();
			folders.clear();

		#ifdef _DEBUG
			Message::GetTerminalMessager()->debug(SCREW_EXTEND_TIP_VARIABLE_RESET,SCREW_EXTEND_VNAME(files));
			Message::GetTerminalMessager()->debug(SCREW_EXTEND_TIP_VARIABLE_RESET,SCREW_EXTEND_VNAME(folders));
		#endif
		}

		return Walk(directoryPath, files, folders, recursion);
	}

	ScrewExtend_API std::tuple<bool, struct stat> Directory::GetDirectoryInfo(const char* directoryPath)
	{
		if (!isDirectoryPathValid(directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return { false, struct stat()};
		}

		return {true,GetDirectoryStat(directoryPath)};
	}

	ScrewExtend_API std::string Directory::GetParentDirectoryFromPath(const char* directoryPath)
	{
		std::filesystem::path dict_path(directoryPath);
		return dict_path.parent_path().string();
	}
}
