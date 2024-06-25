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

#include <stdint.h>
#include <stddef.h>

#include "core.h"

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef rng_t
 *  @brief random number generator
 *  @param[in] min,max - Generated values range
 *  @return range beetwen 0 and UCHAR_MAX
 */
typedef ubyte (*rng_t)();

#pragma endregion

#pragma region --- FUNCTION ---

/// @brief Initializes a RNG generator with current time stamp
void random_init();

/**
 * @brief fill int array with \p generator
 * @param[in,out] block     - Pointer to int array
 * @param[in]     size      - Size of \p block
 * @param[in]     generator - Pointer to RNG generator (can be NULL)
 */
void random_fill(void* block, size_t size, rng_t generator);

#pragma endregion

#endif // !RANDOM_H_
