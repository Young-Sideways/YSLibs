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

#include "core.h"
#include "collection/general.h"
#include "algorithm/comparator.h"

#pragma endregion

#pragma region --- MACRO ---

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- TYPEDEF ---

/**
 *  @typedef array_t
 *  @brief   static array
 */
typedef const struct array_t {
    size_t size;
    size_t element_size;
    void*    data;
} *array_t;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

/**
 * @brief   Array constructor
 * @param[in] size         - Number of elements
 * @param[in] element_size - Size of each element
 */
YSL_EXPORT(array_t) arr_ctor(const size_t size, const size_t element_size);

/**
 * @brief   Array copy constructor
 * @param[in] array - Array pointer
 */
YSL_EXPORT(array_t) arr_copy(const array_t array);

/**
 * @brief   Array copy constructor
 * @param[in] array - Array pointer
 * @param[in] from  - index of first element in slice [0;size)
 * @param[in] count - number of elements in slice (-size;size]
 * @details if count set as negative value - array slice are reversed
 */
YSL_EXPORT(array_t) arr_slice(const array_t array, const int from, const int count);

/**
 * @brief Array destructor
 * @param[in] array - Pointer to array pointer
 */
YSL_EXPORT(void) arr_dtor(array_t* array);

#pragma endregion

#pragma region --- ACCESSOR ---

/**
 * @brief Array size
 * @param[in] array - Array pointer
 */
YSL_EXPORT(size_t) arr_size(const array_t array);

/**
 * @brief Array element size
 * @param[in] array - Array pointer
 */
YSL_EXPORT(size_t) arr_element_size(const array_t array);

/**
 * @brief Array data
 * @param[in] array - Array pointer
 * @returns pointer to memory contains data
 */
YSL_EXPORT(void*) arr_data(array_t array);

/**
 *  @brief   Array element accessor
 *  @param[in] array - Container
 *  @param[in] index - Index of element
 */
YSL_EXPORT(void*) arr_at(array_t array, int index);

/**
 *  @brief   Find index of element
 *  @param[in] array - Container
 *  @param[in] value - Pointer to value
 *  @returns index of element
 *  @returns -1 if no element in array
 */
YSL_EXPORT(int) arr_find(array_t array, const void* value);

/**
 *  @brief   Checks if \p array has \p value
 *  @param[in] array - Container
 *  @param[in] value - Pointer to value
 *  @returns true, if array has value
 *  @returns false, if no value in array
 */
YSL_EXPORT(bool) arr_contains(array_t array, const void* value);

/**
 *  @brief   Sorts elements in \p array with given \p comparator
 *  @param[in,out] array  - Container
 *  @param[in] comparator - Given comparator 
 */
YSL_EXPORT(void) arr_sort(array_t array, comparator_t comparator);

#pragma endregion

YSL_END_DECLS

#endif // !ARRAY_H_
