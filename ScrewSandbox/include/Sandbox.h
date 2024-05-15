#pragma once

#include "ScrewExtend.h"

namespace ScrewSandbox
{
	class Sandbox
	{
	public:
		Sandbox(Sandbox&) = delete;

		static int Init();
		static void RunLoop();
		static void ShutDown();

	public:
		int PullEvents();
		int Update();
		int Output();
	
	private:
		Sandbox();
		~Sandbox();

		static Sandbox& Get() ;

	private:
		bool m_isRunning;
		SE_FILE* m_f;
	};

	class Entity
	{
	public:
		Entity(Entity&) = delete;

		static void Init(std::string _Path);
		static void write(std::string message);
		static void print();

	private:
		Entity();
		virtual ~Entity();

		static Entity& Get();

	private:
		SE_FILE* m_fileA;
	};
}