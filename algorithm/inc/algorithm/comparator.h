/*******************************************************************************
 *  @file      comparator.h
 *  @brief     comparator algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#pragma once

#pragma region --- INCLUDE ---

#include "../core/core.h"
#include "../core/debug.h"

#include <stdint.h>
#include <assert.h>

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef comparator_t
 *  @brief   defines function type, thats swaps memory \p lhs and \p rhs
 *  @param[in,out] lhs,rhs  - Value pointers
 *  @param[in]     size     - Size of memory block
 */
typedef int (comparator_t)(const void* lhs, const void* rhs, size_t size);

/**
 *  @typedef comparator_pt
 *  @brief   pointer type to \ref comparator_t function
 */
typedef comparator_t* comparator_pt;

#pragma endregion

#pragma region --- DECLARATOR ---

#ifdef _COMPARATOR_DECLARATOR_

#define DECLARE_COMP(prefix, type)                                                     \
    static inline int prefix##_fcomp(const void* lhs, const void* rhs, size_t size) {  \
        UNUSED(size);                                                                  \
        explain_assert(lhs, "algorithm error: lhs value can't be NULL");               \
        explain_assert(rhs, "algorithm error: rhs value can't be NULL");               \
        return ((*(type*)lhs > *(type*)rhs) - (*(type*)lhs < *(type*)rhs));            \
    };                                                                                 \
    static inline int prefix##_rcomp(const void* lhs, const void* rhs, size_t size) {  \
        UNUSED(size);                                                                  \
        explain_assert(lhs, "algorithm error: lhs value can't be NULL");               \
        explain_assert(rhs, "algorithm error: rhs value can't be NULL");               \
        return ((*(type*)lhs < *(type*)rhs) - (*(type*)lhs > *(type*)rhs));            \
    }

DECLARE_COMP(i8  , int8_t     );
DECLARE_COMP(i16 , int16_t    );
DECLARE_COMP(i32 , int32_t    );
DECLARE_COMP(i64 , int64_t    );
DECLARE_COMP(u8  , uint8_t    );
DECLARE_COMP(u16 , uint16_t   );
DECLARE_COMP(u32 , uint32_t   );
DECLARE_COMP(u64 , uint64_t   );
DECLARE_COMP(flt , float      );
DECLARE_COMP(dbl , double     );
DECLARE_COMP(ldbl, long double);

#undef DECLARE_COMP

#endif // !_COMPARATOR_DECLARATOR_

#pragma endregion

#endif // !_COMPARATOR_H_
