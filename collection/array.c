/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "array.h"

#pragma region --- INCLUDES ---

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../algorithm/search.h"

#pragma endregion

#pragma region --- STATIC ---

static inline void random_access(array_t* collection, void** block, int* index) {
    *block = (*index < 0 || *index >= collection->size) ? NULL : (collection->data + (collection->element_size * *index)); 
}
static inline void next(array_t* collection, void** block, int* index) {
    *index += 1;
    random_access(collection, block, index);
}
static inline void prev(array_t* collection, void** block, int* index) {
    *index -= 1;
    random_access(collection, block, index);
}
static inline void data(array_t* collection, void** block, int* index) {
    UNUSED(index);
    *block = collection->data;
}

static bool _iterator_private_is_valid(array_t* array) {
    return (array)
        && (array->size == array->capacity)
        && (array->size <= ARRAY_SIZE_MAX)
        && (array->element_size)
        && (array->data);
}
#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(const size_t size, const size_t element_size) {
    array_t result = (array_t){
        header_allocator(
            size,
            element_size,
            NULL,
            &linear_search,
            NULL,
            &qsort,
            &next,
            &prev,
            &data,
            &random_access),
        .data = NULL
    };

    if (result.data = calloc(size, element_size))
        result.size = size;
    else
        result = (array_t){ COLLECTION_INVALID_HEADER() , NULL };

    return result;
}

array_t arr_shadow(_IN const array_t* array) {
    assert(array);
    return arr_init(array->size, array->element_size);
}

array_t arr_copy(_IN const array_t* array) {
    array_t result = arr_shadow(array);
    if (result.data)
        memcpy(result.data, array->data, result.size * result.element_size);
}

array_t arr_move(_IN array_t* array) {
    assert(_iterator_private_is_valid(array));
    array_t result = *array;
    *array = (array_t){ 0 };
    return result;
}

void arr_delete(_IN array_t* array) {
    assert(_iterator_private_is_valid(array));
    free(array->data);
    *array = (array_t){ COLLECTION_INVALID_HEADER(), NULL};
}

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(array_t* array, int position) {
    assert(_iterator_private_is_valid(array));
    if (position < 0)
        position = array->size + position;
    assert(position > -1 && position < array->size);
    return array->data + position * array->element_size;
}

#pragma endregion

#pragma region --- INFORMATION ---

size_t arr_size(array_t* array) {
    assert(_iterator_private_is_valid(array));
    return array->size;
}
size_t arr_element_size(array_t* array) {
    assert(_iterator_private_is_valid(array));
    return array->element_size;
}

#pragma endregion
