#include "ScrewExtend.h"

class Entity
{
public:
	Entity(Entity&) = delete;

	static void Init(std::string _Path) 
	{
		Get().m_fileA = new SE_FILE(_Path);
		Get().m_fileA->Open(true);
	};

	static void write(std::string message)
	{
		if (Get().m_fileA != nullptr)
		{
			Get().m_fileA->Write(message);
		}
	};

	static void print() 
	{
		if (Get().m_fileA != nullptr)
		{
			Get().m_fileA->Print();
		}
	};

private:
	Entity():m_fileA(nullptr) {};

	virtual ~Entity() 
	{
		if (m_fileA != nullptr)
		{
			m_fileA->Close();

			delete m_fileA;
			m_fileA = nullptr;
		}
	};

	static Entity& Get() 
	{
		static Entity instance;
		return instance;
	};

private:
	SE_FILE* m_fileA;
};

int main()
{
	ScrewExtend::Message::Init();

	ScrewExtend::MsgLog("MsgLogTestCritical",ScrewExtend::Critical);
	ScrewExtend::MsgLog("MsgLogTestWarning",ScrewExtend::Warning);
	
	Entity::Init("./Template02/Template02");

	Entity::write("Template02 test line.");
	Entity::print();

	std::cin.get();
}