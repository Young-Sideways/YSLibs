/*******************************************************************************
 *  @file      generic.h
 *  @brief     General collections macro header to include all collections
 *  @author    Young Sideways
 *  @date      03.09.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef GENERIC_H_
#define GENERIC_H_

#pragma once

#pragma region --- INCLUDE ---



#pragma endregion

#pragma region --- GENERICS ---

/**
 * @def new
 * @brief Creates new container with given settings
 * @param type - type of container
 * @param ...  - constructor specific initiators
 * @code
 * tuple_t    : new(tuple_t, ...)                      -> tuple_ctor(size_t* sizes, void* values)
 * pair_t     : new(pair_t, key, value)                -> tuple_ctor((size_t*){ sizeof(key), sizeof(value), 0U }, (void*){ key, value })
 * variant_t  : new(variant_t, value)                  -> tuple_ctor((size_t*){ sizeof(value), 0U }, (void*){ value })
 * array_t    : new(array_t, type, size)               -> array_ctor(sizeof(type), size)
 * vector_t   : new(vector_t, type, size)              -> vector_ctor(sizeof(type), size)
 * list_t     : new(list_t, type, size)                -> list_ctor(sizeof(type), size)
 * matrix_t   : new(matrix_t, type, rows, cols)        -> matrix_ctor( sizeof(type), rows, cols)
 * deque_t    : new(deque_t, type)                     -> deque_ctor(sizeof(type))
 * queue_t    : new(queue_t, type)                     -> queue_ctor(sizeof(type))
 * stack_t    : new(stack_t, type)                     -> stack_ctor(sizeof(type))
 * set_t      : new(set_t, type, size)                 -> set_ctor(sizeof(type), size)
 * map_t      : new(map_t, key_type, value_type, size) -> map_ctor(sizeof(key_type), sizeof(value_type), size)
 * multiset_t : new(multiset_t, type, size)            -> multiset_ctor(sizeof(type), size)
 * multimap_t : new(multimap_t, type, size)            -> multimap_ctor(sizeof(key_type), sizeof(value_type), size)
 * avltree_t  : new(avltree_t, type)                   -> avltree_ctor(sizeof(type))
 * rbtree_t   : new(rbtree_t, type)                    -> rbtree_ctor(sizeof(type)) 
 * btree_t    : new(btree_t, type)                     -> btree_ctor(sizeof(type))  
 * @endcode
 */
#define new(type, ...)

/**
 * @def delete
 * @brief Destroys container from memory
 * @param container - container reference
 * @code
 * tuple_t    : delete(tuple_t)    -> tuple_dtor(container)
 * pair_t     : delete(pair_t)     -> tuple_dtor(container)
 * variant_t  : delete(variant_t)  -> tuple_dtor(container)
 * array_t    : delete(array_t)    -> array_dtor(container)
 * vector_t   : delete(vector_t)   -> vector_dtor(container)
 * list_t     : delete(list_t)     -> list_dtor(container)
 * matrix_t   : delete(matrix_t)   -> matrix_dtor(container)
 * deque_t    : delete(deque_t)    -> deque_dtor(container)
 * queue_t    : delete(queue_t)    -> queue_dtor(container)
 * stack_t    : delete(stack_t)    -> stack_dtor(container)
 * set_t      : delete(set_t)      -> set_dtor(container)
 * map_t      : delete(map_t)      -> map_dtor(container)
 * multiset_t : delete(multiset_t) -> multiset_dtor(container)
 * multimap_t : delete(multimap_t) -> multimap_dtor(container)
 * avltree_t  : delete(avltree_t)  -> avltree_dtor(container)
 * rbtree_t   : delete(rbtree_t)   -> rbtree_dtor(container) 
 * btree_t    : delete(btree_t)    -> btree_dtor(container)  
 * @endcode
 */
#define delete(container)

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

#endif // !GENERIC_H_
