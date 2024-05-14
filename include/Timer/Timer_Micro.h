#pragma once

#define SCREW_EXTEND_TIMER_TRACE_NSTORE() double varn##__LINE__ = 0; ScrewExtend::Timer timer##__LINE__(__FUNCTION__,__FUNCSIG__,true,varn##__LINE__)
#define SCREW_EXTEND_TIMER_TRACE_STORE(varn) ScrewExtend::Timer timer##__LINE__(__FUNCTION__,__FUNCSIG__,true,varn)

#define SCREW_EXTEND_TIMER_NTRACE_NSTORE() double varn##__LINE__ = 0; ScrewExtend::Timer timer##__LINE__(__FUNCTION__,__FUNCSIG__,false,varn##__LINE__)
#define SCREW_EXTEND_TIMER_NTRACE_STORE(varn) ScrewExtend::Timer timer##__LINE__(__FUNCTION__,__FUNCSIG__,false,varn)