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
#include "algorithm/swap.h"

// for memcmp
#include <string.h>

#pragma endregion

#pragma region --- PRIVATE ---

static byte* private_sort_partition__(byte* first, byte* last, size_t element_size, comparator_t comparator) {
    byte* pivot = last;
    last -= element_size;
LOOP:
    while (((comparator == NULL) ? memcmp(first, pivot, element_size) : comparator(first, pivot)) < 0) first += element_size;
    while (((comparator == NULL) ? memcmp(last , pivot, element_size) : comparator(last , pivot)) > 0) last  -= element_size;
    if (first < last) {
        swap_s(first, last, element_size);
        first += element_size;
        last -= element_size;
        goto LOOP;
    }
    if (first < pivot)
        swap_s(first, pivot, element_size);
    return first;
}

static void private_sort_quick_sort__(byte* begin, byte* last, size_t element_size, comparator_t comparator) {
    if (begin >= last)
        return;
    byte* pivot = private_sort_partition__(begin, last, element_size, comparator);
    private_sort_quick_sort__(begin, pivot - element_size, element_size, comparator);
    private_sort_quick_sort__(pivot + element_size, last, element_size, comparator);
}

#pragma endregion

#pragma region --- FUNCTION ---

void selection_sort(void* array, const size_t count, const size_t element_size, const comparator_t comparator) {
    explain_assert(array != NULL, "algorithm/sort: invalid arg - 'array' == NULL"     );
    explain_assert(count        , "algorithm/sort: invalid arg - 'count' == 0u"       );
    explain_assert(element_size , "algorithm/sort: invalid arg - 'element_size' == 0u");

    for (byte* sorted = array, *end = sorted + (count * element_size); sorted < end; sorted += element_size) {
        byte* min = sorted;
        for (byte* ptr = min + element_size; ptr < end; ptr += element_size)
            if (((comparator == NULL) ? memcmp(min, ptr, element_size) : comparator_(min, ptr)) > 0)
                min = ptr;
        if (min != sorted)
            swap_s(min, sorted, element_size);
    }
}

void insertion_sort(void* array, const size_t count, const size_t element_size, const comparator_t comparator) {
    explain_assert(array != NULL, "algorithm/sort: invalid arg - 'array' == NULL"     );
    explain_assert(count        , "algorithm/sort: invalid arg - 'count' == 0u"       );
    explain_assert(element_size , "algorithm/sort: invalid arg - 'element_size' == 0u");

    for (byte *sorted = array, *last = sorted + ((count - 1) * element_size); sorted < last; sorted += element_size)
        for (byte* ptr = sorted + element_size; ptr > (byte*)array; ptr -= element_size)
            if (((comparator == NULL) ? memcmp(ptr, ptr - element_size, element_size) : comparator(ptr, ptr - element_size)) < 0)
                swap_s(ptr, ptr - element_size, element_size);
}

void quick_sort(void* array, const size_t count, const size_t element_size, const comparator_t comparator) {
    explain_assert(array != NULL, "algorithm/sort: invalid arg - 'array' == NULL"     );
    explain_assert(count        , "algorithm/sort: invalid arg - 'count' == 0u"       );
    explain_assert(element_size , "algorithm/sort: invalid arg - 'element_size' == 0u");

    private_sort_quick_sort__(array, (byte*)array + ((count - 1) * element_size), element_size, comparator);
}

#pragma endregion
