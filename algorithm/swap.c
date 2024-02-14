/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#include "swap.h"
#include "types.h"

#include <assert.h>
#include <math.h>

#define UNUSED(var) ((void)var)

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

#define SWAP(type)										  \
	void type##_swap(void* lhs, void* rhs, size_t size) { \
		UNUSED(size);									  \
		assert(lhs);									  \
		assert(rhs);									  \
		type temp = *(type*)lhs;						  \
		*(type*)lhs = *(type*)rhs;						  \
		*(type*)rhs = temp;								  \
	};

SWAP(i8)
SWAP(i16)
SWAP(i32)
SWAP(i64)
SWAP(u8)
SWAP(u16)
SWAP(u32)
SWAP(u64)
SWAP(flt)
SWAP(dbl)
SWAP(ldbl)

#undef SWAP