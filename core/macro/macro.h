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

#define M_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define M_MIN(x, y) (((x) < (y)) ? (x) : (y))

#define M_TERNAR(predicate, if_true, if_false) ((predicate) ? (if_true) : (if_false))

#define M_SPARSE(min, max, lhs, rhs) min = M_MIN(lhs, rhs), max = M_MAX(lhs,rhs)

#endif // !_MACRO_H_
