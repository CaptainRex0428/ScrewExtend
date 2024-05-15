#pragma once

#define SE_CLOCK_CURRENT_TIME_SYS(...) ScrewExtend::Clock::GetCurrentTime_sys(__VA_ARGS__)
#define SE_CLOCK_CURRENT_TIME_GM(...) ScrewExtend::Clock::GetCurrentTime_gm(__VA_ARGS__)

#define SE_CLOCK_CURRENT_TIME_HIGHRES(...) ScrewExtend::Clock::GetCurrentTime_HighRes(__VA_ARGS__)

#define SE_CLOCK_PROCESS_START_SYS_TIME(...) ScrewExtend::Clock::GetProcessStartTime(__VA_ARGS__)
#define SE_CLOCK_PROCESS_START_SYS_TIME_CHAR(...) ScrewExtend::Clock::GetProcessStartTime_CHAR(__VA_ARGS__)
#define SE_CLOCK_PROCESS_START_SYS_TIME_HIGHRES(...) ScrewExtend::Clock::GetProcessStartTime_HIGHRES(__VA_ARGS__)