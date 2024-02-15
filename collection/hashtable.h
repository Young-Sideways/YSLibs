#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#pragma once

#include "general.h"
#include "../core/types.h"

#define HASHTABLE_SIZE_MIN 0u
#define HASHTABLE_SIZE_MAX INT_MAX

typedef uint64_t hash_t;
typedef uint32_t hash_t;
typedef hash_t (hashfunc_t)(const void*, size_t);
typedef hashfunc_t* hashfunc_pt;

size_t hash(const void* key, size_t size) {
	size_t hash = 5381;
	for (byte* begin = key; size; --size)
		hash = ((hash << 5) + hash) ^ *begin;
	return hash;
}
size_t str_hash(const char* str) {
	size_t hash = 5381;
	while (*str)
		hash = ((hash << 5) + hash) ^ *(str++);
	return hash;
}

typedef struct {
	void *key, *data;
	entry_t* next;
} entry_t;

typedef struct {
	struct collection_header;

	hashfunc_pt hashfunc;

	entry_t** table;
} hashtable_t;


#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

hashtable_t ht_create(size_t);
void ht_delete(hashtable_t*);

#pragma endregion

#pragma region --- INCLUDES ---

#pragma endregion

#pragma region --- MACROS ---

#pragma endregion

#pragma region --- TYPEDEFS ---

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

#pragma endregion
#pragma region --- FUNCIONS ---

#pragma endregion
#pragma region ---  ---

#pragma endregion
#pragma region ---  ---

#pragma endregion
#pragma region ---  ---

#pragma endregion
#pragma region --- GENERICS ---

#pragma endregion
//---------------------------------------------------------------------------------------------//
void ht_copy(hashtable_t* dest, hashtable_t* src);
void ht_move(hashtable_t* dest, hashtable_t* src);
void ht_swap(hashtable_t dest, hashtable_t src);
//---------------------------------------------------------------------------------------------//
void ht_insert(hashtable_t container, void* key, void* value);
bool ht_contains(hashtable_t container, void* key);
void* ht_lookup(hashtable_t container, void* key);
//---------------------------------------------------------------------------------------------//

#endif // !HASHTABLE_H
