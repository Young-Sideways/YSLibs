/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "collection/array.h"

#pragma region --- INCLUDE ---

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stdio.h"

#include "core.h"
#include "debug.h"
#include "algorithm/search.h"
#include "algorithm/sort.h"
#include "algorithm/memory.h"

#pragma endregion

#pragma region --- STATIC ---
/**
static inline void init_(struct collection_universal_header* collection, void** block, int* index) {
    *block = NULL;
    if (*index == COLLECTION_INVALID_INDEX)
        return;
    if (*index < 0) {
        *index = -1;
        return;
    }
    if (*index >= (int)collection->size) {
        *index = (int)collection->size;
        return;
    }
    *block = ((byte*)CPH_EXTRACT(collection)->data_ + collection->element_size * *index);
}
static inline void next_(struct collection_universal_header* collection, void** block, int* index) {
    *index += 1;
    init_(collection, block, index);
}
static inline void prev_(struct collection_universal_header* collection, void** block, int* index) {
    *index -= 1;
    init_(collection, block, index);
}
static inline void* copy_(void* collection) {
    array_t from = (array_t)collection;
    CPH_CREF(collection, from_header);

    byte* result = (byte*)malloc(sizeof(struct collection_private_header) + sizeof(struct array_t) + (from->size + from->element_size));
    if (result) {
        memcpy(result, from_header, sizeof(struct collection_private_header) + sizeof(struct array_t) + (from->size + from->element_size));
        result += sizeof(struct collection_private_header);
    }
    return (void*)result;
}
*/
#pragma endregion

#pragma region --- PRIVATE ---
/**
static inline bool array_private_is_valid_(array_t array) {
    return (array->size == array->capacity)
        && (array->size <= ARRAY_SIZE_MAX)
        && (array->element_size)
        && (array->data);
}
*/
#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

array_t arr_ctor(const size_t size, const size_t element_size) {
    explain_assert(size >= ARRAY_SIZE_MIN && size <= ARRAY_SIZE_MAX, "collection/array: invalid arg - 'size' out of range [ARRAY_SIZE_MIN; ARRAY_SIZE_MAX]");
    explain_assert(element_size, "collection/array: invalid arg - 'element_size' == 0");
    struct array_t* result = malloc(sizeof(struct array_t));
    if (!result)
        return NULL;
    result->data = malloc(size * element_size);
    if (!result->data) {
        free(result);
        return NULL;
    }
    result->size = size;
    result->element_size = element_size;
    return result;
}

array_t arr_copy(const array_t array) {
    size_t size = arr_size(array);
    size_t element_size = arr_element_size(array);
    array_t result = arr_ctor(size, element_size);
    if(result)
        if (!memcpy(arr_data(result), arr_data(array), size * element_size))
            arr_dtor(&result);
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
    
    printf("[%lld, %lld]: %lld\n", from_, last_, count_);
    array_t result = arr_ctor(count_, element_size);
    if (result) {
        if(!memcpy((byte*)arr_data(result), arr_data(array) + from_ * element_size, count_ * element_size)){
            arr_dtor(&result);
            return result;
        }
        if (count < 0)
            reverse(arr_data(result), count_, element_size);
    }
    return result;
}

void arr_dtor(array_t* array) {
    explain_assert(array && *array, "collection/array: invalid arg - 'array' == NULL");
    free((*array)->data);
    free(*array);
    *array = NULL;
}

#pragma endregion

#pragma region --- ACCESSOR ---

size_t arr_size(const array_t array) {
    explain_assert(array, "collection/array: invalid arg - 'array' == NULL");
    return array->size;
}

size_t arr_element_size(const array_t array) {
    explain_assert(array, "collection/array: invalid arg - 'array' == NULL");
    return array->element_size;
}

void* arr_data(array_t array) {
    explain_assert(array, "collection/array: invalid arg - 'array' == NULL");
    return array->data;
}

void* arr_at(array_t array, int index) {
    explain_assert(index >= 0 && index < ARRAY_SIZE_MAX, "collection/array: invalid arg - 'index' out of range [0..ARRAY_SIZE_MAX)");
    return ((byte*)arr_data(array)) + (index * arr_element_size(array));
}

int arr_find(array_t array, const void* value) {
    size_t element_size = arr_element_size(array);
    byte* data = (byte*)arr_data(array);
    byte* pos = (byte*)linear_search(data, arr_size(array), element_size, value, NULL);
    if (pos)
        return (pos - data) / element_size;
    return COLLECTION_INVALID_INDEX;
}

bool arr_contains(array_t array, const void* value) {
    return linear_search(arr_data(array), arr_size(array), arr_element_size(array), value, NULL) != NULL;
}

void arr_sort(array_t array, comparator_t comparator) {
    quick_sort(arr_data(array), arr_size(array), arr_element_size(array), comparator, NULL);
}

#pragma endregion
