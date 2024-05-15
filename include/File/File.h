#pragma once

#include "SE_API.h"

#include "SE_Config.h"

#include "File/File_Define.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace ScrewExtend
{
	class File
	{
	// static
	public:
		SE_API static bool isFilePathValid(std::string filepath);

	// class
	public:
		SE_API File();
		SE_API File(std::string filepath);
		SE_API virtual ~File();

		SE_API virtual int Open(bool force = false);
		SE_API virtual int Open(std::string filepath, bool force = false);

		SE_API virtual void CloseStream();
		SE_API virtual void Close();
		
		SE_API virtual bool Write(std::string Content);

		SE_API virtual void Print();
		SE_API virtual void Clear();

		SE_API std::string GetFullPath();
		SE_API std::vector<std::string> GetContent();
		SE_API uintmax_t GetFileByteSize();
	protected:
		SE_API virtual int OpenWriteStream();
		SE_API virtual int OpenReadStream();
		SE_API virtual void CloseWriteStream();
		SE_API virtual void CloseReadStream();
	
	//var
	protected:
		bool m_valid;
		std::string m_filefolder;
		std::string m_filename;
		std::ifstream * m_ifstream;
		std::ofstream * m_ofstream;
	};

}