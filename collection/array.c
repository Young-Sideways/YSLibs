/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "array.h"

#pragma region --- INCLUDES ---

#include <string.h>
#include <stdlib.h>

#include "../algorithm/search.h"
#include "private.h"

#pragma endregion

#pragma region --- STATIC ---

static inline void _init(struct universal_collection_header* collection, void** block, int* index) {
    UCH_DECL_REF(collection, header);
    if (*index < 0) {
        *index = -1;
        *block = NULL;
        return;
    }
    if (*index >= header->size) {
        *index = header->size;
        *block = NULL;
        return;
    }
    *block = ((byte*)collection + header->element_size * *index);
}
static inline void _next(struct universal_collection_header* collection, void** block, int* index) {
    *index += 1;
    _init(collection, block, index);
}
static inline void _prev(struct universal_collection_header* collection, void** block, int* index) {
    *index -= 1;
    _init(collection, block, index);
}

static inline bool _array_private_is_valid(array_t array) {
    UCH_DECL_REF(array, header);
    return (header->size == header->capacity)
        && (header->size <= ARRAY_SIZE_MAX)
        && (header->element_size);
}
#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(const size_t size, const size_t element_size) {
    byte* block = calloc(sizeof(struct universal_collection_header) + (size * element_size), sizeof(byte));
    if (block) {
        *(struct universal_collection_header*)block = uch_allocator(
            size,
            size,
            element_size,
            &memcmp,
            NULL,
            NULL,
            NULL,
            &_init,
            &_next,
            &_prev,
            NULL,
            NULL);
        block += sizeof(struct universal_collection_header);
    }
    return (array_t)block;
}

array_t arr_shadow(_IN const array_t array) {
    assert(array);
    return arr_init(UCH_EXTRACT(array)->size, UCH_EXTRACT(array)->element_size);
}

array_t arr_copy(_IN const array_t array) {
    assert(array);
    byte* block = malloc(sizeof(struct universal_collection_header) + (UCH_EXTRACT(array)->size * UCH_EXTRACT(array)->element_size));
    if (block) {
        if (memcpy(block, UCH_EXTRACT(array), sizeof(struct universal_collection_header) + (UCH_EXTRACT(array)->size * UCH_EXTRACT(array)->element_size)))
            block += sizeof(struct universal_collection_header);
        else {
            free(block);
            block = NULL;
        }
    }
    return (array_t)block;
}

array_t arr_move(_IN array_t* array) {
    assert(_array_private_is_valid(*array));
    array_t result = *array;
    *array = NULL;
    return result;
}

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(array_t array, int position) {
    assert(_array_private_is_valid(array));
    if (position < 0)
        position = (int)UCH_EXTRACT(array)->size + position;
    assert(position > -1 && position < UCH_EXTRACT(array)->size);
    return (byte*)array + position * UCH_EXTRACT(array)->element_size;
}

#pragma endregion
