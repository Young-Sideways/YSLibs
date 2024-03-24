/*******************************************************************************
 *  @file      metrics.h
 *  @brief     metrics module helps testing your code simply
 *  @author    Young Sideways
 *  @date      20.03.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _METRICS_H_
#define _METRICS_H_
#pragma once

#pragma region --- INCLUDES --

#include "varidatic.h"

#pragma endregion

#pragma region --- MACROS ---

#define DECLARE_METRIC_PASTE_0(...) 
#define DECLARE_METRIC_PASTE_1(_1, ...) \
    _1;
#define DECLARE_METRIC_PASTE_2(_1, _2, ...) \
    _1; _2;
#define DECLARE_METRIC_PASTE_3(_1, _2, _3, ...) \
    _1; _2; _3;
#define DECLARE_METRIC_PASTE_4(_1, _2, _3, _4, ...) \
    _1; _2; _3; _4;
#define DECLARE_METRIC_PASTE_5(_1, _2, _3, _4, _5, ...) \
    _1; _2; _3; _4; _5;
#define DECLARE_METRIC_PASTE_6(_1, _2, _3, _4, _5, _6, ...) \
    _1; _2; _3; _4; _5; _6;
#define DECLARE_METRIC_PASTE_7(_1, _2, _3, _4, _5, _6, _7, ...) \
    _1; _2; _3; _4; _5; _6; _7;
#define DECLARE_METRIC_PASTE_8(_1, _2, _3, _4, _5, _6, _7, _8, ...) \
    _1; _2; _3; _4; _5; _6; _7; _8;
// add another declarators


#define CONCAT(a, b) a ## b
#define DECLARE_METRIC_PASTE_(n, ...) CONCAT(DECLARE_METRIC_PASTE_, n) (__VA_ARGS__)
#define DECLARE_METRIC_PASTE(...) DECLARE_METRIC_PASTE_( PP_NARG(__VA_ARGS__), __VA_ARGS__)

#define DECLARE_METRIC_TYPE(name, ...)      \
    struct metrics_struct_ ## name {        \
        DECLARE_METRIC_PASTE(__VA_ARGS__)   \
    }
#define DECLARE_METRIC_INIT(name) \
    struct metrics_struct_ ## name name

#define DECLARE_EXTERN_METRIC(name) \
    extern struct metrics_struct_ ## name name

#define METRIC_GET(name, field) \
    name.field
#define METRIC_INC(name, field) \
    name.field += 1
#define METRIC_DEC(name, field) \
    name.field -= 1

#pragma endregion

DECLARE_METRIC_TYPE(global,
    char* file,
    int line,
    int counter,
    double value,
    void* context
);

#define METRIC_GLOBAL_POINT(_counter, _value, _context) \
    do {                                                \
        DECLARE_EXTERN_METRIC(global);                  \
        global.file = __FILE__;                         \
        global.line = __LINE__;                         \
        global.counter = _counter;                      \
        global.value = _value;                          \
        global.context = _context;                      \
    } while(0)

#endif // !_METRICS_H_
