/*******************************************************************************
 * @file      memory.h
 * @author    Young Sideways
 * @brief     tools, that controls memory
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef MEMORY_H_
#define MEMORY_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core/core.h"

#include <stddef.h>

#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- FUNCTION ---

/**
 *  @brief  reverses blocks of size \p element_size in memory \p src size \p capacity 
 *  @param[in,out] src          - Pointer to memory block
 *  @param[in]     count        - Number of elements
 *  @param[in]     element_size - Size in bytes of each element
 */
YSL_API void* reverse(void* src, const size_t count, const size_t element_size);

/**
 * @brief duplicates memory from \p src
 * @param[in] src  - Pointer to memory block
 * @param[in] size - Number of bytes
 * @return allocated memory of \p size bytes
 */
YSL_API void* memdup(const void* src, const size_t size);

#pragma endregion

YSL_END_DECLS

#endif // !MEMORY_H_
