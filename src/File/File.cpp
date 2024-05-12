#include "File/File.h"
#include "Message/Message.h"
#include "File/File_Config.h"

#include "Directory/Directory.h"

#include "Math/Unit.h"

#include <iostream>
#include <algorithm>

#include <fstream>
#include <filesystem>

namespace ScrewExtend {

	File::File(const char * filepath)
	{
		m_filepath = std::make_shared<char>(*filepath);
		m_fileInfo = GetFileInfo(filepath);
	}

	File::~File()
	{

	}

	bool File::AppendContent(const char* message, const char* filepath)
	{
		if(!isMessageValid(message, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return false;
		}

		if (!isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return false;
		};

		std::fstream filestream(filepath, std::ios::out | std::ios::app);
		
		filestream << message << std::endl;

		filestream.flush();
		filestream.close();

		return true;
	}

	bool File::ReplaceContent(const char* message_src, const char* message_rpc, const char* filepath)
	{
		std::vector<std::string> Content = GetContent(filepath);

		if (Content.size() == 0)
		{
			return false;
		}

		ClearContent(filepath);
		
		bool replaced = false;

		for (auto& line : Content)
		{
			while (true)
			{
				auto exists = line.find(message_src);

				if (exists != std::string::npos)
				{
					line.replace(exists, std::strlen(message_src), message_rpc);
					replaced = true;
				}
				else
				{
					break;
				}
			}

			AppendContent(line.c_str(), filepath);
		}

		return replaced;
	}

	bool File::UpdateContent(const char* message, const char* filepath)
	{
		if (!isMessageValid(message, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return false;
		}

		if (!isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return false;
		};

		std::fstream filestream(filepath, std::ios::out | std::ios::trunc);

		filestream << message << std::endl;

		filestream.flush();
		filestream.close();

		return true;
	}

	void File::ClearContent(const char* filepath)
	{
		if (!isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return;
		};

		std::fstream filestream(filepath, std::ios::out | std::ios::trunc);
		filestream.flush();
		filestream.close();
	}

	void File::PrintContent(const char* filepath)
	{
		if (!isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return;
		};

		std::fstream filestream(filepath, std::ios::in);
		std::vector<std::string>* fileContent = new std::vector<std::string>();
		std::string line;

		while (getline(filestream, line))
		{
			fileContent->push_back(line);
		}
		
		auto [Unit,OutSize] = ByteSizeConvert(GetFileStat(filepath).st_size);
		std::string name = GetFileNameFromPath(filepath);

		Message::GetTerminalMessager()->trace(SCREW_EXTEND_SLASH_TILTE_PATTERN, SCREW_EXTEND_SLASH,name,OutSize, Unit);

		for (auto line : *fileContent)
		{
			Message::GetTerminalMessager()->trace(line);
		}

		Message::GetTerminalMessager()->trace(SCREW_EXTEND_SLASH_FOOTER_PATTERN, SCREW_EXTEND_SLASH, name, OutSize, Unit);
	}

	std::vector<std::string>& File::GetContent(const char* filepath)
	{
		std::fstream filestream(filepath, std::ios::in);
		std::vector<std::string>* fileContent = new std::vector<std::string>();

		if (!isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return *fileContent;
		};

		std::string line;

		while (getline(filestream, line))
		{
			fileContent->push_back(line);
		}

		return *fileContent;
	}

	bool File::Create(const char* filepath, bool force)
	{
		if (isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE, 0))
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->warn(SCREW_EXTEND_FILE_PATH_EXIST_ERROR, filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
		#endif
			return false;
		}

		std::fstream filestream(filepath, std::ios::out | std::ios::trunc);
		
		if(!filestream.is_open())
		{
			if (force)
			{
				Directory::Create(GetFileDirectoyFromPath(filepath).c_str(), true);
				filestream.open(filepath, std::ios::out | std::ios::trunc);
			}
			else 
			{
			#ifdef _DEBUG
				Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_FOLDER_PATH_NOT_EXIST_ERROR, GetFileDirectoyFromPath(filepath), SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
				Message::GetTerminalMessager()->error(SCREW_EXTEND_TIP_FUNCTION_FORCE);
			#endif
				return false;
			}
		}

	#ifdef _DEBUG
		Message::GetTerminalMessager()->debug(SCREW_EXTEND_FILE_CREATED_TIP, filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE);
	#endif

		filestream.flush();
		filestream.close();

		return true;
	}

	std::tuple< bool, struct stat > File::GetFileInfo(const char* filepath)
	{
		if (!isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE))
		{
			return {false,struct stat()};
		};

		return {true,GetFileStat(filepath)};
	}

	inline std::string File::GetFileNameFromPath(const char* filepath)
	{
		std::filesystem::path fs_path(filepath);

		std::string filename = fs_path.filename().string();
		std::string filename_nosub = filename + "." + fs_path.extension().string();
		
	#ifdef SCREW_EXTEND_FILE_GET_NAME_WITH_SUBFIX
		return filename;
	#else
		std::string filename_nosub = filename.substr(0, filename.rfind("."));
		return filename_nosub;
	#endif
	}

	std::string File::GetFileDirectoyFromPath(const char* filepath)
	{
		std::filesystem::path fs_path(filepath);
		return fs_path.parent_path().string();
	}

	struct stat File::GetFileStat(const char* filepath)
	{
		struct stat statbuf;
		stat(filepath, &statbuf);
		return statbuf;
	}

	bool File::isFilePathValid(const char* filepath, const char* _functionName, bool isError)
	{
		struct stat statbuf;

		if (stat(filepath, &statbuf)==-1)
		{
		#ifdef _DEBUG
			if(isError)
			{
				Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_PATH_NOT_EXIST_ERROR, filepath, _functionName);
			}
			else
			{
				Message::GetTerminalMessager()->warn(SCREW_EXTEND_FILE_PATH_NOT_EXIST_ERROR, filepath, _functionName);
			}
		#endif
			return false;
		}

		if (!(statbuf.st_mode & S_IFREG))
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_PATH_NOT_FILE_ERROR, filepath, _functionName);
		#endif
			return false;
		}

		return true;
	}

	ScrewExtend_API bool File::isFilePathValid(const char* filepath, bool isError)
	{
		return isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE_DEFAULT, isError);
	}

	bool File::isMessageValid(const char* message,const char * _functionName)
	{
		if (*message == 0LL)
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_MESSAGE_EMPTY_ERROR, _functionName);
		#endif

			return false;
		}

		return true;
	}

	bool File::AppendContent(const char* message)
	{
		return AppendContent(message, m_filepath.get());
		auto [valid, m_fileInfo] = GetFileInfo(m_filepath.get());
	}

	bool File::ReplaceContent(const char* message_src, const char* message_rpc)
	{
		return ReplaceContent(message_src, message_rpc,m_filepath.get());
		auto [valid, m_fileInfo] = GetFileInfo(m_filepath.get());
	}

	bool File::UpdateContent(const char* message)
	{
		return UpdateContent(message, m_filepath.get());
		auto [valid, m_fileInfo] = GetFileInfo(m_filepath.get());
	}

	void File::ClearContent()
	{
		ClearContent(m_filepath.get());
		auto [valid, m_fileInfo] = GetFileInfo(m_filepath.get());
	}

	void File::PrintContent()
	{
		PrintContent(m_filepath.get());
	}

	std::vector<std::string>& File::GetContent()
	{
		return GetContent(m_filepath.get());
	}

}