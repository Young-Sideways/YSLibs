/*******************************************************************************
 * @file      memory.c
 * @author    Young Sideways
 * @brief     tools, that controls memory
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/memory.h"

#pragma region --- INCLUDE ---

#include "core.h"
#include "debug.h"

#include "algorithm/swap.h"

#include <stdlib.h>
#include <string.h>

#pragma endregion

#pragma region --- FUNCTION ---

void* reverse(void* src, const size_t count, const size_t element_size) {
    explain_assert(src                           , "algorithm/memory: invalid arg - 'src' == NULL"       );
    explain_assert(count                         , "algorithm/memory: invalid arg - 'count' == 0u"       );
    explain_assert(element_size                  , "algorithm/memory: invalid arg - 'element_size' == 0u");

    ubyte* first = (ubyte*)src;
    ubyte* last  = (ubyte*)(first + ((count - 1) * element_size));
    for (; first < last; first += element_size, last -= element_size)
        swap((void*)first, (void*)last, element_size);
    return src;
}

void* memdup(const void* src, const size_t size) {
    explain_assert(src , "algorithm/memory: invalid arg 'src' == NULL");
    explain_assert(size, "algorithm/memory: invalid arg 'size' == 0u" );

    void* dst = malloc(size);
    if (dst)
        memcpy(dst, src, size);
    return dst;
}

#pragma endregion
