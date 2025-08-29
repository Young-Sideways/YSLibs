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
 * +-----------+-------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
 * |  elements | BEGIN                   | END                    | RBEGIN                 | REND                   | FIRST                  | LAST                   |
 * +-----------+-------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
 * |      INIT | data  = NULL            | data  = NULL           | data  = NULL           | data  = NULL           | data  = NULL           | data  = NULL           |
 * |           | stage = 0               | stage = size           | stage = size - 1       | stage = -1             | stage = 0              | stage = size - 1       |
 * +-----------+-------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
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

#include "general.h"

#include <core/core.h>


YSL_BEGIN_DECLS


#pragma region --- TYPEDEF ---

/**
 *  @struct iterator_t
 *  @brief  Defines iterator structure
 */
typedef struct {
    void      *collection;
    void      *data      ;
    void      *value     ;
    c_index_t  index     ;
    uint32_t   context   ;
} iterator_t;

#pragma endregion

#pragma region --- MACRO ---

#define IT_CONTEXT_INVALID UINT32_MAX
#define IT_INVALID (iterator_t) {     \
    .collection = NULL              , \
    .data       = NULL              , \
    .value      = NULL              , \
    .index      = C_INVALID_INDEX   , \
    .context    = IT_CONTEXT_INVALID  \
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

YSL_API iterator_t it_begin (void* collection);
YSL_API iterator_t it_end   (void* collection);
YSL_API iterator_t it_rbegin(void* collection);
YSL_API iterator_t it_rend  (void* collection);
YSL_API iterator_t it_first (void* collection);
YSL_API iterator_t it_last  (void* collection);

#pragma endregion

#pragma region --- FUNCIONS ---

YSL_API bool it_valid      (iterator_t iterator);
YSL_API bool it_is_forward (iterator_t iterator);
YSL_API bool it_is_reverse (iterator_t iterator);
YSL_API bool it_comparable (iterator_t lhs, iterator_t rhs);
YSL_API bool it_equal      (iterator_t lhs, iterator_t rhs);

YSL_API void*  it_get (iterator_t iterator);

YSL_API void  (it_next)(iterator_t* iterator);
YSL_API void  (it_prev)(iterator_t* iterator);

#define it_next(iterator) (it_next)(&iterator)
#define it_prev(iterator) (it_prev)(&iterator)

#pragma endregion

YSL_END_DECLS

#endif // !ITERATOR_H_
