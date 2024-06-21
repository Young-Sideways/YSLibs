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

#include "macro/arg.h"

#include "iterator.h"
#include "macro/foreach.h"

#include "array.h"
#include "hashtable.h"
#include "tree.h"

#pragma endregion


#pragma region --- GENERICS ---

#if (0)
#define ARGS_SEQ_0
#define ARGS_SEQ_1 char
#define ARGS_SEQ_2 char, ARGS_SEQ_1
#define ARGS_SEQ_3 char, ARGS_SEQ_2
#define ARGS_SEQ_4 char, ARGS_SEQ_3

//#define ARGS_SEQ_UNFOLD
#define ARGS_SEQ_UNFOLD(...) __VA_ARGS__

#define __ELEMENT_TYPE_ARRAY(_1, ...) sizeof(_1)
#define _ELEMENT_TYPE_ARRAY(...) __ELEMENT_TYPE_ARRAY(__VA_ARGS__)
#define ELEMENT_TYPE_ARRAY(arg) _ELEMENT_TYPE_ARRAY(ARGS_SEQ_UNFOLD arg, ARGS_SEQ_1)

#define __ELEMENT_TYPE_HASHTABLE(_1, _2, ...) sizeof(_1), sizeof(_2)
#define _ELEMENT_TYPE_HASHTABLE(...) __ELEMENT_TYPE_HASHTABLE(__VA_ARGS__)
#define ELEMENT_TYPE_HASHTABLE(arg) _ELEMENT_TYPE_HASHTABLE(ARGS_SEQ_UNFOLD arg, ARGS_SEQ_2)

#define HASHTABLE_REQ_SEQ 0, NULL
#define ARG_LIST_UNROLL(arg_list, req_arg_list) ARGS_SEQ_UNFOLD arg_list, req_arg_list
// ELEMENT_TYPE_ARRAY()                 -> standart type
// ELEMENT_TYPE_ARRAY(())               -> standart type
// ELEMENT_TYPE_ARRAY((type))           -> type
// ELEMENT_TYPE_ARRAY((type1, type2))   -> type1



#define new(container_type, element_type, ...) _Generic( ((container_type)0),                                         \
    array_t     : arr_init(VA_ARG_FIRST(ARG_LIST_UNROLL((__VA_ARGS__), 0)), ELEMENT_TYPE_ARRAY(element_type)),                              \
    hashtable_t : ht_init(VA_ARG_FIRST(ARG_LIST_UNROLL((__VA_ARGS__), 0)), ELEMENT_TYPE_HASHTABLE(element_type), ARG_LIST_UNROLL((VA_ARG_TAIL(__VA_ARGS__)), NULL)), \
    default     : ((void*)0)                                                                                          \
)

#endif

#pragma endregion

#endif // !COLLECTIONS_H_
