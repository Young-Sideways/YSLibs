/*******************************************************************************
 *  @file      search.c
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/search.h"

#pragma region --- INCLUDE ---

#include <assert.h>
#include <string.h>

#pragma endregion

#pragma region --- FUNCTION ---

void* linear_search(const void* array, const size_t count, const size_t element_size, const void* value, comparator_s_t comparator) {
    assert(array != NULL); // algorithm/search: invalid arg - 'array' == NULL
    assert(count        ); // algorithm/search: invalid arg - 'count' == 0u
    assert(element_size ); // algorithm/search: invalid arg - 'element_size' == 0u
    assert(value != NULL); // algorithm/search: invalid arg - 'value' == NULL

    if ( YSL_UNLIKELY(comparator == NULL) )
        comparator = &memcmp;

    for (byte* begin = (void*)array, *end = begin + (count * element_size); begin < end; begin += element_size)
        if (comparator(begin, value, element_size) == 0)
            return (void*)begin;
    
    return NULL;
}

void* binary_search(const void* array, const size_t count, const size_t element_size, const void* value, comparator_s_t comparator) {
    assert(array != NULL); // algorithm/search: invalid arg - 'array' == NULL
    assert(count        ); // algorithm/search: invalid arg - 'count' == 0u
    assert(element_size ); // algorithm/search: invalid arg - 'element_size' == 0u
    assert(value != NULL); // algorithm/search: invalid arg - 'value' == NULL

    if ( YSL_UNLIKELY(comparator == NULL) )
        comparator = &memcmp;

    byte* mid = (byte*)array;
    for (byte* begin = mid, *end = mid + (count * element_size); begin < end;) {
        mid = begin + (((size_t)(end - begin) / element_size) / 2) * element_size;
        const int compared = comparator(value, mid, element_size);
        if (compared == 0)
            return mid;
        else if (compared < 0)
            end = mid;
        else
            begin = mid;
    }

    return comparator(value, mid, element_size) ? NULL : (void*)mid;
}

#pragma endregion
