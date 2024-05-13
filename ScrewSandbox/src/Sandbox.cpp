#include "ScrewExtend.h"

#include <Windows.h>

int main(int argc, char * argv[])
{
	ScrewExtend::Clock::Init();
	ScrewExtend::Message::Init();

	SCREW_EXTEND_FILE_CREATE("./log/test.log",1);
	SCREW_EXTEND_FILE_CLEAR("./log/test.log");
	SCREW_EXTEND_FILE_APPEND("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", "./log/test.log");
	SCREW_EXTEND_FILE_APPEND("This is a test content created by sandbox.","./log/test.log");
	SCREW_EXTEND_FILE_PRINT("./log/test.log");

	SCREW_EXTEND_FILE_CREATE("./log/test/test.log", 1);
	SCREW_EXTEND_FILE_CLEAR("./log/test/test.log");
	SCREW_EXTEND_FILE_APPEND("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", "./log/test/test.log");
	SCREW_EXTEND_FILE_APPEND("This is a test content created by sandbox.", "./log/test/test.log");
	SCREW_EXTEND_FILE_PRINT("./log/test/test.log");

	SCREW_EXTEND_FILE_CREATE("./test.log");
	SCREW_EXTEND_FILE_CLEAR("./test.log");
	SCREW_EXTEND_FILE_APPEND("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890","./test.log");
	SCREW_EXTEND_FILE_APPEND("This is a test content created by sandbox.","./test.log");
	SCREW_EXTEND_FILE_PRINT("./test.log");

	std::vector<std::string> list;
	std::vector<std::string> folder;
	SCREW_EXTEND_DIRECTORY_WALK("./log",true, list,folder,1);

	for (std::string a : list)
	{
		std::cout << a << std::endl;
	}

	std::cout << "------------------------------" << std::endl;

	for (std::string a : folder)
	{
		std::cout << a << std::endl;
	}

	std::cin.get();

	SCREW_EXTEND_CLOCK_RECORDER_START_CHAR(origin_c);
	SCREW_EXTEND_CLOCK_RECORDER_START_LONG(origin_d);
	std::cout << origin_c << std::endl;
	std::cout << origin_d << std::endl;

	SCREW_EXTEND_CLOCK_ASSIGN_RECORDER_CHAR(time_c);
	SCREW_EXTEND_CLOCK_ASSIGN_RECORDER_LONG(time_d);
	ScrewExtend::Clock::GetCurrentTime_sys(time_c);
	ScrewExtend::Clock::GetCurrentTime_sys(time_d);
	std::cout << time_c << std::endl;
	std::cout << time_d << std::endl;

	std::cin.get();
}