/*******************************************************************************
 * @file      reverse.h
 * @author    Young Sideways
 * @brief     tools, that reverse memory order bytes
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef REVERSE_H_
#define REVERSE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stddef.h>

#pragma endregion

#pragma region --- FUNCTION ---

/**
 *  @brief
 *  @param[in,out] block        - Pointer to memory block
 *  @param[in]     capacity     - Number of elements
 *  @param[in]     element_size - Size of each element
 */
void reverse(void* block, size_t capacity, size_t element_size);

#pragma endregion

#endif // !REVERSE_H_
