/*******************************************************************************
 *  @file      timer.h
 *  @brief     high precision single thread timer for mesure code performance and
 *             work with time stamps
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_

#pragma once

#pragma region --- INCLUDES ---

#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#pragma endregion

#pragma region --- MACROS ---

#define INVALID_TIME ((timediff_t)-1)

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef int64_t timediff_t;

typedef struct {
    struct timespec begin;
    timediff_t elapsed;
    bool started;
    char string[32];
} timer_t;

typedef enum {
    TIM_STATE_INVALID = -1,
    TIM_STATE_OK      =  0,
    TIM_STATE_FAIL    =  1
} timer_state_t;

typedef enum {
    TIM_PRECISION_AUTO          = -1,
    TIM_PRECISION_NANOSECONDS   =  0,
    TIM_PRECISION_MICROSECONDS  =  1,
    TIM_PRECISION_MILLISECONDS  =  2,
    TIM_PRECISION_SECONDS       =  3
} timer_precision_t;

#pragma endregion

#pragma region --- FUNCIONS ---

timer_state_t     tim_start(timer_t* timer);
timer_state_t     tim_stop(timer_t* timer);
timer_state_t     tim_continue(timer_t* timer);
timediff_t        tim_elapsed(const timer_t* timer);
const char const* tim_str(timer_t* timer, timer_precision_t precision);

#pragma endregion

#endif // !_TIMER_H_
