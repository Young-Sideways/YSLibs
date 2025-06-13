/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/swap.h"

#pragma region --- INCLUDE ---

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#pragma endregion

#pragma region --- FUNCTION ---

void swap_s(void* lhs, void* rhs, size_t size) {
    assert(lhs != NULL                                         ); // algorithm/swap: invalid arg - 'lhs' == NULL
    assert(rhs != NULL                                         ); // algorithm/swap: invalid arg - 'rhs' == NULL
    assert(size                                                ); // algorithm/swap: invalid arg - 'size' == 0u
    assert(llabs((byte*)lhs - (byte*)rhs) >= (intptr_t)size); // algorithm/swap: Memory regions overlaps

    for (; size % sizeof(size_t); --size) {
        *(ubyte*)lhs ^= *(ubyte*)rhs;
        *(ubyte*)rhs ^= *(ubyte*)lhs;
        *(ubyte*)lhs ^= *(ubyte*)rhs;
        lhs = (void*)((ubyte*)lhs + 1);
        rhs = (void*)((ubyte*)rhs + 1);
    }
    for (size /= sizeof(size_t); size; --size) {
        *(size_t*)lhs ^= *(size_t*)rhs;
        *(size_t*)rhs ^= *(size_t*)lhs;
        *(size_t*)lhs ^= *(size_t*)rhs;
        lhs = (void*)((size_t*)lhs + 1);
        rhs = (void*)((size_t*)rhs + 1);
    }
}

#pragma endregion
