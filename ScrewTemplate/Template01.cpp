#include "ScrewExtend.h"

int main(int argc, char* argv[])
{
	ScrewExtend::Message::Init();

	SE_MESSAGE_TERMINAL_DEBUG("Template01 DEBUG T");
	SE_MESSAGE_TERMINAL_WARN("Template01 WARN T");
	SE_MESSAGE_CLIENT_DEBUG("Template01 DEBUG C");
	SE_MESSAGE_CLIENT_WARN("Template01 WARN C");

	ScrewExtend::File file("./Template01/Template01.log");

	file.Open(true);
	file.Open(true);
	file.Open(true);
	file.Open(true);
	file.Open(true);
	file.Open(true);

	file.Clear();

	file.Write("Template01.");
	file.Write("Test file.");
	file.Write("A new line.");

	file.Print();
	file.Close();

	file.Open("./Template01/Template01.txt",true);
	file.Open("./Template01/Template01.log",true);

	file.Clear();

	file.Write("Template01.");
	file.Write("Test file text file.");
	file.Write("A new line.");

	file.Print();
	file.Close();

	std::cin.get();

	ScrewExtend::Log Logfile1("Terminal", "./Log/Default.log");
	ScrewExtend::Log Logfile2("Client", "./Log/Default.log");

	Logfile1.Write("Test Log01",ScrewExtend::LogLevel::Trace);
	Logfile2.Write("Test Log01",ScrewExtend::LogLevel::Trace);
	Logfile1.Write("Test Log02",ScrewExtend::LogLevel::Trace);
	Logfile2.Write("Test Log02",ScrewExtend::LogLevel::Trace);
}