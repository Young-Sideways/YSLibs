/*******************************************************************************
 *  @file      comparator.h
 *  @brief     comparator algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef COMPARATOR_H_
#define COMPARATOR_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stddef.h>

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef comparator_t
 *  @brief   defines function pointer type, that's compares memory between \p lhs and \p rhs with size \p size
 *  @param[in,out] lhs,rhs  - Value pointers
 *  @param[in]     size     - Size of memory block
 */
typedef int (*comparator_t)(const void* lhs, const void* rhs, size_t size);

#pragma endregion

#endif // !COMPARATOR_H_
