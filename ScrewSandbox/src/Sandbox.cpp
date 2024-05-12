#include "ScrewExtend.h"

#include "Clock/Clock_Config.h"

int main(int argc, char * argv[])
{
	ScrewExtend::Message::Init();

	ScrewExtend::File::Create("./log/test.log");
	ScrewExtend::File::AppendContent("This is a test content created by sandbox.","./log/test.log");

	ScrewExtend::File::Create("./test.log");
	ScrewExtend::File::ClearContent("./test.log");
	ScrewExtend::File::AppendContent("ABCDEFGHIJKLMN1234567890","./test.log");
	ScrewExtend::File::AppendContent("This is a test content created by sandbox.","./test.log");
	ScrewExtend::File::PrintContent("./test.log");
}