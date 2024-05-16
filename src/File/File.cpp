#include "File/File.h"
#include "File/File_Config.h"

#include "SE_Micro.h" 
#include "SE_Config.h"

#include "Math/Unit.h"

#include "Message/Message.h"
#include "Message/Message_Micro.h"

#include "Directory/Directory.h"

#include <filesystem>
#include <cassert>
#include <format>

namespace ScrewExtend {
	bool File::isFilePathValid(std::string filepath)
	{
		FS::path _p(filepath);
		return FS::status(_p).type() == FILESYSTEM_TYPE_FILE;
	}

	File::File()
		:m_valid(false), 
		m_filefolder(""), 
		m_filename(""),
		m_ofstream(nullptr),
		m_ifstream(nullptr)
	{
	}

	File::File(std::string filepath)
		:m_valid(false), 
		m_ofstream(nullptr),
		m_ifstream(nullptr)
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
		CloseStream();
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

				if (OpenWriteStream() == -1)
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

				if (OpenWriteStream() == -1)
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

	int File::OpenWriteStream()
	{
		std::string _Path = GetFullPath();

		m_ofstream = new std::ofstream(_Path.c_str(), std::ios_base::out | std::ios_base::app, _SH_DENYNO);

		return m_ofstream->is_open() ? 0 : -1;
	}

	int File::OpenReadStream()
	{
		std::string _Path = GetFullPath();

		m_ifstream = new std::ifstream(_Path.c_str(), std::ios_base::in, _SH_DENYNO);

		return m_ifstream->is_open() ? 0 : -1;
	}

	void File::CloseWriteStream()
	{
		if (m_ofstream != nullptr) 
		{
			if (m_ofstream->is_open())
			{
				m_ofstream->flush();
				m_ofstream->close();
			}

			delete m_ofstream;
			m_ofstream = nullptr;
		}
	}

	void File::CloseReadStream()
	{
		if (m_ifstream != nullptr) 
		{
			if (m_ifstream->is_open())
			{
				m_ifstream->close();
			}

			delete m_ifstream;
			m_ifstream = nullptr;
		}
	}

	void File::CloseStream()
	{
		CloseWriteStream();
		CloseReadStream();
	}

	void File::Close()
	{
		CloseStream();

		m_valid = false;

		m_filename = "";
		m_filefolder = "";
	}

	bool File::Write(std::string Content)
	{
		if (m_valid && m_ofstream!= nullptr)
		{
			*m_ofstream << Content << std::endl;
			m_ofstream->flush();

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

		CloseStream();

		m_ofstream = new std::ofstream(GetFullPath(), std::ios::out | std::ios::trunc);

	#ifdef _DEBUG
		SE_MESSAGE_TERMINAL_TRACE(FILE_CLEAR_TIP,GetFullPath(), SE_DEBUG_FUNCTION_DETAIL_OUT);
	#endif

	}

	std::vector<std::string> File::GetContent()
	{
		std::vector<std::string> *vector = new std::vector<std::string>();

		if (!m_valid)
		{
			return *vector;
		}

		CloseReadStream();
		OpenReadStream();

		std::string line;
		
		if (m_ifstream->is_open())
		{
			while (getline(*m_ifstream, line))
			{
				vector->push_back(line);
			}

			CloseReadStream();
		}

		return *vector;
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