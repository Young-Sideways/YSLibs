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

typedef struct {
    struct collection_header;
    byte* data;
} array_t;

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(size_t size, size_t element_size);

array_t arr_copy(const array_t* array);
array_t arr_move(const array_t* array);
array_t arr_shadow(const array_t* array);

void arr_delete(array_t* array);

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(array_t array, int position);

#pragma endregion

#pragma region --- INFORMATION ---

int arr_capacity(array_t array);
int arr_element_size(array_t array);

#pragma endregion



#ifdef _ITERATOR_H_ // Adaptor for iterators

#include "iterator.h"

iterator_t arr_first(array_t array);
iterator_t arr_last(array_t array);
iterator_t arr_end(array_t array);

#endif // !_ITERATOR_H_

#ifdef _SEARCH_H_

#include "../algorithm/search.h"

iterator_t arr_find(void* container, const void* value);
iterator_t arr_last(void* container, const void* value);

#endif // !_SEARCH_H_

#endif // !_ARRAY_H_