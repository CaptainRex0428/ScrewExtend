#pragma once

#define CHRONO ::std::chrono

#define CHRONO_SYSTEM_CLOCK ::std::chrono::system_clock
#define CHRONO_STEADY_CLOCK ::std::chrono::steady_clock
#define CHRONO_HIGHRES_CLOCK ::std::chrono::high_resolution_clock

#define MAX_TIME_STRING_SIZE 100
#define TIME_STRING_PATTERN_CORE "%Y-%m-%d-%H:%M:%S"
#define TIME_STRING_PATTERN_FULL "%Y-%m-%d-%H:%M:%S %a."