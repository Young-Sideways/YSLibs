/*******************************************************************************
 *  @file      collections.h
 *  @brief     General collections header to include all collections
 *  @author    Young Sideways
 *  @date      16.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

#pragma once

#pragma region --- INCLUDE ---

#include "algorithm/comparator.h"
#include "algorithm/swap.h"
#include "algorithm/search.h"
#include "algorithm/sort.h"

#include "tuple.h"
#include "pair.h"
#include "variant.h"
#include "array.h"
#include "vector.h"
#include "string.h"
#include "list.h"
#include "matrix.h"
#include "deque.h"
#include "queue.h"
#include "stack.h"
#include "set.h"
#include "map.h"
#include "multiset.h"
#include "multimap.h"

#include "iterator.h"

#include "macro/arg.h"

#pragma endregion

#pragma region --- GENERICS ---

#define copy(type, src) \
_Generic( ((type)0), \
    array_t     : _Generic( ((typeof(src))0),                \
                      array_t : arr_from_arr( (array_t)src), \
                      vector_t: arr_from_vec((vector_t)src), \
                      list_t  : arr_from_lst(  (list_t)src), \
                      default : static_assert(0, "collection: array can only be copied from: [ array_t, vector_t, list_t ]") \
                  ), \
    vector_t    : _Generic( ((typeof(src))0),                \
                      array_t : vec_from_arr( (array_t)src), \
                      vector_t: vec_from_vec((vector_t)src), \
                      list_t  : vec_from_lst(  (list_t)src), \
                      default : static_assert(0, "collection: vector can only be copied from: [ array_t, vector_t, list_t ]") \
                  ), \
    list_t      : _Generic( ((typeof(src))0),                \
                      array_t : lst_from_arr( (array_t)src), \
                      vector_t: lst_from_vec((vector_t)src), \
                      list_t  : lst_from_lst(  (list_t)src), \
                      default : static_assert(0, "collection: list can only be copied from: [ array_t, vector_t, list_t ]") \
                  ), \
    default     : ((void)0) \
)

#define at(collection, ...) \
_Generic( ((typeof(collection))0) , \
    tuple_t   : tpl_at()
    pair_t    :
    array_t   :
    vector_t  :
    string_t  :
    list_t    :
    matrix_t  :
    set_t     :
    map_t     :
    multiset_t:
    multimap_t:
    avltree_t :
    rbtree_t  :
    btree_t   :
    )
#define find(collection, key)
#define sort(collection)

#define delete(container) _Generic( ((typeof(container))0), \
    tuple_t     : tpl_dtor((tuple_t   )container), \
    pair_t      : par_dtor((pair_t    )container), \
    variant_t   : var_dtor((variant_t )container), \
    array_t     : arr_dtor((array_t   )container), \
    vector_t    : vec_dtor((vector_t  )container), \
    string_t    : str_dtor((string_t  )container), \
    list_t      : lst_dtor((list_t    )container), \
    matrix_t    : mtx_dtor((matrix_t  )container), \
    deque_t     : deq_dtor((deuque_t  )container), \
    queue_t     : que_dtor((queue_t   )container), \
    stack_t     : stk_dtor((stack_t   )container), \
    set_t       : set_dtor((set_t     )container), \
    map_t       : map_dtor((map_t     )container), \
    multiset_t  : mst_dtor((multiset_t)container), \
    multimap_t  : mmp_dtor((multimap_t)container), \
    avltree_t   : avl_dtor((avltree_t )container), \
    rbtree_t    : rbt_dtor((rbtree_t  )container), \
    btree_t     : btr_dtor((btree_t   )container), \
    default     : ((void)0)                        \
)

#pragma endregion

#endif // !COLLECTIONS_H_
