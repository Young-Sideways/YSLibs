/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/swap.h"

#pragma region --- INCLUDE ---

#include <stdlib.h>

#include "debug.h"

#pragma endregion

#pragma region --- FUNCTION ---

void swap(void* lhs, void* rhs, size_t size) {
    assert(lhs);
    assert(rhs);
    assert(size);
    explain_assert(llabs((char*)lhs - (char*)rhs) >= (long long)size, "Memory regions overlaps");
    for (; size % sizeof(size_t); --size) {
        *(char*)lhs ^= *(char*)rhs;
        *(char*)rhs ^= *(char*)lhs;
        *(char*)lhs ^= *(char*)rhs;
        lhs = (void*)((char*)lhs + 1);
        lhs = (void*)((char*)rhs + 1);
    }
    for (size /= sizeof(size_t); size; --size) {
        *(size_t*)lhs ^= *(size_t*)rhs;
        *(size_t*)rhs ^= *(size_t*)lhs;
        *(size_t*)lhs ^= *(size_t*)rhs;
        lhs = (void*)((size_t*)lhs + 1);
        lhs = (void*)((size_t*)rhs + 1);
    }
};

#pragma endregion
