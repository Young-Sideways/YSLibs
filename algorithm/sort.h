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

#include "comparator.h"
#include "swap.h"


typedef void (sort_t)(void*, size_t, size_t, comparator_pt, swap_pt);
typedef sort_t* sort_pt;

/**
 *  @brief Implementation of selection sort
 *  @param array        - pointer to array
 *  @param count        - number of elements
 *  @param element_size - size of each element
 *  @param _comparator  - pointer to compare function
 *  @param _swap        - pointer to swap funtion
 */
sort_t selection_sort;

/**
 *  @brief Implementation of insertion sort
 *  @param array        - pointer to array
 *  @param count        - number of elements
 *  @param element_size - size of each element
 *  @param _comparator  - pointer to compare function
 *  @param _swap        - pointer to swap funtion
 */
sort_t insertion_sort;

/**
 *  @brief Implementation of quick sort
 *  @param array        - pointer to array
 *  @param count        - number of elements
 *  @param element_size - size of each element
 *  @param _comparator  - pointer to compare function
 *  @param _swap        - pointer to swap funtion
 */
sort_t quick_sort;

#endif // !_SORT_H_
