/*******************************************************************************
 *  @file      timer.c
 *  @brief     high precision single thread timer for mesure code performance and
 *			   work with time stamps
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/


#include "timer.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>


#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)

#else

#endif


timer_state_t tim_start(timer_t* timer) {
	assert(timer);

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
	struct timespec now;
	if (timespec_get(&now, TIME_UTC)) {
		timer->begin = now;
		timer->started = true;
	}
	else
		return TIM_FAIL;
#else // __STDC_VERSION__ < 201112L
	timer->begin = clock();
	timer->started = true;
#endif
	timer->elapsed = 0;
	return TIM_OK;
}

timer_state_t tim_stop(timer_t* timer){
	assert(timer);

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
	struct timespec now;
	if (timespec_get(&now, TIME_UTC)) {
		timer->end = now;
		timer->started = false;
	}
	else
		return TIM_FAIL;
#else // __STDC_VERSION__ < 201112L
	timer->end = clock();
	timer->started = false;
#endif
	return TIM_OK;
}

timediff_t tim_elapsed(const timer_t* timer) {
	assert(timer);
	if (timer->started)
		return INVALID_TIME;
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
	return (timer->end.tv_sec - timer->begin.tv_sec) * 1000000000 + (timer->end.tv_nsec - timer->begin.tv_nsec);
#else // __STDC_VERSION__ < 201112L
	return timer->end - timer->begin;
#endif
}

timer_state_t tim_continue(timer_t* timer) {
	assert(timer);

	if (timer->started)
		return TIM_ALREADY_STARTED;

	timediff_t timediff = tim_elapsed(timer);
	if (timediff < 0)
		return TIM_INVALID;

	if (tim_start(timer) != TIM_OK)
		return TIM_FAIL;

	timer->elapsed += timediff;
	return TIM_OK;
}

const char* tim_str(timer_t* timer, char* str) {
	assert(timer);
	if (!str || timer->started)
		return "";

	int64_t time = tim_elapsed(timer);
	if (time < 0)
		return "";
	time += timer->elapsed;
	if (time > 1000000000)
		sprintf(str, "%.3lfs", (double)time / 1000000000);
	else if (time > 1000000)
		sprintf(str, "%.3lfms", (double)time / 1000000);
	else if (time > 1000)
		sprintf(str, "%.3lfus", (double)time / 1000);
	else
		sprintf(str, "%lluns", time);
	return str;
}


char* timer_str(timer_t* timer, char* str) {
	assert(timer);
	
	if (!str || timer->started)
		return "";
	int64_t time = tim_elapsed(timer);
	if (time < 0)
		return "";
	time += timer->elapsed;

	double sec = ((double)time / CLOCKS_PER_SEC);
	sprintf(str, "%.3Lfs", sec);
	return str;
}