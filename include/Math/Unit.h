#pragma once

#include "ScrewExtend_API.h"

#include <tuple>

namespace ScrewExtend
{
	enum ScrewExtend_API SystemSizeUnit
	{
		Byte = 0,
		KB = 1,
		MB = 2,
		GB = 3,
		TB = 4,
		PB = 5,
		EB = 6,
		ZB = 7,
		YB = 8
	};

	// transfer Byte size to specific unit output in double
	ScrewExtend_API double ByteSizeTo(int bytesize, SystemSizeUnit unit);

	// transfer Byte size to a proper unit output in double
	ScrewExtend_API std::tuple<const char*, double> ByteSizeConvert(int bytesize);

}