/*******************************************************************************
 *  @file      sort.c
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/


#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "../inc/algorithm/sort.h"
#include "../inc/algorithm/swap.h"


#pragma region --- PRIVATE ---

static uint8_t* private_sort_partition__(uint8_t* first, uint8_t* last, size_t element_size, comparator_s_t comparator) {
    uint8_t* pivot = last;
    last -= element_size;
LOOP:
    if (comparator == NULL) {
        while (memcmp(first, pivot, element_size) < 0) first += element_size;
        while (memcmp(last , pivot, element_size) > 0) last  -= element_size;
    }
    else {
        while (comparator(first, pivot,element_size) < 0) first += element_size;
        while (comparator(last , pivot,element_size) > 0) last  -= element_size;
    }

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

static void private_sort_quick_sort__(uint8_t* begin, uint8_t* last, size_t element_size, comparator_s_t comparator) {
    if (begin >= last)
        return;
    uint8_t* pivot = private_sort_partition__(begin, last, element_size, comparator);
    private_sort_quick_sort__(begin, pivot - element_size, element_size, comparator);
    private_sort_quick_sort__(pivot + element_size, last, element_size, comparator);
}

#pragma endregion

#pragma region --- FUNCTION ---

void selection_sort(void* array, const size_t count, const size_t element_size, comparator_s_t comparator) {
    assert(array != NULL); // algorithm/sort: invalid arg - 'array' == NULL
    assert(count        ); // algorithm/sort: invalid arg - 'count' == 0u
    assert(element_size ); // algorithm/sort: invalid arg - 'element_size' == 0u

    for (uint8_t* sorted = array, *end = sorted + (count * element_size); sorted < end; sorted += element_size) {
        uint8_t* min = sorted;
        for (uint8_t* ptr = min + element_size; ptr < end; ptr += element_size)
            if (((comparator == NULL) ? memcmp(min, ptr, element_size) : comparator(min, ptr, element_size)) > 0)
                min = ptr;
        if (min != sorted)
            swap_s(min, sorted, element_size);
    }
}

void insertion_sort(void* array, const size_t count, const size_t element_size, comparator_s_t comparator) {
    assert(array != NULL); // algorithm/sort: invalid arg - 'array' == NULL
    assert(count        ); // algorithm/sort: invalid arg - 'count' == 0u
    assert(element_size ); // algorithm/sort: invalid arg - 'element_size' == 0u

    for (uint8_t *sorted = array, *last = sorted + ((count - 1) * element_size); sorted < last; sorted += element_size)
        for (uint8_t* ptr = sorted + element_size; ptr > (uint8_t*)array; ptr -= element_size)
            if (((comparator == NULL) ? memcmp(ptr, ptr - element_size, element_size) : comparator(ptr, ptr - element_size, element_size)) < 0)
                swap_s(ptr, ptr - element_size, element_size);
}

void quick_sort(void* array, const size_t count, const size_t element_size, comparator_s_t comparator) {
    assert(array != NULL); // algorithm/sort: invalid arg - 'array' == NULL
    assert(count        ); // algorithm/sort: invalid arg - 'count' == 0u
    assert(element_size ); // algorithm/sort: invalid arg - 'element_size' == 0u

    private_sort_quick_sort__(array, (uint8_t*)array + ((count - 1) * element_size), element_size, comparator);
}

#pragma endregion
