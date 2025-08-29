/*******************************************************************************
 *  @file      hashtable.h
 *  @brief     Implementation of key-value associative hash container
 *  @attribute associative, non-sortable
 *  @author    Young Sideways
 *  @date      15.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_MAP_H_
#define C_MAP_H_


#ifdef C_GENERIC_H_
#   error Container library headers must be placed before <collection/generic.h> header
#endif


#include "general.h"
#include <macro/arg.h>


#pragma region --- MACRO ---

#if (C_SIZE_MIN < 8U)
    #define MAP_SIZE_MIN (8U)
#else
    #define MAP_SIZE_MIN C_SIZE_MIN
#endif
#define MAP_SIZE_MAX C_SIZE_MAX

/**
 *  @def   MAP_LOAD_FACTOR_MAX
 *  @brief default max load factor of all table - 75%
 */
#define MAP_LOAD_FACTOR_MAX (0.75)

/**
 *  @def   MAP_BUCKET_LOAD_FACTOR_PER_SIZE_MAX
 *  @brief default max load factor of 1 bucket, before table rehashing - 35%
 */
#define MAP_BUCKET_LOAD_FACTOR_PER_SIZE_MAX (0.35)

#define MAP_GROWTH_FACTOR(n) C_GROWTH_FACTOR(n)

#pragma endregion

#pragma region --- TYPEDEF ---

typedef uint32_t hash_t;
#define DEFAULT_HASH_VALUE ((hash_t)0U)

typedef hash_t (*hashfunc_t)(const void* key, size_t key_size);

typedef struct ht_entry_t {
    struct ht_entry_t* next;
} *ht_entry_t;

typedef struct {} *map_t;

#pragma endregion

#pragma region --- DEFAULT ---

hash_t hash(const void* key, size_t key_size);
hash_t str_hash(const void* key, size_t key_size);

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

map_t (map_ctor)(size_t size, size_t key_size, size_t value_size, hashfunc_t hashfunc);
#define map_ctor(size, key_t, value_t, ...) (map_ctor)(VA_MEGRE((__VA_ARGS__), MAP_SIZE_MIN, 1u, 1u, NULL))

#pragma endregion

#pragma region --- FUNCION ---

void  map_insert  (map_t table, const void* key, const void* value);
void  map_erase   (map_t table, const void* key);

bool  map_contains(map_t table, const void* key);
void* map_lookup  (map_t table, const void* key);

#pragma endregion

#endif // !C_MAP_H_
