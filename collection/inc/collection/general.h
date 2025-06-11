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

#include "macro/expect.h"

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   COLLECTION_PREFIX
 *  @brief defines default prefix
 *  @param name - name of statement
 */
#ifndef COLLECTION_PREFIX
    #define COLLECTION_PREFIX(name) c_##name
#endif

/**
*  @typedef collection_size_t
*  @brief   collection size type 
*/
typedef uint32_t c_size_t;
/**
*  @typedef collection_size_t
*  @brief   collection size type 
*/
typedef int32_t c_index_t;

static_assert(sizeof(c_size_t) == sizeof(c_index_t), "Collection error: basic 'index' and 'size' types has unequal sizes");

/**
*  @def   COLLECTION_SIZE_MIN
*  @brief Default minimum size for all containers
*/
#define COLLECTION_SIZE_MIN (collection_size_t)(0u)

/**
*  @def   COLLECTION_SIZE_MAX
*  @brief Default maximum size for all containers
*/
#define COLLECTION_SIZE_MAX (collection_size_t)(INT32_MAX)

/**
*  @def   COLLECTION_INVALID_INDEX
*  @brief Value of invalid index for all containers
*/
#define COLLECTION_INVALID_INDEX (INT32_MIN)

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( 'new size' = 2 * 'old size' )
 *  @param n - current size
 */
#ifndef COLLECTION_GROWTH_FACTOR
    #define COLLECTION_GROWTH_FACTOR(n) (n != 0 ? (n << 1) : 1u)
#endif

#define COLLLECTION_KEY   (0)
#define COLLLECTION_VALUE (1)

#pragma endregion

#pragma region --- FUNCTION ---

void* c_copy(void* container);
#define c_copy(container) (typeof_unqual(container))(c_copy)((void*)container)

void* c_shadow(void* container);
#define c_shadow(container) (typeof_unqual(container))(c_shadow)((void*)container)

void* c_slice(void* container, c_index_t index, c_size_t size);
#define c_slice(container, index, size) (typeof_unqual(container))(c_slice)((void*)container, index, size)


void* c_move(void** from, void** to);
#define c_move(from, to) (typeof_unqual(container))(c_move)((void**)&from, (void**)&to); M_EXPECT_T_EQUAL(from, to)

void  c_delete(void** conatiner);
#define c_delete(conatiner) (c_delete)((void**)&conatiner);

#pragma endregion

#endif // !COLLECTION_GENERAL_H_
