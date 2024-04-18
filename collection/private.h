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

#pragma region --- INCLUDES ---

#include "../core/core.h"
#include "../core/debug.h"

#include "general.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

/**
 *  @typedef u_acc_t
 *  @brief   function prototype typedef for unifying access to container memory
 */
typedef void (*u_acc_t)(_IN struct universal_collection_header* collection, _INOUT void**, _INOUT int*);

/**
 *  @typedef uch_mgr_t
 *  @brief   function prototype typedef for unifying collection managing
 */
typedef void (*u_mgr_t)(_IN void* collection);

struct collection_algorithm_adapter {
    void* _comp;
    void* _swap;
    void* _srch;
    void* _sort;
};
struct collection_iterator_adapter {
    u_acc_t _init;
    u_acc_t _next;
    u_acc_t _prev;
};
struct collection_manager {
    u_mgr_t _copy;
    u_mgr_t _dtor;
};

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   UCH_INVALID
 *  @brief invalid value for UCH
 */
#define UCH_INVALID() (struct universal_collection_header){ \
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

#define UCH_EXTRACT(collection) (((struct universal_collection_header*)(collection)) - 1)

#define UCH_DECL_REF(collection, name) struct universal_collection_header* name = UCH_EXTRACT(collection)
#define UCH_DECL_CREF(collection, name) const struct unviersal_collection_header* const name = UCH_EXTRACT(collection)

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

struct collection_universal_header _alloc_cuh(
    _IN _NULLABLE const size_t capacity, 
    _IN _NULLABLE const size_t size, 
    _IN           const size_t element_size
);

struct collection_algorithm_adapter _alloc_caa(
    _IN _NULLABLE const void* _comp,
    _IN _NULLABLE const void* _swap,
    _IN _NULLABLE const void* _srch,
    _IN _NULLABLE const void* _sort
);

struct collection_iterator_adapter _alloc_cia(
    _IN const u_acc_t _init, 
    _IN const u_acc_t _next, 
    _IN const u_acc_t _prev
);

struct collection_manager _alloc_cm(
    _IN           const u_mgr_t _copy, 
    _IN _NULLABLE const u_mgr_t _dtor
);

#pragma endregion

#pragma region --- DEFAULT ---

void _default_manager(_IN void* collection);

#pragma endregion

#endif // !_COLLECTION_PRIVATE_H_
