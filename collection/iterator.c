/*******************************************************************************
 *  @file      iterator.c
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "iterator.h"

#pragma region --- INCLUDES ---

#include "private.h"

#pragma endregion

#pragma region --- STATIC ---

static inline bool _iterator_private_is_init(iterator_t* iterator) {
    return iterator->collection && (iterator->stage != INVALID_STAGE) && (iterator->direction != IT_UNDEFINED);
}

static inline bool _iterator_private_is_bound(iterator_t* iterator) {
    UCH_DECL_REF(iterator->collection, header);

    switch (iterator->direction)
    {
    case IT_REVERSE:
        return !(iterator->stage < -1 || iterator->stage >= header->size); // [-1 ... N)  --->  true, otherwise false
    case IT_FORWARD:
        return !(iterator->stage < 0 || iterator->stage > header->size);   // (-1 ... N]  --->  true, otherwise false
    default:
        return false;
    }
}

static inline bool _iterator_private_is_range(iterator_t* iterator) {
    return !(iterator->stage < 0 || iterator->stage >= UCH_EXTRACT(iterator->collection)->size); // [0 ... N)  --->  true, otherwise false
}

static inline bool _iterator_private_is_valid(iterator_t* iterator) {
    return _iterator_private_is_init(iterator) && _iterator_private_is_bound(iterator);
}

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

iterator_t it_begin(_IN void* collection) {
    assert(collection);

    iterator_t result = (iterator_t){
            .collection = collection,
            .data       = NULL,
            .stage      = 0,
            .direction  = IT_FORWARD
    };
    UCH_EXTRACT(collection)->_init(collection, &(result.data), &(result.stage));
    return result;
}
iterator_t it_end(_IN void* collection) {
    assert(collection);

    return (iterator_t) {
        .collection = collection,
        .data = NULL,
        .stage = (int)UCH_EXTRACT(collection)->size,
        .direction = IT_FORWARD
    };
}

iterator_t it_rbegin(_IN void* collection) {
    assert(collection);

    iterator_t result = (iterator_t){
        .collection = collection,
        .data = NULL,
        .stage = (int)UCH_EXTRACT(collection)->size - 1,
        .direction = IT_REVERSE
    };
    UCH_EXTRACT(collection)->_init(collection, &(result.data), &(result.stage));
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
        .stage = (int)UCH_EXTRACT(collection)->size,
        .direction = IT_FORWARD
    };
    if (result.stage)
        result.stage--;
    UCH_EXTRACT(collection)->_init(collection, &(result.data), &(result.stage));
    return _iterator_private_is_valid(&result) ? result : INVALID_ITERATOR;
}

#pragma endregion

#pragma region --- FUNCIONS ---

void* it_get(_IN iterator_t* iterator) {
    assert(iterator);
    assert(_iterator_private_is_valid(iterator));
    return iterator->data;
}
void it_next(_IN iterator_t* iterator) {
    assert(iterator);
    assert(_iterator_private_is_valid(iterator));

    if (_iterator_private_is_range(iterator))
        switch (iterator->direction)
        {
        case IT_REVERSE:
            UCH_EXTRACT(iterator->collection)->_prev(iterator->collection, &iterator->data, &iterator->stage);
            break;
        case IT_FORWARD:
            UCH_EXTRACT(iterator->collection)->_next(iterator->collection, &iterator->data, &iterator->stage);
            break;
        default:
            break;
        }
    else
        switch (iterator->direction)
        {
        case IT_REVERSE:
            *iterator = it_rend(iterator->collection);
            break;
        case IT_FORWARD:
            *iterator = it_end(iterator->collection);
            break;
        default:
            *iterator = INVALID_ITERATOR;
            break;
        }
}
void it_prev(_IN iterator_t* iterator) {
    assert(iterator);
    assert(_iterator_private_is_valid);

    if (_iterator_private_is_range(iterator))
        switch (iterator->direction)
        {
        case IT_REVERSE:
            UCH_EXTRACT(iterator->collection)->_next(iterator->collection, &iterator->data, &iterator->stage);
            break;
        case IT_FORWARD:
            UCH_EXTRACT(iterator->collection)->_prev(iterator->collection, &iterator->data, &iterator->stage);
            break;
        default:
            break;
        }
    else
        switch (iterator->direction)
        {
        case IT_REVERSE:
            *iterator = it_rend(iterator->collection);
            break;
        case IT_FORWARD:
            *iterator = it_end(iterator->collection);
            break;
        default:
            *iterator = INVALID_ITERATOR;
            break;
        }
}

#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

#include "../core/macro/macro.h"

int it_comp(void* lhs, void* rhs, size_t size) {
    UNUSED(size);

    explain_assert(_iterator_private_is_valid(lhs), "iterator error: invalid begin iterator");
    explain_assert(_iterator_private_is_valid(rhs), "iterator error: invalid end iterator"  );
    assert(((iterator_t*)lhs)->collection == ((iterator_t*)rhs)->collection);

    return ((iterator_t*)lhs)->stage - ((iterator_t*)rhs)->stage;
}

static void* _iterator_private_try_normalize_forward(_IN iterator_t begin, _IN iterator_t end, _OUT size_t* size) {
    assert(size);

    explain_assert(_iterator_private_is_valid(&begin), "iterator error: invalid begin iterator"         );
    explain_assert(_iterator_private_is_valid(&end)  , "iterator error: invalid end iterator"           );
    explain_assert(begin.collection == end.collection, "iterator error: differrent iterator collections");
    explain_assert(begin.direction == end.direction  , "iterator error: differrent iterator directions" );
    explain_assert(it_comp(&begin, &end, NULL) >= 0  , "iterator error: the end is to the left of begin");

    if (!UCH_EXTRACT(begin.collection)->_data) {
        *size = 0U;
        return NULL;
    }

    UCH_DECL_REF(begin.collection, header);

    int range = it_comp(&begin, &end, NULL);

    byte* base_address = NULL;
    header->_data(header, &base_address, NULL);
    base_address += begin.stage * header->element_size;
    *size = range;
    return base_address;
}

#pragma endregion
