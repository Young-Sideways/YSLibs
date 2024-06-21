/*******************************************************************************
 *  @file      general.c
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "collection/general.h"

#pragma region --- INCLUDE ---

#include <stdlib.h>

#include "debug.h"
#include "collection/private.h"

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

void* copy(const void* collection) {
    assert(collection);
    return CPH_EXTRACT(collection)->cma.copy_((void*)collection);
}
void* move(void** collection) {
    assert(collection);
    void* result = copy(*collection);
    if (result) {
        delete(collection);
        return result;
    }
    return collection;
}

void delete(void** collection) {
    assert(collection);
    assert(*collection);
    CPH_REF(*collection, header);
    if (header->cma.dtor_)
        header->cma.dtor_(collection);
    free(header);
    *collection = NULL;
}

#pragma endregion

#pragma region --- GETTER / SETTER ---

#define DECL_GET_SET(field)                                                                                                                   \
    void* _collection_private_##field##_get(void* collection) {                                                                               \
        explain_assert(collection, "collection error: invalid arg 'collection'");                                                             \
        explain_assert(CPH_EXTRACT(collection)->caa.field, "collection error: container has no '"#field"' function");                         \
        return (CPH_EXTRACT(collection)->caa.field == &private_collection_function_placeholder_) ? NULL : CPH_EXTRACT(collection)->caa.field; \
    }                                                                                                                                         \
    void _collection_private_##field##_set(void* collection, void* value) {                                                                   \
        explain_assert(collection, "collection error: invalid arg 'collection'");                                                             \
        explain_assert(CPH_EXTRACT(collection)->caa.field, "collection error: container has no '"#field"' function");                         \
        if (CPH_EXTRACT(collection)->caa.field)                                                                                               \
            CPH_EXTRACT(collection)->caa.field = (value ? value : &private_collection_function_placeholder_);                                 \
    }

DECL_GET_SET(comparator_)
DECL_GET_SET(swap_      )
DECL_GET_SET(search_    )
DECL_GET_SET(sort_      )

#undef DECL_GET_SET

#pragma endregion

#pragma region --- FUNCTION ---

bool is_empty(const void* collection) {
    explain_assert(collection, "collection error: invalid arg 'collection'");
    return !(((struct collection_universal_header*)collection)->size);
}

#pragma endregion
