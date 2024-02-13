#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "general.h"

#define HASHTABLE_SIZE_MIN 0u
#define HASHTABLE_SIZE_MAX INT_MAX

size_t hash(register const char* key, size_t key_size) {
	size_t hash = 5381;
	for (char* end = key + key_size; key < end; key++)
		hash = ((hash << 5) + hash) ^ *key;
	return hash;
}
inline size_t shash(register const char* str) {
	size_t hash = 5381;
	while (*str)
		hash = ((hash << 5) + hash) ^ *(str++);
	return hash;
}

typedef struct hashtable {
	size_t 
		size, 
		element_size, 
		capacity;

	comparison_t comparator;
	hashfunc_t hashfunc;

	struct entry_t *table;
} *hashtable_t;

typedef struct entry {
	void *key, *data;
	entry_t next;
} *entry_t;


typedef uint32_t hash_t;
typedef hash_t(*hashfunc_t)(void*);

//---------------------------------------------------------------------------------------------//
_inl_ hashtable_t ht_create(size_t);
_inl_ void ht_delete(hashtable_t*);
//---------------------------------------------------------------------------------------------//
void ht_copy(hashtable_t dest, hashtable_t src);
void ht_move(hashtable_t dest, hashtable_t src);
void ht_swap(hashtable_t dest, hashtable_t src);
//---------------------------------------------------------------------------------------------//
void ht_insert(hashtable_t container, void* key, void* value);
int ht_contains(hashtable_t container, void* key);
void* ht_lookup(hashtable_t container, void* key);
//---------------------------------------------------------------------------------------------//

#endif // !HASHTABLE_H
