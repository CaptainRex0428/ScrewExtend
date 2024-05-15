#pragma once

#pragma warning(disable:5103)
#define _SE_MICRO_CONTACT(x,y) x##y
#define SE_MICRO_CONTACT(x,y) _SE_MICRO_CONTACT(x,y)

#define SE_VNAME(value) (#value)
#define SE_CNAME(value) (#value)

#define SE_THREAD_DELAY_MICRO(value) std::this_thread::sleep_for(std::chrono::microseconds(value))