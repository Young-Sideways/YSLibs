/*******************************************************************************
 *  @file      sort.h
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _SORT_H_
#define _SORT_H_

#pragma once

#pragma region --- INCLUDE ---

#include "swap.h"
#include "comparator.h"

#pragma endregion

#pragma region --- TYPEDEF ---

typedef void (sort_t)(_INOUT void*, _IN size_t, _IN size_t, _IN _NULLABLE comparator_pt, _IN _NULLABLE swap_pt);
typedef sort_t* sort_pt;

#pragma endregion

#pragma region --- FUNCTION ---

/**
 *  @brief Implementation of selection sort
 *  @param array        - pointer to array
 *  @param count        - number of elements
 *  @param element_size - size of each element
 *  @param comparator   - pointer to compare function
 *  @param swap         - pointer to swap funtion
 */
sort_t selection_sort;

/**
 *  @brief Implementation of insertion sort
 *  @param array        - pointer to array
 *  @param count        - number of elements
 *  @param element_size - size of each element
 *  @param comparator   - pointer to compare function
 *  @param swap         - pointer to swap funtion
 */
sort_t insertion_sort;

/**
 *  @brief Implementation of quick sort
 *  @param array        - pointer to array
 *  @param count        - number of elements
 *  @param element_size - size of each element
 *  @param comparator   - pointer to compare function
 *  @param swap         - pointer to swap funtion
 */
sort_t quick_sort;

#pragma endregion

#endif // !_SORT_H_
