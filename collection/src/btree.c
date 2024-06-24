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
#define LOG_SUBMODULE_NAME "btree"
#define LOG_MODULE_SEPARATE (true)

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
    if (!node)
        return;
    if (parent) {
        explain_assert(parent->count > 0, "collection error: invalid arg 'node'");
        btree_node_t* from_parent = (parent->left == node)  ? &parent->left : (
                                    (parent->right == node) ? &parent->right:
                                    NULL);
        if (from_parent)
            *from_parent = NULL;
        else
            warn("wrong parent pointer. node [ %#zX ], parent: [ l: %#zX, r: %#zX ]", (size_t)node, (size_t)parent->left, (size_t)parent->right);
    }
    if (node->left)
        private_delete_node_(node, node->left);
    if (node->right)
        private_delete_node_(node, node->right);
    free(node->value);
    free(node);
}

static inline btree_node_t private_find_node_(btree_node_t root, const void* value, const size_t element_size, const comparator_t comp_) {
    explain_assert(element_size, "collection error: invalid arg 'element_size'");
    explain_assert(value, "collection error: invalid arg 'value'");
    explain_assert(comp_, "collection error: invalid arg 'comp_'");

    if (!root)
        return NULL;

    btree_node_t node = NULL;
    int compared = comp_(root->value, value, element_size);
    if (compared < 0)
        node = private_find_node_(root->left, value, element_size, comp_);
    else if (compared > 0)
        node = private_find_node_(root->right, value, element_size, comp_);
    else
        return root;
    return node;
}
static inline btree_node_t private_find_parent_(btree_node_t root, btree_t parent, const void* value, const size_t element_size, const comparator_t comp_) {
    explain_assert(element_size, "collection error: invalid arg 'element_size'");
    explain_assert(value, "collection error: invalid arg 'value'");
    explain_assert(comp_, "collection error: invalid arg 'comp_'");

    if (!root)
        return NULL;

    btree_node_t node = NULL;

    int compared = comp_(root->value, value, element_size);
    if (compared < 0)
        node = private_find_parent_(root->left, root, value, element_size, comp_);
    else if (compared > 0)
        node = private_find_parent_(root->right, root, value, element_size, comp_);
    else
        return parent;
    return node;
}

static inline void private_add_node_(btree_node_t* root, const void* value, const size_t element_size, const comparator_t comp_) {
    if (!*root)
        *root = private_alloc_node_(NULL, element_size, value);
    else {
        int compared = comp_((*root)->value, value, element_size);
        if (compared < 0) {
            private_add_node_(&((*root)->left), value, element_size, comp_);
        }
        else if (compared > 0) {
            private_add_node_(&((*root)->right), value, element_size, comp_);
        }
        else
            (*root)->count++;
    }
}

static inline void private_recursive_add_(btree_node_t root, btree_node_t nodes, const size_t element_size, const comparator_t comp_) {
    if (!nodes)
        return;
    private_add_node_(root, nodes->value, element_size, comp_);
    private_recursive_add_(root, nodes->left, element_size, comp_);
    private_recursive_add_(root, nodes->right, element_size, comp_);
}

static inline btree_node_t private_iterate_through(btree_node_t root, const int count, int* index) {
    if (!root)
        return NULL;

    if (*index <= count && (*index + root->count - 1) >= count)
        return root;

    *index = *index + root->count;

    btree_node_t node = NULL;
    if (node = private_iterate_through(root->left, count, index))
        return node;
    if (node = private_iterate_through(root->right, count, index))
        return node;
    return NULL;
}

static inline void private_erase(btree_node_t root, const void* value, const size_t element_size, const comparator_t comp_) {

}
#pragma endregion

#pragma region --- STATIC ---

static inline void init_(struct collection_universal_header* collection, void** block, int* index) {
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

    int i = 0;
    CPH_REF(collection, header);
    btree_node_t entries = header->data_;
    btree_node_t found = private_iterate_through(entries, *index, &i);
    if (found)
        *block = found->value;
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
    btree_t tree = collection;
    CPH_REF(tree, header);
    private_delete_node_(header->data_, NULL);
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
    CPH_REF(btree, header);
    return private_find_node_(header->data_, value, btree->element_size, header->caa.comparator_) != NULL;
}
int btree_count(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");
    CPH_REF(btree, header);
    btree_node_t node = private_find_node_(header->data_, value, btree->element_size, header->caa.comparator_);
    if (node)
        return node->count;
    return 0;
}
void btree_insert(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");
    struct btree_s *from = btree;
    CPH_REF(btree, header);
    private_add_node_(&(header->data_), value, btree->element_size, header->caa.comparator_);
    from->size++;
}
void btree_erase(btree_t btree, const void* value) {
    explain_assert(btree, "collection error: invalid arg 'btree'");
    explain_assert(value, "collection error: invalid arg 'value'");

    CPH_REF(btree, header);
    btree_node_t node = private_find_node_(header->data_, value, btree->element_size, header->caa.comparator_);
    if (node) {
        if (node->count > 1)
            node->count--;
        else {
            btree_node_t parent = private_find_parent_(header->data_, NULL, value, btree->element_size,header->caa.comparator_);
            if (parent) {
                if (parent->left == node)
                    parent->left = NULL;
                else if (parent->right == node)
                    parent->right = NULL;
                else
                    return;
                private_recursive_add_(header->data_, node, btree->element_size, header->caa.comparator_);
                private_delete_node_(NULL, node);
            }
        }
    }
}

#pragma endregion
