#include "Sandbox.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <cassert>
#include <format>
#include <vector>

int main(int argc, char * argv[])
{
	if (ScrewSandbox::Sandbox::Init())
	{
		ScrewSandbox::Sandbox::RunLoop();
	}

	ScrewSandbox::Sandbox::ShutDown();
}