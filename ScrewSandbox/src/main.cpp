#include "Sandbox.h"

int main(int argc, char * argv[])
{
	if (ScrewSandbox::Sandbox::Init())
	{
		ScrewSandbox::Sandbox::RunLoop();
	};

	ScrewSandbox::Sandbox::ShutDown();

	// ScrewExtend::File file0("./log/file.log");

	/*ScrewSandbox::Sandbox::Init();

	ScrewExtend::File file1;
	bool f = true;
	file1.Open("./log/file.log",f);
	file1.AppendContent("This is a test content.");
	file1.PrintContent();

	ScrewExtend::File file2;
	file2.Open("./log/file2",f);
	file2.ClearContent();
	file2.AppendContent("This is a test content.");
	file2.PrintContent();

	ScrewExtend::File file3;
	file3.Open("./log/file3.log",f);
	file3.ClearContent();
	file3.AppendContent("This is a test content.");
	file3.PrintContent();*/

}