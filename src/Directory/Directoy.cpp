#include "Directory/Directory.h"
#include "Directory/Directory_Config.h"
#include "Directory/Directory_Define.h"

#include "SE_Config.h"
#include "SE_Micro.h" 

#include "Message/Message.h"
#include "Message/Message_Micro.h"

#include <filesystem>

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

	bool Directory::isDirectoryPathValid(std::string directoryPath)
	{
		FS::path _p(directoryPath);
		return FS::status(_p).type() == FILESYSTEM_TYPE_DIRECTORY;
	}

	bool Directory::Create(std::string directoryPath, bool force)
	{
		if (isDirectoryPathValid(directoryPath))
		{
		#ifdef _DEBUG
			SE_MESSAGE_TERMINAL_ERROR(SE_DIRECTORY_PATH_EXIST_ERROR, directoryPath, SE_DEBUG_FUNCTION_DETAIL_OUT ? __FUNCSIG__ : __FUNCTION__);
		#endif
			return false;
		}

		std::filesystem::path targetPath(directoryPath);

		if (force)
		{
			FS::create_directories(targetPath);
			return(isDirectoryPathValid(directoryPath));
		}
		else
		{
			FS::create_directory(targetPath);
			return(isDirectoryPathValid(directoryPath));
		}
	}

	int Directory::Walk(std::string directoryPath, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion)
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

	int Directory::Walk(std::string directoryPath, bool clear, std::vector<std::string>& files, std::vector<std::string>& folders, bool recursion)
	{
		if (clear)
		{
			if (!files.empty()) 
			{
				files.clear();
			};

			if (!folders.empty()) 
			{

				folders.clear();
			};
		}

		return Walk(directoryPath, files, folders, recursion);
	}

	std::string Directory::GetParentPath(std::string directoryPath)
	{
		std::filesystem::path dict_path(directoryPath);
		return dict_path.parent_path().string();
	}
}
