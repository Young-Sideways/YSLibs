/*******************************************************************************
 *  @file      sort.c
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/sort.h"

#pragma region --- INCLUDE ---

#include "core.h"
#include "debug.h"

// for memcmp
#include <string.h>

#pragma endregion

#pragma region --- PRIVATE ---

static void* private_sort_partition__(ubyte* first, ubyte* last, size_t element_size, comparator_t comparator_, swap_t swap_) {
    ubyte* pivot = last;
    last -= element_size;
    LOOP:
    while (comparator_(first, pivot, element_size) < 0) first += element_size;
    while (comparator_(last, pivot, element_size) > 0) last -= element_size;
    if (first < last) {
        swap_(first, last, element_size);
        first += element_size;
        last -= element_size;
        goto LOOP;
    }
    if (first < pivot)
        swap_(first, pivot, element_size);
    return first;
}

static void private_sort_quick_sort__(ubyte* begin, ubyte* end, size_t element_size, comparator_t comparator_, swap_t swap_) {
    if (begin >= end)
        return;
    ubyte* pivot = (ubyte*)private_sort_partition__(begin, end, element_size, comparator_, swap_);
    private_sort_quick_sort__(begin, pivot - element_size, element_size, comparator_, swap_);
    private_sort_quick_sort__(pivot + element_size, end, element_size, comparator_, swap_);
}

#pragma endregion

#pragma region --- FUNCTION ---

void selection_sort(void* array, const size_t count, const size_t element_size, comparator_t comparator_, swap_t swap_) {
    explain_assert(array       , "algorithm/sort: invalid arg - 'array' == NULL"     );
    explain_assert(count       , "algorithm/sort: invalid arg - 'count' == 0u"       );
    explain_assert(element_size, "algorithm/sort: invalid arg - 'element_size' == 0u");

    if (!comparator_)
        comparator_ = &memcmp;
    if (!swap_)
        swap_ = &swap;

    for (ubyte* sorted = array, *end = sorted + (count * element_size); sorted < end; sorted += element_size) {
        ubyte* min = sorted;
        for (ubyte* ptr = min + element_size; ptr < end; ptr += element_size)
            if (comparator_(min, ptr, element_size) > 0)
                min = ptr;
        if (min != sorted)
            swap_(min, sorted, element_size);
    }
}

void insertion_sort(void* array, const size_t count, const size_t element_size, comparator_t comparator_, swap_t swap_) {
    explain_assert(array       , "algorithm/sort: invalid arg - 'array' == NULL"     );
    explain_assert(count       , "algorithm/sort: invalid arg - 'count' == 0u"       );
    explain_assert(element_size, "algorithm/sort: invalid arg - 'element_size' == 0u");

    if (!comparator_)
        comparator_ = &memcmp;
    if (!swap_)
        swap_ = &swap;

    for (ubyte*sorted = array, *last = sorted + ((count - 1) * element_size); sorted < last; sorted += element_size)
        for (ubyte* ptr = sorted + element_size; ptr > (ubyte*)array; ptr -= element_size)
            if (comparator_(ptr, ptr - element_size, element_size) < 0)
                swap_(ptr, ptr - element_size, element_size);
}

void quick_sort(void* array, const size_t count, const size_t element_size, comparator_t comparator_, swap_t swap_) {
    explain_assert(array       , "algorithm/sort: invalid arg - 'array' == NULL"     );
    explain_assert(count       , "algorithm/sort: invalid arg - 'count' == 0u"       );
    explain_assert(element_size, "algorithm/sort: invalid arg - 'element_size' == 0u");

    if (!comparator_)
        comparator_ = &memcmp;
    if (!swap_)
        swap_ = &swap;

    private_sort_quick_sort__(array, (ubyte*)array + ((count - 1) * element_size), element_size, comparator_, swap_);
}

#pragma endregion
