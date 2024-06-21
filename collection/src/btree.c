/*******************************************************************************
 * @file      btree.h
 * @author    Young Sideways
 * @brief     tree collection
 * @date      17.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "collection/btree.h"

#pragma region --- INCLUDE ---

#include <stdlib.h>
#include <string.h>

#include "collection/private.h"
#include "core.h"
#include "debug.h"
#include "macro/macro.h"

#include "algorithm/comparator.h"

#define LOG_MODULE_NAME "collection"
#include "util/log.h"

#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct btree_node_s {
    struct btree_node_s* left ;
    struct btree_node_s* right;
    int                  count;
    void*                value;
} *btree_node_t;

#pragma endregion

#pragma region --- PRIVATE ---

static inline bool private_node_is_valid(btree_node_t node) {
    return node && (node->count > 0);
}

static inline btree_node_t private_alloc_node_(btree_node_t parent, size_t element_size, const void* value) {
    explain_assert(element_size, "collection error: invalid arg 'element_size'");
    explain_assert(value, "collection error: invalid arg 'value'");

    btree_node_t node = malloc(sizeof(struct btree_node_s));
    if (!node)
        goto ERR_MEM_NODE;

    node->value = malloc(element_size);
    if (!node->value)
        goto ERR_MEM_VALUE;

    memcpy(node->value, value, element_size);
    node->left = NULL;
    node->right = NULL;
    node->count = 1;
    return node;


ERR_MEM_VALUE:
    error("btree: memory allocation for value");
    free(node);
    return NULL;
ERR_MEM_NODE:
    error("btree: memory allocation for node");
    return NULL;
}

static inline void private_delete_node_(btree_node_t parent, btree_node_t node) {
    explain_assert(private_node_is_valid(node), "collection error: invalid arg 'node'");
    if (parent) {
        explain_assert(parent->count > 0, "collection error: invalid arg 'node'");
        btree_node_t* from_parent = (parent->left == node)  ? &parent->left : (
                                    (parent->right == node) ? &parent->right:
                                    NULL);
        if (from_parent)
            *from_parent = NULL;
        else
            warn("btree: wrong parent pointer. node [ %#zX ], parent: [ l: %#zX, r: %#zX ]", (size_t)node, (size_t)parent->left, (size_t)parent->right);
    }
    if (node->left)
        private_delete_node_(node, node->left);
    if (node->right)
        private_delete_node_(node, node->right);
    free(node);
}

static inline void* private_find_node_value_(btree_node_t root, const void* value, const size_t element_size, const comparator_t comp_) {
    explain_assert(private_node_is_valid(root), "collection error: invalid arg 'root'");
    explain_assert(element_size, "collection error: invalid arg 'element_size'");
    explain_assert(value, "collection error: invalid arg 'value'");
    explain_assert(comp_, "collection error: invalid arg 'comp_'");

    if (!comp_(root->value, value, element_size))
        return root->value;

    void* left  = NULL;
    void* right = NULL;
    if (root->left)
        left = private_find_node_value_(root->left, value, element_size, comp_);
    if (root->right)
        right = private_find_node_value_(root->right, value, element_size, comp_);

    if (!left ^ !right) {
        warn("btree: left and right leaf have same value");
        return NULL;
    }
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
    btree_node_t entries = header->data_;

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
}

static inline void* dtor_(void* collection) {
    return NULL;
}

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

btree_t btree_init(size_t element_size) {
    explain_assert(element_size, "collection error: element size can't be NULL");
    struct btree_s* result = NULL;
    struct collection_private_header* block = (struct collection_private_header*)malloc(sizeof(struct collection_private_header) + sizeof(struct btree_s));
    if (block) {
        *block = alloc_cph(
            alloc_caa(NULL, NULL, NULL, NULL),
            alloc_cia(&init_, &next_, &prev_),
            alloc_cma(&copy_, &dtor_),
            NULL);

        result = (struct btree_s*)(block + 1);
        *result = (struct btree_s){
                alloc_cuh(0U, 0U, element_size)
        };
    }
    return (btree_t)result;
}

#pragma endregion

#pragma region --- FUNCTION ---

bool btree_contains(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");

}
int btree_count(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");

}
void btree_insert(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");

}
void btree_erase(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");

}
void btree_rebalance(btree_t btree) {
    explain_assert(btree, "collection error: invalid arg 'btree'");

}

#pragma endregion
