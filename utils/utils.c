/**
 * @file utils.c
 * @author Young Sideways (young.sideways@mail.ru)
 * @brief Библиотека полезных утилит для тестирования и отладки
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 */

#include "utils.h"

#include <stdio.h>
#include <ctype.h>
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

char* timer_str(timer_t* timer, char* str) {
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
	return str;
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

char* timer_str(timer_t* timer, char* str) {
	assert(timer);
	assert(!timer->started);
	assert(str);

	double sec = ((double)timer->time / CLOCKS_PER_SEC);
	sprintf(str, "%.3Lfs", sec);
	return str;
}
#endif // OS Related

void swap(void* lhs, void* rhs, size_t size) {
	for (; size % sizeof(size_t); ++(char*)lhs, ++(char*)rhs, --size) {
		*(char*)lhs ^= *(char*)rhs;
		*(char*)rhs ^= *(char*)lhs;
		*(char*)lhs ^= *(char*)rhs;
	}
	for (size /= sizeof(size_t); size; ++(size_t*)lhs, ++(size_t*)rhs, --size) {
		*(size_t*)lhs ^= *(size_t*)rhs;
		*(size_t*)rhs ^= *(size_t*)lhs;
		*(size_t*)lhs ^= *(size_t*)rhs;
	}
}

char getch_menu() {
	char mode = '\0';
	do {
		mode = getchar();
	} while (isspace(mode));
	while (getchar() != '\n');
	return mode;
}