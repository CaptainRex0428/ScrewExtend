#include "ScrewExtend.h"

namespace ScrewExtend
{
	int Init()
	{
		ScrewExtend::Message::Init();

		auto result = ScrewExtend::GlobalClock::Init();

		return result;
	}
}