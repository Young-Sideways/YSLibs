/*******************************************************************************
 *  @file      arg.h
 *  @brief     arg macro
 *  @author    Young Sideways
 *  @date      21.05.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _M_ARG_H_
#define _M_ARG_H_

#pragma region --- INCLUDE ---

#include "reverse.h"

#pragma endregion

// FIX: Поправить багу, связанную с передачей 1 или 0 элементов в макросы...
#pragma region --- VARIADIC ---

#define VA_ARG_FIRST(arg, ...) arg

#define _VA_ARG_LAST_HELPER(...) VA_ARG_FIRST(__VA_ARGS__)
#define VA_ARG_LAST(...) _VA_ARG_LAST_HELPER(VA_ARG_REVERSE(__VA_ARGS__))

#define _VA_ARG_HEAD_HELPER(...) VA_ARG_REVERSE(VA_ARG_TAIL(__VA_ARGS__))
#define VA_ARG_HEAD(...) _VA_ARG_HEAD_HELPER(VA_ARG_REVERSE(__VA_ARGS__))

#define VA_ARG_TAIL(arg, ...) __VA_ARGS__

#pragma endregion

#endif // !_M_ARG_H_
