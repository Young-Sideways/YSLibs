/*******************************************************************************
 *  @file      search.c
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/search.h"

#pragma region --- INCLUDE ---

#include "core.h"
#include "debug.h"

// for memcmp
#include <string.h>

#pragma endregion

#pragma region --- FUNCTION ---

void* linear_search(const void* array, const size_t count, const size_t element_size, const void* value, comparator_t comparator_) {
    explain_assert(array       , "algorithm/search: invalid arg - 'array' == NULL"     );
    explain_assert(count       , "algorithm/search: invalid arg - 'count' == 0u"       );
    explain_assert(element_size, "algorithm/search: invalid arg - 'element_size' == 0u");
    explain_assert(value       , "algorithm/search: invalid arg - 'value' == NULL"     );

    if (!comparator_)
        comparator_ = &memcmp;

    for (ubyte* begin = (void*)array, *end = begin + (count * element_size); begin < end; begin += element_size)
        if (comparator_(begin, value, element_size))
            return (void*)array;
    return NULL;
}

void* binary_search(const void* array, const size_t count, const size_t element_size, const void* value, comparator_t comparator_) {
    explain_assert(array       , "algorithm/search: invalid arg - 'array' == NULL"     );
    explain_assert(count       , "algorithm/search: invalid arg - 'count' == 0u"       );
    explain_assert(element_size, "algorithm/search: invalid arg - 'element_size' == 0u");
    explain_assert(value       , "algorithm/search: invalid arg - 'value' == NULL"     );

    if (!comparator_)
        comparator_ = &memcmp;
    if (count == 0)
        return NULL;
    if (count == 1)
        return (void*)(comparator_(value, array, element_size) ? NULL : array);

    ubyte* mid = (ubyte*)array;
    for (ubyte* begin = mid, *end = mid + (count * element_size); begin < end;) {
        mid = begin + (((size_t)(end - begin) / element_size) / 2) * element_size;
        int compared = comparator_(value, mid, element_size);
        if (compared == 0)
            return mid;
        else if (compared < 0)
            end = mid;
        else
            begin = mid;
    }
    return comparator_(value, mid, element_size) ? NULL : mid;
}

#pragma endregion
