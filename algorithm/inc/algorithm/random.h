/*******************************************************************************
 *  @file      random.h
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef RANDOM_H_
#define RANDOM_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core/core.h"

#include <stddef.h>

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef rng_t
 *  @brief   random number generator function pointer
 *  @param[in,out] dst  - Pointer to destination memory
 *  @param[in]     size - Size in bytes of \p dst
 */
YSL_API typedef void (*rng_t)(void* dst, const size_t size);

#pragma endregion

#pragma region --- FUNCTION ---

/**
 * @brief fill array with \p generator
 * @param[in,out] ptr          - Pointer memory block
 * @param[in]     capacity     - Size in bytes of \p ptr
 * @param[in]     element_size - Size in bytes of each element
 * @param[in]     generator    - Pointer to RNG generator (can be NULL)
 */
YSL_API void rng_fill(void* ptr, const size_t capacity, const size_t element_size, rng_t generator);

#pragma endregion

#endif // !RANDOM_H_
