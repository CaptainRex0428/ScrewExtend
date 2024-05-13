#pragma once

#pragma warning(disable:5103)
#define _SCREW_EXTEND_MICRO_CONTACT(x,y) x##y
#define SCREW_EXTEND_MICRO_CONTACT(x,y) _SCREW_EXTEND_MICRO_CONTACT(x,y)

#define SCREW_EXTEND_VNAME(value) (#value)