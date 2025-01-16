/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef COLLECTION_GENERAL_H_
#define COLLECTION_GENERAL_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stddef.h>
#include <stdint.h>

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( 'new size' = 2 * 'old size' )
 *  @param n - current size
 */
#define GROWTH_FACTOR(n) (n ? (n << 1) : 1u)

/**
*  @def   COLLECTION_SIZE_MIN
*  @brief Minimum size for all containers
*/
#define COLLECTION_SIZE_MIN (0x0u)

/**
*  @def   COLLECTION_SIZE_MAX
*  @brief Maximum size for all containers
*/
#define COLLECTION_SIZE_MAX ((uint32_t)INT32_MAX)

/**
*  @def   COLLECTION_INVALID_INDEX
*  @brief Value of invalid index for all containers
*/
#define COLLECTION_INVALID_INDEX (INT32_MIN)

#pragma endregion

#endif // !COLLECTION_GENERAL_H_
