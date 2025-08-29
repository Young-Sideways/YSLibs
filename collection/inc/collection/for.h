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
    for (iterator_t __iter = it_begin(collection), __end = it_end(collection); !it_equal(&__iter, &__end); it_next(&__iter)) \
        for (it##_temp, *__temp = it_get(__##it##_iter); __temp != NULL;) \
            for (it = *__temp; __temp != NULL; __temp = NULL)



#endif // !C_FOR_H_



#define c_rfor(type, it, collection) \
    for (iterator_t _##it = it_rbegin(collection), _##end = it_rend(collection); it_comp(&_##it, &_##end, 0U); it_next(&_##it)) \
        for (type* it = (type*)it_get(_##it); it; it = NULL)