#pragma once

#include "ScrewExtend_API.h"

#include "ScrewExtend_Config.h"

#include "File/File_Define.h"

#include <fstream>
#include <string>
#include <vector>


namespace ScrewExtend
{
	class File
	{
	// static
	public:
		ScrewExtend_API static bool isFilePathValid(std::string filepath);

	// class
	public:
		ScrewExtend_API File();
		ScrewExtend_API File(std::string filepath);
		ScrewExtend_API virtual ~File();

		ScrewExtend_API virtual int Open(bool force = false);
		ScrewExtend_API virtual int Open(std::string filepath, bool force = false);

		ScrewExtend_API virtual void Close();
		
		ScrewExtend_API virtual bool Write(std::string Content);

		ScrewExtend_API virtual void Print();
		ScrewExtend_API virtual void Clear();

		ScrewExtend_API std::string GetFullPath();
		ScrewExtend_API std::vector<std::string> GetContent();
		ScrewExtend_API uintmax_t GetFileByteSize();
	protected:
		ScrewExtend_API virtual int OpenStream();
	
	//var
	protected:
		bool m_valid;
		std::string m_filefolder;
		std::string m_filename;
		std::ifstream m_ifstream;
		std::ofstream m_ofstream;
	};

}