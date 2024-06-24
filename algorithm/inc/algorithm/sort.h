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

#include "swap.h"
#include "comparator.h"

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef sort_t
 *  @brief   defines type of sort function
 *  @param[in,out] array        - Pointer to memory block
 *  @param[in]     count        - Element count
 *  @param[in]     element_size - Size of each element
 *  @param[in]     comparator_  - Pointer to comparator function
 *  @param[in]     swap_        - Pointer to swap function
 */
typedef void (*sort_t)(void* array, size_t count, size_t element_size, comparator_t comparator_, swap_t swap_);

#pragma endregion

#pragma region --- FUNCTION ---

void selection_sort(void* array, size_t count, size_t element_size, comparator_t comparator_, swap_t swap_);
void insertion_sort(void* array, size_t count, size_t element_size, comparator_t comparator_, swap_t swap_);
void quick_sort(void* array, size_t count, size_t element_size, comparator_t comparator_, swap_t swap_);

#pragma endregion

#endif // !SORT_H_
