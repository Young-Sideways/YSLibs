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

#define M_STR(var) #var
#define VA_STR(...) #__VA_ARGS__

#define M_CAT(a, b) a##b
#define VA_CAT(var, ...) var##__VA_ARGS__

#define M_OFFSETOF(container_type, field) &(((container_type*)NULL)->field)

#define M_COMMA() ,
#define M_LPAREN (
#define M_RPAREN )

#define M_EVAL(...)  M_EVAL1(M_EVAL1(M_EVAL1(M_EVAL1(__VA_ARGS__))))
#define M_EVAL1(...) M_EVAL2(M_EVAL2(M_EVAL2(M_EVAL2(__VA_ARGS__))))
#define M_EVAL2(...) M_EVAL3(M_EVAL3(M_EVAL3(M_EVAL3(__VA_ARGS__))))
#define M_EVAL3(...) M_EVAL4(M_EVAL4(M_EVAL4(M_EVAL4(__VA_ARGS__))))
#define M_EVAL4(...) __VA_ARGS__

#define M_EMPTY(...)
#define M_DEFER(var) var M_EMPTY()
#define M_OBSTRUCT(var) var M_DEFER(M_EMPTY)()
#define M_EXPAND(var) var
#define VA_DEFER(...) __VA_ARGS__ M_EMPTY()
#define VA_OBSTRUCT(...) __VA_ARGS__ M_DEFER(M_EMPTY)()
#define VA_EXPAND(...) __VA_ARGS__

#define M_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define M_MIN(x, y) (((x) < (y)) ? (x) : (y))

#define M_TERNAR(predicate, if_true, if_false) ((predicate) ? (if_true) : (if_false))
#define M_ISNULL(value, other) ((value) ? (value) : (other))


#endif // !MACRO_H_
