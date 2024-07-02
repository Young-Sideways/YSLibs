/*******************************************************************************
 *  @file      macro.h
 *  @brief     MACRO core lib
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef MACRO_H_
#define MACRO_H_

#pragma once

#define M_STRINGIFY(var) #var
#define M_STRINGIFY_LATER(var) M_STRINGIFY(var)

#define M_CONCAT(a, b) a##b
#define M_CONCAT_LATER(a, b) M_CONCAT(a, b)

#define M_OFFSETOF(container_type, field) &(((container_type*)NULL)->field)

#define M_COMMA() ,
#define M_OPEN_BRACKET (
#define M_CLOSE_BRACKET )

#define M_EVAL(...)  M_EVAL1(M_EVAL1(M_EVAL1(__VA_ARGS__)))
#define M_EVAL1(...) M_EVAL2(M_EVAL2(M_EVAL2(__VA_ARGS__)))
#define M_EVAL2(...) M_EVAL3(M_EVAL3(M_EVAL3(__VA_ARGS__)))
#define M_EVAL3(...) M_EXPAND(M_EXPAND(M_EXPAND(__VA_ARGS__)))

#define M_EMPTY(...)
#define M_DEFER(...)    __VA_ARGS__ M_EMPTY()
#define M_OBSTRUCT(...) __VA_ARGS__ M_DEFER(M_EMPTY)()
#define M_EXPAND(...)   __VA_ARGS__

#define M_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define M_MIN(x, y) (((x) < (y)) ? (x) : (y))

#define M_TERNAR(predicate, if_true, if_false) ((predicate) ? (if_true) : (if_false))
#define M_ISNULL(value, other) ((value) ? (value) : (other))

#define M_SPARSE(min, max, lhs, rhs) min = M_MIN(lhs, rhs), max = M_MAX(lhs,rhs)

#endif // !MACRO_H_
