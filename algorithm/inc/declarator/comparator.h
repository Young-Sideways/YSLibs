/*******************************************************************************
 *  @file      comparator.h
 *  @brief     comparator declarators
 *  @author    Young Sideways
 *  @date      17.06.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef COMPARATOR_DECLARATOR_H_
#define COMPARATOR_DECLARATOR_H_

#pragma once

#ifdef COMPARATOR_H_

#pragma region --- INCLUDE ---

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#pragma endregion

#pragma region --- DECLARATOR ---

#define DECLARE_COMP(prefix, type)                                          \
    static inline int prefix##_fcomp(const void* lhs, const void* rhs) {    \
        assert(lhs != NULL);                                                \
        assert(rhs != NULL);                                                \
        return ((*(type*)lhs > *(type*)rhs) - (*(type*)lhs < *(type*)rhs)); \
    };                                                                      \
    static inline int prefix##_rcomp(const void* lhs, const void* rhs) {    \
        assert(lhs != NULL);                                                \
        assert(rhs != NULL);                                                \
        return ((*(type*)lhs < *(type*)rhs) - (*(type*)lhs > *(type*)rhs)); \
    }

DECLARE_COMP(i8  , int8_t     );
DECLARE_COMP(i16 , int16_t    );
DECLARE_COMP(i32 , int32_t    );
DECLARE_COMP(i64 , int64_t    );
DECLARE_COMP(u8  , uint8_t    );
DECLARE_COMP(u16 , uint16_t   );
DECLARE_COMP(u32 , uint32_t   );
DECLARE_COMP(u64 , uint64_t   );
DECLARE_COMP(iptr, intptr_t   );
DECLARE_COMP(imax, intmax_t   );
DECLARE_COMP(size, size_t     );
DECLARE_COMP(flt , float      );
DECLARE_COMP(dbl , double     );
DECLARE_COMP(ldbl, long double);

#pragma endregion

#endif // COMPARATOR_H_

#endif // !COMPARATOR_DECLARATOR_H_
