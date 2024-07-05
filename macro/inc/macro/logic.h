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

/**
 * @def     M_IF(cnd)
 * @brief   checks condition and then expands value
 * @details usage M_IF(cnd)(true_value, false_value)\n
            cnd: 0 -> false_value\n
                 1 -> true_value
 */
#define M_IF_CND(cnd) M_CAT(M_IF_CND_, cnd)
#define M_IF_CND_0(t, ...) __VA_ARGS__
#define M_IF_CND_1(t, ...) t
#define M_IF(c) M_IF_CND(M_BOOL(c))

#define M_WHEN(cnd) M_IF(cnd)(M_EXPAND, M_EMPTY)

#pragma endregion

#pragma region --- MACRO ---

/**
 * @def     M_BOOL(x)
 * @brief   Translates operand to boolean value
 * @details (0  ) -> 0\n
            (any) -> 1
 */
#define M_BOOL(x) M_COMPL(M_NOT(x))

/**
 * @def     M_NOT(x)
 * @brief   Applies NOT logic to operand
 * @details (0  ) -> 1\n
            (any) -> 0
 */
#define M_NOT(x) M_CHECK(M_CAT(M_NOT_, x))
#define M_NOT_0 M_PROBE(~)

/**
 * @def     M_AND(x, y)
 * @brief   Applies AND logic to operands
 * @details (0,0) -> 0\n
            (0,1) -> 0\n
            (1,0) -> 0\n
            (1,1) -> 1
 */
/**
 * @def     M_NAND(x, y)
 * @brief   Applies inverted AND logic to operands
 * @details (0,0) -> 1\n
            (0,1) -> 1\n
            (1,0) -> 1\n
            (1,1) -> 0
 */
#define M_AND_0(x) 0
#define M_AND_1(x) x
#define M_AND(x, y) M_EXPAND(M_DEFER(M_CAT)(M_AND_, M_BOOL(x))(M_BOOL(y)))
#define M_NAND(x, y) M_COMPL(M_AND(x, y))

/**
 * @def     M_OR(x, y)
 * @brief   Applies OR logic to operands
 * @details (0,0) -> 0\n
            (0,1) -> 1\n
            (1,0) -> 1\n
            (1,1) -> 1
 */
/**
 * @def     M_NOR(x, y)
 * @brief   Applies inverted OR logic to operands
 * @details (0,0) -> 1\n
            (0,1) -> 0\n
            (1,0) -> 0\n
            (1,1) -> 0
 */
#define M_OR_0(x) x
#define M_OR_1(x) 1
#define M_OR(x, y) M_EXPAND(M_DEFER(M_CAT)(M_OR_, M_BOOL(x))(M_BOOL(y)))
#define M_NOR(x, y) M_COMPL(M_OR(x, y))

/**
 * @def     M_IMP(x, y)
 * @brief   Applies IMPLY logic to operands
 * @details (0,0) -> 1\n
            (0,1) -> 1\n
            (1,0) -> 0\n
            (1,1) -> 1
 */
/**
 * @def     M_NIMP(x, y)
 * @brief   Applies inverted IMPLY logic to operands
 * @details (0,0) -> 0\n
            (0,1) -> 0\n
            (1,0) -> 1\n
            (1,1) -> 0
 */
#define M_IMP_0(x) 1
#define M_IMP_1(x) x
#define M_IMP(x, y) M_EXPAND(M_DEFER(M_CAT)(M_IMP_, M_BOOL(x))(M_BOOL(y)))
#define M_NIMP(x, y) M_COMPL(M_IMP(x, y))

/**
 * @def     M_XOR(x, y)
 * @brief   Applies XOR logic to operands
 * @details (0,0) -> 1\n
            (0,1) -> 0\n
            (1,0) -> 0\n
            (1,1) -> 1
 */
/**
 * @def     M_XNOR(x, y)
 * @brief   Applies inverted XOR logic to operands
 * @details (0,0) -> 0\n
            (0,1) -> 1\n
            (1,0) -> 1\n
            (1,1) -> 0
 */
#define M_XOR_0(x) M_COMPL(x)
#define M_XOR_1(x) x
#define M_XOR(x, y) M_EXPAND(M_DEFER(M_CAT)(M_XOR_, M_BOOL(x))(M_BOOL(y)))
#define M_XNOR(x, y) M_COMPL(M_XOR(x, y))

#pragma endregion

#endif // !M_LOGIC_H_
