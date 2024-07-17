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

#include "core.h"
#include "debug.h"
#include "algorithm/search.h"
#include "collection/private.h"

#pragma endregion

#pragma region --- STATIC ---

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

#pragma endregion

#pragma region --- PRIVATE ---

static inline bool array_private_is_valid_(array_t array) {
    return (array->size == array->capacity)
        && (array->size <= ARRAY_SIZE_MAX)
        && (array->element_size)
        && (array->data);
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

array_t arr_ctor(const size_t size, const size_t element_size) {
    struct array_t* result = NULL;
    struct collection_private_header* block = (struct collection_private_header*)malloc(sizeof(struct collection_private_header) + sizeof(struct array_t) + (size * element_size));
    if (block) {
        *block = alloc_cph(
            alloc_caa(NULL, NULL, &private_collection_function_placeholder_, &private_collection_function_placeholder_),
            alloc_cia(&init_, &next_, &prev_),
            alloc_cma(&copy_, NULL),
            NULL);

        result = (struct array_t*)(block + 1);
        *result = (struct array_t){ alloc_cuh(size, size, element_size), NULL };

        block->data_ = result->data = (void*)(result + 1);
        memset(result->data, 0, size * element_size);
    }
    return (array_t)result;
}

#pragma endregion

#pragma region --- ACCESSOR ---

void* arr_at(array_t array, int index) {
    assert(array_private_is_valid_(array));
    assert(index >= 0 && index < (int)array->size);
    return (byte*)array->data + index * array->element_size;
}

#pragma endregion
