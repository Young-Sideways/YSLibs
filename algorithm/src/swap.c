/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/swap.h"

#pragma region --- INCLUDE ---

#include "core.h"
#include "debug.h"

// for llabs
#include <stdlib.h>

#pragma endregion

#pragma region --- FUNCTION ---

void swap(void* lhs, void* rhs, size_t size) {
    explain_assert(lhs , "algorithm/swap: invalid arg - 'lhs' == NULL");
    explain_assert(rhs , "algorithm/swap: invalid arg - 'rhs' == NULL");
    explain_assert(size, "algorithm/swap: invalid arg - 'size' == 0u" );
    explain_assert(llabs((ubyte*)lhs - (ubyte*)rhs) >= (long long)size, "algorithm/swap: Memory regions overlaps");

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
