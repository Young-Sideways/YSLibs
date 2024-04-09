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

#include "general.h"

#pragma endregion

#pragma region --- MACROS ---

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEFS ---

struct array {
    struct collection_header;
    byte* data;
};

#pragma endregion

#pragma region --- STATIC ---

static void* next(array_t* collection, void** block, int* index) {
    *index += 1;
    return (byte*)*block = (collection->data + (collection->element_size * *index));
}
static void* prev(array_t* collection, void** block, int* index) {
    *index -= 1;
    return (byte*)*block = (collection->data + (collection->element_size * *index));
}
static void* data(array_t* collection, void** block, int* index) {
    UNUSED(block);
    UNUSED(index);
    return collection->data;
}
static void* random_access(array_t* collection, void** block, int* index) {
    return (byte*)*block = (collection->data + (collection->element_size * *index));
}

static bool is_valid(array_t* array) {
    return (array)
        && (array->size)
        && (array->size == array->capacity)
        && (array->size <= ARRAY_SIZE_MAX)
        && (array->element_size)
        && (array->data);
}
#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(const size_t size, const size_t element_size) {
    assert(element_size);
    assert(size <= ARRAY_SIZE_MAX);

    array_t result = { 0 };

    void* block = calloc(size, element_size);
    if (block) {
        result = (array_t){
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
            NULL };
        result.size = size;
        result.data = block;
    }
    return result;
}

array_t arr_shadow(_IN const array_t* array) {
    assert(is_valid(array));
    return arr_init(array->size, array->element_size);
}

array_t arr_copy(_IN const array_t* array) {
    assert(is_valid(array));
    array_t result = arr_init(array->size, array->element_size);
    if (result.size)
        memcpy(result.data, array->data, result.size * result.element_size);
}

array_t arr_move(_IN array_t* array) {
    assert(is_valid(array));
    array_t result = *array;
    *array = (array_t){ 0 };
    return result;
}


void arr_delete(_IN array_t* array) {
    assert(is_valid(array));
    free(array->data);
    *array = (array_t){ 0 };
}

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(array_t* array, int position) {
    assert(is_valid(array));
    if (position < 0)
        position = array->size + position;
    assert(position < array->size);
    return array->data + position * array->element_size;
}

#pragma endregion

#pragma region --- INFORMATION ---

size_t arr_size(array_t* array) {
    assert(is_valid(array));
    return array->size;
}
size_t arr_element_size(array_t* array) {
    assert(is_valid(array));
    return array->element_size;
}

#pragma endregion
