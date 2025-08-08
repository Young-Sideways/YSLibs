/*******************************************************************************
 * @file      menum.h
 * @author    Young Sideways
 * @brief     Meta enum declaration
 * @date      13.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef MENUM_H_
#define MENUM_H_


#include <assert.h>
#include <string.h>
#include <stddef.h>


#include <macro/arg.h>
#include <macro/exec.h>
#include <macro/sequence.h>


#define MEN(name, ...)                                                                                                        \
    enum __MEN_IMPL_NAME name __MEN_IMPL_TYPE name {                                                                          \
        __MEN_IMPL_UNFOLD(__VA_ARGS__)                                                                                        \
    };                                                                                                                        \
    static const char* VA_EXPAND(M_DEFER(M_CAT)(__men_impl_to_str_, __MEN_IMPL_NAME name))(enum __MEN_IMPL_NAME name var) {   \
        __MEN_IMPL_DECL_TO_STR(__VA_ARGS__);                                                                                  \
    }                                                                                                                         \
    static enum __MEN_IMPL_NAME name VA_EXPAND(M_DEFER(M_CAT)(__men_impl_from_str_, __MEN_IMPL_NAME name))(const char* var) { \
        __MEN_IMPL_DECL_FROM_STR(__VA_ARGS__);                                                                                \
    }

#define MEN_TS(type, var) __men_impl_to_str_##type((enum type)var)
#define MEN_FS(type, name) __men_impl_from_str_##type(name)

#define MEN_FLAGS(name, ...)                                                                                                    \
    enum __MEN_IMPL_NAME name __MEN_IMPL_TYPE name {                                                                            \
        __MEN_F_IMPL_UNFOLD(__VA_ARGS__)                                                                                        \
    };                                                                                                                          \
    static const char* VA_EXPAND(M_DEFER(M_CAT)(__men_f_impl_to_str_, __MEN_IMPL_NAME name))(enum __MEN_IMPL_NAME name var) {   \
        __MEN_F_IMPL_DECL_TO_STR(__VA_ARGS__);                                                                                  \
    }                                                                                                                           \
    static enum __MEN_IMPL_NAME name VA_EXPAND(M_DEFER(M_CAT)(__men_impl_f_from_str_, __MEN_IMPL_NAME name))(const char* var) { \
        __MEN_F_IMPL_DECL_FROM_STR(__VA_ARGS__);                                                                                \
    }

#pragma region --- IMPL ---

#define __MEN_IMPL_NAME(name, ...) name
#define __MEN_IMPL_TYPE(name, ...) __VA_OPT__(: VA_ARG_FIRST(__VA_ARGS__))


#define __MEN_IMPL_UNFOLD_HELPER(name, ...) name __VA_OPT__(= __VA_ARGS__)
#define __MEN_IMPL_UNFOLD(...) VA_EXEC1(M_APPLY, __MEN_IMPL_UNFOLD_HELPER, __VA_ARGS__)


#define __MEN_IMPL_DECL_TO_STR_HELPER_CASE(name, ...) case name: return #name
#define __MEN_IMPL_DECL_TO_STR(...)                                                              \
    switch (var) {                                                                               \
        VA_SEQ( M_SEMI() , VA_EXEC1(M_APPLY, __MEN_IMPL_DECL_TO_STR_HELPER_CASE , __VA_ARGS__)); \
        default: assert(NULL && "Unexpected arg value.");                                        \
    }


#define __MEN_IMPL_DECL_FROM_STR_HELPER_IF(name, ...) if (strcmp(var, #name) == 0) return name; else
#define __MEN_IMPL_DECL_FROM_STR(...)                                                  \
        VA_SEQ( , VA_EXEC1(M_APPLY, __MEN_IMPL_DECL_FROM_STR_HELPER_IF , __VA_ARGS__)) \
        assert(NULL && "Unexpected arg value.");                                       \
        unreachable();

#pragma endregion


#endif // !MENUM_H_
