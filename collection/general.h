/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

/*******************************************************************************
 * 
 * UCH - universal collection header
 * SCH - specific collection header
 * DAT - data segments
 * 
 * - inplace container type
 *     |---------------|---------------|---------------|
 *     |      UCH      |      SCH      |      DAT      |
 *     |---------------|---------------|---------------|
 * -size(UCH)          0            size(SCH)      size(DAT)
 *     |---------------|---------------|---------------|
 *
 * 
 * - reference container type
 *     |---------------|---------------|
 *     |      UCH      |      SCH      |
 *     |---------------|---------------|
 * -size(UCH)          0            size(SCH)
 *     |---------------|------|--------|
 *                            |
 *                         pointer          |---------------|
 *                            |             |      DAT      |
 *                            ------------> |---------------|
 *                                          0           size(DAT)
 *                                          |---------------|
 * 
 ******************************************************************************/

#ifndef _COLLECTION_GENERAL_H_
#define _COLLECTION_GENERAL_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( new size = x2 )
 *  @param n - current size
 */
#define GROWTH_FACTOR(n) (n ? (n << 1) : 0x1U)

/**
*  @def   COLLECTION_SIZE_MIN
*  @brief Minimum size for all containers
*/
#define COLLECTION_SIZE_MIN (0x0U)

/**
*  @def   COLLECTION_SIZE_MAX
*  @brief Maximum size for all containers
*/
#define COLLECTION_SIZE_MAX ((uint32_t)INT32_MAX)

/**
*  @def   COLLECTION_INVALID_INDEX
*  @brief Value of invalid index for all containers
*/
#define COLLECTION_INVALID_INDEX (INT32_C(-1))

#define COLLECTION_TYPE_DECLARATOR(typename) typedef struct typename *typename

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

void delete(_INOUT void** collection);

#pragma endregion

#pragma region --- FUNCTIONS ---

// void set_comp

#pragma endregion


#pragma region --- STATIC ASSERTION BLOCK ---

#define TYPE_SIZE_ASSERT(expression) static_assert(expression, "Collection core error: default type pointers have different sizes")
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(char*)              );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(short*)             );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(int*)               );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long*)              );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long long*)         );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed char*)       );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed short*)      );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed int*)        );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long*)       );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long long*)  );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned char*)     );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned short*)    );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned int*)      );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long*)     );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long long*));
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(float*)             );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(double*)            );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long double*)       );

static_assert(sizeof(int32_t) == sizeof(uint32_t), "Collection core error: fixed size for signed and unsigned 32 bit integers are different");
#undef TYPE_SIZE_ASSERT

#pragma endregion

#endif // !_COLLECTION_GENERAL_H_
