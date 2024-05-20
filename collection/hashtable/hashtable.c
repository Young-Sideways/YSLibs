/*******************************************************************************
 *  @file      hashtable.c
 *  @brief     Implementation of key-value associative hash container
 *  @attribute associative, non-sortable
 *  @author    Young Sideways
 *  @date      20.05.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/
#include "hashtable.h"

#pragma region --- INCLUDE ---

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../private.h"
#include "../../core/debug.h"
#include "../../core/macro/macro.h"

#include "../../algorithm/comparator.h"

#pragma endregion

#pragma region --- STATIC ---

static inline void _init(struct collection_universal_header* collection, void** block, int* index) {
    
}

static inline void _next(struct collection_universal_header* collection, void** block, int* index) {
    
}

static inline void _prev(struct collection_universal_header* collection, void** block, int* index) {
    
}

static inline void* _copy(void* collection) {
    
}

static inline void* _dtor(void* collection) {

}

#pragma endregion

#pragma region --- PRIVATE ---

static inline size_t _private_hashtable_table_memory_align(size_t size) {
    size = M_MIN(M_MAX(size, HASHTABLE_SIZE_MIN), HASHTABLE_SIZE_MAX); //!< select size between [ HASHTABLE_SIZE_MIN; HASHTABLE_SIZE_MAX ]
    return (size_t)pow(2.0, ceil(log2((double)size)));  //!< return nearest pow of 2, greater than init_size
}

static inline double _private_hashtable_get_load_factor(hashtable_t table) {
    return (double)table->size / (double)table->capacity;
}

static inline double _private_hashtable_get_max_bucket_load_factor(hashtable_t table) {
    ht_entry_t* entries = CPH_EXTRACT(table)->_data;
    int max_entries = 0;
    for (int i = 0; i < table->capacity; i++)
        if (entries[i]) {
            ht_entry_t entry = entries[i];
            int current_entries = 0;
            do {
                current_entries++;
            } while (entry = entry->next);
            max_entries = M_MAX(current_entries, max_entries);
        }
    return (double)max_entries / (double)table->capacity;
}

#define HT_ENTRY_EXTRACT_KEY(entry) ((entry) + 1)
#define HT_ENTRY_EXTRACT_VALUE(entry, key_size) (((byte*)HT_ENTRY_EXTRACT_KEY(entry)) + key_size)

static inline ht_entry_t _private_hashtable_alloc_entry(
    _IN           const void*      key, 
    _IN           size_t           key_size, 
    _IN           const void*      value, 
    _IN           size_t           value_size, 
    _IN _NULLABLE const ht_entry_t next)
{
    ht_entry_t entry = malloc(sizeof(struct ht_entry_t) + key_size + value_size);
    if (entry) {
        entry->next = next;
        memcpy(HT_ENTRY_EXTRACT_KEY(entry), key, key_size);
        memcpy(HT_ENTRY_EXTRACT_VALUE(entry, key_size), value, value_size);
    }
    return entry;
}

static inline bool _private_hashtable_valid(hashtable_t table) {
    
}

void _private_hashtable_recursive_delete() {

}

#pragma endregion

#pragma region --- DEFAULT ---

hash_t hash(_IN const void* key, _IN size_t size) {
    if (!key || !size)
        return (hash_t)0;
    hash_t hash = 5381;
    ubyte* ptr = (ubyte*)key;
    for (int i = 0; i < size; i++)
        hash = ((hash << 5) + hash) ^ ptr[i];
    return hash;
}
hash_t str_hash(_IN const void* key, _IN size_t size) {
    UNUSED(size);
    if (!key)
        return (hash_t)0;
    char* str = (char*)key;
    hash_t hash = 5381;
    while (*str)
        hash = ((hash << 5) + hash) ^ *(str++);
    return hash;
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

hashtable_t ht_init(_IN size_t size, _IN size_t key_size, _IN size_t value_size, _IN _NULLABLE hashfunc_pt hashfunc) {
    explain_assert(key_size, "collection error: key size can't be NULL");
    size = _private_hashtable_table_memory_align(size);
    struct hashtable_t* result = NULL;
    struct collection_private_header* block = (struct collection_private_header*)malloc(sizeof(struct collection_private_header) + sizeof(struct hashtable_t));
    if (block) {
        *block = alloc_cph(
            alloc_caa(NULL, NULL, NULL, NULL),
            alloc_cia(&_init, &_next, &_prev),
            alloc_cma(&_copy, &_dtor),
            NULL);

        result = (struct hashtable_t*)(block + 1);
        *result = (struct hashtable_t){
            alloc_cuh(size, 0U, value_size),
            .hashfunc = M_ISNULL(hashfunc, &hash),
            .key_size = key_size
        };

        if (!(block->_data = calloc(size, sizeof(ht_entry_t))))
            goto HT_ERR_TABLE_ALLOC;
    }
    return (hashtable_t)result;

HT_ERR_TABLE_ALLOC:
    free(block);
    return (hashtable_t)NULL;
}

#pragma endregion

#pragma region --- FUNCION ---

void ht_insert(_IN hashtable_t table, _IN const void* key, _IN const void* value) {
    // Ïýïýýýýö...
    // 50%
    ht_entry_t* entries = (ht_entry_t*)CPH_EXTRACT(table)->_data;
    hash_t calculated = table->hashfunc(key, table->key_size);
    ht_entry_t located = entries[(table->capacity - 1) & calculated];
    if (located) {
        if (((comparator_pt)CPH_EXTRACT(table)->caa._comp)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
            return;
        while (located->next) {
            located = located->next;
            if (((comparator_pt)CPH_EXTRACT(table)->caa._comp)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
                return;
        }
        located->next = _private_hashtable_alloc_entry(key, table->key_size, value, table->element_size, NULL);
    }
    else
        entries[(table->capacity - 1) & calculated] = _private_hashtable_alloc_entry(key, table->key_size, value, table->element_size, NULL);
}
void ht_erase(_IN hashtable_t table, _IN const void* key) {
    
}

bool ht_contains(_IN const hashtable_t table, _IN const void* key) {
    ht_entry_t* entries = (ht_entry_t*)CPH_EXTRACT(table)->_data;
    hash_t calculated = table->hashfunc(key, table->key_size);
    ht_entry_t located = entries[(table->capacity - 1) & calculated];

    while (located) {
        if (((comparator_pt)CPH_EXTRACT(table)->caa._comp)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
            return true;
        located = located->next;
    }
    return false;
}
void* ht_lookup(_IN const hashtable_t table, _IN const void* key) {

}

#pragma endregion

#pragma region ---  ---



#pragma endregion
