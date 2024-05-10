#include "ScrewExtend.h"

int main(int argc, char * argv[])
{
	ScrewExtend::Message::Init();
	ENGINE_TERMINAL_WARN("TerminalLogger worked!");
	ENGINE_CLIENT_DEBUG("ClientLogger worked!");

	char* local = new char();
	char* gm = new char();
	ScrewExtend::Clock::GetCurrentTime_sys(local,true);
	ScrewExtend::Clock::GetCurrentTime_gm(gm,true);
	std::cout << local << std::endl;
	std::cout << gm << std::endl;
}