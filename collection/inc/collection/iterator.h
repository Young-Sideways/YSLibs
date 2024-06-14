/*******************************************************************************
 *  @file      iterator.h
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
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


#ifndef ITERATOR_H_
#define ITERATOR_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdbool.h>

#include "collection/general.h"
#include "debug.h"

#pragma endregion

#pragma region --- TYPEDEF ---
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
    struct collection_universal_header* collection;
    byte*                               data      ;
    int                                 stage     ;
    it_direction_t                      direction ;
} iterator_t;

#pragma endregion

#pragma region --- MACRO ---

#define INVALID_STAGE COLLECTION_INVALID_INDEX

#define INVALID_ITERATOR (iterator_t) { \
    .collection = NULL,                 \
    .data       = NULL,                 \
    .stage      = INVALID_STAGE,        \
    .direction  = IT_UNDEFINED          \
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to begin element
 */
iterator_t it_begin(void* collection);
/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to memory block after last container element
 */
iterator_t it_end(void* collection);

/**
 *  @brief  reverse iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - reverse iterator to last element
 */
iterator_t it_rbegin(void* collection);
/**
 *  @brief  reverse iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - reverse iterator to memory block before first container element
 */
iterator_t it_rend(void* collection);

/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to first element
 */
iterator_t it_first(void* collection);
/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval               - forward iterator to last element
 */
iterator_t it_last(void* collection);

#pragma endregion

#pragma region --- FUNCIONS ---

bool it_valid(iterator_t iterator);

bool it_comparable(iterator_t lhs, iterator_t rhs);

bool it_equal(iterator_t lhs, iterator_t rhs);

/**
 *  @brief     pointer to data block
 *  @param[in] iterator - valid iterator pointer
 *  @retval             - returns valid data pointer, otherwise @code{.c} NULL @endcode
 */
void* it_get(iterator_t iterator);
/**
 *  @brief shifts iterator to next data block of container
 *  @param[in] iterator - valid iterator pointer
 */
void it_next(iterator_t* iterator);
/**
 *  @brief shifts iterator to previous data block of container
 *  @param[in] iterator - valid iterator pointer
 */
void it_prev(iterator_t* iterator);

#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

/**
 *  @brief      compares @code lhs @endcode and @code rhs @endcode iterators
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval     offset between lhs and rhs
 */
int it_comp(void* lhs, void* rhs, size_t size);

#ifdef SWAP_H_

/**
 *  @brief      swaps @code lhs @endcode and @code rhs @endcode iterator values
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval     offset between lhs and rhs, othewise @code CONTAINER_INVALID_INDEX @endcode
 */
static void it_swap(void* lhs, void* rhs, size_t size) {
    UNUSED(size);

    explain_assert(lhs, "iterator error: invalid left iterator");
    explain_assert(rhs, "iterator error: invalid right iterator");

    if (!it_comparable(*(iterator_t*)lhs, *(iterator_t*)rhs)) {
        explain_error("iterator error: invalid comparison between two iterators");
        return INVALID_STAGE;
    }

    swap(((iterator_t*)lhs)->data, ((iterator_t*)rhs)->data, (((iterator_t*)lhs)->collection)->element_size);
}

#endif // SWAP_H_

#ifdef SEARCH_H_

/**
 *  @brief      swaps @code lhs @endcode and @code rhs @endcode iterator values
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval     offset between lhs and rhs, othewise @code CONTAINER_INVALID_INDEX @endcode
 */
static iterator_t it_find(iterator_t begin, iterator_t end, void* value) {
    if (it_comp(&begin, &end, 0) == INVALID_STAGE)
        return it_end(begin.collection);
    comparator_pt comp = get_comp(begin.collection);
    if (comp)
        for (iterator_t it = begin; it_comp(&begin, &end, 0U) <= 0; it_next(&it))
            if (comp(it.data, value, begin.collection->element_size) == 0)
                return it;
    return it_end(begin.collection);
}

#endif // SEARCH_H_

#ifdef SORT_H_

/**
 *  @brief      sorts container between @code begin @endcode and @code end @endcode iterators
 *  @param[in]  begin - valid left begin iterator
 *  @param[in]  end   - valid right end iterator
 */
static void it_sort(iterator_t begin, iterator_t end) {
    if (!it_comparable(begin, end) || !get_comp(begin.collection))
        goto IT_ERR_UNSORTABLE;

    // simple buble sort
    comparator_pt comp = get_comp(begin.collection);
    for (iterator_t i = begin, i_end = end; it_comp(&i, &i_end, 0U); it_next(&i))
        for (iterator_t j = i, j_end = end; it_comp(&j, &j_end, 0U); it_next(&j))
            if (comp(i.data, j.data, i.collection->element_size) > 0)
                it_swap(&i, &j, 0U);
    return;

IT_ERR_UNSORTABLE:
    explain_error("iterator error: collection can't be sorted");
}

#endif // SORT_H_

#pragma endregion

#endif // !ITERATOR_H_
