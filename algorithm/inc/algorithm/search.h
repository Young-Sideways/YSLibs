/*******************************************************************************
 *  @file      search.h
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      17.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef SEARCH_H_
#define SEARCH_H_


#include "comparator.h"

#include <core/core.h>


#pragma region --- TYPEDEF ---

/**
 *  @typedef search_t
 *  @brief   defines pointer type of search function
 *  @param[in,out] array        - Pointer to memory block
 *  @param[in]     count        - Number of elements
 *  @param[in]     element_size - Size of each element
 *  @param[in]     value        - Pointer to reference value
 *  @param[in]     comparator   - Pointer to comparator function
 */
typedef void* (*search_t)(const void* array, const size_t count, const size_t element_size, const void* value, comparator_s_t comparator);

#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- FUNCTION ---

YSL_API void* linear_search(const void* array, const size_t count, const size_t element_size, const void* value, comparator_s_t comparator);
YSL_API void* binary_search(const void* array, const size_t count, const size_t element_size, const void* value, comparator_s_t comparator);

#pragma endregion

YSL_END_DECLS

#endif // !SEARCH_H_
