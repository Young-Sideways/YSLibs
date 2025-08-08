/*******************************************************************************
 *  @file      reverse.h
 *  @brief     MACRO extension lib to reverse arguments
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_REVERSE_H_
#define M_REVERSE_H_


#include "core.h"


#define __VA_REVERSE_HELPER1() __VA_REVERSE_HELPER
#define __VA_REVERSE_HELPER(_1, ...) __VA_OPT__(M_DEFER(__VA_REVERSE_HELPER1)()(__VA_ARGS__) ,) _1


#define VA_REVERSE(...) __VA_OPT__(M_EVAL(__VA_REVERSE_HELPER(__VA_ARGS__)))


#endif // !M_REVERSE_H_
