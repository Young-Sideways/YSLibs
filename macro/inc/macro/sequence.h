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
#define VA_SEQ_HELPER(sep, _1, ...) _1 __VA_OPT__(M_CAT(M_EXPAND,sep) M_DEFER(VA_SEQ_HELPER1)()(sep, ##__VA_ARGS__))

#define VA_SEQ(sep, ...) M_EVAL(VA_SEQ_HELPER((sep), ##__VA_ARGS__))

#define M_SEQ_GEN_0(val)
#define M_SEQ_GEN_1(val) val
#define M_SEQ_GEN_2(val) val, val
#define M_SEQ_GEN_3(val) val, val, val
#define M_SEQ_GEN_4(val) val, val, val, val
#define M_SEQ_GEN_5(val) val, val, val, val, val
#define M_SEQ_GEN_6(val) val, val, val, val, val, val
#define M_SEQ_GEN_7(val) val, val, val, val, val, val, val
#define M_SEQ_GEN_8(val) val, val, val, val, val, val, val, val
#define M_SEQ_GEN_9(val) M_SEQ_GEN_5(M_CAT(M_EXPAND,sep), val) M_CAT(M_EXPAND,sep) M_SEQ_GEN_4(M_CAT(M_EXPAND,sep), val)
#define M_SEQ_GEN_10(val) M_SEQ_GEN_5(M_CAT(M_EXPAND,sep), val) M_CAT(M_EXPAND,sep) M_SEQ_GEN_5(M_CAT(M_EXPAND,sep), val)
#define M_SEQ_GEN_11(val) M_SEQ_GEN_6(M_CAT(M_EXPAND,sep), val) M_CAT(M_EXPAND,sep) M_SEQ_GEN_5(M_CAT(M_EXPAND,sep), val)
#define M_SEQ_GEN_12(val) M_SEQ_GEN_6(M_CAT(M_EXPAND,sep), val) M_CAT(M_EXPAND,sep) M_SEQ_GEN_6(M_CAT(M_EXPAND,sep), val)

#define M_SEQ_GEN(n, sep, val) M_CAT(M_SEQ_GEN_, n)(M_CAT(M_EXPAND,sep), val)

#pragma endregion

#endif // !M_SEQUENCE_H_
