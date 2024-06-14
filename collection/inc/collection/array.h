/*******************************************************************************
 *  @file      array.h
 *  @brief     array - collection, with fixed memory allocation
 *  @attribute linear, sortable
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef ARRAY_H_
#define ARRAY_H_

#pragma once

#pragma region --- INCLUDE ---

#include "collection/general.h"

#pragma endregion

#pragma region --- MACRO ---

#define ARRAY_SIZE_MIN COLLECTION_SIZE_MIN
#define ARRAY_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 *  @typedef array_t
 *  @brief   static array
 */
typedef const struct array_t {
    struct collection_universal_header;
    void* data;
} *array_t;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

/**
 *  @brief   Array construct
 *  @param[in] size         - Number of elements
 *  @param[in] element_size - Size of each element
 */
array_t arr_init(size_t size, size_t element_size);

#pragma endregion

#pragma region --- ACCESSOR ---

/**
 *  @brief   Array element accessor
 *  @param[in] array - Container
 *  @param[in] index - Index of element
 */
void* arr_at(array_t array, int index);

#pragma endregion

#endif // !ARRAY_H_
