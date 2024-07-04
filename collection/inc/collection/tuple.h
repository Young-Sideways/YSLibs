/*******************************************************************************
 * @file      tuple.h
 * @author    Young Sideways
 * @brief     tuple collection
 * @date      21.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef TUPLE_H_
#define TUPLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include "macro/exec.h"
#include "macro/sequence.h"
#include "collection/general.h"

#pragma endregion

#pragma region --- MACRO ---

#define M_ARR_WRAP(arg) (typeof(arg)[1]){arg}

#define make_tuple(...) tpl_init(                                               \
    VA_NARG(__VA_ARGS__),                                                       \
    (size_t[VA_NARG(__VA_ARGS__)]){ VA_EXEC0(sizeof, __VA_ARGS__), (size_t)0 }, \
    VA_EXEC0((void*)M_ARR_WRAP, __VA_ARGS__)               \
)

#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct tuple_s {
    struct collection_universal_header;
}* tuple_t;

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

tuple_t tpl_init(size_t arg_count, size_t total_mem_size, size_t* sizes, void** values) {
    return NULL;
}

#pragma endregion

#pragma region --- FUNCTION ---

void* tpl_at(int index);
void* tpl_pack(tuple_t tuple, void* dst);

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#endif // !TUPLE_H_

#if (0) // tuple pre implementation tuple

typedef struct { intptr_t offset; size_t size; } field_spec_t;

#define FOLD_ADD_PARAM__(container_type, type, name) { (intptr_t)M_OFFSETOF(container_type, name), sizeof(type) }
#define FOLD_ADD_PARAM_(container_type, ...) FOLD_ADD_PARAM__(container_type, __VA_ARGS__)
#define FOLD_ADD_PARAM(container_type, field) FOLD_ADD_PARAM_(container_type, M_CAT(SPEC_,field))

#define FIELD_ADD_PARAM(type, name) type name
#define SPEC_ADD_PARAM(type, name) type, name

#define SETTINGS_TYPEDEF(name, ...)                                                         \
typedef struct {                                                                            \
    VA_SEQ_SEMI(VA_EXEC1(M_CAT, FIELD_, __VA_ARGS__))                                    \
} name;                                                                                     \
                                                                                            \
const field_spec_t name##_field_specs[] = {                                                 \
    VA_EXEC1(FOLD_ADD_PARAM, name, __VA_ARGS__)                                             \
};                                                                                          \
                                                                                            \
const size_t name##_field_specs_size = VA_NARG(__VA_ARGS__)



SETTINGS_TYPEDEF(setting_t,
    ADD_PARAM(float, p1),
    ADD_PARAM(int, p2)
);
#endif
