/*******************************************************************************
 *  @file      generic.h
 *  @brief     General collections macro header to include all collections
 *  @author    Young Sideways
 *  @date      03.09.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_GENERIC_H_
#define C_GENERIC_H_


#include "general.h"

#include <core/core.h>
#include <macro/expect.h>


#pragma region --- GENERICS ---

/**
 * @def c_ctor
 * @brief Creates new container with given \p type
 * @param type - type of container
 * @param ...  - constructor specific initiators
 * @code
 * tuple_t    : c_ctor(tuple_t, ...)                      -> tuple_ctor(size_t* sizes, void* values)
 * pair_t     : c_ctor(pair_t, key, value)                -> tuple_ctor((size_t*){ sizeof(key), sizeof(value), 0U }, (void*){ key, value })
 * variant_t  : c_ctor(variant_t, value)                  -> tuple_ctor((size_t*){ sizeof(value), 0U }, (void*){ value })
 * array_t    : c_ctor(array_t, type, size)               -> array_ctor(sizeof(type), size)
 * vector_t   : c_ctor(vector_t, type, size)              -> vector_ctor(sizeof(type), size)
 * list_t     : c_ctor(list_t, type, size)                -> list_ctor(sizeof(type), size)
 * matrix_t   : c_ctor(matrix_t, type, rows, cols)        -> matrix_ctor( sizeof(type), rows, cols)
 * deque_t    : c_ctor(deque_t, type)                     -> deque_ctor(sizeof(type))
 * queue_t    : c_ctor(queue_t, type)                     -> queue_ctor(sizeof(type))
 * stack_t    : c_ctor(stack_t, type)                     -> stack_ctor(sizeof(type))
 * set_t      : c_ctor(set_t, type, size)                 -> set_ctor(sizeof(type), size)
 * map_t      : c_ctor(map_t, key_type, value_type, size) -> map_ctor(sizeof(key_type), sizeof(value_type), size)
 * multiset_t : c_ctor(multiset_t, type, size)            -> multiset_ctor(sizeof(type), size)
 * multimap_t : c_ctor(multimap_t, type, size)            -> multimap_ctor(sizeof(key_type), sizeof(value_type), size)
 * avltree_t  : c_ctor(avltree_t, type)                   -> avltree_ctor(sizeof(type))
 * rbtree_t   : c_ctor(rbtree_t, type)                    -> rbtree_ctor(sizeof(type))
 * btree_t    : c_ctor(btree_t, type)                     -> btree_ctor(sizeof(type))
 * @endcode
 */
#define c_ctor(type, ...)

/**
 * @def c_dtor
 * @brief Destroys container from memory
 * @param container - container reference
 * @code
 * tuple_t    : c_dtor(tuple_t)    -> tuple_dtor(container)
 * pair_t     : c_dtor(pair_t)     -> tuple_dtor(container)
 * variant_t  : c_dtor(variant_t)  -> tuple_dtor(container)
 * array_t    : c_dtor(array_t)    -> array_dtor(container)
 * vector_t   : c_dtor(vector_t)   -> vector_dtor(container)
 * list_t     : c_dtor(list_t)     -> list_dtor(container)
 * matrix_t   : c_dtor(matrix_t)   -> matrix_dtor(container)
 * deque_t    : c_dtor(deque_t)    -> deque_dtor(container)
 * queue_t    : c_dtor(queue_t)    -> queue_dtor(container)
 * stack_t    : c_dtor(stack_t)    -> stack_dtor(container)
 * set_t      : c_dtor(set_t)      -> set_dtor(container)
 * map_t      : c_dtor(map_t)      -> map_dtor(container)
 * multiset_t : c_dtor(multiset_t) -> multiset_dtor(container)
 * multimap_t : c_dtor(multimap_t) -> multimap_dtor(container)
 * avltree_t  : c_dtor(avltree_t)  -> avltree_dtor(container)
 * rbtree_t   : c_dtor(rbtree_t)   -> rbtree_dtor(container)
 * btree_t    : c_dtor(btree_t)    -> btree_dtor(container)
 * @endcode
 */
#define c_dtor(container)

/**
 * @def copy
 * @brief Makes copy of given cntainer
 * @param container - container reference
 * @code
 * tuple_t    : copy(tuple_t)    -> tuple_copy(container)
 * pair_t     : copy(pair_t)     -> tuple_copy(container)
 * variant_t  : copy(variant_t)  -> tuple_copy(container)
 * array_t    : copy(array_t)    -> array_copy(container)
 * vector_t   : copy(vector_t)   -> vector_copy(container)
 * list_t     : copy(list_t)     -> list_copy(container)
 * matrix_t   : copy(matrix_t)   -> matrix_copy(container)
 * deque_t    : copy(deque_t)    -> deque_copy(container)
 * queue_t    : copy(queue_t)    -> queue_copy(container)
 * stack_t    : copy(stack_t)    -> stack_copy(container)
 * set_t      : copy(set_t)      -> set_copy(container)
 * map_t      : copy(map_t)      -> map_copy(container)
 * multiset_t : copy(multiset_t) -> multiset_copy(container)
 * multimap_t : copy(multimap_t) -> multimap_copy(container)
 * avltree_t  : copy(avltree_t)  -> avltree_copy(container)
 * rbtree_t   : copy(rbtree_t)   -> rbtree_copy(container)
 * btree_t    : copy(btree_t)    -> btree_copy(container)
 * @endcode
 */
#define copy(container)

/**
 * @def at
 * @brief Take item from container with given index
 * @param container - container reference
 * @param ...       - arg depends on container
 * @code
 * tuple_t    : at(tuple_t, index)    -> tuple_copy(container)
 * pair_t     : at(pair_t, index)     -> tuple_copy(container)
 * array_t    : at(array_t, index)    -> array_copy(container)
 * vector_t   : at(vector_t, index)   -> vector_copy(container)
 * list_t     : at(list_t, index)     -> list_copy(container)
 * matrix_t   : at(matrix_t, row, col)-> matrix_copy(container)
 * set_t      : at(set_t, value)      -> set_copy(container)
 * map_t      : at(map_t, key)        -> map_copy(container)
 * multiset_t : at(multiset_t, value) -> multiset_copy(container)
 * multimap_t : at(multimap_t, key)   -> multimap_copy(container)
 * @endcode
 */
#define at(collection, ...)
#define find(collection, key)

#define sort(collection)

#pragma endregion

#pragma region --- FUNCTION ---

void* (c_copy)(void* container);
#define c_copy(container) (YSL_TYPEOF_UNQUAL(container))(c_copy)((void*)container)

void* (c_shadow)(void* container);
#define c_shadow(container) (YSL_TYPEOF_UNQUAL(container))(c_shadow)((void*)container)

void* (c_slice)(void* container, c_index_t index, c_size_t size);
#define c_slice(container, index, size) (YSL_TYPEOF_UNQUAL(container))(c_slice)((void*)container, index, size)


void* (c_move)(void** from, void** to);
#define c_move(from, to) (YSL_TYPEOF_UNQUAL(container))(c_move)((void**)&from, (void**)&to); M_EXPECT_T_EQUAL(from, to)

void  (c_delete)(void** conatiner);
#define c_delete(conatiner) (c_delete)((void**)&conatiner);

#pragma endregion


#pragma region --- IMPL ---

#ifdef C_TUPLE_H_
#   define __C_GENERIC_USE_TUPLE(impl) tuple_t : impl,
#else
#   define __C_GENERIC_USE_TUPLE(impl)
#endif

#ifdef C_ARRAY_H_
#   define __C_GENERIC_USE_ARRAY(impl) array_t : impl,
#else
#   define __C_GENERIC_USE_ARRAY(impl)
#endif

#ifdef C_VECTOR_H_
#   define __C_GENERIC_USE_VECTOR(impl) vector_t : impl,
#else
#   define __C_GENERIC_USE_VECTOR(impl)
#endif

#ifdef C_LIST_H_
#   define __C_GENERIC_USE_LIST(impl) list_t : impl,
#else
#   define __C_GENERIC_USE_LIST(impl)
#endif

#ifdef C_STRING_H_
#   define __C_GENERIC_USE_STRING(impl) string_t : impl,
#else
#   define __C_GENERIC_USE_STRING(impl)
#endif

#ifdef C_HASHTABLE_H_
#   define __C_GENERIC_USE_HASHTABLE(impl) hashtable_t : impl,
#else
#   define __C_GENERIC_USE_HASHTABLE(impl)
#endif

#ifdef C__H_
#   define __C_GENERIC_USE_(impl) _t : impl,
#else
#   define __C_GENERIC_USE_(impl)
#endif

#pragma endregion

#endif // !C_GENERIC_H_
