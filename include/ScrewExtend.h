#pragma once

//------------------ Base tool ---------------
#include "Message/Message.h"
#include "Clock/Clock.h"
#include "Clock/GlobalClock.h"
#include "File/File.h"
#include "Directory/Directory.h"
#include "Timer/Timer.h"
#include "Trace/Trace.h"
//---------------------------------------------

//----------------- Micro Define --------------
#include "SE_Micro.h"
#include "Message/Message_Micro.h"
#include "Clock/Clock_Micro.h"
#include "Clock/GlobalClock_Micro.h"
#include "File/File_Micro.h"
#include "Directory/Directory_Micro.h"
#include "Math/Math_Micro.h"
#include "Timer/Timer_Micro.h"
#include "Trace/Trace_Micro.h"
//---------------------------------------------

namespace ScrewExtend
{
	SE_API int Init();
}