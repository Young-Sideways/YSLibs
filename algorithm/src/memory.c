/*******************************************************************************
 * @file      memory.c
 * @author    Young Sideways
 * @brief     tools, that controls memory
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/memory.h"

#pragma region --- INCLUDE ---

#include "algorithm/swap.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#pragma endregion

#pragma region --- FUNCTION ---

void* reverse(void* src, const size_t count, const size_t element_size) {
    assert(src != NULL ); // algorithm/memory: invalid arg - 'src' == NULL
    assert(count       ); // algorithm/memory: invalid arg - 'count' == 0u
    assert(element_size); // algorithm/memory: invalid arg - 'element_size' == 0u

    // ubyte* first = (ubyte*)src;
    // ubyte* last  = (ubyte*)(first + ((count - 1) * element_size));

    for (ubyte *first = (ubyte*)src, *last  = (ubyte*)(first + ((count - 1) * element_size)); first < last; first += element_size, last -= element_size)
        swap_s((void*)first, (void*)last, element_size);
    return src;
}

void* memdup(const void* src, const size_t size) {
    assert(src != NULL); // algorithm/memory: invalid arg 'src' == NULL
    assert(size       ); // algorithm/memory: invalid arg 'size' == 0u

    void* dst = malloc(size);
    if (dst)
        memcpy(dst, src, size);
    return dst;
}

#pragma endregion
