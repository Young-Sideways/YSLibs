/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#include "swap.h"
#include "../core/types.h"

#include <assert.h>
#include <math.h>

void swap(void* lhs, void* rhs, size_t size) {
	assert(lhs);
	assert(rhs);
	assert(size);
	assert(llabs((char*)lhs - (char*)rhs) < (int64_t)size);
	for (; size % sizeof(size_t); ++(char*)lhs, ++(char*)rhs, --size) {
		*(char*)lhs ^= *(char*)rhs;
		*(char*)rhs ^= *(char*)lhs;
		*(char*)lhs ^= *(char*)rhs;
	}
	for (size /= sizeof(size_t); size; ++(size_t*)lhs, ++(size_t*)rhs, --size) {
		*(size_t*)lhs ^= *(size_t*)rhs;
		*(size_t*)rhs ^= *(size_t*)lhs;
		*(size_t*)lhs ^= *(size_t*)rhs;
	}
};

#define SWAP(prefix, type)									\
	void prefix##_swap(type* lhs, type* rhs, size_t size) { \
		UNUSED(size);									    \
		assert(lhs);									    \
		assert(rhs);										\
		type temp = *lhs;									\
		*lhs = *rhs;										\
		*rhs = temp;										\
	};

SWAP(i8  , int8_t     )
SWAP(i16 , int16_t    )
SWAP(i32 , int32_t    )
SWAP(i64 , int64_t    )
SWAP(u8	 , int8_t     )
SWAP(u16 , int16_t    )
SWAP(u32 , int32_t    )
SWAP(u64 , int64_t    )
SWAP(flt , float	  )
SWAP(dbl , double	  )
SWAP(ldbl, long double)

#undef SWAP