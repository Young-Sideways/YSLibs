/*******************************************************************************
 *  @file      swap.h
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#ifndef _SWAP_H_
#define _SWAP_H_

#pragma once

#include <stdint.h>


typedef void (swap_t)(void*, void*, size_t);
typedef swap_t* swap_pt;

/**
 * @brief swaps values between lhs and rhs pointers with size
 * @param lhs  - left-hand side value pointer
 * @param rhs  - right-hand side value pointer
 * @param size - swapable area size
 */
swap_t swap;


#define DECLARE_SWAP(type) \
	swap_t type##_swap;

DECLARE_SWAP(i8)
DECLARE_SWAP(i16)
DECLARE_SWAP(i32)
DECLARE_SWAP(i64)
DECLARE_SWAP(u8)
DECLARE_SWAP(u16)
DECLARE_SWAP(u32)
DECLARE_SWAP(u64)
DECLARE_SWAP(flt)
DECLARE_SWAP(dbl)
DECLARE_SWAP(ldbl)

#undef DECLARE_SWAP

#endif // !_SWAP_H_
