#pragma once

#define ENGINE_CLOCK_CURRENT_TIME_SYS(...) ::ScrewExtend::Clock::GetCurrentTime_sys(__VA_ARGS__)
#define ENGINE_CLOCK_CURRENT_TIME_GM(...) ::ScrewExtend::Clock::GetCurrentTime_gm(__VA_ARGS__)

#define ENGINE_CLOCK_CURRENT_TIME_HIGHRES(...) ::ScrewExtend::Clock::GetCurrentTime_HighRes(__VA_ARGS__)