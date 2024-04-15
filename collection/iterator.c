/*******************************************************************************
 *  @file      iterator.c
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "iterator.h"

#pragma region --- INCLUDES ---

#include <assert.h>

#pragma endregion

#pragma region --- STATIC ---

static inline bool _iterator_private_is_bound(iterator_t* iterator) {
    assert(iterator);
    switch (iterator->direction)
    {
    case IT_REVERSE:
        return !(iterator->stage < -1 || iterator->stage >= iterator->collection->size); // [-1 ... N)  --->  true, otherwise false
    case IT_FORWARD:
        return !(iterator->stage < 0 || iterator->stage > iterator->collection->size);   // (-1 ... N]  --->  true, otherwise false
    default:
        return false;
    }
}

static inline bool _iterator_private_is_range(iterator_t* iterator) {
    assert(iterator);
    return iterator->collection && !(iterator->stage < 0 || iterator->stage >= iterator->collection->size); // [0 ... N - 1]  --->  true, otherwise false
}

static inline bool _iterator_private_is_valid(iterator_t* iterator) {
    assert(iterator);
    return iterator->collection && _iterator_private_is_bound(iterator);
}

// Maybe deprecated...
static inline bool _iterator_private_on_bound(iterator_t* iterator) {
    return _iterator_private_is_valid(iterator) && ((iterator->stage == -1) || (iterator->stage == iterator->collection->size));
}

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

iterator_t it_begin(_IN void* collection) {
    assert(collection);
    iterator_t result = (iterator_t){
            .collection = collection,
            .data = NULL,
            .stage = 0,
            .direction = IT_FORWARD
    };
    result.collection->random_access(collection, &(result.data), &(result.stage));
    return result;
}
iterator_t it_end(_IN void* collection) {
    assert(collection);
    return (iterator_t) {
        .collection = collection,
        .data = NULL,
        .stage = (int)((struct collection_header*)collection)->size,
        .direction = IT_FORWARD
    };
}

iterator_t it_rbegin(_IN void* collection) {
    assert(collection);

    iterator_t result = (iterator_t){
        .collection = collection,
        .data = NULL,
        .stage = (int)((struct collection_header*)collection)->size - 1,
        .direction = IT_REVERSE
    };
    result.collection->random_access(collection, &(result.data), &(result.stage));
    return result;
}
iterator_t it_rend(_IN void* collection) {
    assert(collection);
    return (iterator_t) {
        .collection = collection,
        .data = NULL,
        .stage = -1,
        .direction = IT_REVERSE
    };
}

iterator_t it_first(_IN void* collection) {
    return it_begin(collection);
}
iterator_t it_last(_IN void* collection) {
    assert(collection);

    iterator_t result = (iterator_t){
        .collection = collection,
        .data = NULL,
        .stage = (int)((struct collection_header*)collection)->size,
        .direction = IT_FORWARD
    };
    if (result.stage)
        result.stage--;
    result.collection->random_access(collection, &(result.data), &(result.stage));
    return _iterator_private_is_valid(&result) ? result : INVALID_ITERATOR;
}

#pragma endregion

#pragma region --- FUNCIONS ---

void* it_get(_IN iterator_t* iterator) {
    _iterator_private_is_valid(iterator);
    return iterator->data;
}
void it_next(_IN iterator_t* iterator) {
    if (_iterator_private_is_range(iterator))
        switch (iterator->direction)
        {
        case IT_REVERSE:
            iterator->collection->prev(iterator->collection, &iterator->data, &iterator->stage);
            break;
        case IT_FORWARD:
            iterator->collection->next(iterator->collection, &iterator->data, &iterator->stage);
            break;
        default:
            break;
        }
}
void it_prev(_IN iterator_t* iterator) {
    if (_iterator_private_is_range(iterator))
        switch (iterator->direction)
        {
        case IT_REVERSE:
            iterator->collection->next(iterator->collection, &iterator->data, &iterator->stage);
            break;
        case IT_FORWARD:
            iterator->collection->prev(iterator->collection, &iterator->data, &iterator->stage);
            break;
        default:
            break;
        }
}

#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

#include "../core/macro/macro.h"

void* _iterator_private_try_normalize_forward(_IN iterator_t begin, _IN iterator_t end, _OUT size_t* size) {
    _iterator_private_is_valid(&begin);
    _iterator_private_is_valid(&end);
    assert(size);
    if (begin.collection != end.collection || !begin.collection->data_block)
        return NULL;
    struct collection_header* header = begin.collection;

    int from = M_MIN(begin.stage, end.stage);
    int to = M_MAX(begin.stage, end.stage);
    int range = to - from;
    if (from == -1 || range == 0)
        return NULL;

    byte* base_address = NULL;
    header->data_block(header, &base_address, NULL);
    base_address += from * header->element_size;
    *size = range;
    return base_address;
}

#pragma endregion
