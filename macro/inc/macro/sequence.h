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

#include "macro/core.h"
#include "macro/logic.h"

#pragma endregion

#pragma region --- MACRO ---

#define VA_SEQ_HELPER1() VA_SEQ_HELPER
#define VA_SEQ_HELPER(sep, _1, ...) _1 __VA_OPT__(M_CAT(M_EXPAND,sep) M_DEFER(VA_SEQ_HELPER1)()(sep, ##__VA_ARGS__))

#define VA_SEQ(sep, ...) __VA_OPT__(M_EVAL(VA_SEQ_HELPER((sep), ##__VA_ARGS__)))

#define M_SEQ_GEN_HELPER1() M_SEQ_GEN_HELPER
#define M_SEQ_GEN_HELPER(n, var) M_WHEN(n)(var M_IF(M_DEC(n))(M_COMMA()) M_OBSTRUCT(M_SEQ_GEN_HELPER1)()(M_DEC(n), var))
#define M_SEQ_GEN(n, var) M_EVAL(M_SEQ_GEN_HELPER(n, var))

#pragma endregion

#endif // !M_SEQUENCE_H_
