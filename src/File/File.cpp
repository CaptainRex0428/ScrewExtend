#include "File/File.h"
#include "File/File_Config.h"

#include "Math/Unit.h"
#include "ScrewExtend_Micro.h" 
#include "ScrewExtend_Config.h"

#include "Message/Message.h"
#include "Directory/Directory.h"

#include <Windows.h>
#include <iostream>
#include <algorithm>

#include <filesystem>
#include <format>

namespace ScrewExtend {

	std::string File::GetFileNameFromPath(const char* filepath)
	{
		std::filesystem::path fs_path(filepath);

		std::string filename = fs_path.filename().string();
		std::string filename_nosub = fs_path.stem().string();

		#ifdef SCREW_EXTEND_FILE_GET_NAME_SUBFIX
			return filename;
		#else
			return filename_nosub;
		#endif
		
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
				Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_PATH_NEXIST_ERROR, filepath, _functionName);
			}
			else
			{
				Message::GetTerminalMessager()->warn(SCREW_EXTEND_FILE_PATH_NEXIST_ERROR, filepath, _functionName);
			}
		#endif
			return false;
		}

		if (!(statbuf.st_mode & S_IFREG))
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_PATH_NFILE_ERROR, filepath, _functionName);
		#endif
			return false;
		}

		return true;
	}

	bool File::isFilePathValid(const FstreamSession* filesession, const char* _functionName, bool isError)
	{
		if (filesession == nullptr)
		{
			#ifdef _DEBUG
				Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_OBJ_NINIT_ERROR, m_fstreamSession->SessionName, _functionName);
			#endif
			return false;
		}

		return isFilePathValid(filesession->SessionName.c_str(),_functionName,isError);
	}

	bool File::isFilePathValid(const char* filepath, bool isError)
	{
		return isFilePathValid(filepath, SCREW_EXTEND_DEBUG_FUNCTION_TYPE_DEFAULT, isError);
	}

	bool File::isContentValid(const char* Content,const char * _functionName)
	{
		if (*Content == 0LL)
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_MESSAGE_EMPTY_ERROR, _functionName);
		#endif

			return false;
		}

		return true;
	}

	bool File::isContentValid(const char* content)
	{
		return isContentValid(content, SCREW_EXTEND_DEBUG_FUNCTION_TYPE_DEFAULT);
	}

	File::File()
		: m_fstreamSession(nullptr), m_fstream(std::fstream()), m_fileInfo(struct stat())
	{
	}

	File::File(const char* filepath)
		:m_fstream(std::fstream()), m_fileInfo(struct stat())
	{
		m_fstreamSession = new FstreamSession({ filepath });
	}

	File::~File()
	{
		if (m_fstream.is_open() || m_fstreamSession != nullptr)
		{
			Close();
		}
	}

	struct stat File::GetFileStat()
	{
		return m_fileInfo;
	}

	int File::Open(bool force)
	{
		if (!isFilePathValid(m_fstreamSession, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__,!force))
		{
			std::string fileFolder = Directory::GetParentPath(m_fstreamSession->SessionName.c_str());
			
			if(Directory::isDirectoryPathValid(fileFolder.c_str(),false))
			{
				if(force)
				{
					Directory::Create(fileFolder.c_str(), true);
				}
			}

			m_fstream.open(m_fstreamSession->SessionName, SCREW_EXTEND_FILE_DEFAULT_MODE);
			
			if (m_fstream.is_open())
			{
				m_fileInfo = GetFileStat(m_fstreamSession->SessionName.c_str());
			
			#ifdef _DEBUG
				Message::GetTerminalMessager()->debug(SCREW_EXTEND_FILE_CREATED_TIP, m_fstreamSession->SessionName, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
			#endif
				// m_fstream.flush();

				SCREW_EXTEND_FILECREATE_DELAY;
				return 0;
			}

			#ifdef _DEBUG
				Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_FOLDER_PATH_NEXIST_ERROR, m_fstreamSession->SessionName, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
				Message::GetTerminalMessager()->error(SCREW_EXTEND_TIP_FUNCTION_FORCE, SCREW_EXTEND_VNAME(force), "true");
			#endif

			delete m_fstreamSession;
			m_fstreamSession = nullptr;
			return -1;
		}
		else
		{
			// path valid
			m_fstream.open(m_fstreamSession->SessionName, SCREW_EXTEND_FILE_DEFAULT_MODE);

			if (m_fstream.is_open())
			{
				m_fileInfo = GetFileStat(m_fstreamSession->SessionName.c_str());
				m_fstream.flush();

				SCREW_EXTEND_FILECREATE_DELAY;
				return 0;
			}
			delete m_fstreamSession;
			m_fstreamSession = nullptr;
			return -1;
		}
	}

	int File::Open(const char* filepath, bool force)
	{
		if(*filepath != 0LL)
		{
			m_fstreamSession = new FstreamSession({ filepath });

			return Open(force);
		}

		return -1;
	}

	int File::Close()
	{
		if (m_fstream.is_open() || m_fstreamSession != nullptr) 
		{
			m_fstream.clear();
			m_fstream.flush();
			m_fstream.close();

			delete m_fstreamSession;
			m_fstreamSession = nullptr;

			return 1;
		}

		return 0;
	}
	
	bool File::AppendContent(const char* message)
	{
		if (!isContentValid(message))
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_MESSAGE_EMPTY_ERROR, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
		#endif
			return false;
		}

		if(m_fstream.is_open())
		{
			m_fstream << message << std::endl;

			m_fstream.flush();
			return true;
		}

	#ifdef _DEBUG
		Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_OBJ_NINIT_ERROR, m_fstreamSession->SessionName,SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
	#endif

		return false;
	}

	void File::ClearContent()
	{
		if(!m_fstream.is_open())
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_OBJ_NINIT_ERROR, m_fstreamSession->SessionName, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
		#endif
			return;
		}

		
		m_fstream.flush();
		m_fstream.close();

		m_fstream.clear();
		

		m_fstream.open(m_fstreamSession->SessionName, SCREW_EXTEND_FILE_CLEAR_MODE);

		m_fstream.flush();
		m_fstream.close();

		m_fstream.clear();

		// update info
		m_fstream.open(m_fstreamSession->SessionName, SCREW_EXTEND_FILE_DEFAULT_MODE);

		m_fstream.flush();

		m_fileInfo = GetFileStat(m_fstreamSession->SessionName.c_str());

	#ifdef _DEBUG
		Message::GetTerminalMessager()->debug(SCREW_EXTEND_FILE_CLEAR_TIP, m_fstreamSession->SessionName, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
	#endif
	}

	std::vector<std::string>& File::GetContent()
	{
		std::vector<std::string>* list = new std::vector<std::string>();

		if (!m_fstream.is_open())
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_OBJ_NINIT_ERROR, m_fstreamSession->SessionName, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
		#endif
			return *list;
		}

		std::fstream fsm(m_fstreamSession->SessionName, SCREW_EXTEND_FILE_GET_MODE);
		
		std::string line;

		while(getline(fsm,line))
		{
			list->push_back(line);
		}

		return *list;
	}

	void File::PrintContent()
	{
		if (!m_fstream.is_open())
		{
		#ifdef _DEBUG
			Message::GetTerminalMessager()->error(SCREW_EXTEND_FILE_OBJ_NINIT_ERROR, m_fstreamSession->SessionName, SCREW_EXTEND_DEBUG_FUNCTION_DETAIL ? __FUNCSIG__ : __FUNCTION__);
		#endif
			return;
		}

		std::vector<std::string> list = GetContent();

		auto filename = GetFileNameFromPath(m_fstreamSession->SessionName.c_str());
		auto [s_u,s_size] =  ByteSizeConvert(m_fileInfo.st_size);

		Message::GetTerminalMessager()->trace(std::format(SCREW_EXTEND_SLASH_TILTE_PATTERN, SCREW_EXTEND_SLASH,filename,s_size,s_u));

		for (auto line : list)
		{
			Message::GetTerminalMessager()->trace(line);
		}

		Message::GetTerminalMessager()->trace(std::format(SCREW_EXTEND_SLASH_FOOTER_PATTERN, SCREW_EXTEND_SLASH,filename,s_size,s_u));
	}
}