/*******************************************************************************
 *  @file      swap.h
 *  @brief     swap declarators
 *  @author    Young Sideways
 *  @date      17.06.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef SWAP_DECLARATOR_H_
#define SWAP_DECLARATOR_H_

#pragma once

#ifdef SWAP_H_

#pragma region --- INCLUDE ---

#include "core.h"
#include "debug.h"

// for fixed width int types
#include <stdint.h>
// for llabs
#include <stdlib.h>

#pragma endregion

#pragma region --- DECLARATOR ---

#define DECLARE_SWAP(prefix, type)                                          \
    static inline void prefix##_swap(void* lhs, void* rhs, size_t size) {   \
        explain_assert(lhs, "algorithm/swap: invalid arg - 'lhs' == NULL"); \
        explain_assert(rhs, "algorithm/swap: invalid arg - 'rhs' == NULL"); \
        YSL_UNUSED(size);                                                   \
        type temp   = *(type*)lhs;                                          \
        *(type*)lhs = *(type*)rhs;                                          \
        *(type*)rhs = temp;                                                 \
    }

DECLARE_SWAP(i8  , int8_t     );
DECLARE_SWAP(i16 , int16_t    );
DECLARE_SWAP(i32 , int32_t    );
DECLARE_SWAP(i64 , int64_t    );
DECLARE_SWAP(u8  , uint8_t    );
DECLARE_SWAP(u16 , uint16_t   );
DECLARE_SWAP(u32 , uint32_t   );
DECLARE_SWAP(u64 , uint64_t   );
DECLARE_SWAP(flt , float      );
DECLARE_SWAP(dbl , double     );
DECLARE_SWAP(ldbl, long double);

#endif // SWAP_H_

#endif // !SWAP_DECLARATOR_H_
