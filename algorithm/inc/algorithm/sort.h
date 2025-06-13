/*******************************************************************************
 *  @file      sort.h
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef SORT_H_
#define SORT_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core/core.h"

#include "comparator.h"

#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- TYPEDEF ---

/**
 *  @typedef sort_t
 *  @brief   defines type of sort function
 *  @param[in,out] array        - Pointer to memory block
 *  @param[in]     count        - Element count
 *  @param[in]     element_size - Size of each element
 *  @param[in]     comparator   - Pointer to comparator function
 */
YSL_API typedef void (*sort_t)(void* array, size_t count, size_t element_size, comparator_t comparator);

#pragma endregion

#pragma region --- FUNCTION ---

YSL_API void selection_sort(void* array, size_t count, size_t element_size, comparator_t comparator);
YSL_API void insertion_sort(void* array, size_t count, size_t element_size, comparator_t comparator);
YSL_API void quick_sort(void* array, size_t count, size_t element_size, comparator_t comparator);

#pragma endregion

YSL_END_DECLS

#endif // !SORT_H_
