#pragma once

#include <iostream>

#include "spdlog/spdlog.h"

#include "ScrewExtend.h"

namespace ScrewExtend
{
	class ScrewExtend_API ScrewLog
	{
	public:
		ScrewLog();
		~ScrewLog();
	};

	void ScrewExtend_API Print();
}