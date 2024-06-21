/*******************************************************************************
 *  @file      exec.h
 *  @brief     Executes each arg on foo
 *  @author    Young Sideways
 *  @date      1.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_EXEC_H_
#define M_EXEC_H_

#pragma once

#pragma region --- INCLUDE ---

#include "macro/macro.h"

#pragma endregion

#pragma region --- MACRO ---

#define VA_EXEC(_f, ...) M_EVAL(VA_EXEC_HELPER(_f, ##__VA_ARGS__))
#define VA_EXEC1(_f, _p1, ...) M_EVAL(VA_EXEC1_HELPER(_f, _p1, ##__VA_ARGS__))
#define VA_EXEC2(_f, _p1, _p2, ...) M_EVAL(VA_EXEC1_HELPER(_f, _p1, _p2, ##__VA_ARGS__))
#define VA_EXEC3(_f, _p1, _p2, _p3, ...) M_EVAL(VA_EXEC1_HELPER(_f, _p1, _p2, _p3, ##__VA_ARGS__))

#define VA_EXEC_HELPER(_f, _1, ...)                 _f(_1) __VA_OPT__(, M_DEFER(VA_EXEC_HELPER1)()(_f, ##__VA_ARGS__))
#define VA_EXEC1_HELPER(_f, _p1, _1, ...)           _f(_p1, _1) __VA_OPT__(, M_DEFER(VA_EXEC1_HELPER1)()(_f, _p1, ##__VA_ARGS__))
#define VA_EXEC2_HELPER(_f, _p1, _p2, _1, ...)      _f(_p1, _p2, _1) __VA_OPT__(, M_DEFER(VA_EXEC2_HELPER1)()(_f, _p1, _p2, ##__VA_ARGS__))
#define VA_EXEC3_HELPER(_f, _p1, _p2, _p3, _1, ...) _f(_p1, _p2, _p3, _1) __VA_OPT__(, M_DEFER(VA_EXEC3_HELPER1)()(_f, _p1, _p2, _p3, ##__VA_ARGS__))

#define VA_EXEC_HELPER1()  VA_EXEC_HELPER
#define VA_EXEC1_HELPER1() VA_EXEC1_HELPER
#define VA_EXEC2_HELPER1() VA_EXEC2_HELPER
#define VA_EXEC3_HELPER1() VA_EXEC3_HELPER

#pragma endregion

#endif // !M_EXEC_H_
