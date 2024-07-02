/*******************************************************************************
 *  @file      iterator.h
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
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
 * |         0 | data  = NULL  stage = 0 | data  = NULL stage = 0 | data  = NULL  stage = -1    | data  = NULL stage = -1 | BEGIN                   | data  = NULL  stage = 0     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         1 | data  = (ptr) stage = 0 | data  = NULL stage = 1 | data  = (ptr) stage = 0     | data  = NULL stage = -1 | BEGIN                   | data  = (ptr) stage = 0     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         2 | data  = (ptr) stage = 0 | data  = NULL stage = 2 | data  = (ptr) stage = 1     | data  = NULL stage = -1 | BEGIN                   | data  = (ptr) stage = 1     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         3 | data  = (ptr) stage = 0 | data  = NULL stage = 3 | data  = (ptr) stage = 2     | data  = NULL stage = -1 | BEGIN                   | data  = (ptr) stage = 2     |
 * +-----------+-------------------------+------------------------+-----------------------------+-------------------------+-------------------------+-----------------------------+
 * |         N | data  = (ptr) stage = 0 | data  = NULL stage = N | data  = (ptr) stage = N - 1 | data  = NULL stage = -1 | BEGIN                   | data  = (ptr) stage = N - 1 |
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
typedef struct iterator_s {
    struct collection_universal_header* collection;
    void*                               data      ;
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

#endif // !ITERATOR_H_
