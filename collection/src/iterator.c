/*******************************************************************************
 *  @file      iterator.c
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "collection/iterator.h"

#pragma region --- INCLUDE ---

#include <stdbool.h>

#include "collection/private.h"

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

iterator_t it_begin(void* collection) {
    if (!collection) {
        explain_error("iterator error: bad pointer to container");
        return INVALID_ITERATOR;
    }

    iterator_t result = (iterator_t){
            .collection = collection,
            .data       = NULL,
            .stage      = 0,
            .direction  = IT_FORWARD
    };
    CPH_EXTRACT(collection)->cia.init_(collection, &(result.data), &(result.stage));
    return result;
}
iterator_t it_end(void* collection) {
    if (!collection) {
        explain_error("iterator error: bad pointer to container");
        return INVALID_ITERATOR;
    }

    return (iterator_t) {
        .collection = collection,
        .data = NULL,
        .stage = (int)((struct collection_universal_header*)collection)->size,
        .direction = IT_FORWARD
    };
}

iterator_t it_rbegin(void* collection) {
    if (!collection) {
        explain_error("iterator error: bad pointer to container");
        return INVALID_ITERATOR;
    }

    iterator_t result = (iterator_t){
        .collection = collection,
        .data = NULL,
        .stage = (int)((struct collection_universal_header*)collection)->size - 1,
        .direction = IT_REVERSE
    };
    CPH_EXTRACT(collection)->cia.init_(collection, &(result.data), &(result.stage));
    return result;
}
iterator_t it_rend(void* collection) {
    if (!collection) {
        explain_error("iterator error: bad pointer to container");
        return INVALID_ITERATOR;
    }

    return (iterator_t) {
        .collection = collection,
        .data = NULL,
        .stage = -1,
        .direction = IT_REVERSE
    };
}

iterator_t it_first(void* collection) {
    return it_begin(collection);
}
iterator_t it_last(void* collection) {
    if (!collection) {
        explain_error("iterator error: bad pointer to container");
        return INVALID_ITERATOR;
    }

    iterator_t result = (iterator_t){
        .collection = collection,
        .data = NULL,
        .stage = (int)((struct collection_universal_header*)collection)->size,
        .direction = IT_FORWARD
    };
    if (result.stage)
        result.stage--;
    CPH_EXTRACT(collection)->cia.init_(collection, &(result.data), &(result.stage));
    return it_valid(result) ? result : INVALID_ITERATOR;
}

#pragma endregion

#pragma region --- FUNCION ---

bool it_valid(iterator_t iterator) {
    if (!iterator.collection)
        goto IT_ERR_COLLECTION;
    bool is_bound = false;
    switch (iterator.direction)
    {
    case IT_REVERSE:
        is_bound = !((iterator.stage < -1) || (iterator.stage >= (int)iterator.collection->size)); // [-1 ... N)  --->  true, otherwise false
        break;
    case IT_FORWARD:
        is_bound = !((iterator.stage < 0) || (iterator.stage > (int)iterator.collection->size));   // (-1 ... N]  --->  true, otherwise false
        break;
    default:
        goto IT_ERR_DIRECTION;
    }
    if (!is_bound)
        goto IT_ERR_STAGE;
    if ((iterator.stage >= 0 && iterator.stage < (int)iterator.collection->size) ^ (!!iterator.data))
        goto IT_ERR_DATA;

    return true;

IT_ERR_COLLECTION:
    explain_error("iterator error: collection points to NULL");
IT_ERR_DIRECTION:
    explain_error("iterator error: undefined direction");
IT_ERR_STAGE:
    explain_error("iterator error: invalid stage");
IT_ERR_DATA:
    explain_error("iterator error: invalid data pointer");
    return false;
}

static inline bool _private_iterator_in_bound(iterator_t* iterator) {
    return (iterator->stage >= 0) && (iterator->stage < (int)iterator->collection->size);
}

bool it_comparable(iterator_t lhs, iterator_t rhs) {
    return it_valid(lhs) && it_valid(rhs) && (lhs.collection == rhs.collection) && (lhs.direction == rhs.direction);
}

bool it_equal(iterator_t lhs, iterator_t rhs) {
    return it_valid(lhs) && it_valid(rhs) && (lhs.collection == rhs.collection) && (lhs.direction == rhs.direction) && (lhs.stage == rhs.stage) && (lhs.data == rhs.data);
}

void* it_get(iterator_t iterator) {
    return it_valid(iterator) ? iterator.data : NULL;
}

void it_next(iterator_t* iterator) {
    if (!iterator || !it_valid(*iterator)) {
        explain_error("iterator error: invalid iterator");
        return;
    }

    if (_private_iterator_in_bound(iterator))
        switch (iterator->direction)
        {
        case IT_REVERSE:
            CPH_EXTRACT(iterator->collection)->cia.prev_(iterator->collection, &(iterator->data), &(iterator->stage));
            break;
        case IT_FORWARD:
            CPH_EXTRACT(iterator->collection)->cia.next_(iterator->collection, &(iterator->data), &(iterator->stage));
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
void it_prev(iterator_t* iterator) {
    if (!iterator || !it_valid(*iterator)) {
        explain_error("iterator error: invalid iterator");
        return;
    }

    if (_private_iterator_in_bound(iterator))
        switch (iterator->direction)
        {
        case IT_REVERSE:
            CPH_EXTRACT(iterator->collection)->cia.next_(iterator->collection, &(iterator->data), &(iterator->stage));
            break;
        case IT_FORWARD:
            CPH_EXTRACT(iterator->collection)->cia.prev_(iterator->collection, &(iterator->data), &(iterator->stage));
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

int it_comp(void* lhs, void* rhs, size_t size) {
    UNUSED(size);

    explain_assert(lhs, "iterator error: invalid left iterator");
    explain_assert(rhs, "iterator error: invalid right iterator");

    if (!lhs || !rhs || !it_comparable(*(iterator_t*)lhs, *(iterator_t*)rhs))
        return INVALID_STAGE;

    return ((iterator_t*)lhs)->stage - ((iterator_t*)rhs)->stage;
}

#pragma endregion
