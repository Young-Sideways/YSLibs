/*******************************************************************************
 *  @file      general.c
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "general.h"

#pragma region --- INCLUDE ---

#include "private.h"
#include <stdlib.h>

#include <stdarg.h>

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

void* copy(_IN const void* collection) {
    assert(collection);
    return CPH_EXTRACT(collection)->cma._copy((void*)collection);
}
void* move(_INOUT void** collection) {
    assert(collection);
    void* result = copy(*collection);
    if (result) {
        delete(collection);
        return result;
    }
    return collection;
}

void delete(_INOUT void** collection) {
    assert(collection);
    assert(*collection);
    CPH_REF(*collection, header);
    if (header->cma._dtor)
        header->cma._dtor(collection);
    free(header);
    *collection = NULL;
}

#pragma endregion

#pragma region --- GETTER / SETTER ---

#define DECL_GET_SET(field)                                                                                                 \
    void* _collection_private_##field##_get(void* collection) {                                                             \
        assert(collection);                                                                                                 \
        explain_assert(CPH_EXTRACT(collection)->caa.field, "collection error: container has no " #field " funtion");        \
        return (CPH_EXTRACT(collection)->caa.field == &__function_placeholder) ? NULL : CPH_EXTRACT(collection)->caa.field; \
    }                                                                                                                       \
    void _collection_private_##field##_set(void* collection, void* value) {                                                 \
        assert(collection);                                                                                                 \
        explain_assert(CPH_EXTRACT(collection)->caa.field, "collection error: container has no " #field " funtion");        \
        if (CPH_EXTRACT(collection)->caa.field)                                                                             \
            CPH_EXTRACT(collection)->caa.field = value;                                                                     \
    }

DECL_GET_SET(_comp)
DECL_GET_SET(_swap)
DECL_GET_SET(_srch)
DECL_GET_SET(_sort)

#undef DECL_GET_SET

#pragma endregion
