/*******************************************************************************
 *  @file      arg.h
 *  @brief     arg manipulator macro
 *  @author    Young Sideways
 *  @date      21.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_ARG_H_
#define M_ARG_H_

#include "core.h"     // VA_EXPAND, M_EMPTY, M_LPAREN, M_RPAREN, M_COMMA, M_OBSTRUCT
#include "reverse.h"  // VA_REVERSE
#include "variadic.h" // VA_NARG
#include "logic.h"    // M_WHEN, M_IF
#include "dec.h"      // M_DEC


#define VA_ARG_FIRST(...) __VA_OPT__(__VA_ARG_FIRST_HELPER(__VA_ARGS__))
#define VA_ARG_LAST(...) VA_ARG_FIRST(VA_REVERSE(__VA_ARGS__))

#define VA_ARG_HEAD(...) VA_REVERSE(VA_ARG_TAIL(VA_REVERSE(__VA_ARGS__)))
#define VA_ARG_TAIL(...) __VA_OPT__( __VA_ARG_TAIL_HELPER( __VA_ARGS__))

#define VA_ARG_TAKE(n, ...) __VA_OPT__(M_EVAL(__VA_ARG_TAKE_HELPER(n, ##__VA_ARGS__)))


#pragma region --- IMPL ---

#define __VA_ARG_FIRST_HELPER(_1, ...) _1

#define __VA_ARG_TAIL_HELPER(_1, ...) M_IF(VA_NARG( __VA_ARGS__ ))( ,_1) __VA_ARGS__

#define __VA_ARG_TAKE_HELPER1() __VA_ARG_TAKE_HELPER
#define __VA_ARG_TAKE_HELPER(n, _1, ...)                                         \
    M_WHEN(n)(                                                                   \
        _1                                                                       \
        __VA_OPT__(M_IF(M_DEC(n))(M_COMMA()))                                    \
        __VA_OPT__(M_OBSTRUCT(__VA_ARG_TAKE_HELPER1)()(M_DEC(n), ##__VA_ARGS__)) \
    )

#pragma endregion

#endif // !M_ARG_H_
