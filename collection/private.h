/*******************************************************************************
 *  @file      private.h
 *  @brief     private collection members definition
 *  @note      only for internal use
 *  @author    Young Sideways
 *  @date      10.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COLLECTION_PRIVATE_H_
#define _COLLECTION_PRIVATE_H_

#pragma once

// UCH - Universal collectoin header

#pragma region --- INCLUDES ---

#include "../core/core.h"

#include <string.h>
#include "../algorithm/swap.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

/**
 *  @typedef uch_access_t
 *  @brief   function prototype typedef for unifying access to container memory
 */
typedef void (*uch_access_t)(_IN struct unversal_collection_header* collection, _INOUT _NULLABLE void**, _INOUT _NULLABLE int*);

/**
 *  @typedef uch_dtor_t
 *  @brief   function prototype typedef for unifying collection delete
 */
typedef void (*uch_dtor_t)(_IN void* collection);

/**
 *  @struct collection_header
 *  @brief  main data structure for all collections
 */
struct unversal_collection_header {
    size_t capacity;
    size_t size;
    size_t element_size;

    void* _comp;
    void* _search;
    void* _swap;
    void* _sort;

    uch_access_t _init;
    uch_access_t _next;
    uch_access_t _prev;
    uch_access_t _data;

    uch_dtor_t   _dtor;
};

#pragma endregion

#pragma region --- MACROS ---

/**
 *  @def   UCH_INVALID
 *  @brief invalid value for UCH
 */
#define UCH_INVALID() (struct unversal_collection_header){ \
    .capacity     = 0,                                     \
    .size         = 0,                                     \
    .element_size = 0,                                     \
    ._comp        = NULL,                                  \
    ._search      = NULL,                                  \
    ._swap        = NULL,                                  \
    ._sort        = NULL,                                  \
    ._init        = NULL,                                  \
    ._next        = NULL,                                  \
    ._prev        = NULL,                                  \
    ._data        = NULL,                                  \
    ._dtor        = NULL                                   \
}

#define UCH_EXRACT(collection) (((struct unversal_collection_header*)collection) - 1)

#define UCH_DECL_REF(collection, name) struct unversal_collection_header* name = UCH_EXRACT(collection)
#define UCH_DECL_CREF(collection, name) const struct unversal_collection_header* const name = UCH_EXRACT(collection)

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

struct unversal_collection_header uch_allocator(
    _IN _NULLABLE const size_t       capacity    ,
    _IN _NULLABLE const size_t       size        ,
    _IN           const size_t       element_size,
    _IN _NULLABLE const void*        _comp       ,
    _IN _NULLABLE const void*        _search     ,
    _IN _NULLABLE const void*        _swap       ,
    _IN _NULLABLE const void*        _sort       ,
    _IN           const uch_access_t _init       ,
    _IN           const uch_access_t _next       ,
    _IN           const uch_access_t _prev       ,
    _IN _NULLABLE const uch_access_t _data       ,
    _IN _NULLABLE const uch_dtor_t   _dtor       )
{
    assert(element_size);
    assert(_init);
    assert(_next);
    assert(_prev);

    struct unversal_collection_header result = {
        .capacity     = capacity,
        .size         = size,
        .element_size = element_size,
        ._comp        = (_comp ? _comp : &memcmp),
        ._search      = _search,
        ._swap        = (_swap ? _swap : &swap),
        ._sort        = _sort,
        ._init        = _init,
        ._next        = _next,
        ._prev        = _prev,
        ._data        = _data,
        ._dtor        = _dtor
    };
    return result;
}

#pragma endregion


#endif // !_COLLECTION_PRIVATE_H_
