/*******************************************************************************
 * @file      btree.h
 * @author    Young Sideways
 * @brief     tree collection
 * @date      19.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef BTREE_H_
#define BTREE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdlib.h>
#include <stdbool.h>

#include "collection/general.h"

#pragma endregion

#pragma region --- MACRO ---

#define BTREE_SIZE_MIN COLLECTION_SIZE_MIN
#define BTREE_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

typedef const struct btree_s {
    struct collection_universal_header;
} *btree_t;

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

btree_t btree_init(size_t element_size);

#pragma endregion

#pragma region --- FUNCTION ---

bool btree_contains(btree_t btree, const void* value);
int  btree_count(btree_t btree, const void* value);
void btree_insert(btree_t btree, const void* value);
void btree_erase(btree_t btree, const void* value);

#pragma endregion

#endif // !BTREE_H_
