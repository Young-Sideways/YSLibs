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
#include <stdbool.h>

#include "../../algorithm/search.h"
#include "../private.h"

#pragma endregion

#pragma region --- STATIC ---

static inline void _init(struct collection_universal_header* collection, void** block, int* index) {
    *block = NULL;
    if (*index == COLLECTION_INVALID_INDEX)
        return;
    if (*index < 0) {
        *index = -1;
        return;
    }
    if (*index >= collection->size) {
        *index = (int)collection->size;
        return;
    }
    *block = ((byte*)CPH_EXTRACT(collection)->_data + collection->element_size * *index);
}
static inline void _next(struct collection_universal_header* collection, void** block, int* index) {
    *index += 1;
    _init(collection, block, index);
}
static inline void _prev(struct collection_universal_header* collection, void** block, int* index) {
    *index -= 1;
    _init(collection, block, index);
}
static inline void* _copy(void* collection) {
    array_t from = (array_t)collection;
    CPH_CREF(collection, from_header);

    byte* result = (byte*)malloc(sizeof(struct collection_private_header) + sizeof(struct array_t) + (from->size + from->element_size));
    if (result) {
        memcpy(result, from_header, sizeof(struct collection_private_header) + sizeof(struct array_t) + (from->size + from->element_size));
        result += sizeof(struct collection_private_header);
    }
    return (array_t)result;
}

static inline bool _array_private_is_valid(array_t array) {
    return (array->size == array->capacity)
        && (array->size <= ARRAY_SIZE_MAX)
        && (array->element_size)
        && (array->data);
}

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(_IN const size_t size, _IN const size_t element_size) {
    struct array_t* result = NULL;
    struct collection_private_header* block = (struct collection_private_header*)malloc(sizeof(struct collection_private_header) + sizeof(struct array_t) + (size * element_size));
    if (block) {
        *block = alloc_cph(
            alloc_caa(NULL, NULL, __function_placeholder, __function_placeholder),
            alloc_cia(&_init, &_next, &_prev),
            alloc_cma(&_copy, NULL),
            NULL);

        result = (struct array_t*)(block + 1);
        *result = (struct array_t){ alloc_cuh(size, size, element_size), NULL };

        block->_data = result->data = (void*)(result + 1);
        memset(result->data, 0, size * element_size);
    }
    return (array_t)result;
}

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(_IN array_t array, _IN int position) {
    assert(_array_private_is_valid(array));
    assert(position >= 0 && position < array->size);
    return (byte*)array->data + position * array->element_size;
}

#pragma endregion
