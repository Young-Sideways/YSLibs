/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

/*******************************************************************************
 * 
 * adaptors - private headers
 * CUH      - universal collection header
 * SCH      - specific collection header
 * DAT      - data segment
 * 
 * 
 * - inplace container type with specific header
 *     +---------------+---------------+---------------+---------------+
 *     |   adaptors    |      CUH      |      SCH      |      DAT      |
 *     +---------------+---------------+---------------+---------------+
 * -size(adaptors)     0            size(CUH)      size(SCH)       size(DAT)
 *     +---------------+---------------+---------------+---------------+
 * 
 * - inplace container type without specific header
 *     +---------------+---------------+---------------+
 *     |   adaptors    |      CUH      |      DAT      |
 *     +---------------+---------------+---------------+
 * -size(adaptors)     0           size(CUH)       size(DAT)
 *     +---------------+---------------+---------------+
 * 
 * 
 * - reference container type with specific header
 *     +---------------+---------------+---------------+
 *     |   adaptors    |      CUH      |      SCH      |
 *     +---------------+---------------+---------------+
 * -size(adaptors)     0           size(CUH)       size(SCH)
 *     +---------------+-----------+---+-----------+---+
 *                                 |               *
 *                                 |               *
 *                                 |       * maybe pointer *
 *                                 |               *
 *                                 |               v
 *                              pointer     +---------------+
 *                                 |        |      DAT      |
 *                                 +------> +---------------+
 *                                          0           size(DAT)
 *                                          +---------------+
 * 
 * - reference container type
 *     +---------------+---------------+
 *     |   adaptors    |      CUH      |
 *     +---------------+---------------+
 * -size(adaptors)     0           size(CUH)
 *     +---------------+-----------+---+
 *                                 |
 *                              pointer     +---------------+
 *                                 |        |      DAT      |
 *                                 +------> +---------------+
 *                                          0           size(DAT)
 *                                          +---------------+
 * 
 ******************************************************************************/

#ifndef COLLECTION_GENERAL_H_
#define COLLECTION_GENERAL_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( new size = x2 )
 *  @param n - current size
 */
#define GROWTH_FACTOR(n) (n ? (n << 1) : 1U)

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
#define COLLECTION_INVALID_INDEX (INT32_MIN)

#pragma endregion

#pragma region --- TYPEDEF ---

struct collection_universal_header {
    size_t capacity;
    size_t size;
    size_t element_size;
};

#pragma endregion

#pragma region --- UNIVERSAL CONSTRUCTOR / DESTRUCTOR ---

void* copy(const void* collection);
void* move(void** collection);

void delete(void** collection);

#pragma endregion

#pragma region --- GETTER / SETTER ---

#define DECL_GET_SET__(type, name, field)                                             \
    static inline type get_##name(void* collection) {                                 \
        extern void* _collection_private_##field##_get(void*);                        \
        return (type)_collection_private_##field##_get(collection);                   \
    }                                                                                 \
    static inline void set_##name(void* collection, type value) {                     \
        extern void _collection_private_##field##_set(void* collection, void* value); \
        _collection_private_##field##_set(collection, (void*)value);                  \
    }

#ifdef SWAP_H_

DECL_GET_SET__(swap_t, swap, swap_)

#endif // SWAP_H_

#ifdef COMPARATOR_H_

DECL_GET_SET__(comparator_t, comp, comparator_)

#endif // COMPARATOR_H_

#ifdef SEARCH_H_

DECL_GET_SET__(search_t, search, search_)

#endif // SEARCH_H_

#ifdef SORT_H_

DECL_GET_SET__(sort_t, sort, sort_)

#endif // SORT_H_

#undef DECL_GET_SET__

#pragma endregion

#pragma region --- FUNCTION ---

bool is_empty(const void* collection);

#pragma endregion

#pragma region --- STATIC ASSERTION BLOCK ---

//#define TYPE_SIZE_ASSERT(expression) static_assert(expression, "Collection core error: default type pointers have different sizes")
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(char*)              );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(short*)             );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(int*)               );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long*)              );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long long*)         );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed char*)       );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed short*)      );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed int*)        );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long*)       );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long long*)  );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned char*)     );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned short*)    );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned int*)      );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long*)     );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long long*));
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(float*)             );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(double*)            );
//TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long double*)       );
//
//static_assert(sizeof(int32_t) == sizeof(uint32_t), "Collection core error: fixed size for signed and unsigned 32 bit integers are different");
//#undef TYPE_SIZE_ASSERT

#pragma endregion

#endif // !COLLECTION_GENERAL_H_
