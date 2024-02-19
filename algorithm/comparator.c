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


#define FORWARD_COMPARATOR(prefix, type)							    \
	int prefix##_fcomp(const type* lhs, const type* rhs, size_t size) { \
		UNUSED(size);												    \
		assert(lhs);												    \
		assert(rhs);												    \
		return (int)(*lhs - *rhs);									    \
	}
#define REVERSE_COMPARATOR(prefix, type)							    \
	int prefix##_rcomp(const type* lhs, const type* rhs, size_t size) { \
		UNUSED(size);												    \
		assert(lhs);												    \
		assert(rhs);												    \
		return (int)(*rhs - *lhs);										\
	}

#pragma warning(disable : 4244)

FORWARD_COMPARATOR(i8  , int8_t     )
FORWARD_COMPARATOR(i16 , int16_t    )
FORWARD_COMPARATOR(i32 , int32_t    )
FORWARD_COMPARATOR(i64 , int64_t    )
FORWARD_COMPARATOR(u8  , int8_t     )
FORWARD_COMPARATOR(u16 , int16_t    )
FORWARD_COMPARATOR(u32 , int32_t    )
FORWARD_COMPARATOR(u64 , int64_t    )
FORWARD_COMPARATOR(flt , float		)
FORWARD_COMPARATOR(dbl , double		)
FORWARD_COMPARATOR(ldbl, long double)

REVERSE_COMPARATOR(i8  , int8_t     )
REVERSE_COMPARATOR(i16 , int16_t    )
REVERSE_COMPARATOR(i32 , int32_t    )
REVERSE_COMPARATOR(i64 , int64_t    )
REVERSE_COMPARATOR(u8  , int8_t     )
REVERSE_COMPARATOR(u16 , int16_t    )
REVERSE_COMPARATOR(u32 , int32_t    )
REVERSE_COMPARATOR(u64 , int64_t    )
REVERSE_COMPARATOR(flt , float		)
REVERSE_COMPARATOR(dbl , double		)
REVERSE_COMPARATOR(ldbl, long double)

#pragma warning(default : 4244)

#undef FORWARD_COMPARATOR
#undef REVERSE_COMPARATOR