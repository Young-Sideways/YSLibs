/*******************************************************************************
 *  @file      foreach.h
 *  @brief     MACRO Extension lib that add foreach loops
 *  @author    Young Sideways
 *  @date      12.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _FOREACH_H_
#define _FOREACH_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../core.h"

#pragma endregion

#pragma region --- MACROS ---

#ifdef _ITERATOR_H_

#define for_each(type, it, collection, ...) \
    for (iterator_t _##it = it_begin(collection), _end = it_end(collection); it_comp(&_##it, &_end, NULL); it_next(&_##it)) \
        for (type* it = (type*)it_get(&_##it); it; it = NULL)

#define rfor_each(type, it, collection, ...) \
    for (iterator_t _##it = it_rbegin(collection), _##end = it_rend(collection); it_comp(&_##it, &_##end, NULL); it_next(&_##it)) \
        for (type* it = (type*)it_get(&_##it); it; it = NULL)

#else // !_ITERATOR_H_

#define for_each(type, it, collection, size) \
    for (type* it = (type*)collection, *_iter_local_end = ((byte*)collection) + sizeof(type) * size; it < _iter_local_end; ((byte*)it) += sizeof(type))

#define rfor_each(type, it, collection, size) \
    for (type* it = ((byte*)collection) + sizeof(type) * (size - 1), *_iter_local_end = (type*)collection; it >= _iter_local_end; ((byte*)it) -= sizeof(type))

#endif

#endif // !_FOREACH_H_
