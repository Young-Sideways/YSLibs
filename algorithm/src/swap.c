/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/


#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "../inc/algorithm/swap.h"


void swap_s(void* lhs, void* rhs, size_t size) {
    assert(lhs != NULL                                         ); // algorithm/swap: invalid arg - 'lhs' == NULL
    assert(rhs != NULL                                         ); // algorithm/swap: invalid arg - 'rhs' == NULL
    assert(size                                                ); // algorithm/swap: invalid arg - 'size' == 0u
    assert(llabs((uint8_t*)lhs - (uint8_t*)rhs) >= (intptr_t)size); // algorithm/swap: Memory regions overlaps

    for (; size % sizeof(size_t); --size) {
        *(uint8_t*)lhs ^= *(uint8_t*)rhs;
        *(uint8_t*)rhs ^= *(uint8_t*)lhs;
        *(uint8_t*)lhs ^= *(uint8_t*)rhs;
        lhs = (void*)((uint8_t*)lhs + 1);
        rhs = (void*)((uint8_t*)rhs + 1);
    }
    for (size /= sizeof(uint_fast64_t); size; --size) {
        *(uint_fast64_t*)lhs ^= *(uint_fast64_t*)rhs;
        *(uint_fast64_t*)rhs ^= *(uint_fast64_t*)lhs;
        *(uint_fast64_t*)lhs ^= *(uint_fast64_t*)rhs;
        lhs = (void*)((uint_fast64_t*)lhs + 1);
        rhs = (void*)((uint_fast64_t*)rhs + 1);
    }
}
