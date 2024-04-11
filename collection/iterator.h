/*******************************************************************************
 *  @file      iterator.h
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/



/******************************************************************************************************************************************************************************
                                                                           ITERATOR APPLICATION LAYER

|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
|  elements | BEGIN                   | END                    | RBEGIN                      | REND                    | FIRST                   | LAST                        |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
|         0 | data  = NULL  stage = 0 | data  = NULL stage = 0 | data  = NULL  stage = -1    | data  = NULL stage = -1 | data  = NULL  stage = 0 | data  = NULL  stage = 0     |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
|         1 | data  = (ptr) stage = 0 | data  = NULL stage = 1 | data  = (ptr) stage = 0     | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = 0     |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
|         2 | data  = (ptr) stage = 0 | data  = NULL stage = 2 | data  = (ptr) stage = 1     | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = 1     |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
|         3 | data  = (ptr) stage = 0 | data  = NULL stage = 3 | data  = (ptr) stage = 2     | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = 2     |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
|         N | data  = (ptr) stage = 0 | data  = NULL stage = N | data  = (ptr) stage = N - 1 | data  = NULL stage = -1 | data  = (ptr) stage = 0 | data  = (ptr) stage = N - 1 |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|
| direction | FORWARD                 | FORWARD                | REVERSE                     | REVERSE                 | FORWARD                 | FORWARD                     |
|-----------|-------------------------|------------------------|-----------------------------|-------------------------|-------------------------|-----------------------------|


*******************************************************************************************************************************************************************************/


#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core/core.h"

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
    struct collection_header* collection;
    byte*                     data      ;
    int                       stage     ;
    it_direction_t            direction ;
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
 *  @retval     offset between lhs and rhs, othewise @code CONTAINER_INVALID_INDEX @endcode
 */
static int it_comp(void* lhs, void* rhs, size_t size) {
    UNUSED(size);

    extern bool _iterator_private_is_valid(iterator_t* iterator);

    assert(_iterator_private_is_valid(lhs) && _iterator_private_is_valid(rhs));
    assert(((iterator_t*)lhs)->collection == ((iterator_t*)rhs)->collection);

    return ((iterator_t*)lhs)->stage - ((iterator_t*)rhs)->stage;
}

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

    extern bool _iterator_private_is_valid(iterator_t* iterator);

    assert(_iterator_private_is_valid(lhs) && _iterator_private_is_valid(rhs));
    assert(((iterator_t*)lhs)->collection == ((iterator_t*)rhs)->collection);

    swap_pt data_swap = ((iterator_t*)lhs)->collection->_swap;
    data_swap(((iterator_t*)lhs)->data, ((iterator_t*)rhs)->data, ((iterator_t*)lhs)->collection->element_size);
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
    struct collection_header* header = begin.collection;
    if (address) {
        sort_pt data_sort = header->_sort;
        data_sort(address, size, header->element_size, header->_comp, header->_swap);
    }
    else {
        // implementation iterators sort...
    }
}

#endif // !_SORT_H_

#pragma endregion

#endif // !_ITERATOR_H_
