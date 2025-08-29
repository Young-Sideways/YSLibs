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


#define VA_EXEC(n, _f, ...) __VA_OPT__(M_EVAL( M_DEFER(__VA_EXEC)(_f, ( VA_HEAD(n, __VA_ARGS__) ), VA_SKIP(n, __VA_ARGS__))))

#define __VA_EXEC_CALL(_f, ...) _f(__VA_ARGS__)
#define __VA_EXEC1() __VA_EXEC
#define __VA_EXEC(_f, defs, _1, ...) M_DEFER(__VA_EXEC_CALL)(_f, VA_EXPAND defs M_IF(VA_COUNT defs)(M_COMMA(),) _1) __VA_OPT__(, M_DEFER(__VA_EXEC1)()(_f, defs, __VA_ARGS__))

#endif // !M_EXEC_H_
