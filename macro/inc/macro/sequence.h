/*******************************************************************************
 *  @file      sequence.h
 *  @brief     MACRO extension lib, that translates arguments to sequence
 *  @author    Young Sideways
 *  @date      2.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_SEQUENCE_H_
#define M_SEQUENCE_H_


#include "core.h"
#include "dec.h"
#include "logic.h"


#define VA_SEQ(sep, ...) __VA_OPT__(M_EVAL(__VA_SEQ((sep), __VA_ARGS__)))
#define M_SEQ_GEN(n, var) M_EVAL(__M_SEQ_GEN(n, var))

#pragma region --- IMPL ---

#define __VA_SEQ1() __VA_SEQ
#define __VA_SEQ(sep, _1, ...) _1 __VA_OPT__(M_DEFER(M_EXPAND)sep M_DEFER(__VA_SEQ1)()(sep, __VA_ARGS__))

#define __M_SEQ_GEN1() __M_SEQ_GEN
#define __M_SEQ_GEN(n, var)                       \
    M_WHEN(n)(                                    \
        var                                       \
        M_IF(M_DEC(n))(M_COMMA())                 \
        M_OBSTRUCT(__M_SEQ_GEN1)()(M_DEC(n), var) \
    )

#pragma endregion

#endif // !M_SEQUENCE_H_
