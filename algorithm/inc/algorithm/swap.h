/*******************************************************************************
 *  @file      swap.h
 *  @brief     swap algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef SWAP_H_
#define SWAP_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core/core.h"

#include <stddef.h>

#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- TYPEDEF ---

/**
 *  @typedef swap_t
 *  @brief   defines type of swap function
 *  @param[in,out] lhs,rhs - Pointers to values
 */
YSL_API typedef void (*swap_t)(void* lhs, void* rhs);

/**
 *  @typedef swap_s_t
 *  @brief   defines type of swap function with size
 *  @param[in,out] lhs,rhs - Pointers to values
 *  @param[in]     size    - Memory size to swap
 */
YSL_API typedef void (*swap_s_t)(void* lhs, void* rhs, size_t size);

#pragma endregion

#pragma region --- FUNCTION ---

/**
 * @brief Swaps memory between \p lhs and \p rhs pointers with size \p size
 * @param[in,out] lhs,rhs  - Pointers to values
 * @param[in]     size     - Memory size to swap
 */
YSL_API void swap_s(void* lhs, void* rhs, size_t size);

#pragma endregion

YSL_END_DECLS

#endif // !SWAP_H_
