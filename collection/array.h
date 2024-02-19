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

#include "general.h"
#include "../core/types.h"

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX

typedef struct array array_t;

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(const size_t size, const size_t element_size);

array_t arr_copy(_IN const array_t* array);
array_t arr_move(_IN const array_t* array);
array_t arr_shadow(_IN const array_t* array);

void arr_delete(_INOUT array_t* array);

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(array_t array, int position);

#pragma endregion

#pragma region --- INFORMATION ---

int arr_size(array_t array);
int arr_element_size(array_t array);

#pragma endregion

#ifdef _SEARCH_H_

#include "../algorithm/search.h"

iterator_t arr_find(void* container, const void* value);
iterator_t arr_last(void* container, const void* value);

#endif // !_SEARCH_H_

#endif // !_ARRAY_H_