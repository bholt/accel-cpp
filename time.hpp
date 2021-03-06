/////////////////////////////////////////////////////
// Author: Brandon Holt
// Source: github.com/bholt/accel-cpp
/////////////////////////////////////////////////////
#pragma once

#if defined(__MTA__)
#include <sys/mta_task.h>
#include <machine/runtime.h>
#elif defined(__MACH__)
#include <mach/mach_time.h>
#elif !defined(WINDOWS)
#include <time.h>
#endif

#ifdef WINDOWS
double LIToSecs( LARGE_INTEGER * L) { 
  LARGE_INTEGER frequency;
  QueryPerformanceFrequency( &frequency ) ; 
  return ((double)L->QuadPart /(double)frequency.QuadPart) ; } 
#endif

/// "Universal" wallclock time (works at least for Mac, MTA, and most Linux)
inline double walltime(void) {
#if defined(__MTA__)
	return((double)mta_get_clock(0) / mta_clock_freq());
#elif defined(__MACH__)
	static mach_timebase_info_data_t info;
	mach_timebase_info(&info);
	uint64_t now = mach_absolute_time();
	now *= info.numer;
	now /= info.denom;
	return 1.0e-9 * (double)now;
#elif defined(WINDOWS)
  // return 1.0e-3 * GetTickCount();
  // static LARGE_INTEGER freq = 0;
  // if (freq == 0) 
  LARGE_INTEGER c; QueryPerformanceCounter(&c);
  return LIToSecs(&c);
#else
	struct timespec tp;
#if defined(CLOCK_PROCESS_CPUTIME_ID)
#define CLKID CLOCK_PROCESS_CPUTIME_ID
#elif  defined(CLOCK_REALTIME_ID)
#define CLKID CLOCK_REALTIME_ID
#endif
	clock_gettime(CLOCK_MONOTONIC, &tp);
	return (double)tp.tv_sec + (double)tp.tv_nsec / BILLION;
#endif
}
