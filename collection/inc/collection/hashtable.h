/*******************************************************************************
 *  @file      hashtable.h
 *  @brief     Implementation of key-value associative hash container
 *  @attribute associative, non-sortable
 *  @author    Young Sideways
 *  @date      15.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdbool.h>

#include "collection/general.h"

#pragma endregion

#pragma region --- MACRO ---

#if (COLLECTION_SIZE_MIN < 8U)
    #define HASHTABLE_SIZE_MIN (8U)
#else
    #define HASHTABLE_SIZE_MIN COLLECTION_SIZE_MIN
#endif
#define HASHTABLE_SIZE_MAX COLLECTION_SIZE_MAX

/**
 *  @def   HASHTABLE_LOAD_FACTOR
 *  @brief default max load factor of all table - 75%
 */
#define HASHTABLE_MAX_LOAD_FACTOR (0.75)

/**
 *  @def   HASHTABLE_MAX_BUCKET_LOAD_FACTOR_PER_SIZE
 *  @brief default max load factor of 1 bucket, before table rehashing - 35%
 */
#define HASHTABLE_MAX_BUCKET_LOAD_FACTOR_PER_SIZE (0.35)

#define HASHTABLE_GROWTH_FACTOR(n) GROWTH_FACTOR(n)

#pragma endregion

#pragma region --- TYPEDEF ---

typedef uint32_t hash_t;
#define DEFAULT_HASH_VALUE ((hash_t)0U)

typedef hash_t (hasher_t)(const void* key, size_t key_size);

typedef hasher_t* hasher_pt;

typedef struct ht_entry_t {
    struct ht_entry_t* next;
} *ht_entry_t;

typedef const struct hashtable_t {
    struct collection_universal_header;
    hasher_pt hasher;
    size_t key_size;
} *hashtable_t;

#pragma endregion

#pragma region --- DEFAULT ---

hasher_t hash;
hasher_t str_hash;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

hashtable_t ht_init(size_t size, size_t key_size, size_t value_size, hasher_pt hasher);

#pragma endregion

#pragma region --- FUNCION ---

void ht_insert(hashtable_t table, const void* key, const void* value);
void ht_erase(hashtable_t table, const void* key);

bool ht_contains(const hashtable_t table, const void* key);
void* ht_lookup(const hashtable_t table, const void* key);

#pragma endregion

#endif // !HASHTABLE_H_
