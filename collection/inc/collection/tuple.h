 /*******************************************************************************
 * @file      tuple.h
 * @author    Young Sideways
 * @brief     tuple collection
 * @date      21.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_TUPLE_H_
#define C_TUPLE_H_


#ifdef C_GENERIC_H_
#   error Container library headers must be placed before <collection/generic.h> header
#endif


#include "general.h"

#include <macro/exec.h>


#pragma region --- MACRO ---


#define tpl_ctor(...)                                         \
    (tpl_ctor)(                                               \
        VA_COUNT(__VA_ARGS__),                                \
        (__tpl_args){                                         \
            VA_EXEC(0, __TPL_CTOR_TRANSFORM_ARG, __VA_ARGS__) \
        }                                                     \
    )


#define __TPL_CTOR_TRANSFORM_ARG(arg) { (void*)(YSL_TYPEOF_UNQUAL(arg)[1]){ arg } , sizeof(arg) }

#pragma endregion


typedef struct __tpl_arg { void* arg; size_t size; } __tpl_args[];
typedef struct {}* tuple_t;


#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

tuple_t (tpl_ctor)(size_t count, __tpl_args values);
tuple_t (tpl_dtor)(tuple_t* tuple);

#pragma endregion

#pragma region --- FUNCTION ---

YSL_API void*    (tpl_at)  (c_index_t index);
YSL_API c_size_t (tpl_size)(tuple_t tuple);

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#endif // !C_TUPLE_H_

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
