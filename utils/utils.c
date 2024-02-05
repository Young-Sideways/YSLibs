#include "utils.h"

#include <stdio.h>
#include <assert.h>

#if (__STDC_VERSION__ >= 201112L)

void timer_start(timer_t* timer) {
	assert(timer);

	if (timespec_get(timer, TIME_UTC)) {
		timer->started = true;
	}
}
void timer_elapsed(timer_t* timer) {
	assert(timer);
	assert(timer->started);

	struct timespec now;
	if (timespec_get(&now, TIME_UTC)) {
		int64_t nsec = (now.tv_sec - timer->tv_sec) * 1000000000 + (now.tv_nsec - timer->tv_nsec);

		assert(nsec >= 0);

		timer->tv_sec = nsec / 1000000000;
		timer->tv_nsec = nsec % 1000000000;
		timer->started = false;
	}
}

void timer_str(timer_t* timer, char* str) {
	assert(timer);
	assert(!timer->started);
	assert(str);

	uint64_t nsec = timer->tv_sec * 1000000000 + timer->tv_nsec;
	if (nsec > 1000000000)
		sprintf(str, "%.3lfs", (double)nsec / 1000000000);
	else if (nsec > 1000000)
		sprintf(str, "%.3lfms", (double)nsec / 1000000);
	else if (nsec > 1000)
		sprintf(str, "%.3lfus", (double)nsec / 1000);
	else
		sprintf(str, "%lluns", nsec);
}
#else

void timer_start(timer_t* timer) {
	assert(timer);

	timer->time = clock();
	timer->started = true;
}
void timer_elapsed(timer_t* timer) {
	assert(timer);
	assert(timer->started);

	timer->time = clock() - timer->time;
	timer->started = false;
	assert(timer->time >= 0);
}

void timer_str(timer_t* timer, char* str) {
	assert(timer);
	assert(!timer->started);
	assert(str);

	double sec = ((double)timer->time / CLOCKS_PER_SEC);
	sprintf(str, "%.3Lfs", sec);
}
#endif // OS Related
