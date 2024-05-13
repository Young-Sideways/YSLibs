/*******************************************************************************
 *  @file      collections.h
 *  @brief     General collections header to include all collections
 *  @author    Young Sideways
 *  @date      16.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COLLECTIONS_H_
#define _COLLECTIONS_H_

#pragma once

#pragma region --- INCLUDES ---

#include "iterator/iterator.h"
#include "../core/macro/foreach.h"

#include "array/array.h"

#pragma endregion

#pragma region --- GENERICS ---

#define new(type, element_type, ...) _Generic( ((type)0),  \
    array_t : arr_init(__VA_ARGS__, sizeof(element_type)), \
    default : ((void)0)                                    \
)

#pragma endregion


#endif // !_COLLECTIONS_H_
