/*******************************************************************************
 *  @file      collections.h
 *  @brief     
 *  @author    Young Sideways
 *  @date      16.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COLLECTIONS_H_
#define _COLLECTIONS_H_

#pragma once

#pragma region --- INCLUDES ---

#include "array.h"
#include "iterator.h"
#include "../core/macro/foreach.h"

#pragma endregion

#pragma region --- GENERICS ---

#define new(type, ...) _Generic( ((type)0), \
    array_t : arr_init(__VA_ARGS__),        \
    default : ((void)0)                     \
)

#pragma endregion


#endif // !_COLLECTIONS_H_
