#include "ScrewExtend.h"

namespace ScrewExtend
{
	int Init()
	{
		ScrewExtend::Message::Init();
		ScrewExtend::GlobalClock::Init();

		return 1;
	}
}