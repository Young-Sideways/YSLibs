/*******************************************************************************
 *  @file      hashtable.h
 *  @brief     Implementation of key-value associative hash container
 *  @attribute associative, non-sortable
 *  @author    Young Sideways
 *  @date      15.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdbool.h>

#include "../general.h"

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

typedef hash_t(hashfunc_t)(_IN const void* key, _IN size_t key_size);

typedef hashfunc_t* hashfunc_pt;

typedef struct ht_entry_t {
    struct ht_entry_t* next;
} *ht_entry_t;

typedef const struct hashtable_t {
    struct collection_universal_header;
    hashfunc_pt hashfunc;
    size_t key_size;
} *hashtable_t;

#pragma endregion

#pragma region --- DEFAULT ---

hashfunc_t hash;
hashfunc_t str_hash;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

hashtable_t ht_init(_IN size_t size, _IN size_t key_size, _IN size_t value_size, _IN _NULLABLE hashfunc_pt hashfunc);

#pragma endregion

#pragma region --- FUNCION ---

void ht_insert(_IN hashtable_t table, _IN const void* key, _IN const void* value);
void ht_erase(_IN hashtable_t table, _IN const void* key);

bool ht_contains(_IN const hashtable_t table, _IN const void* key);
void* ht_lookup(_IN const hashtable_t table, _IN const void* key);

#pragma endregion

#endif // !_HASHTABLE_H_
