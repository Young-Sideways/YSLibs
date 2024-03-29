/*******************************************************************************
 *  @file      swap.h
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _SWAP_H_
#define _SWAP_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"
#include <math.h>

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef void (swap_t)(_INOUT void*, _INOUT void*, _IN size_t);
typedef swap_t* swap_pt;

#pragma endregion

#pragma region --- FUNCTIONS ---

/**
 * @brief swaps values between lhs and rhs pointers with size
 * @param lhs  - left-hand side value pointer
 * @param rhs  - right-hand side value pointer
 * @param size - swapable area size
 */
swap_t swap;

#pragma endregion

#pragma region --- DECLARATORS ---
#ifdef _SWAP_DECLARATOR_

#define DECLARE_SWAP(prefix, type)                                 \
    inline void prefix##_swap(void* lhs, void* rhs, size_t size) { \
        UNUSED(size);                                              \
        assert(lhs);                                               \
        assert(rhs);                                               \
        type temp = *(type*)lhs;                                   \
        *(type*)lhs = *(type*)rhs;                                 \
        *(type*)rhs = temp;                                        \
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

#endif // !_SWAP_H_
