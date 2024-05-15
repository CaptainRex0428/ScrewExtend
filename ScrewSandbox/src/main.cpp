#include "Sandbox.h"

int main(int argc, char * argv[])
{
	if (ScrewSandbox::Sandbox::Init())
	{
		ScrewSandbox::Sandbox::RunLoop();
		ScrewSandbox::Sandbox::ShutDown();
	}
}

//int main(int argc, char* argv[])
//{
//	// ScrewSandbox::Sandbox::Init();
//	ScrewExtend::Message::Init();
//	ScrewExtend::File file("./release/re01.log");
//
//	file.Open(true);
//	file.Open(true);
//	file.Open(true);
//	file.Open(true);
//	file.Open(true);
//	file.Open(true);
//
//	file.Clear();
//
//	file.Write("ReMessage01");
//	file.Write("ReMessage02");
//	file.Write("ReMessage02");
//
//	file.Print();
//	file.Close();
//
//	file.Open("./release/re02.log",true);
//
//	file.Clear();
//
//	file.Write("ReMessage01");
//	file.Write("ReMessage02");
//	file.Write("ReMessage02");
//
//	file.Print();
//	file.Close();
//}

//int main ()
//{
//	ScrewSandbox::Sandbox::Init();
//
//	SE_MESSAGE_TERMINAL_DEBUG("CCC");
//	SE_MESSAGE_TERMINAL_WARN("PPPP");
//	SE_MESSAGE_CLIENT_DEBUG("CCC");
//	SE_MESSAGE_CLIENT_WARN("PPPP");
//	return 0;
//}

//int main()
//{
//	ScrewExtend::Message::Init();
//
//	ScrewSandbox::Entity::Init("./Dist/Dist");
//
//	ScrewSandbox::Entity::write("Dist Dist");
//	ScrewSandbox::Entity::print();
//
//}