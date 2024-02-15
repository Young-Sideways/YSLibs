/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef GENERAL_H_
#define GENERAL_H_

#pragma once

#include "../core/types.h"

#include "../algorithm/comparator.h"
#include "../algorithm/search.h"
#include "../algorithm/swap.h"
#include "../algorithm/sort.h"

#include <limits.h>

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor fo collections ( new size = ~ x1.5 )
 *  @param n - current size
 */
#define GROWTH_FACTOR(n) (n < 2U ? n + 1 : n + (n >> 1))

#define COLLECTION_SIZE_MIN 0U
#define COLLECTION_SIZE_MAX UINT_MAX

typedef void (*internal_memory_access_t)(_IN struct collection_header* collection, _INOUT _NULLABLE void**, _INOUT _NULLABLE int*);

struct collection_header {
    uint32_t size;
    size_t allocated;
    size_t element_size;

    comparator_pt _comp;
    search_pt     _search;
    swap_pt       _swap;
    sort_pt       _sort;
    
    internal_memory_access_t next;
    internal_memory_access_t prev;
    internal_memory_access_t random_access;
};

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
#undef TYPE_SIZE_ASSERT

#pragma endregion

#endif // !GENERAL_H_
