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

#include "general.h"

#include "core/core.h"
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
typedef struct array_s {} *array_t;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

/**
 * @brief   Array constructor
 * @param[in] size         - Number of elements
 * @param[in] element_size - Size of each element
 */
YSL_EXPORT(array_t) arr_ctor(const c_size_t size, const c_size_t element_size);

/**
 * @brief   Array copy constructor
 * @param[in] array - Array pointer
 */
YSL_EXPORT(array_t) arr_copy(const array_t array);

/**
 * @brief   Array slice constructor
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
#define arr_dtor(array) (arr_dtor)(&array)

#pragma endregion

#pragma region --- ACCESSOR ---

/**
 * @brief Array size
 * @param[in] array - Array pointer
 */
YSL_EXPORT(collection_size_t) arr_size(const array_t array);

/**
 * @brief Array element size
 * @param[in] array - Array pointer
 */
YSL_EXPORT(collection_size_t) arr_element_size(const array_t array);

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
 *  @param[in] array      - Container
 *  @param[in] value      - Pointer to value
 *  @param[in] comparator - Pointer to comparator function
 *  @retval 0 <= index < array size - on success
 *  @retval #COLLECTION_INVALID_INDEX  if no element in array
 */
YSL_EXPORT(collection_index_t) arr_find(const array_t array, const void* value, const comparator_t comparator);

/**
 *  @brief   Checks if \p array has \p value
 *  @param[in] array - Container
 *  @param[in] value - Pointer to value
 *  @retval - true , if array has value
 *  @retval - false, if no value in array
 */
YSL_EXPORT(bool) arr_contains(const array_t array, const void* value, const comparator_t comparator);

/**
 *  @brief   Sorts elements in \p array with given \p comparator
 *  @param[in,out] array  - Container
 *  @param[in] comparator - Given comparator 
 */
YSL_EXPORT(void) arr_sort(array_t array, const comparator_t comparator);

#pragma endregion

YSL_END_DECLS

#endif // !ARRAY_H_
