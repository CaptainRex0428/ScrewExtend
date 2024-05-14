#pragma once

#include "ScrewExtend_API.h"
#include "Clock/Clock.h"

namespace ScrewExtend
{
	class Timer : virtual public Clock
	{
	public:
		ScrewExtend_API Timer(const char * _tag, const char * _obj, bool _traced, double & _ms);
		ScrewExtend_API virtual ~Timer();

	private:
	
	// var
	protected:
		const char* m_tag;
		const char* m_obj;
		bool m_traced;
		double* m_ms;
		CHRONO_HIGHRES_CLOCK::time_point m_ConstructedTime;
		CHRONO_HIGHRES_CLOCK::time_point m_DestructedTime;
	};
}