/*******************************************************************************
 *  @file      tuple.h
 *  @brief     tuple type
 *  @author    Young Sideways
 *  @date      18.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#if (0) // Зачатки tuple
#define _SEQ_PRINTERS

#include "core/macro/varidatic.h"
#include "core/macro/reverse.h"
#include "core/macro/sequence.h"
#include "core/macro/exec.h"


typedef struct { intptr_t offset; size_t size; } field_spec_t;

#define FOLD_ADD_PARAM__(container_type, type, name) { (intptr_t)M_OFFSETOF(container_type, name), sizeof(type) }
#define FOLD_ADD_PARAM_(container_type, ...) FOLD_ADD_PARAM__(container_type, __VA_ARGS__)
#define FOLD_ADD_PARAM(container_type, field) FOLD_ADD_PARAM_(container_type, M_CONCAT(SPEC_,field))

#define FIELD_ADD_PARAM(type, name) type name
#define SPEC_ADD_PARAM(type, name) type, name

#define SETTINGS_TYPEDEF(name, ...)                                                         \
typedef struct {                                                                            \
    VA_SEQ_SEMI(VA_EXEC1(M_CONCAT, FIELD_, __VA_ARGS__))                                    \
} name;                                                                                     \
                                                                                            \
const field_spec_t name##_field_specs[] = {                                                 \
    VA_EXEC1(FOLD_ADD_PARAM, name, __VA_ARGS__)                                             \
};                                                                                          \
                                                                                            \
const size_t name##_field_specs_size = VA_NARG(__VA_ARGS__) // ; static_assert(VA_NARG(__VA_ARGS__) < FLASH_RW_CODE, "too many params (> 255) for settings")



SETTINGS_TYPEDEF(setting_t,
    ADD_PARAM(float, p1),
    ADD_PARAM(int, p2)
);
#endif

#ifndef _TUPLE_H_
#define _TUPLE_H_

#pragma once

#pragma region --- INCLUDE ---
#pragma endregion
#pragma region --- MACRO ---
#pragma endregion
#pragma region --- TYPEDEF ---
#pragma endregion
#pragma region --- CONSTRUCTOR / DESTRUCTOR ---
#pragma endregion
#pragma region --- FUNCION ---
#pragma endregion
#pragma region ---  ---
#pragma endregion
#pragma region --- GENERIC ---
#pragma endregion
#endif // !_TUPLE_H_
