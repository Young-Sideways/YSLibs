/*******************************************************************************
 *  @file      timer.c
 *  @brief     high precision single thread timer for mesure code performance and
 *             work with time stamps
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "util/timer.h"

#pragma region --- INCLUDES ---

#include <assert.h>
#include <stdio.h>
#include <math.h>

#pragma endregion

#pragma region --- MACROS ---

#define DEFAULT_TIME ((timediff_t)0)

#pragma endregion

#pragma region --- STATIC ---

static const char* const _timer_postfix[] = {
    "ns",
    "us",
    "ms",
    "s"
};

#pragma endregion

#pragma region --- FUNCIONS ---

tim_state_t tim_start(tim_t* timer) {
    assert(timer);

    *timer = (tim_t){
        .begin   = (struct timespec){ .tv_sec = 0, .tv_nsec = 0 },
        .elapsed = DEFAULT_TIME,
        .started = false,
        .string  = { 0 }
    };

    if (timespec_get(&(timer->begin), TIME_UTC) != TIME_UTC)
        return TIM_STATE_INVALID;

    timer->started = true;
    return TIM_STATE_OK;
}

tim_state_t tim_stop(tim_t* timer) {
    assert(timer);

    if (timer->started == false)
        return TIM_STATE_FAIL;

    struct timespec now;
    if (timespec_get(&now, TIME_UTC) != TIME_UTC)
        return TIM_STATE_INVALID;

    timer->started = false;
    timer->elapsed += ((timediff_t)now.tv_sec * 1000000000 + (timediff_t)now.tv_nsec) - ((timediff_t)timer->begin.tv_sec * 1000000000 + (timediff_t)timer->begin.tv_nsec);

    if (timer->elapsed < 0) {
        timer->elapsed = INVALID_TIME;
        return TIM_STATE_INVALID;
    }

    return TIM_STATE_OK;
}

tim_state_t tim_continue(tim_t* timer) {
    assert(timer);

    if (timer->started == true)
        return TIM_STATE_FAIL;

    if (tim_elapsed(timer) == INVALID_TIME)
        return TIM_STATE_INVALID;

    if (timespec_get(&(timer->begin), TIME_UTC) != TIME_UTC)
        return TIM_STATE_INVALID;

    timer->started = true;
    return TIM_STATE_OK;
}

timediff_t tim_elapsed(const tim_t* timer) {
    assert(timer);

    return timer->started ? INVALID_TIME : timer->elapsed;
}

const char* const tim_str(tim_t* timer, tim_precision_t precision) {
    timediff_t diff = tim_elapsed(timer);
    if (diff == INVALID_TIME)
        return "";

    double time = (double)diff;

PRECISION_OVERHEAD_LABEL:
    switch (precision) {
    case TIM_PRECISION_SECONDS:
        time /= 1000;
    case TIM_PRECISION_MILLISECONDS:
        time /= 1000;
    case TIM_PRECISION_MICROSECONDS:
        time /= 1000;
    case TIM_PRECISION_NANOSECONDS:
        snprintf(timer->string, 32, "%.3f%s", time, _timer_postfix[precision]);
        break;
    default:
        precision = (__typeof__(precision))fmin(3, log10(time + 1) / 3);
        goto PRECISION_OVERHEAD_LABEL;
    }

    return timer->string;
}

#pragma endregion
