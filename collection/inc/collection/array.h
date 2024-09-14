/*******************************************************************************
 *  @file      array.h
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef ARRAY_H_
#define ARRAY_H_

#pragma once

#pragma region --- INCLUDE ---

#include "collection/general.h"
#include "algorithm/comparator.h"

#pragma endregion

#pragma region --- MACRO ---

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef array_t
 *  @brief   static array
 */
typedef const struct array_t {
    size_t size;
    size_t element_size;
    void* data;
} *array_t;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

/**
 *  @brief   Array construct
 *  @param[in] size         - Number of elements
 *  @param[in] element_size - Size of each element
 */
array_t array_ctor(size_t size, size_t element_size);
void array_dtor(array_t array);

#pragma endregion

#pragma region --- ACCESSOR ---

/**
 *  @brief   Array element accessor
 *  @param[in] array - Container
 *  @param[in] index - Index of element
 */
void* array_at(array_t array, int index);

/**
 *  @brief   Find index of element
 *  @param[in] array - Container
 *  @param[in] value - Pointer to value
 *  @returns index of element
 *  @returns -1 if no element in array
 */
int array_find(array_t array, const void* value);

/**
 *  @brief   Checks if \p array has \p value
 *  @param[in] array - Container
 *  @param[in] value - Pointer to value
 *  @returns true, if array has value
 *  @returns false, if no value in array
 */
bool array_contains(array_t array, const void* value);

/**
 *  @brief   Sorts elements in \p array with given \p comparator
 *  @param[in,out] array  - Container
 *  @param[in] comparator - Given comparator 
 */
void array_sort(array_t array, comparator_t comparator);

#pragma endregion

#endif // !ARRAY_H_
