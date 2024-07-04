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
#define M_SEQ_GEN_1(val)  val
#define M_SEQ_GEN_2(val)  val, val
#define M_SEQ_GEN_3(val)  val, val, val
#define M_SEQ_GEN_4(val)  val, val, val, val
#define M_SEQ_GEN_5(val)  val, val, val, val, val
#define M_SEQ_GEN_6(val)  val, val, val, val, val, val
#define M_SEQ_GEN_7(val)  val, val, val, val, val, val, val
#define M_SEQ_GEN_8(val)  val, val, val, val, val, val, val, val

#define M_SEQ_GEN_9(val)  M_SEQ_GEN_8(val), M_SEQ_GEN_1(val)
#define M_SEQ_GEN_10(val) M_SEQ_GEN_8(val), M_SEQ_GEN_2(val)
#define M_SEQ_GEN_11(val) M_SEQ_GEN_8(val), M_SEQ_GEN_3(val)
#define M_SEQ_GEN_12(val) M_SEQ_GEN_8(val), M_SEQ_GEN_4(val)
#define M_SEQ_GEN_13(val) M_SEQ_GEN_8(val), M_SEQ_GEN_5(val)
#define M_SEQ_GEN_14(val) M_SEQ_GEN_8(val), M_SEQ_GEN_6(val)
#define M_SEQ_GEN_15(val) M_SEQ_GEN_8(val), M_SEQ_GEN_7(val)
#define M_SEQ_GEN_16(val) M_SEQ_GEN_8(val), M_SEQ_GEN_8(val)

#define M_SEQ_GEN_17(val) M_SEQ_GEN_16(val), M_SEQ_GEN_1(val)
#define M_SEQ_GEN_18(val) M_SEQ_GEN_16(val), M_SEQ_GEN_2(val)
#define M_SEQ_GEN_19(val) M_SEQ_GEN_16(val), M_SEQ_GEN_3(val)
#define M_SEQ_GEN_20(val) M_SEQ_GEN_16(val), M_SEQ_GEN_4(val)
#define M_SEQ_GEN_21(val) M_SEQ_GEN_16(val), M_SEQ_GEN_5(val)
#define M_SEQ_GEN_22(val) M_SEQ_GEN_16(val), M_SEQ_GEN_6(val)
#define M_SEQ_GEN_23(val) M_SEQ_GEN_16(val), M_SEQ_GEN_7(val)
#define M_SEQ_GEN_24(val) M_SEQ_GEN_16(val), M_SEQ_GEN_8(val)
#define M_SEQ_GEN_25(val) M_SEQ_GEN_16(val), M_SEQ_GEN_9(val)
#define M_SEQ_GEN_26(val) M_SEQ_GEN_16(val), M_SEQ_GEN_10(val)
#define M_SEQ_GEN_27(val) M_SEQ_GEN_16(val), M_SEQ_GEN_11(val)
#define M_SEQ_GEN_28(val) M_SEQ_GEN_16(val), M_SEQ_GEN_12(val)
#define M_SEQ_GEN_29(val) M_SEQ_GEN_16(val), M_SEQ_GEN_13(val)
#define M_SEQ_GEN_30(val) M_SEQ_GEN_16(val), M_SEQ_GEN_14(val)
#define M_SEQ_GEN_31(val) M_SEQ_GEN_16(val), M_SEQ_GEN_15(val)
#define M_SEQ_GEN_32(val) M_SEQ_GEN_16(val), M_SEQ_GEN_16(val)

#define M_SEQ_GEN_33(val) M_SEQ_GEN_32(val), M_SEQ_GEN_1(val)
#define M_SEQ_GEN_34(val) M_SEQ_GEN_32(val), M_SEQ_GEN_2(val)
#define M_SEQ_GEN_35(val) M_SEQ_GEN_32(val), M_SEQ_GEN_3(val)
#define M_SEQ_GEN_36(val) M_SEQ_GEN_32(val), M_SEQ_GEN_4(val)
#define M_SEQ_GEN_37(val) M_SEQ_GEN_32(val), M_SEQ_GEN_5(val)
#define M_SEQ_GEN_38(val) M_SEQ_GEN_32(val), M_SEQ_GEN_6(val)
#define M_SEQ_GEN_39(val) M_SEQ_GEN_32(val), M_SEQ_GEN_7(val)
#define M_SEQ_GEN_40(val) M_SEQ_GEN_32(val), M_SEQ_GEN_8(val)
#define M_SEQ_GEN_41(val) M_SEQ_GEN_32(val), M_SEQ_GEN_9(val)
#define M_SEQ_GEN_42(val) M_SEQ_GEN_32(val), M_SEQ_GEN_10(val)
#define M_SEQ_GEN_43(val) M_SEQ_GEN_32(val), M_SEQ_GEN_11(val)
#define M_SEQ_GEN_44(val) M_SEQ_GEN_32(val), M_SEQ_GEN_12(val)
#define M_SEQ_GEN_45(val) M_SEQ_GEN_32(val), M_SEQ_GEN_13(val)
#define M_SEQ_GEN_46(val) M_SEQ_GEN_32(val), M_SEQ_GEN_14(val)
#define M_SEQ_GEN_47(val) M_SEQ_GEN_32(val), M_SEQ_GEN_15(val)
#define M_SEQ_GEN_48(val) M_SEQ_GEN_32(val), M_SEQ_GEN_16(val)
#define M_SEQ_GEN_49(val) M_SEQ_GEN_32(val), M_SEQ_GEN_17(val)
#define M_SEQ_GEN_50(val) M_SEQ_GEN_32(val), M_SEQ_GEN_18(val)
#define M_SEQ_GEN_51(val) M_SEQ_GEN_32(val), M_SEQ_GEN_19(val)
#define M_SEQ_GEN_52(val) M_SEQ_GEN_32(val), M_SEQ_GEN_20(val)
#define M_SEQ_GEN_53(val) M_SEQ_GEN_32(val), M_SEQ_GEN_21(val)
#define M_SEQ_GEN_54(val) M_SEQ_GEN_32(val), M_SEQ_GEN_22(val)
#define M_SEQ_GEN_55(val) M_SEQ_GEN_32(val), M_SEQ_GEN_23(val)
#define M_SEQ_GEN_56(val) M_SEQ_GEN_32(val), M_SEQ_GEN_24(val)
#define M_SEQ_GEN_57(val) M_SEQ_GEN_32(val), M_SEQ_GEN_25(val)
#define M_SEQ_GEN_58(val) M_SEQ_GEN_32(val), M_SEQ_GEN_26(val)
#define M_SEQ_GEN_59(val) M_SEQ_GEN_32(val), M_SEQ_GEN_27(val)
#define M_SEQ_GEN_60(val) M_SEQ_GEN_32(val), M_SEQ_GEN_28(val)
#define M_SEQ_GEN_61(val) M_SEQ_GEN_32(val), M_SEQ_GEN_29(val)
#define M_SEQ_GEN_62(val) M_SEQ_GEN_32(val), M_SEQ_GEN_30(val)
#define M_SEQ_GEN_63(val) M_SEQ_GEN_32(val), M_SEQ_GEN_31(val)
#define M_SEQ_GEN_64(val) M_SEQ_GEN_32(val), M_SEQ_GEN_32(val)

#define M_SEQ_GEN(n, val) M_CAT(M_SEQ_GEN_, n)(val)

#pragma endregion

#endif // !M_SEQUENCE_H_
