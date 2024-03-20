/*******************************************************************************
 *  @file      random.h
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _RANDOM_H_
#define _RANDOM_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef (random_t)(_IN int, _IN int);
typedef random_t* random_pt;

#pragma endregion

#pragma region --- FUNCTIONS ---

/// @brief Initilizes a PRNG with current time stamp
void random_init();

/**
 * @brief default random function
 * @param min - minimum value of generated range
 * @param max - maximum value of generated range
 * @return generated value via [min; max]
 */
random_t random;

/**
 * @brief fills int array with predicated PRNG
 * @param array - pointer to int array
 * @param size - size of input array
 * @param generator - pointer to PRNG (can be NULL)
 * @param min - minimum value of generated range
 * @param max - maximum value of generated range
 */
void random_fill(int*, size_t, random_pt, int, int);

#pragma endregion

#endif // !_RANDOM_H_
