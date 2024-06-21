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
    int a[] = { VA_SEQ(4,5,7,12) };
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
