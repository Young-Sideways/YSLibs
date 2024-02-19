/*******************************************************************************
 *  @file      search.h
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/


#ifndef _SEARCH_H_
#define _SEARCH_H_

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "comparator.h"


typedef void* (search_t)(void*, size_t, size_t, void*, comparator_pt);
typedef search_t* search_pt;

search_t linear_search;
search_t binary_search;

#ifdef _ITERATOR_H_

#include "../collection/iterator.h"

iterator_t find(const void* container,const void* value);
bool contains(const void* container, const void* value);

#endif

#endif // !_SEARCH_H_