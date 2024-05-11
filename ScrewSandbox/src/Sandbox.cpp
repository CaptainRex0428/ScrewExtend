#include "ScrewExtend.h"

#include "Clock/Clock_Config.h"

int main(int argc, char * argv[])
{
	ScrewExtend::Message::Init();
	ENGINE_MESSAGE_TERMINAL_WARN("TerminalLogger worked!");
	ENGINE_MESSAGE_CLIENT_DEBUG("ClientLogger worked!");

	char* local = new char();
	char* gm = new char();
	ENGINE_CLOCK_CURRENT_TIME_SYS(local);
	ENGINE_CLOCK_CURRENT_TIME_GM(gm);
	std::cout << local << std::endl;
	std::cout << gm << std::endl;
}