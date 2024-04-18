/*******************************************************************************
 *  @file      hashtable.h
 *  @brief     
 *  @author    Young Sideways
 *  @date      15.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include "general.h"

#pragma endregion

#pragma region --- MACRO ---

#define HASHTABLE_SIZE_MIN COLLECTION_SIZE_MIN
#define HASHTABLE_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

typedef uint32_t hash_t;
typedef hash_t(hashfunc_t)(const void*, size_t);
typedef hashfunc_t* hashfunc_pt;

typedef struct {
    void *key, *data;
    entry_t* next;
} entry_t;

typedef struct {
    struct collection_header;

    hashfunc_pt hashfunc;

    entry_t** table;
} hashtable_t;

#pragma endregion

#pragma region --- DEFAULT ---

hash_t hash(const void* key, size_t size) {
    hash_t hash = 5381;
    for (byte* begin = (byte*)key; size; --size)
        hash = ((hash << 5) + hash) ^ *begin;
    return hash;
}
hash_t str_hash(const char* str) {
    hash_t hash = 5381;
    while (*str)
        hash = ((hash << 5) + hash) ^ *(str++);
    return hash;
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

hashtable_t ht_create(size_t);
void ht_delete(hashtable_t*);

#pragma endregion

#pragma region --- FUNCION ---

void ht_copy(hashtable_t* dest, hashtable_t* src);
void ht_move(hashtable_t* dest, hashtable_t* src);
void ht_swap(hashtable_t dest, hashtable_t src);

void ht_insert(hashtable_t container, void* key, void* value);
bool ht_contains(hashtable_t container, void* key);
void* ht_lookup(hashtable_t container, void* key);

#pragma endregion

#pragma region ---  ---

#pragma endregion

#endif // !_HASHTABLE_H_
