/*******************************************************************************
 *  @file      algorithm.h
 *  @brief     universal algorithm lib
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#pragma once

#include "comparator.h"
#include "swap.h"
#include "search.h"
#include "sort.h"
#include "random.h"

/**
 *  @brief 
 *  @param[in,out] block        - Pointer to memory block
 *  @param[in]     capacity     - Number of elements
 *  @param[in]     element_size - Size of each element
 */
static void reverse(void* block, const size_t capacity, const size_t element_size) {
    for (byte* first = block, *last = (byte*)block + (capacity - 1) * element_size; first < last; first += element_size, last -= element_size)
        swap(first, last, element_size);
}

#endif // !ALGORITHM_H_
