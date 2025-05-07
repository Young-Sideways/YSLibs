/*******************************************************************************
 * @file      param.h
 * @author    Young Sideways
 * @brief     Common parameters definition for RPC system
 * @date      07.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef RPC_PARAM_H_
#define RPC_PARAM_H_

#include <cstdint>
#pragma once

#pragma region --- INCLUDE ---

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#pragma endregion

#pragma region --- TYPEDEF ---

typedef const struct RPC_param {
    const char* type ;
    const char* name ;
    size_t      size ;
    size_t      align;
    void*       data ;
} RPC_param_t;

#pragma endregion

#pragma region --- MACRO ---

#define RPC_PARAM_INVALID (RPC_param_t){ \
    .type  = NULL,                       \
    .name  = NULL,                       \
    .size  = 0   ,                       \
    .align = 0   ,                       \
    .data  = NULL                        \
}
#define RPC_PARAM_IS_VALID(param) ( \
    (param.type  != NULL)           \
 && (param.name  != NULL)           \
 && (param.size  != 0   )           \
 && (param.align != 0   )           \
 && (param.data  != NULL)           \
)

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

#define RPC_PARAM_DECLARE(type, var) (RPC_param_t){ \
    .type  = M_STR(type)  ,                         \
    .name  = M_STR(var)   ,                         \
    .size  = sizeof(type) ,                         \
    .align = alignof(type),                         \
    .data  = (void*)&var                            \
}

#pragma endregion

#pragma region --- FUNCTION ---

/**
 * @brief Converts memory to hexcoded string
 * @param[in,out] buf  - String buffer pointer
 * @param[in]     src  - Memory block
 * @param[in]     size - Size of \p src
 * @note \p buf must large enough to hold ( \p size * 2 + 1 ) characters
 * @return Number of written characters
 */
int memthex(char* buf, const void* src, const size_t size) {
    assert(buf  != NULL);
    assert(src  != NULL);
    assert(size != 0u);

    int ret = 0;
    int i = 0;

    // minimize 'snprintf' syscalls

    for (; ((size - i) / sizeof(intmax_t)) != 0u; i += sizeof(intmax_t))
        ret += snprintf(&(buf[i * 2]), sizeof(intmax_t) * 2, "%" PRIXMAX, *(intmax_t*)&(((int8_t*)src)[i]));
    for (; i < size; i++)
        ret += snprintf(&(buf[i * 2]), sizeof(int8_t) * 2, "%" PRIX8, ((int8_t*)src)[i]);
    buf[size * 2] = '\0';
    
    return ret;
}

int rpc_param_to_s(char* buf, size_t n, RPC_param_t param) {
    assert(RPC_PARAM_IS_VALID(param));

    int ret = -1;

    size_t value_buf_size = (param.size * 2) + 1;
    char*  value_buf      = (char*)malloc(value_buf_size);

    if (value_buf != NULL) {
        memthex(value_buf, (const void*)param.data, param.size);
        ret = snprintf(buf, n, "%s %s - [ %zu | %zu ]: '%s'",
            param.type ,
            param.name ,
            param.size ,
            param.align,
            value_buf
        );
        free(value_buf);
    }
    return ret;
}

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#endif // !RPC_PARAM_H_
