/*******************************************************************************
 *  @file      iterator.h
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/


/***********************************************************************************************************************************************************************************
 * 
 * 
 * 
 *                                                                     ITERATOR IMPLEMENTATION LAYER TABLE
 * 
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |  elements | BEGIN                   | END                    | RBEGIN                      | REND                    | FIRST                   | LAST                        |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         0 | data  = NULL  stage = 0 | data  = NULL stage = 0 | data  = NULL  stage = -1    | data  = NULL stage = -1 | data  = NULL  stage = 0 | data  = NULL  stage = 0     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         1 | data  = (ptr) stage = 0 | data  = NULL stage = 1 | data  = (ptr) stage = 0     | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = 0     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         2 | data  = (ptr) stage = 0 | data  = NULL stage = 2 | data  = (ptr) stage = 1     | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = 1     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         3 | data  = (ptr) stage = 0 | data  = NULL stage = 3 | data  = (ptr) stage = 2     | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = 2     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         N | data  = (ptr) stage = 0 | data  = NULL stage = N | data  = (ptr) stage = N - 1 | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = N - 1 |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * | direction | FORWARD                 | FORWARD                | REVERSE                     | REVERSE                 | FORWARD                 | FORWARD                     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * 
 * 
 * 
 *                                                                  ITERATOR INIT RULES for linear containers
 * 
 * +-----------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
 * |  elements | BEGIN                  | END                    | RBEGIN                 | REND                   | FIRST                  | LAST                   |
 * +-----------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
 * |      INIT | data  = NULL           | data  = NULL           | data  = NULL           | data  = NULL           | data  = NULL           | data  = NULL           |
 * |           | stage = 0              | stage = size           | stage = size - 1       | stage = -1             | stage = 0              | stage = size - 1       |
 * +-----------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
 *
 * 
 * 
 *                                                                ITERATOR INIT RULES for associative containers
 * 
 * +------------------------+        +------------------------+        +--------------------------+
 * |          INIT          |        |     VALID ITERATOR     |        |  VALID FORWARD ITERATOR  |
 * +------------------------+        +------------------------+        +--------------------------+
 * | data  = (data)         | --+--> | data  = (ptr)          | --+--> | data  = (ptr)            |
 * | stage = (any)          |   |    | stage = [0..size)      |   |    | stage = [0..size)        |
 * +------------------------+   |    +------------------------+   |    +--------------------------+
 *                              |                                 |
 *                              |                                 |    +--------------------------+
 *                              |                                 |    |  VALID REVERSE ITERATOR  |
 *                              |                                 |    +--------------------------+
 *                              |                                 +--> | data  = (ptr)            |
 *                              |                                      | stage = [0..size)        |
 *                              |                                      +--------------------------+
 *                              |
 *                              |    +------------------------+        +--------------------------+
 *                              |    |    INVALID ITERATOR    |        |            END           |
 *                              |    +------------------------+        +--------------------------+
 *                              +--> | data  = NULL           | --+--> | data  = NULL             |
 *                                   | stage = {-1, size}     |   |    | stage = size             |
 *                                   +------------------------+   |    +--------------------------+
 *                                                                |
 *                                                                |    +--------------------------+
 *                                                                |    |           REND           |
 *                                                                |    +--------------------------+
 *                                                                +--> | data  = NULL             |
 *                                                                     | stage = -1               |
 *                                                                     +--------------------------+
 * 
 * 
 * 
 ***********************************************************************************************************************************************************************************/


#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#pragma once

#pragma region --- INCLUDES ---

#include "general.h"

#pragma endregion

#pragma region --- TYPEDEFS ---
 /**
  *  @enum  it_direction_t
  *  @brief Defines iterator bypass type
  */
typedef enum {
    IT_REVERSE   = -1,
    IT_UNDEFINED =  0,
    IT_FORWARD   =  1
} it_direction_t;

/**
 *  @struct iterator_t
 *  @brief  Defines iterator structure
 */
typedef struct {
    void*          collection;
    byte*          data      ;
    int            stage     ;
    it_direction_t direction ;
} iterator_t;

#pragma endregion

#pragma region --- MACRO ---

#define INVALID_STAGE (INT32_MIN)

#define INVALID_ITERATOR (iterator_t) { \
    .collection = NULL,                 \
    .data       = NULL,                 \
    .stage      = INVALID_STAGE,        \
    .direction  = IT_UNDEFINED          \
}

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to begining element
 */
iterator_t it_begin(_IN void* collection);
/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to memory block after last container element
 */
iterator_t it_end(_IN void* collection);

/**
 *  @brief  reverse iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - reverse iterator to last element
 */
iterator_t it_rbegin(_IN void* collection);
/**
 *  @brief  reverse iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - reverse iterator to memory block before first container element
 */
iterator_t it_rend(_IN void* collection);

/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to first element
 */
iterator_t it_first(_IN void* collection);
/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to last element
 */
iterator_t it_last(_IN void* collection);

#pragma endregion

#pragma region --- FUNCIONS ---

/**
 *  @brief     pointer to data block
 *  @param[in] iterator - valid iterator pointer
 *  @retval             - returns valid data pointer, otherwise @code{.c} NULL @endcode
 */
void* it_get(_IN iterator_t* iterator);
/**
 *  @brief shifts iterator to next data block of container
 *  @param[in] iterator - valid iterator pointer
 */
void it_next(_IN iterator_t* iterator);
/**
 *  @brief shifts iterator to previous data block of container
 *  @param[in] iterator - valid iterator pointer
 */
void it_prev(_IN iterator_t* iterator);

#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

/**
 *  @brief      compares @code lhs @endcode and @code rhs @endcode iterators
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval     offset between lhs and rhs
 */
int it_comp(_IN void* lhs, _IN void* rhs, _IN size_t size);

#ifdef _SWAP_H_

/**
 *  @brief      swaps @code lhs @endcode and @code rhs @endcode iterator values
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval     offset between lhs and rhs, othewise @code CONTAINER_INVALID_INDEX @endcode
 */
static void it_swap(void* lhs, void* rhs, size_t size) {
    UNUSED(size);

    extern bool _iterator_private_is_range(iterator_t* iterator);

    it_comp(lhs, rhs, 0);
    explain_assert(_iterator_private_is_range((iterator_t*)lhs), "iterator error: left iterator out of range");
    explain_assert(_iterator_private_is_range((iterator_t*)rhs), "iterator error: right iterator out of range");

    swap(((iterator_t*)lhs)->data, ((iterator_t*)rhs)->data, get_element_size(((iterator_t*)lhs)->collection));
}

#endif // !_SWAP_H_

#ifdef _SEARCH_H_

/**
 *  @brief      swaps @code lhs @endcode and @code rhs @endcode iterator values
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval     offset between lhs and rhs, othewise @code CONTAINER_INVALID_INDEX @endcode
 */
iterator_t it_find(_IN iterator_t begin, _IN iterator_t end, _IN void* value) {
    it_comp(&begin, &end, 0);
    comparator_pt comp = get_comp(begin.collection);
    if (comp)
        for (iterator_t it = begin; it_comp(&begin, &end, 0) <= 0; it_next(&it))
            if (comp(it.data, value, get_element_size(begin.collection)) == 0)
                return it;
    return INVALID_ITERATOR;
}

#endif // !_SEARCH_H_

#ifdef _SORT_H_

/**
 *  @brief      sorts container between @code begin @endcode and @code end @endcode iterators
 *  @param[in]  begin - valid left begin iterator
 *  @param[in]  end   - valid right end iterator
 */
void it_sort(_IN iterator_t begin, _IN iterator_t end) {
    extern void* _iterator_private_try_normalize_forward(iterator_t begin, iterator_t end, size_t* size);

    size_t size = 0;
    byte* address = _iterator_private_try_normalize_forward(begin, end, &size);
    if (address) {
        sort_pt data_sort = get_sort(begin.collection);
        data_sort(address, size, get_element_size(begin.collection), get_comp(begin.collection), get_swap(begin.collection));
    }
    else {
        // implementation iterators sort...
        // mayby use external bubble sort
    }
}

#endif // !_SORT_H_

#pragma endregion

#endif // !_ITERATOR_H_
