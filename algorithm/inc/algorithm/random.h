/*******************************************************************************
 *  @file      random.h
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef RANDOM_H_
#define RANDOM_H_


#include <stddef.h>

#include <core/core.h>


#pragma region --- TYPEDEF ---

/**
 *  @typedef rng_t
 *  @brief   random number generator function pointer
 *  @note    compatible with 
 */
typedef int (*rng_t)(void);

#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- FUNCTION ---

/**
 * @brief fill array with \p generator
 * @param[in,out] ptr       - pointer memory block
 * @param[in]     size      - size in bytes of \p ptr
 * @param[in]     generator - pointer to RNG generator (can be NULL)
 */
YSL_API void rng_fill(void* ptr, const size_t size, rng_t generator);

#pragma endregion

YSL_END_DECLS

#endif // !RANDOM_H_
