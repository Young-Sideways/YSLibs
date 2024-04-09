/*******************************************************************************
 *  @file      general.h
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _GENERAL_H_
#define _GENERAL_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../algorithm/comparator.h"
#include "../algorithm/search.h"
#include "../algorithm/swap.h"
#include "../algorithm/sort.h"

#include <limits.h>

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   GROWTH_FACTOR
 *  @brief memory consumption growth factor for collections ( new size = ~x2 )
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
#define COLLECTION_SIZE_MAX (INTMAX_MAX)

 /**
  *  @def   COLLECTION_INVALID_INDEX
  *  @brief Value of invalid index for all containers
  */
#define COLLECTION_INVALID_INDEX (INTMAX_C(-1))

#pragma endregion

#pragma region --- TYPEDEFS ---

/**
 *  @typedef internal_memory_access_t
 *  @brief   function prototype for unifying access to container memory
 */
typedef void (*internal_memory_access_t)(_IN struct collection_header* collection, _INOUT _NULLABLE void**, _INOUT _NULLABLE int*);

/**
 *  @struct collection_header
 *  @brief  main data structure for all collections
 */
struct collection_header {
    size_t capacity    ;
    size_t size        ;
    size_t element_size;

    comparator_pt _comp  ;
    search_pt     _search;
    swap_pt       _swap  ;
    sort_pt       _sort  ;

    internal_memory_access_t next         ;
    internal_memory_access_t prev         ;
    internal_memory_access_t data_block   ;
    internal_memory_access_t random_access;
};

#pragma endregion

#pragma region --- FUNCTIONS ---

struct collection_header header_allocator(
    _IN _NULLABLE const size_t capacity,
    _IN const size_t element_size,
    _IN _NULLABLE const comparator_pt _comp,
    _IN _NULLABLE const search_pt _search,
    _IN _NULLABLE const swap_pt _swap,
    _IN _NULLABLE const sort_pt _sort,
    _IN const internal_memory_access_t next,
    _IN const internal_memory_access_t prev,
    _IN _NULLABLE const internal_memory_access_t data_block,
    _IN _NULLABLE const internal_memory_access_t random_access);

#pragma endregion

#pragma region --- PUBLIC ---

#define GENERAL_CHANGE_COMP(collection, value)   ((struct collection_header*)(&collection))->_comp   = value
#define GENERAL_CHANGE_SEARCH(collection, value) ((struct collection_header*)(&collection))->_search = value
#define GENERAL_CHANGE_SWAP(collection, value)   ((struct collection_header*)(&collection))->_swap   = value
#define GENERAL_CHANGE_COMP(collection, value)   ((struct collection_header*)(&collection))->_sort   = value

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
#undef TYPE_SIZE_ASSERT

#pragma endregion

#endif // !_GENERAL_H_
