/*******************************************************************************
 *  @file      comparator.c
 *  @brief     comparator algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#include "comparator.h"
#include "../core/types.h"

#include <assert.h>

#define UNUSED(var) ((void)var)

#define FORWARD_COMPARATOR(type)								      \
	int type##_fcomp(const void* lhs, const void* rhs, size_t size) { \
		UNUSED(size);												  \
		assert(lhs);												  \
		assert(rhs);												  \
		return (type)(*(type*)lhs - *(type*)rhs);					  \
	}
#define REVERSE_COMPARATOR(type)									  \
	int type##_rcomp(const void* lhs, const void* rhs, size_t size) { \
		UNUSED(size);												  \
		assert(lhs);												  \
		assert(rhs);												  \
		return (type)(*(type*)rhs - *(type*)lhs);					  \
	}

#pragma warning(disable : 4244)

FORWARD_COMPARATOR(i8)
FORWARD_COMPARATOR(i16)
FORWARD_COMPARATOR(i32)
FORWARD_COMPARATOR(i64)
FORWARD_COMPARATOR(u8)
FORWARD_COMPARATOR(u16)
FORWARD_COMPARATOR(u32)
FORWARD_COMPARATOR(u64)
FORWARD_COMPARATOR(flt)
FORWARD_COMPARATOR(dbl)
FORWARD_COMPARATOR(ldbl)

REVERSE_COMPARATOR(i8)
REVERSE_COMPARATOR(i16)
REVERSE_COMPARATOR(i32)
REVERSE_COMPARATOR(i64)
REVERSE_COMPARATOR(u8)
REVERSE_COMPARATOR(u16)
REVERSE_COMPARATOR(u32)
REVERSE_COMPARATOR(u64)
REVERSE_COMPARATOR(flt)
REVERSE_COMPARATOR(dbl)
REVERSE_COMPARATOR(ldbl)

#pragma warning(default : 4244)

#undef FORWARD_COMPARATOR
#undef REVERSE_COMPARATOR