/*******************************************************************************
 *  @file      sort.h
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
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
 *  @param[in]     _comparator  - Pointer to comparator function
 *  @param[in]     _swap        - Pointer to swap function
 */
typedef void (sort_t)(void* array, const size_t count, const size_t element_size, comparator_pt _comparator, swap_pt _swap);

/**
 *  @typedef sort_pt
 *  @brief   pointer type to \ref sort_t function
 */
typedef sort_t* sort_pt;

#pragma endregion

#pragma region --- FUNCTION ---

sort_t selection_sort;

sort_t insertion_sort;

sort_t quick_sort;

#pragma endregion

#endif // !SORT_H_
