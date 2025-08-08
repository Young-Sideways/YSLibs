/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_GENERAL_H_
#define C_GENERAL_H_


#include <stddef.h>
#include <stdint.h>


#pragma region --- TYPEDEF ---

/**
*  @typedef c_size_t
*  @brief   collection size type
*/
typedef uint32_t c_size_t;
/**
*  @typedef c_index_t
*  @brief   collection indexing type
*/
typedef int32_t c_index_t;

#pragma endregion

#pragma region --- MACRO ---

/**
*  @def   C_SIZE_MIN
*  @brief Default minimum size for all containers
*/
#define C_SIZE_MIN (c_size_t)(0u)

/**
*  @def   C_SIZE_MAX
*  @brief Default maximum size for all containers
*/
#define C_SIZE_MAX (c_size_t)(INT32_MAX)

/**
*  @def   C_INVALID_INDEX
*  @brief Value of invalid index for all containers
*/
#define C_INVALID_INDEX (INT32_MIN)

/**
 *  @def   C_GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( 'new size' = 2 * 'old size' )
 *  @param n - current size
 */
#ifndef C_GROWTH_FACTOR
    #define C_GROWTH_FACTOR(n) (n != 0 ? (n << 1) : 1u)
#endif

/**
 *  @def   C_KEY
 *  @brief Defines 'field id' value for keys
 */
#define C_KEY   (0)

/**
 *  @def   C_VALUE
 *  @brief Defines 'field id' value for values
 */
#define C_VALUE (1)

#pragma endregion

#endif // !C_GENERAL_H_
