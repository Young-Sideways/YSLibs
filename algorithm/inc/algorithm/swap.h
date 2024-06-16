/*******************************************************************************
 *  @file      swap.h
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef SWAP_H_
#define SWAP_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stddef.h>

#include "core.h"

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef swap_t
 *  @brief   defines type of swap function
 *  @param[in,out] lhs,rhs - Pointers to values
 *  @param[in]     size    - Memory size to swap
 */
typedef void (swap_t)(void* lhs, void* rhs, size_t size);

/**
 *  @typedef swap_pt
 *  @brief   pointer type to \ref swap_t function
 */
typedef swap_t* swap_pt;

#pragma endregion

#pragma region --- FUNCTION ---

/**
 * @brief Swaps values between \p lhs and \p rhs pointers with size
 * @param[in,out] lhs,rhs  - Pointers to values
 * @param[in]     size     - Memory size to swap
 */
swap_t swap;

#pragma endregion

#pragma region --- DECLARATOR ---
#ifdef _SWAP_DECLARATOR_

#define DECLARE_SWAP(prefix, type)                                        \
    static inline void prefix##_swap(void* lhs, void* rhs, size_t size) { \
        UNUSED(size);                                                     \
        assert(lhs);                                                      \
        assert(rhs);                                                      \
        type temp = *(type*)lhs;                                          \
        *(type*)lhs = *(type*)rhs;                                        \
        *(type*)rhs = temp;                                               \
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

#undef DECLARE_SWAP

#endif // !_SWAP_DECLARATOR_

#pragma endregion

#pragma region --- METRICS ADAPTER ---
#ifdef _ENABLE_GLOBAL_MERICS_

#include "../core/metrics.h"
DECLARE_METRIC_TYPE(swap,
    size_t swap_calls,
    size_t byte_swapped);

#endif // !_ENABLE_GLOBAL_MERICS_
#pragma endregion

#endif // !SWAP_H_
