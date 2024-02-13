/*********************************************************************
 * \file   search.h
 * \brief  search algorithms
 *
 * \author Young Sideways
 * \date   February 2024
 *********************************************************************/

#ifndef _SEARCH_H_
#define _SEARCH_H_

#pragma once

#include <stdint.h>
#include "comparator.h"

/// \brief search function typedefs
typedef void* (search_t)(void*, size_t, size_t, void*, comp_pt);
typedef search_t* search_pt;

search_t linear_search;
search_t binary_search;

#endif // !_SEARCH_H_