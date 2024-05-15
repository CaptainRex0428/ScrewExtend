#include "File/File.h"
#include "File/File_Config.h"

#include "Math/Unit.h"
#include "ScrewExtend_Micro.h" 
#include "ScrewExtend_Config.h"

#include "Message/Message.h"
#include "Message/Message_Micro.h"
#include "Directory/Directory.h"

#include <iostream>
#include <filesystem>
#include <cassert>
#include <format>
#include <vector>

namespace ScrewExtend {
	bool File::isFilePathValid(std::string filepath)
	{
		FS::path _p(filepath);
		return FS::status(_p).type() == FILESYSTEM_TYPE_FILE;
	}

	ScrewExtend::File::File()
		:m_valid(false), m_filefolder(""), m_filename("")
	{
	}

	File::File(std::string filepath)
		:m_valid(false)
	{
		if (filepath.empty())
		{
			return;
		}

		FS::path p(filepath);
		m_filename = p.filename().string();
		m_filefolder = p.parent_path().string();

		if (m_filefolder.empty())
		{
			m_filefolder = "./";
		}
	}

	File::~File()
	{
		Close();
	}

	int File::Open(bool force)
	{
		if (!m_filefolder.empty() && !m_filename.empty())
		{
			if (m_valid) 
			{
			#ifdef _DEBUG
				SE_MESSAGE_TERMINAL_WARN(FILE_REOPEN_WARN, GetFullPath(), SE_DEBUG_FUNCTION_DETAIL_OUT);
			#endif
				return 0;
			}

			if (force)
			{
				if (FS::status(m_filefolder).type() != FILESYSTEM_TYPE_DIRECTORY)
				{
					FS::create_directories(m_filefolder);
				#ifdef _DEBUG
					SE_MESSAGE_TERMINAL_DEBUG(FILE_FOLDER_CREATED, m_filefolder, SE_DEBUG_FUNCTION_DETAIL_OUT);
				#endif
				}

				if (OpenStream() == -1)
				{
				#ifdef _DEBUG
					SE_MESSAGE_TERMINAL_ERROR(FILE_OPEN_FAILED, GetFullPath(), SE_DEBUG_FUNCTION_DETAIL_OUT);
				#endif
					return -1;
				}
				
				m_valid = true;
				return 0;
			}
			else
			{
				if (FS::status(GetFullPath()).type() != FILESYSTEM_TYPE_FILE)
				{
				#ifdef _DEBUG
					SE_MESSAGE_TERMINAL_ERROR(FILE_PATH_NEXIST_ERROR,GetFullPath(), SE_DEBUG_FUNCTION_DETAIL_OUT);
				#endif
					return -2;
				}

				if (OpenStream() == -1)
				{
				#ifdef _DEBUG
					SE_MESSAGE_TERMINAL_ERROR(FILE_OPEN_FAILED, GetFullPath(), SE_DEBUG_FUNCTION_DETAIL_OUT);
				#endif
					return -1;
				}

				m_valid = true;
				return 0;
			}

		}
	#ifdef _DEBUG
		SE_MESSAGE_TERMINAL_ERROR(FILE_PATH_NULL, SE_DEBUG_FUNCTION_DETAIL_OUT);
	#endif
		return -3;
	}

	int File::Open(std::string filepath, bool force)
	{
		if (filepath.empty())
		{
		#ifdef _DEBUG
			SE_MESSAGE_TERMINAL_ERROR(FILE_PATH_NULL, SE_DEBUG_FUNCTION_DETAIL_OUT);
		#endif
			return -1;
		}

		if (m_ofstream.is_open())
		{
			m_ofstream.flush();
			m_ofstream.close();
		}

		if (m_ifstream.is_open())
		{
			m_ifstream.close();
		}

		Close();

		FS::path p(filepath);
		m_filename = p.filename().string();
		m_filefolder = p.parent_path().string();

		if (m_filefolder.empty())
		{
			m_filefolder = "./";
		}

		return Open(force);
	}

	int File::OpenStream()
	{
		std::string _Path = GetFullPath();
		
		// SE_THREAD_DELAY_MICRO(SE_FILECREATE_DELAY_MICRO);
		// Problem is here
		m_ofstream.open(_Path.c_str(), std::ios::out | std::ios::app, _SH_DENYNO);

		m_ifstream.open(_Path.c_str(), std::ios::in, _SH_DENYNO);

		return (m_ofstream.is_open() && m_ifstream.is_open()) ? 0 : -1;
	}

	void File::Close()
	{
		m_valid = false;

		if (m_ofstream.is_open())
		{
			m_ofstream.flush();
			m_ofstream.close();
			m_ofstream.clear();
		}

		if (m_ifstream.is_open())
		{
			m_ifstream.close();
			m_ifstream.clear();
		};
	}

	bool File::Write(std::string Content)
	{
		if (m_valid)
		{
			m_ofstream << Content << std::endl;
			m_ofstream.flush();

			return true;
		}

		return false;
	}

	void File::Print()
	{
		if (!m_valid)
		{
			return;
		}

		auto vector = GetContent();
		auto [_unit, _size] = ByteSizeConvert(GetFileByteSize());

		SE_MESSAGE_TERMINAL_TRACE(SE_PRINT_TILTE_PATTERN, SE_PRINT_FORMAT_DASH, m_filename, _size, _unit);

		for (auto list : vector)
		{
			SE_MESSAGE_TERMINAL_TRACE(list);
		}

		SE_MESSAGE_TERMINAL_TRACE(SE_PRINT_FOOTER_PATTERN, SE_PRINT_FORMAT_DASH, m_filename, _size, _unit);
	}

	void File::Clear()
	{
		if (!m_valid)
		{
			return;
		}

		if (m_ofstream.is_open())
		{
			m_ofstream.flush();
			m_ofstream.close();
		}

		m_ofstream.open(GetFullPath(), std::ios::out | std::ios::trunc);

	#ifdef _DEBUG
		SE_MESSAGE_TERMINAL_TRACE(FILE_CLEAR_TIP,GetFullPath(), SE_DEBUG_FUNCTION_DETAIL_OUT);
	#endif

	}

	std::vector<std::string> File::GetContent()
	{
		std::vector<std::string> vector;

		if (!m_valid)
		{
			return vector;
		}

		if (m_ifstream.is_open())
		{
			m_ifstream.close();
		}

		m_ifstream.open(GetFullPath(), std::ios::in);

		std::string line;
		
		if (m_ifstream.is_open())
		{
			while (getline(m_ifstream, line))
			{
				vector.push_back(line);
			}

			m_ifstream.close();
		}

		return vector;
	}

	uintmax_t File::GetFileByteSize()
	{
		if (!m_valid)
		{
			return 0;
		}

		return FS::file_size(GetFullPath());
	}

	std::string File::GetFullPath()
	{
		return std::format("{0}/{1}", m_filefolder, m_filename);
	}

}