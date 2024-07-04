/*******************************************************************************
 * @file      logic.h
 * @author    Young Sideways
 * @brief     MACRO logic lib implements boolean operations 
 * @date      04.07.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_LOGIC_H_
#define M_LOGIC_H_

#pragma once

#pragma region --- INCLUDE ---

#include "macro/core.h"

#pragma endregion

#pragma region --- DETECT ---

#define M_CHECK_PROBE(x, probe, ...) probe
#define M_CHECK(...) M_CHECK_PROBE(__VA_ARGS__, 0)
#define M_PROBE(var) var, 1

#define M_COMPL(x) M_CAT(M_COMPL_, x)
#define M_COMPL_0 1
#define M_COMPL_1 0

#define M_IF_CND(cnd) M_CAT(M_IF_CND_, cnd)
#define M_IF_CND_0(t, ...) __VA_ARGS__
#define M_IF_CND_1(t, ...) t
#define M_IF(c) M_IF_CND(M_BOOL(c))

#define M_WHEN(cnd) M_IF(cnd)(VA_EXPAND, M_EMPTY)

#pragma endregion

#pragma region --- MACRO ---

#define M_BOOL(x) M_COMPL(M_NOT(x))

#define M_NOT(x) M_CHECK(M_CAT(M_NOT_, x))
#define M_NOT_0 M_PROBE(~)

#define M_AND_0(x) 0
#define M_AND_1(x) x
#define M_AND(x, y) M_CAT(M_AND_, x)(y)
#define M_NAND(x, y) M_NOT(M_AND(x, y))

#define M_OR_0(x) x
#define M_OR_1(x) 1
#define M_OR(x, y) M_CAT(M_OR_, x)(y)
#define M_NOR(x, y) M_NOT(M_OR(x, y))

/**
 * @def     M_IMP(x, y)
 * @brief   uses IMPLY logic to operands
 * @details (0,0) -> 1, (0,1) -> 1, (1,0) -> 0, (0,0) -> 1
 */
/**
 * @def     M_NIMP(x, y)
 * @brief   uses inverted IMPLY logic to operands
 * @details (0,0) -> 0, (0,1) -> 0, (1,0) -> 1, (0,0) -> 0
 */
#define M_IMP_0(x) 1
#define M_IMP_1(x) x
#define M_IMP(x, y) M_CAT(M_IMP_, x)(y)
#define M_NIMP(x, y) M_NOT(M_IMP(x, y))

/**
 * @def     M_XOR(x, y)
 * @brief   uses XOR logic to operands
 * @details (0,0) -> 1, (0,1) -> 0, (1,0) -> 0, (0,0) -> 1
 */
/**
 * @def     M_XNOR(x, y)
 * @brief   uses inverted XOR logic to operands
 * @details (0,0) -> 0, (0,1) -> 1, (1,0) -> 1, (0,0) -> 0
 */
#define M_XOR_0(x) M_NOT(x)
#define M_XOR_1(x) x
#define M_XOR(x, y) M_CAT(M_XOR_, x)(y)
#define M_XNOR(x, y) M_NOT(M_XOR(x, y))

/**
 * @def     M_IF(cnd)
 * @brief   checks condition
 * @details usage M_IF(cnd)(true, false) : (cnd == 0) -> 'false' value, (cnd == 1) -> 'true' value
 */
#define M_IF_0(t, f) f
#define M_IF_1(t, f) t
#define M_IF(cnd) M_CAT(M_IF_, cnd)

#pragma endregion

#endif // !M_LOGIC_H_
