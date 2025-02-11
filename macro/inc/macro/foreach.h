/*******************************************************************************
 *  @file      foreach.h
 *  @brief     MACRO Extension lib that add foreach loops
 *  @author    Young Sideways
 *  @date      12.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_FOREACH_H_
#define M_FOREACH_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core.h"

#pragma endregion

#pragma region --- MACRO ---

#ifdef ITERATOR_H_

#define for_each(it, collection) \
    for (iterator_t _##it = it_begin(collection), _iter_local_end = it_end(collection); it_comp(&_##it, &_iter_local_end, 0U) != 0; it_next(&_##it)) \
        for (it = (typeof(it)*)it_get(_##it); it != NULL; it = NULL)

#define rfor_each(type, it, collection) \
    for (iterator_t _##it = it_rbegin(collection), _##end = it_rend(collection); it_comp(&_##it, &_##end, 0U); it_next(&_##it)) \
        for (type* it = (type*)it_get(_##it); it; it = NULL)

#else // ITERATOR_H_

#define for_each(type, it, array) \
    for (type* it = (type*)collection, *_iter_local_end = ((byte*)collection) + sizeof(array); it < _iter_local_end; it++)

#define rfor_each(type, it, array) \
    for (type* it = ((byte*)collection) + sizeof(array), *_iter_local_end = (type*)collection; it >= _iter_local_end; it--)

#endif

#endif // !M_FOREACH_H_
