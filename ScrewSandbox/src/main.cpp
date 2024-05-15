#include "Sandbox.h"

int main(int argc, char * argv[])
{
	if (ScrewSandbox::Sandbox::Init())
	{
		ScrewSandbox::Sandbox::RunLoop();
		ScrewSandbox::Sandbox::ShutDown();
	}
}