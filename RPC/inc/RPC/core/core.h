/*******************************************************************************
 * @file      core.h
 * @author    Young Sideways
 * @brief     common defines of RPC system
 * @date      07.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef RPC_CORE_H_
#define RPC_CORE_H_

#include <ctime>
#pragma once

#pragma region --- INCLUDE ---

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

#pragma endregion

#pragma region --- MACRO ---

#pragma endregion

#pragma region --- TYPEDEF ---

struct str_t {  };
struct txt_t {  };

typedef int8_t             RPC_i8_t  ;
typedef int16_t            RPC_i16_t ;
typedef int32_t            RPC_i32_t ;
typedef int64_t            RPC_i64_t ;
typedef uint8_t            RPC_u8_t  ;
typedef uint16_t           RPC_u16_t ;
typedef uint32_t           RPC_u32_t ;
typedef uint64_t           RPC_u64_t ;
typedef float              RPC_flt_t ;
typedef double             RPC_dbl_t ;
typedef long double        RPC_ldbl_t;

typedef bool               RPC_bool_t;
typedef size_t             RPC_size_t;

typedef str_t             *RPC_str_t ;
typedef txt_t             *RPC_txt_t ;

typedef time_t             RPC_time_t;
typedef struct tm          RPC_tm_t  ;
typedef struct timespec    RPC_tmsp_t;
typedef void               RPC_void_t;
typedef void               RPC_bin_t ;

#define __RPC_TRANSFORM_ARG_unified__(type, value) (RPC_method_arg_t) { \
    .type  = ##type,                                                    \
    .name  = ##value,                                                   \
    .size  = sizeof(type),                                              \
    .align = alignof(type),                                             \
    .data  = (void*)(&data)                                             \
}

#define __RPC_TRANSFORM_ARG__int8_t__(value)  __RPC_TRANSFORM_ARG_unified__(int8_t , value)
#define __RPC_TRANSFORM_ARG__int16_t__(value) __RPC_TRANSFORM_ARG_unified__(int16_t, value)
#define __RPC_TRANSFORM_ARG__int32_t__(value) __RPC_TRANSFORM_ARG_unified__(int32_t, value)
#define __RPC_TRANSFORM_ARG__int64_t__(value) __RPC_TRANSFORM_ARG_unified__(int64_t, value)
#define __RPC_TRANSFORM_ARG__uint8_t__(value)  __RPC_TRANSFORM_ARG_unified__(uint8_t , value)
#define __RPC_TRANSFORM_ARG__uint16_t__(value) __RPC_TRANSFORM_ARG_unified__(uint16_t, value)
#define __RPC_TRANSFORM_ARG__uint32_t__(value) __RPC_TRANSFORM_ARG_unified__(uint32_t, value)
#define __RPC_TRANSFORM_ARG__uint64_t__(value) __RPC_TRANSFORM_ARG_unified__(uint64_t, value)
#define __RPC_TRANSFORM_ARG__float__(value) __RPC_TRANSFORM_ARG_unified__(float, value)
#define __RPC_TRANSFORM_ARG__double__(value) __RPC_TRANSFORM_ARG_unified__(double, value)

#pragma endregion

#pragma region --- FUNCTION ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#endif // !RPC_CORE_H_
