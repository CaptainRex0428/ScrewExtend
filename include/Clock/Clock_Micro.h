#pragma once

#define SCREW_EXTEND_CLOCK_CURRENT_TIME_SYS(...) ::ScrewExtend::Clock::GetCurrentTime_sys(__VA_ARGS__)
#define SCREW_EXTEND_CLOCK_CURRENT_TIME_GM(...) ::ScrewExtend::Clock::GetCurrentTime_gm(__VA_ARGS__)

#define SCREW_EXTEND_CLOCK_CURRENT_TIME_HIGHRES(...) ::ScrewExtend::Clock::GetCurrentTime_HighRes(__VA_ARGS__)

#define SCREW_EXTEND_CLOCK_PROCESS_START_SYS_TIME(...) ::ScrewExtend::Clock::GetProcessStartTime(__VA_ARGS__)
#define SCREW_EXTEND_CLOCK_PROCESS_START_SYS_TIME_CHAR(...) ::ScrewExtend::Clock::GetProcessStartTime_CHAR(__VA_ARGS__)
#define SCREW_EXTEND_CLOCK_PROCESS_START_SYS_TIME_HIGHRES(...) ::ScrewExtend::Clock::GetProcessStartTime_HIGHRES(__VA_ARGS__)


#define SCREW_EXTEND_CLOCK_ASSIGN_RECORDER_CHAR(value) char* value = new char();
#define SCREW_EXTEND_CLOCK_ASSIGN_RECORDER_LONG(value) long long value = 0;

#define SCREW_EXTEND_CLOCK_RECORDER_START_CHAR(value) const char* value = new char();value =ScrewExtend::Clock::GetProcessStartTime_CHAR();
#define SCREW_EXTEND_CLOCK_RECORDER_START_LONG(value) const long long value = ScrewExtend::Clock::GetProcessStartTime_HIGHRES()->time_since_epoch().count();