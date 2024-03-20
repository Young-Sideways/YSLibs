/*******************************************************************************
 *  @file      swap.c
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "swap.h"

#pragma region --- INCLUDES ---

#include <math.h>

#pragma endregion

#pragma region --- FUNCTIONS ---

void swap(void* lhs, void* rhs, size_t size) {
    assert(lhs);
    assert(rhs);
    assert(size);
    explain_assert(llabs((char*)lhs - (char*)rhs) >= (int64_t)size, "Memory regions overlaps");
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

#pragma endregion
