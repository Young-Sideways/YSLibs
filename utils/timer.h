/*******************************************************************************
 *  @file      timer.h
 *  @brief     high precision single thread timer for mesure code performance and
 *             work with time stamps
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_

#pragma once

#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
typedef int64_t timediff_t;
#define DEFAULT_TIME 0
#define INVALID_TIME -1
typedef struct {
    struct timespec begin, end;
    timediff_t elapsed;
    bool started;
} timer_t;
#else
#define DEFAULT_TIME (clock_t)0
#define INVALID_TIME (clock_t)-1

typedef clock_t timediff_t;
typedef struct {
    clock_t begin, end;
    timediff_t elapsed;
    bool started;
} timer_t;
#endif

typedef enum {
    TIM_OK,
    TIM_FAIL,
    TIM_ALREADY_STARTED,
    TIM_ALREADY_STOPED,
    TIM_INVALID
} timer_state_t;


timer_state_t tim_start(timer_t* timer);
timer_state_t tim_stop(timer_t* timer);
timediff_t    tim_elapsed(const timer_t* timer);
timer_state_t tim_continue(timer_t* timer);
const char*   tim_str(timer_t* timer, char* str);

#endif // !_TIMER_H_
