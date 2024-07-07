/*******************************************************************************
 *  @file      arg.h
 *  @brief     arg manipulator macro
 *  @author    Young Sideways
 *  @date      21.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_ARG_H_
#define M_ARG_H_

#pragma region --- INCLUDE ---

#include "macro/reverse.h"
#include "macro/logic.h"
#include "macro/dec.h"

#pragma endregion

#pragma region --- VARIADIC ---

#define VA_ARG_FIRST_HELPER(_1, ...) _1
#define VA_ARG_FIRST(...) __VA_OPT__(VA_ARG_FIRST_HELPER(__VA_ARGS__))

#define VA_ARG_LAST(...) VA_ARG_FIRST(VA_REVERSE(__VA_ARGS__))

#define VA_ARG_HEAD(...) VA_REVERSE(VA_ARG_TAIL(VA_REVERSE(__VA_ARGS__)))

#define VA_ARG_TAIL_HELPER(_1, ...) VA_EXPAND(__VA_OPT__(M_EMPTY M_LPAREN) _1 __VA_OPT__(M_RPAREN)) __VA_ARGS__
#define VA_ARG_TAIL(...) __VA_OPT__(VA_ARG_TAIL_HELPER(__VA_ARGS__))

#pragma endregion

#define VA_ARG_TAKE_HELPER1() VA_ARG_TAKE_HELPER
#define VA_ARG_TAKE_HELPER(n, _1, ...)                                          \
    M_WHEN(n)(                                                                  \
        _1                                                                      \
        __VA_OPT__(M_IF(M_DEC(n))(M_COMMA()))                                   \
        __VA_OPT__(M_OBSTRUCT(VA_ARG_TAKE_HELPER1)()(M_DEC(n), ##__VA_ARGS__))  \
    )
#define VA_ARG_TAKE(n, ...) __VA_OPT__(M_EVAL(VA_ARG_TAKE_HELPER(n, ##__VA_ARGS__)))

#endif // !M_ARG_H_
