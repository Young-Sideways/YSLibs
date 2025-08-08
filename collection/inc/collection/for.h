/*******************************************************************************
 *  @file      for.h
 *  @brief     Collection extension lib that adds 'for each' loops
 *  @author    Young Sideways
 *  @date      12.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_FOR_H_
#define C_FOR_H_

#include "iterator.h"

#define c_for(it, collection) \
    for (iterator_t _##it = it_begin(collection), _iter_local_end = it_end(collection); it_comp(&_##it, &_iter_local_end, 0U) != 0; it_next(&_##it)) \
        for (it = (typeof(it)*)it_get(_##it); it != NULL; it = NULL)

#define c_rfor(type, it, collection) \
    for (iterator_t _##it = it_rbegin(collection), _##end = it_rend(collection); it_comp(&_##it, &_##end, 0U); it_next(&_##it)) \
        for (type* it = (type*)it_get(_##it); it; it = NULL)


#endif // !C_FOR_H_
