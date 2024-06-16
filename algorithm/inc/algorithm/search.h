/*******************************************************************************
 *  @file      search.h
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef SEARCH_H_
#define SEARCH_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core.h"
#include "comparator.h"

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef search_t
 *  @brief   defines type of search function
 *  @param[in,out] array        - Pointer to memory block
 *  @param[in]     count        - Number of elements
 *  @param[in]     element_size - Size of each element
 *  @param[in]     value        - Pointer to reference value
 *  @param[in]     comparator   - Pointer to comparator function
 */
typedef void* (search_t)(const void* array, const size_t count, const size_t element_size, const void* value, comparator_pt comparator);
/**
 *  @typedef search_pt
 *  @brief   pointer type to \ref search_t function
 */
typedef search_t* search_pt;

#pragma endregion

#pragma region --- FUNCTION ---

search_t linear_search;
search_t binary_search;

#pragma endregion

#endif // !SEARCH_H_
