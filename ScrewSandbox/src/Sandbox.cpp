#include "ScrewExtend.h"

int main(int argc, char * argv[])
{
	ScrewExtend::Print();

	ScrewExtend::Log::Init();
	ENGINE_TERMINAL_WARN("TerminalLogger worked!");
	ENGINE_CLIENT_DEBUG("ClientLogger worked!");
}