#include "ScrewExtend.h"

int main(int argc, char * argv[])
{
	ScrewExtend::Message::Init();
	ENGINE_TERMINAL_WARN("TerminalLogger worked!");
	ENGINE_CLIENT_DEBUG("ClientLogger worked!");
}