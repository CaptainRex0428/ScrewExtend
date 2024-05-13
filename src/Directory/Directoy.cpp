#include "Directory/Directory.h"
#include "Directory/Directory_Config.h"
#include "ScrewExtend_Config.h"
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

	bool Directory::isDirectoryPathValid(const char* directoryPath, const char* _functionName, bool isError)
	{
		struct stat statbuf;
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

		if (targetPath.extension().string() != "")
		{
#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_DIRECTORY_PATH_NOT_DIRECTORY_LIKE_ERROR, directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
#endif
			return false;
		};

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
					_mkdir(path.c_str());
				}
			}
			else
			{
#ifdef _DEBUG
				Message::GetTerminalMessager()->error(SCREW_EXTEND_DIRECTORY_PARENT_PATH_NOT_EXIST_ERROR, GetParentDirectoryFromPath(directoryPath), SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
				Message::GetTerminalMessager()->error(SCREW_EXTEND_TIP_FUNCTION_FORCE);
#endif
				return false;
			}
		}

#ifdef _DEBUG
		Message::GetTerminalMessager()->debug(SCREW_EXTEND_DIRECTORY_CREATED_TIP, directoryPath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
#endif

		return true;
	}
	ScrewExtend_API std::string Directory::GetParentDirectoryFromPath(const char* directoryPath)
	{
		std::filesystem::path dict_path(directoryPath);
		return dict_path.parent_path().string();
	}
}
