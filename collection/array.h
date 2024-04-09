/*******************************************************************************
 *  @file      array.h
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _ARRAY_H_
#define _ARRAY_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef struct array array_t;

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(_IN const size_t size, _IN const size_t element_size);

array_t arr_copy(_IN const array_t* array);
array_t arr_move(_IN array_t* array);
array_t arr_shadow(_IN const array_t* array);

void arr_delete(_IN array_t* array);

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(array_t array, int position);

#pragma endregion

#pragma region --- INFORMATION ---

int arr_size(array_t array);
int arr_element_size(array_t array);

#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

#ifdef _SEARCH_H_

iterator_t arr_find(void* container, const void* value);
iterator_t arr_last(void* container, const void* value);

#endif // !_SEARCH_H_

#ifdef _SORT_H_

void arr_sort(_IN array_t* array, _IN _NULLABLE comparator_pt comparator);

#endif // !_SORT_H_

#pragma endregion

#endif // !_ARRAY_H_
