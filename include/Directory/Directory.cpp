#include "Directory/Directory.h"
#include "Directory/Directory_Config.h"
#include "Message/Message.h"

namespace ScrewExtend
{
    Directory::Directory()
    {
    }

	Directory::~Directory()
	{
	}

    bool Directory::isDirectoryPathValid(const char* directoryPath, const char* _functionName, bool isError)
    {
        struct stat statbuf;
        if (stat (directoryPath, &statbuf) == -1)
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

    Directory& Directory::Get()
    {
        static Directory instance;
        return instance;
    }
}
