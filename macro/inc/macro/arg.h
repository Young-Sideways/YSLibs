/*******************************************************************************
 *  @file      arg.h
 *  @brief     arg manipulator macro
 *  @author    Young Sideways
 *  @date      21.05.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef M_ARG_H_
#define M_ARG_H_

#pragma region --- INCLUDE ---

#include "macro/reverse.h"

#pragma endregion

// FIX: issue with zero arguments
#pragma region --- VARIADIC ---

#define VA_ARG_FIRST(arg, ...) arg

#define _VA_ARG_LAST_HELPER(...) VA_ARG_FIRST(__VA_ARGS__)
#define VA_ARG_LAST(...) _VA_ARG_LAST_HELPER(VA_ARG_REVERSE(__VA_ARGS__))

#define _VA_ARG_HEAD_HELPER(...) VA_ARG_REVERSE(VA_ARG_TAIL(__VA_ARGS__))
#define VA_ARG_HEAD(...) _VA_ARG_HEAD_HELPER(VA_ARG_REVERSE(__VA_ARGS__))

#define VA_ARG_TAIL(arg, ...) __VA_ARGS__

#pragma endregion

#endif // !M_ARG_H_
