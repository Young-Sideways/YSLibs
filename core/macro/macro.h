/*******************************************************************************
 *  @file      macro.h
 *  @brief     MACRO core lib
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _MACRO_H_
#define _MACRO_H_

#pragma once

#define M_STRINGIFY(var) #var

#define M_CONCAT(a, b) a##b
#define M_CONCAT_LATER(a, b) M_CONCAT(a, b)

#define M_EXPAND(a) a
#define M_ECHO(...) __VA_ARGS__
#define M_OFFSETOF(container_type, field) &(((container_type*)NULL)->field)


#include <inttypes.h>



#define VA_GPRINT_ARG(...) VA_EACH0(M_FORMAT_OF, __VA_ARGS__)

#include <stdarg.h>
// %1, %2, %3
int gprintf(const char* format, int argc, ...) {

}

#define gprint(format, ...)

#endif // !_MACRO_H_
