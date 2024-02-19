/*******************************************************************************
 *  @file      comparator.h
 *  @brief     comparator algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#pragma once

#include <stdint.h>


typedef int (comparator_t)(const void* lhs, const void* rhs, size_t size);
typedef comparator_t* comparator_pt;

#define FORWARD_COMPARATOR(prefix, type)							    \
	int prefix##_fcomp(const type* lhs, const type* rhs, size_t size) { \
		UNUSED(size);												    \
		assert(lhs);												    \
		assert(rhs);												    \
		return (int)(*lhs - *rhs);									    \
	}
#define REVERSE_COMPARATOR(prefix, type)							    \
	int prefix##_rcomp(const type* lhs, const type* rhs, size_t size) { \
		UNUSED(size);												    \
		assert(lhs);												    \
		assert(rhs);												    \
		return (int)(*rhs - *lhs);										\
	}

#endif // !_COMPARATOR_H_
