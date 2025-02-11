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

void* linear_search(const void* array, const size_t count, const size_t element_size, const void* value, const comparator_t comparator) {
    explain_assert(array != NULL, "algorithm/search: invalid arg - 'array' == NULL"     );
    explain_assert(count        , "algorithm/search: invalid arg - 'count' == 0u"       );
    explain_assert(element_size , "algorithm/search: invalid arg - 'element_size' == 0u");
    explain_assert(value != NULL, "algorithm/search: invalid arg - 'value' == NULL"     );

    for (byte* begin = (void*)array, *end = begin + (count * element_size); begin < end; begin += element_size)
        if (((comparator == NULL) ? memcmp(begin, value, element_size) : comparator(begin, value)) == 0)
            return (void*)begin;
    
    return NULL;
}

void* binary_search(const void* array, const size_t count, const size_t element_size, const void* value, const comparator_t comparator) {
    explain_assert(array != NULL, "algorithm/search: invalid arg - 'array' == NULL"     );
    explain_assert(count        , "algorithm/search: invalid arg - 'count' == 0u"       );
    explain_assert(element_size , "algorithm/search: invalid arg - 'element_size' == 0u");
    explain_assert(value != NULL, "algorithm/search: invalid arg - 'value' == NULL"     );

    byte* mid = (ubyte*)array;
    for (byte* begin = mid, *end = mid + (count * element_size); begin < end;) {
        mid = begin + (((size_t)(end - begin) / element_size) / 2) * element_size;
        int compared = ((comparator == NULL) ? memcmp(value, mid, element_size) : comparator(value, mid));
        if (compared == 0)
            return mid;
        else if (compared < 0)
            end = mid;
        else
            begin = mid;
    }

    if (comparator == NULL)
        return (void*)(memcmp(value, mid, element_size) ? NULL : mid);
    else
        return (void*)(comparator(value, mid) ? NULL : mid);
}

#pragma endregion
