/*******************************************************************************
 *  @file      exec.h
 *  @brief     Executes each arg on foo
 *  @author    Young Sideways
 *  @date      1.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_EXEC_H_
#define M_EXEC_H_


#include "core.h"


#define VA_EXEC(_f, ...)                 __VA_OPT__(M_EVAL(__VA_EXEC_HELPER(_f, __VA_ARGS__)))
#define VA_EXEC1(_f, _p1, ...)           __VA_OPT__(M_EVAL(__VA_EXEC1_HELPER(_f, _p1, __VA_ARGS__)))
#define VA_EXEC2(_f, _p1, _p2, ...)      __VA_OPT__(M_EVAL(__VA_EXEC2_HELPER(_f, _p1, _p2, __VA_ARGS__)))
#define VA_EXEC3(_f, _p1, _p2, _p3, ...) __VA_OPT__(M_EVAL(__VA_EXEC3_HELPER(_f, _p1, _p2, _p3, __VA_ARGS__)))

#define __VA_EXEC_HELPER(_f, _1, ...)                 _f(_1) __VA_OPT__(, M_DEFER(__VA_EXEC_HELPER1)()(_f, __VA_ARGS__))
#define __VA_EXEC1_HELPER(_f, _p1, _1, ...)           _f(_p1, _1) __VA_OPT__(, M_DEFER(__VA_EXEC1_HELPER1)()(_f, _p1, __VA_ARGS__))
#define __VA_EXEC2_HELPER(_f, _p1, _p2, _1, ...)      _f(_p1, _p2, _1) __VA_OPT__(, M_DEFER(__VA_EXEC2_HELPER1)()(_f, _p1, _p2, __VA_ARGS__))
#define __VA_EXEC3_HELPER(_f, _p1, _p2, _p3, _1, ...) _f(_p1, _p2, _p3, _1) __VA_OPT__(, M_DEFER(__VA_EXEC3_HELPER1)()(_f, _p1, _p2, _p3, __VA_ARGS__))

#define __VA_EXEC_HELPER1()  __VA_EXEC_HELPER
#define __VA_EXEC1_HELPER1() __VA_EXEC1_HELPER
#define __VA_EXEC2_HELPER1() __VA_EXEC2_HELPER
#define __VA_EXEC3_HELPER1() __VA_EXEC3_HELPER


#endif // !M_EXEC_H_
