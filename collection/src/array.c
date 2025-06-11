/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "collection/array.h"
#include "private.h"

#pragma region --- INCLUDE ---

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "core/core.h"
#include "algorithm/search.h"
#include "algorithm/sort.h"
#include "algorithm/memory.h"

#include "private.h"

#pragma endregion

#pragma region --- STATIC ---

static void* copy__(void* collection, int n, va_list list) {
    YSL_UNUSED(n);
    YSL_UNUSED(list);

    
}

static inline void init__(void* collection, void** block, collection_index_t* index) {
    c_size_t size         = arr_size((array_t)collection);
    c_size_t element_size = arr_element_size((array_t)collection);
    byte*    data         = arr_data((array_t)collection);

    *block = NULL;

    if (*index < -1 || *index > size || *index == COLLECTION_INVALID_INDEX) {
        *index = COLLECTION_INVALID_INDEX;
        return;
    }
    if (*index == -1 || *index == size)
        return;

    *block = ((byte*)arr_data((array_t)collection) + element_size * *index);
}
static inline void next__(void* collection, void** block, collection_index_t* index) {
    *index += 1;
    init__(collection, block, index);
}
static inline void prev__(void* collection, void** block, collection_index_t* index) {
    *index -= 1;
    init__(collection, block, index);
}

static struct collection_vtable_s array_t_vtable__ = {
    ._copy          = NULL,
    ._dtor          = NULL,
    ._element_size  = NULL,
    ._size          = NULL,
    ._capacity      = NULL,
    ._allocated     = NULL,
    ._init          = init__,
    ._next          = next__,
    ._prev          = prev__,
    ._comparator    = NULL, // uses 'memcmp'
    ._search        = &linear_search,
    ._sort          = &quick_sort
};

#pragma endregion

#pragma region --- PRIVATE ---

struct __array_s {
    c_size_t size;
    c_size_t element_size;
};

#pragma endregion

#pragma region --- MACRO ---

#define __ARR_PRIVATE_GET_HEADER(var) __C_GET_PRIVATE_HEADER(var, struct __array_s*)

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

array_t arr_ctor(const c_size_t size, const c_size_t element_size) {
    assert(size >= ARRAY_SIZE_MIN && size <= ARRAY_SIZE_MAX); // invalid arg - 'size' out of range [ARRAY_SIZE_MIN; ARRAY_SIZE_MAX]
    assert(element_size);                                     // invalid arg - 'element_size' == 0

    struct __array_s* result = malloc(sizeof(struct __array_s) + (size * element_size));

    if (result != NULL) {
        result->size         = size;
        result->element_size = element_size;
        ++result; // slide header pointer to data segment
    }

    return (array_t)result;
}

array_t arr_copy(const array_t array) {
    assert(array != NULL); // invalid arg - 'array' == NULL

    array_t src = ((array_t)array) - 1; // reverse slide pointer to header segment

    array_t result = malloc(sizeof(struct array_s) + (src->size * src->element_size));

    if(result != NULL) {
        memcpy(result, src, sizeof(struct array_s) + (src->size * src->element_size));
        ++result; // slide header pointer to data segment
    }

    return result;
}

array_t arr_slice(const array_t array, const int from, const int count) {
    size_t size         = arr_size(array);
    size_t element_size = arr_element_size(array);

    long long from_   = (long long)from + (((long long)count < 0LL) ? (long long)count + 1LL : 0LL);
    long long count_  = llabs(count);
    long long last_   = from_ + count_ - 1LL;

    explain_assert(from_ >= 0LL && from_ < size && last_ >= 0LL && last_ <= size, "collection/array: slice out of range");
    explain_assert(count != 0, "collection/array: invalid arg - 'count' == 0");
    
    array_t result = arr_ctor(count_, element_size);
    if (result != NULL) {
        memcpy((byte*)arr_data(result), arr_data(array) + from_ * element_size, count_ * element_size);
        if (count < 0)
            reverse(arr_data(result), count_, element_size);
    }

    return result;
}

void arr_dtor(array_t* array) {
    assert(array != NULL);  // invalid arg - 'array' == NULL
    assert(*array != NULL); // invalid arg - '*array' == NULL
    
    free((*array) - 1); // reverse slide pointer to header segment
    *array = NULL;
}

#pragma endregion

#pragma region --- ACCESSOR ---

size_t arr_size(const array_t array) {
    assert(array != NULL); // invalid arg - 'array' == NULL
    return (((array_t)array) - 1)->size;
}

size_t arr_element_size(const array_t array) {
    assert(array != NULL); // invalid arg - 'array' == NULL
    return (((array_t)array) - 1)->element_size;
}

void* arr_data(array_t array) {
    assert(array != NULL); // invalid arg - 'array' == NULL
    return array;
}

void* arr_at(array_t array, int index) {
    assert(index >= 0u && index < arr_size(array)); //invalid arg - 'index' out of range [0..arr_size)
    return ((byte*)array) + arr_size(array) * arr_element_size(array);
}

c_index_t arr_find(const array_t array, const void* value, const comparator_t comparator) {
    size_t element_size = arr_element_size(array);
    byte* data = (byte*)arr_data(array);
    byte* pos = (byte*)linear_search(data, arr_size(array), element_size, value, comparator);
    if (pos)
        return (pos - data) / element_size;
    return COLLECTION_INVALID_INDEX;
}

bool arr_contains(const array_t array, const void* value, const comparator_t comparator) {
    return linear_search(arr_data(array), arr_size(array), arr_element_size(array), value, comparator) != NULL;
}

void arr_sort(array_t array, const comparator_t comparator) {
    quick_sort(arr_data(array), arr_size(array), arr_element_size(array), comparator, NULL);
}

#pragma endregion
