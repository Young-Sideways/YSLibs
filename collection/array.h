/*******************************************************************************
 *  @file      array.h
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _ARRAY_H_
#define _ARRAY_H_

#pragma once

#pragma region --- INCLUDES ---

#include "general.h"

#pragma endregion

#pragma region --- MACROS ---

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEFS ---

COLLECTION_TYPE_DECLARATOR(array_t);

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

array_t arr_init(_IN const size_t size, _IN const size_t element_size);

array_t arr_copy(_IN const array_t array);
array_t arr_move(_IN array_t* array);
array_t arr_shadow(_IN const array_t array);

#pragma endregion

#pragma region --- ACCESSORS ---

void* arr_at(_IN array_t array, _IN int position);

#pragma endregion

#pragma region --- INFORMATION ---

size_t arr_size(_IN const array_t array);
size_t arr_element_size(_IN const array_t array);

#pragma endregion

#endif // !_ARRAY_H_
