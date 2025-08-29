/*******************************************************************************
 *  @file      iterator.c
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#define YSL_API
#define YSL_BEGIN_DECLS
#define YSL_END_DECLS
#define YSL_LIKELY(...)


#include "../inc/collection/iterator.h"

#include <assert.h>

#include "private.h"


#pragma region --- FUNCION ---

/*static inline bool _private_iterator_in_bound(iterator_t* iterator) {
    return (iterator->stage >= 0) && (iterator->stage < (int)iterator->collection->size);
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
} */

#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

int it_comp(void* lhs, void* rhs, size_t size) {
    YSL_UNUSED(size);

    assert(lhs != NULL); // collection/iterator invalid arg 'lhs' == NULL
    assert(rhs != NULL); // collection/iterator invalid arg 'rhs' == NULL
    assert(it_comparable(*(iterator_t*)lhs, *(iterator_t*)rhs)); // collection/iterator incomparable iterator rypes

    return ((iterator_t*)lhs)->index - ((iterator_t*)rhs)->index;
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

iterator_t it_begin (void* collection) {
    assert(collection != NULL); // collection/iterator invalid arg 'collection' == NULL

    C_MNGR_HDLR_PTR(hdlr, collection);

    iterator_t ret = IT_INVALID;

    if (hdlr->mngr != NULL) {
        ret.context = C_MNGR_CTX_STATE_NEW | C_MNGR_CTX_SITE_BEGIN | C_MNGR_CTX_DIRECTION_FORWARD;
        ret.value = hdlr->mngr(collection, ret.context, &(ret.data), &(ret.index));
    }

    return ret;
}
iterator_t it_end   (void* collection) {
    assert(collection != NULL); // collection/iterator invalid arg 'collection' == NULL

    C_MNGR_HDLR_PTR(hdlr, collection);

    iterator_t ret = IT_INVALID;

    if (hdlr->mngr != NULL) {
        ret.context = C_MNGR_CTX_STATE_NEW | C_MNGR_CTX_SITE_END | C_MNGR_CTX_DIRECTION_FORWARD;
        ret.value = hdlr->mngr(collection, ret.context, &(ret.data), &(ret.index));
    }
    
    return ret;
}
iterator_t it_rbegin(void* collection) {
    assert(collection != NULL); // collection/iterator invalid arg 'collection' == NULL

    C_MNGR_HDLR_PTR(hdlr, collection);

    iterator_t ret = IT_INVALID;

    if (hdlr->mngr != NULL) {
        ret.context = C_MNGR_CTX_STATE_NEW | C_MNGR_CTX_SITE_BEGIN | C_MNGR_CTX_DIRECTION_REVERSE;
        ret.value = hdlr->mngr(collection, ret.context, &(ret.data), &(ret.index));
    }
    
    return ret;
}
iterator_t it_rend  (void* collection) {
    assert(collection != NULL); // collection/iterator invalid arg 'collection' == NULL

    C_MNGR_HDLR_PTR(hdlr, collection);

    iterator_t ret = IT_INVALID;

    if (hdlr->mngr != NULL) {
        ret.context = C_MNGR_CTX_STATE_NEW | C_MNGR_CTX_SITE_END | C_MNGR_CTX_DIRECTION_REVERSE;
        ret.value = hdlr->mngr(collection, ret.context, &(ret.data), &(ret.index));
    }
    
    return ret;
}
iterator_t it_first (void* collection) {
    assert(collection != NULL); // collection/iterator invalid arg 'collection' == NULL

    C_MNGR_HDLR_PTR(hdlr, collection);

    iterator_t ret = IT_INVALID;

    if (hdlr->mngr != NULL) {
        ret.context = C_MNGR_CTX_STATE_NEW | C_MNGR_CTX_SITE_FIRST | C_MNGR_CTX_DIRECTION_FORWARD;
        ret.value = hdlr->mngr(collection, ret.context, &(ret.data), &(ret.index));
    }
    
    return ret;
}
iterator_t it_last  (void* collection) {
    assert(collection != NULL); // collection/iterator invalid arg 'collection' == NULL

    C_MNGR_HDLR_PTR(hdlr, collection);

    iterator_t ret = IT_INVALID;

    if (hdlr->mngr != NULL) {
        ret.context = C_MNGR_CTX_STATE_NEW | C_MNGR_CTX_SITE_LAST | C_MNGR_CTX_DIRECTION_FORWARD;
        ret.value = hdlr->mngr(collection, ret.context, &(ret.data), &(ret.index));
    }
    
    return ret;
}

#pragma endregion

#pragma region --- FUNCIONS ---

bool it_valid     (iterator_t iterator) {
    if (iterator.collection == NULL           )
        return false;
    if (iterator.index      == C_INDEX_INVALID)
        return false;

    return true;
}
bool it_is_forward (iterator_t iterator) {
    return iterator.context & C_MNGR_CTX_DIRECTION_FORWARD;
}
bool it_is_reverse (iterator_t iterator) {
    return c_mngr_ctx_direction(iterator.context) == C_MNGR_CTX_DIRECTION_REVERSE;
}
bool it_comparable(iterator_t lhs, iterator_t rhs) {
    return 
        (it_valid(lhs)  && it_valid(rhs) ) &&
        (lhs.collection == rhs.collection) &&
        (lhs.direction  == rhs.direction );
}
bool it_equal     (iterator_t lhs, iterator_t rhs) {
    return 
        it_comparable(lhs, rhs)  &&
        (lhs.index == rhs.index) &&
        (lhs.value == rhs.value);
}

void*  it_get  (iterator_t iterator) {
    return is_valid(iterator) ? iterator.value : NULL;
}
void  (it_next)(iterator_t* iterator) {
    assert(iterator != NULL); // collection/iterator invalid arg 'iterator' == NULL

}
void  (it_prev)(iterator_t* iterator) {
    assert(iterator != NULL); // collection/iterator invalid arg 'iterator' == NULL

}

#pragma endregion