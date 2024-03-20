/*******************************************************************************
 *  @file      sort.c
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "sort.h"

#pragma region --- INCLUDES ---

#include <math.h>
#include <string.h>

#pragma endregion

#pragma region --- FUNCTIONS ---

void selection_sort(void* array, size_t count, size_t element_size, comparator_pt _comparator, swap_pt _swap) {
    assert(array);
    assert(count);
    assert(element_size);

    if (!_comparator)
        _comparator = &memcmp;
    if (!_swap)
        _swap = &swap;

    for (byte* sorted = array, *end = sorted + (count * element_size); sorted < end; sorted += element_size) {
        byte* min = sorted;
        for (byte* ptr = min + element_size; ptr < end; ptr += element_size)
            if (_comparator(min, ptr, element_size) > 0)
                min = ptr;
        if (min != sorted)
            _swap(min, sorted, element_size);
    }
}

void insertion_sort(void* array, size_t count, size_t element_size, comparator_pt _comparator, swap_pt _swap) {
    assert(array);
    assert(count);
    assert(element_size);

    if (!_comparator)
        _comparator = &memcmp;
    if (!_swap)
        _swap = &swap;

    for (byte *sorted = array, *last = sorted + ((count - 1) * element_size); sorted < last; sorted += element_size)
        for (byte* ptr = sorted + element_size; ptr > (byte*)array; ptr -= element_size)
            if (_comparator(ptr, ptr - element_size, element_size) < 0)
                _swap(ptr, ptr - element_size, element_size);
}

static void* partition(byte* first, byte* last, size_t element_size, comparator_pt _comparator, swap_pt _swap) {
    byte* pivot = last;
    last -= element_size;
LOOP:
    while (_comparator(first, pivot, element_size) < 0) first += element_size;
    while (_comparator(last, pivot, element_size) > 0) last -= element_size;
    if (first < last) {
        _swap(first, last, element_size);
        first += element_size;
        last -= element_size;
        goto LOOP;
    }
    if (first < pivot)
        _swap(first, pivot, element_size);
    return first;
}

static void _private_quick_sort(byte* begin, byte* end, size_t element_size, comparator_pt _comparator, swap_pt _swap) {
    if (begin >= end)
        return;
    byte* pivot = (byte*)partition(begin, end, element_size, _comparator, _swap);
    _private_quick_sort(begin, pivot - element_size, element_size, _comparator, _swap);
    _private_quick_sort(pivot + element_size, end, element_size, _comparator, _swap);
}

void quick_sort(void* array, size_t count, size_t element_size, comparator_pt _comparator, swap_pt _swap) {
    assert(array);
    assert(count);
    assert(element_size);

    if (!_comparator)
        _comparator = &memcmp;
    if (!_swap)
        _swap = &swap;

    _private_quick_sort(array, (byte*)array + ((count - 1) * element_size), element_size, _comparator, _swap);
}

#pragma endregion
