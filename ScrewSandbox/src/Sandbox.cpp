#include "ScrewExtend.h"

#include<filesystem>

int main(int argc, char * argv[])
{
	ScrewExtend::Message::Init();

	ScrewExtend::File::Create("./log/test.log",1);
	ScrewExtend::File::ClearContent("./log/test.log");
	ScrewExtend::File::AppendContent("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", "./log/test.log");
	ScrewExtend::File::AppendContent("This is a test content created by sandbox.","./log/test.log");
	ScrewExtend::File::PrintContent("./log/test.log");

	ScrewExtend::File::Create("./log/test/test.log", 1);
	ScrewExtend::File::ClearContent("./log/test/test.log");
	ScrewExtend::File::AppendContent("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", "./log/test/test.log");
	ScrewExtend::File::AppendContent("This is a test content created by sandbox.", "./log/test/test.log");
	ScrewExtend::File::PrintContent("./log/test/test.log");

	ScrewExtend::File::Create("./test.log");
	ScrewExtend::File::ClearContent("./test.log");
	ScrewExtend::File::AppendContent("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890","./test.log");
	ScrewExtend::File::AppendContent("This is a test content created by sandbox.","./test.log");
	ScrewExtend::File::PrintContent("./test.log");
}