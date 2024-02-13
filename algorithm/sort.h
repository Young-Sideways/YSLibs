/*********************************************************************
 * \file   sort.h
 * \brief  sort algorithms
 * 
 * \author Young Sideways
 * \date   February 2024
 *********************************************************************/

#ifndef _SORT_H_
#define _SORT_H_

#pragma once

#include "comparator.h"
#include "swap.h"

/// \brief sort function typedefs
typedef void (sort_t)(void*, size_t, size_t, comp_pt, swap_pt);
typedef sort_t* sort_pt;

sort_t selection_sort;
sort_t insertion_sort;
sort_t quick_sort;

#endif // !_SORT_H_
