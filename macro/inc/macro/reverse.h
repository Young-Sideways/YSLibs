/*******************************************************************************
 *  @file      reverse.h
 *  @brief     MACRO extension lib to reverse arguments
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_REVERSE_H_
#define M_REVERSE_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core.h"

#pragma endregion

#pragma region --- MACRO ---

#define VA_REVERSE_HELPER1() VA_REVERSE_HELPER
#define VA_REVERSE_HELPER(_1, ...) __VA_OPT__(M_DEFER(VA_REVERSE_HELPER1)()(__VA_ARGS__) ,) _1
// BUG: M_EVAL (not M_EVAL2) goes huge RAM consumption when prepocessing
#define VA_REVERSE(...) __VA_OPT__(M_EVAL2(VA_REVERSE_HELPER(__VA_ARGS__)))

#pragma endregion

#endif // !M_REVERSE_H_
