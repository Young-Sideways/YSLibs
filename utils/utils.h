#ifndef _UTILS_H_
#define _UTILS_H_

#pragma once

#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define UNUSED(var) ((void)var)


#if (__STDC_VERSION__ >= 201112L)
	typedef struct {
		struct timespec;
		bool started;
	} timer_t;
#else
	typedef struct {
		clock_t time;
		bool started;
	} timer_t;
#endif // OS Related

void timer_start(timer_t* timer);
void timer_elapsed(timer_t* timer);
void timer_str(timer_t* timer, char* str);

#endif // !_UTILS_H_