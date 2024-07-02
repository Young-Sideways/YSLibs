/*******************************************************************************
 *  @file      sequence.h
 *  @brief     MACRO extension lib, that translates arguments to sequence
 *  @author    Young Sideways
 *  @date      2.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_SEQUENCE_H_
#define M_SEQUENCE_H_

#pragma once

#pragma region --- INCLUDE ---

#include "macro/macro.h"

#pragma endregion

#pragma region --- MACRO ---

#define VA_SEQ_HELPER1() VA_SEQ_HELPER
#define VA_SEQ_HELPER(sep, _1, ...) _1 __VA_OPT__(M_CONCAT(M_EXPAND,sep) M_DEFER(VA_SEQ_HELPER1)()(sep, ##__VA_ARGS__))

#define VA_SEQ(sep, ...) M_EVAL(VA_SEQ_HELPER((sep), ##__VA_ARGS__))

#define M_SEQ_GEN_0(sep, val)
#define M_SEQ_GEN_1(sep, val) val
#define M_SEQ_GEN_2(sep, val) val M_CONCAT(M_EXPAND,sep) M_SEQ_GEN_1((sep), val)
#define M_SEQ_GEN_3(sep, val) val M_CONCAT(M_EXPAND,sep) M_SEQ_GEN_2((sep), val)
#define M_SEQ_GEN_4(sep, val) val M_CONCAT(M_EXPAND,sep) M_SEQ_GEN_3((sep), val)
#define M_SEQ_GEN_5(sep, val) val M_CONCAT(M_EXPAND,sep) M_SEQ_GEN_4((sep), val)

#define M_SEQ_GEN(n, sep, val) M_CONCAT(M_SEQ_GEN_, n)((sep), val)

#pragma endregion

#endif // !M_SEQUENCE_H_
