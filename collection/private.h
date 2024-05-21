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
 *  @param[in]     collection - Pointer to main collection structure
 *  @param[in,out] block      - init/proccessed block
 *  @param[in,out] stage      - init/proccessed stage
 */
typedef void (*u_acc_t)(struct collection_universal_header* collection, void** block, int* stage);

/**
 *  @typedef u_mgr_t
 *  @brief   function prototype typedef for unifying collection managing
 *  @param[in]     collection - Pointer to main collection structure
 */
typedef void* (*u_mgr_t)(void* collection);

/**
 *  @struct collection_algorithm_adapter
 *  @brief  algorithm adapter header
 * 
 *  default field policy:
 *      NULL   : this algorithm can NOT be applied
 *      POINTER: this algorithm can be applied to the container, and function pointer can be replaced to another function
 */
struct collection_algorithm_adapter {
    void* _comp;
    void* _swap;
    void* _srch;
    void* _sort;
};

/**
 *  @struct collection_iterator_adapter
 *  @brief  iterator adapter header
 */
struct collection_iterator_adapter {
    u_acc_t _init;
    u_acc_t _next;
    u_acc_t _prev;
};

/**
 *  @struct collection_manager_adapter
 *  @brief  collection maganer adapter
 *  default field policy:
 *      _copy: can NOT be NULL
 *      _dtor:
 *          NULL: data memory block places after universal header
 */
struct collection_manager_adapter {
    u_mgr_t _copy;
    u_mgr_t _dtor;
};

/**
 *  @struct collection_private_header
 *  @brief  private header, thats contain info about collection
 */
struct collection_private_header {
    struct collection_algorithm_adapter caa;
    struct collection_iterator_adapter cia;
    struct collection_manager_adapter cma;
    void* _data;
};

#pragma endregion

#pragma region --- MACRO ---

#define CPH_EXTRACT(collection) (((struct collection_private_header*)(collection)) - 1)

#define CPH_REF(collection, name) struct collection_private_header* name = CPH_EXTRACT(collection)
#define CPH_CREF(collection, name) const struct collection_private_header* const name = CPH_EXTRACT(collection)

#pragma endregion

#pragma region --- PLACEHOLDER ---

static inline void function_placeholder() {};

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

struct collection_universal_header alloc_cuh(
    const size_t capacity, 
    const size_t size, 
    const size_t element_size
);

struct collection_algorithm_adapter alloc_caa(
    const void* _comp, 
    const void* _swap, 
    const void* _srch, 
    const void* _sort
);

struct collection_iterator_adapter alloc_cia(
    const u_acc_t _init, 
    const u_acc_t _next, 
    const u_acc_t _prev
);

struct collection_manager_adapter alloc_cma(
    const u_mgr_t _copy, 
    const u_mgr_t _dtor
);

struct collection_private_header alloc_cph(
    struct collection_algorithm_adapter caa,
    struct collection_iterator_adapter cia,
    struct collection_manager_adapter cma,
    void* _data
);

#pragma endregion

#endif // !_COLLECTION_PRIVATE_H_
