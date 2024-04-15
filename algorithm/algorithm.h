/*******************************************************************************
 *  @file      algorithm.h
 *  @brief     universal algorithm lib
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#pragma once

#include "comparator.h"
#include "swap.h"
#include "search.h"
#include "sort.h"
#include "random.h"

void reverse(void* block, size_t capacity, size_t element_size) {
    for (byte* first = block, *last = (byte*)block + (capacity - 1) * element_size; first < last; first += element_size, last -= element_size)
        swap(first, last, element_size);
}

#endif // !_ALGORITHM_H_
