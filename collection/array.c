/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "array.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX


struct array {
    struct collection_header;
    byte* data;
};

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


array_t arr_init(size_t size, size_t element_size) {
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
        result.data = block;
    }
    return result;
}
array_t array_shadow(_IN const array_t* array) {
    assert(array);
    struct _array_header* header = (struct _array_header*)array - 1;
    return array_init(header->capacity, header->element_size);
}
array_t array_copy(array_t array) {
    assert(array);
    struct _array_header* header = (struct _array_header*)array - 1;
    size_t size = sizeof(struct _array_header) + header->capacity * header->element_size;
    struct _array_header* result = (struct _array_header*)malloc(size);
    if (result) {
        memcpy(result, header, size);
        result++;
    }
    return (array_t)result;
}
void array_delete(array_t* array) {
    assert(array);
    free(array->data);
    *array =
}

// ------------------------------------------------------------------- //

void* array_at(array_t array, int position) {
    assert(array);
    struct _array_header* header = ((struct _array_header*)array) - 1;
    if (position < 0)
        if (-position - 1 > header->capacity)
            return NULL;
        else
            if (position > header->capacity)
                return NULL;
    //position = (int)header->capacity + position;
    return (byte*)array + position * header->element_size;
}