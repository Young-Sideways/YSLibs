/*********************************************************************
 * \file   comparator.h
 * \brief  comparator algorithms
 *
 * \author Young Sideways
 * \date   February 2024
 *********************************************************************/

#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#pragma once

#include <stdint.h>

/// \brief comparator function typedefs
typedef int (comp_t)(const void* lhs, const void* rhs);
typedef comp_t* comp_pt;

#define DECLARE_FORWARD_COMPARATOR(type) \
	comp_t type##_fcomp;
#define DECLARE_REVERSE_COMPARATOR(type) \
	comp_t type##_rcomp;

DECLARE_FORWARD_COMPARATOR(i8)
DECLARE_FORWARD_COMPARATOR(i16)
DECLARE_FORWARD_COMPARATOR(i32)
DECLARE_FORWARD_COMPARATOR(i64)
DECLARE_FORWARD_COMPARATOR(u8)
DECLARE_FORWARD_COMPARATOR(u16)
DECLARE_FORWARD_COMPARATOR(u32)
DECLARE_FORWARD_COMPARATOR(u64)
DECLARE_FORWARD_COMPARATOR(flt)
DECLARE_FORWARD_COMPARATOR(dbl)
DECLARE_FORWARD_COMPARATOR(ldbl)

DECLARE_REVERSE_COMPARATOR(i8)
DECLARE_REVERSE_COMPARATOR(i16)
DECLARE_REVERSE_COMPARATOR(i32)
DECLARE_REVERSE_COMPARATOR(i64)
DECLARE_REVERSE_COMPARATOR(u8)
DECLARE_REVERSE_COMPARATOR(u16)
DECLARE_REVERSE_COMPARATOR(u32)
DECLARE_REVERSE_COMPARATOR(u64)
DECLARE_REVERSE_COMPARATOR(flt)
DECLARE_REVERSE_COMPARATOR(dbl)
DECLARE_REVERSE_COMPARATOR(ldbl)

#undef DECLARE_FORWARD_COMPARATOR
#undef DECLARE_REVERSE_COMPARATOR

#endif // !_COMPARATOR_H_
