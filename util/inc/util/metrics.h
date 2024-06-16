/*******************************************************************************
 *  @file      metrics.h
 *  @brief     metrics module helps testing your code simply
 *  @author    Young Sideways
 *  @date      20.03.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef METRICS_H_
#define METRICS_H_

#pragma once

#pragma region --- INCLUDE --

#include "macro/macro.h"
#include "macro/variadic.h"
#include "macro/sequence.h"

#pragma endregion

#pragma region --- MACRO ---

#define DECLARE_METRIC_TYPE(name, ...)      \
    struct M_CONCAT_LATER(metrics_struct_,name) { \
        VA_SEQ_SEMI(__VA_ARGS__)            \
    }

#define DECLARE_METRIC_INIT(name) \
    static struct metrics_struct_ ## name name

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

#endif // !METRICS_H_
