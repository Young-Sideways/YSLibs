/*******************************************************************************
 *  @file      hashtable.c
 *  @brief     Implementation of key-value associative hash container
 *  @attribute associative, non-sortable
 *  @author    Young Sideways
 *  @date      20.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 *  @note      hashtable does not own data on a double reference (example: cstring (char*) etc.)
 *             1. main data pointer invalidation init UB
 *             2. object pointers are different &(char*) != &(char[]) != &("some str")
 *  @bug       stack arg != heap arg of double pointer
 ******************************************************************************/

#include "collection/hashtable.h"

#pragma region --- INCLUDE ---

#include <stdlib.h>
#include <string.h>

#include "collection/private.h"
#include "core.h"
#include "debug.h"
#include "macro/macro.h"

#include "algorithm/comparator.h"

#pragma endregion

#pragma region --- PRIVATE ---

static inline size_t private_hashtable_table_memory_align_(size_t size) {
    size = M_MIN(M_MAX(size, HASHTABLE_SIZE_MIN), HASHTABLE_SIZE_MAX); //!< select size between [ HASHTABLE_SIZE_MIN; HASHTABLE_SIZE_MAX ]
    // fast way to compute most-significant bit of number
    size_t aligned = size | 1;
    for (; size >>= 1; aligned |= size);
    return  aligned; //!< return nearest (2^n - 1) > init_size (7, 15, 31, 63, 127 ...)
}

//static inline double private_hashtable_get_load_factor_(hashtable_t table) {
//    return (double)table->size / (double)table->capacity;
//}

//static inline double private_hashtable_get_max_bucket_load_factor_(hashtable_t table) {
//    ht_entry_t* entries = CPH_EXTRACT(table)->data_;
//    int max_entries = 0;
//    for (int i = 0; i < (int)table->capacity; i++)
//        if (entries[i]) {
//            ht_entry_t entry = entries[i];
//            int current_entries = 0;
//            do {
//                current_entries++;
//            } while ((entry = entry->next));
//            max_entries = M_MAX(current_entries, max_entries);
//        }
//    return (double)max_entries / (double)table->capacity;
//}

#define HT_ENTRY_EXTRACT_KEY(entry) ((entry) + 1)
#define HT_ENTRY_EXTRACT_VALUE(entry, key_size) (((byte*)HT_ENTRY_EXTRACT_KEY(entry)) + key_size)

static inline ht_entry_t private_hashtable_alloc_entry_(
    const void*       key       ,
    size_t            key_size  ,
    const void*       value     ,
    size_t            value_size,
    const ht_entry_t  next       )
{
    ht_entry_t entry = malloc(sizeof(struct ht_entry_t) + key_size + value_size);
    if (entry) {
        entry->next = next;
        memcpy(HT_ENTRY_EXTRACT_KEY(entry), key, key_size);
        memcpy(HT_ENTRY_EXTRACT_VALUE(entry, key_size), value, value_size);
    }
    return entry;
}

static inline bool private_hashtable_valid_(hashtable_t table) {
    return true;
}

void private_hashtable_recursive_delete_() {

}

#pragma endregion

#pragma region --- STATIC ---

static inline void init_(struct collection_universal_header* collection, void** block, int* index) {
    // index -> iterate through
    // block -> hash value

    *block = NULL;
    if (*index == COLLECTION_INVALID_INDEX)
        return;
    if (*index < 0) {
        *index = -1;
        return;
    }
    if (*index >= (int)collection->size) {
        *index = (int)collection->size;
        return;
    }

    CPH_REF(collection, header);
    ht_entry_t* entries = header->data_;
    
    int i = 0;
    for (int bucket = 0; bucket < collection->capacity; bucket++) {
        ht_entry_t entry = entries[bucket];
        while (entry) {
            if (i == *index) {
                *block = HT_ENTRY_EXTRACT_KEY(entry);
                return;
            }
            i++;
            entry = entry->next;
        }
    }
}

static inline void next_(struct collection_universal_header* collection, void** block, int* index) {
    *index = (*index) + 1;
    init_(collection, block, index);
}

static inline void prev_(struct collection_universal_header* collection, void** block, int* index) {
    *index = (*index) - 1;
    init_(collection, block, index);
}

static inline void* copy_(void* collection) {
    return NULL;
    hashtable_t this = collection;
    hashtable_t result = ht_init(this->size, this->key_size, this->element_size, this->hashfunc);
    ht_entry_t* entries = CPH_EXTRACT(collection)->data_;

    for (int bucket = 0; bucket < this->capacity; bucket++) {
        ht_entry_t entry = entries[bucket];
        while (entry) {
            ht_insert(result, HT_ENTRY_EXTRACT_KEY(entry), HT_ENTRY_EXTRACT_VALUE(entry, this->key_size));
            entry = entry->next;
        }
    }
    return (void*)result;
}

static inline void* dtor_(void* collection) {
    return NULL;
    CPH_REF(collection, header);
    ht_entry_t* entries = header->data_;
    for (int i = 0; i < ((struct collection_universal_header*)collection)->size; i++) {
        ht_entry_t entry = entries[i];
        while (entry) {
            ht_entry_t next = entry;
            free(entry);
            entry = next;
        }
    }
    free(entries);
}

#pragma endregion

#pragma region --- DEFAULT ---

hash_t hash(const void* key, size_t size) {
    if (!key || !size)
        return (hash_t)0;
    hash_t hash = 5381;
    ubyte* ptr = (ubyte*)key;
    for (int i = 0; i < (int)size; i++)
        hash = ((hash << 5) + hash) ^ ptr[i];
    return hash;
}
hash_t str_hash(const void* key, size_t size) {
    YSL_UNUSED(size);
    if (!key)
        return (hash_t)0;
    const char* str = (char*)*(void**)key;
    hash_t hash = 5381;
    while (*str)
        hash = ((hash << 5) + hash) ^ *(str++);
    return hash;
}

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

hashtable_t ht_init(size_t size, size_t key_size, size_t value_size, hashfunc_t hashfunc) {
    explain_assert(key_size, "collection error: key size can't be NULL");
    size = private_hashtable_table_memory_align_(size);
    struct hashtable_t* result = NULL;
    struct collection_private_header* block = (struct collection_private_header*)malloc(sizeof(struct collection_private_header) + sizeof(struct hashtable_t));
    if (block) {
        *block = alloc_cph(
            alloc_caa(NULL, NULL, NULL, NULL),
            alloc_cia(&init_, &next_, &prev_),
            alloc_cma(&copy_, &dtor_),
            NULL);

        result = (struct hashtable_t*)(block + 1);
        *result = (struct hashtable_t){
            alloc_cuh(size, 0U, value_size),
            .hashfunc = M_ISNULL(hashfunc, &hash),
            .key_size = key_size
        };

        if (!(block->data_ = calloc(size, sizeof(ht_entry_t))))
            goto HT_ERR_TABLE_ALLOC;
    }
    return (hashtable_t)result;

HT_ERR_TABLE_ALLOC:
    free(block);
    return (hashtable_t)NULL;
}

#pragma endregion

#pragma region --- FUNCION ---

void set_hasher(hashtable_t table, const hashfunc_t hashfunc) {
    explain_assert(table, "collection error: hash function can't be NULL");
    explain_assert(hashfunc, "collection error: hash function can't be NULL");
    struct hashtable_t* _table = (struct hashtable_t*)table;
    _table->hashfunc = M_ISNULL(hashfunc, &hash);
}

void ht_insert(hashtable_t table, const void* key, const void* value) {
    if (table->size >= (size_t)((double)table->capacity * HASHTABLE_MAX_LOAD_FACTOR)) {
        size_t new_capacity = private_hashtable_table_memory_align_(table->capacity + 1);
        if (new_capacity > HASHTABLE_SIZE_MAX)
            return;
        ht_entry_t* new_entries = calloc(new_capacity, sizeof(ht_entry_t));
        if (!new_entries)
            return;
        ht_entry_t* old_entries = CPH_EXTRACT(table)->data_;
        (((struct hashtable_t*)table)->size) = 0;
        (((struct hashtable_t*)table)->capacity) = new_capacity;
        CPH_EXTRACT(table)->data_ = new_entries;
        for (int i = 0; i < table->capacity; i++) {
            ht_entry_t entry = old_entries[i];
            if (entry) {
                while (entry) {
                    ht_entry_t next = entry->next;
                    ht_insert(table, HT_ENTRY_EXTRACT_KEY(entry), HT_ENTRY_EXTRACT_VALUE(entry, table->key_size));
                    free(entry);
                }
            }
        }
        free(old_entries);
    }
    ht_entry_t* entries = (ht_entry_t*)CPH_EXTRACT(table)->data_;
    hash_t calculated = table->hashfunc(key, table->key_size);
    ht_entry_t located = entries[(table->capacity - 1) & calculated];
    if (located) {
        if (((comparator_t)CPH_EXTRACT(table)->caa.comparator_)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
            return;
        while (located->next) {
            located = located->next;
            if (((comparator_t)CPH_EXTRACT(table)->caa.comparator_)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
                return;
        }
        located->next = private_hashtable_alloc_entry_(key, table->key_size, value, table->element_size, NULL);
    }
    else
        entries[(table->capacity - 1) & calculated] = private_hashtable_alloc_entry_(key, table->key_size, value, table->element_size, NULL);
    (((struct hashtable_t*)table)->size)++;
}
void ht_erase(hashtable_t table, const void* key) {
    ht_entry_t* entries = (ht_entry_t*)CPH_EXTRACT(table)->data_;
    hash_t calculated = table->hashfunc(key, table->key_size);
    ht_entry_t located = entries[(table->capacity - 1) & calculated];
    if (located) {
        if (((comparator_t)CPH_EXTRACT(table)->caa.comparator_)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0) {
            entries[(table->capacity - 1) & calculated] = located->next;
            free(located);
            ((struct hashtable_t*)table)->size--;
            return;
        }
        while (located->next) {
            if (((comparator_t)CPH_EXTRACT(table)->caa.comparator_)(HT_ENTRY_EXTRACT_KEY(located->next), key, table->key_size) == 0) {
                ht_entry_t found = located->next;
                located->next = found->next;
                free(found);
                ((struct hashtable_t*)table)->size--;
                return;
            }
            located = located->next;
        }
    }
}

bool ht_contains(const hashtable_t table, const void* key) {
    ht_entry_t* entries = (ht_entry_t*)CPH_EXTRACT(table)->data_;
    hash_t calculated = table->hashfunc(key, table->key_size);
    ht_entry_t located = entries[(table->capacity - 1) & calculated];

    while (located) {
        if (((comparator_t)CPH_EXTRACT(table)->caa.comparator_)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
            return true;
        located = located->next;
    }
    return false;
}

void* ht_lookup(const hashtable_t table, const void* key) {
    ht_entry_t* entries = (ht_entry_t*)CPH_EXTRACT(table)->data_;
    hash_t calculated = table->hashfunc(key, table->key_size);
    ht_entry_t located = entries[(table->capacity - 1) & calculated];

    while (located) {
        if (((comparator_t)CPH_EXTRACT(table)->caa.comparator_)(HT_ENTRY_EXTRACT_KEY(located), key, table->key_size) == 0)
            break;
        located = located->next;
    }
    if (located)
        return HT_ENTRY_EXTRACT_VALUE(located, table->key_size);
    return NULL;
}

#pragma endregion
