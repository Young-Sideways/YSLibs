/*******************************************************************************
 * @file      menum.h
 * @author    Young Sideways
 * @brief     Meta enum declaration
 * @date      13.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef MENUM_H_
#define MENUM_H_

#pragma once

#pragma region --- INCLUDE ---

#include <macro/core.h>
#include <macro/sequence.h>
#include <macro/exec.h>

#pragma endregion

#pragma region --- MACRO ---

#define __MENUM_NAME_POINT(name) case name: return M_STR(name)
#define __MENUM_VALUE_POINT(string, name)   \
    if (strcmp(M_STR(name), string) == 0)   \
        return name;                        \
    else

#define __MENUM_ENUM_HELPER1(arg) VA_ARG_FIRST arg = VA_ARG_LAST arg
#define __MENUM_ENUM_HELPER(...) VA_EXEC(__MENUM_ENUM_HELPER1, __VA_ARGS__)

#define __MENUM_ITS_HELPER2(...) VA_EXEC(__MENUM_NAME_POINT, __VA_ARGS__)
#define __MENUM_ITS_HELPER1(...) __MENUM_ITS_HELPER2(VA_EXEC1(M_CAT, VA_ARG_FIRST, __VA_ARGS__))
#define __MENUM_ITS_HELPER(...)  M_DEFER(VA_SEQ)(;, __MENUM_ITS_HELPER1(__VA_ARGS__))

#define __MENUM_STI_HELPER1(...) VA_SEQ( , __VA_ARGS__)
#define __MENUM_STI_HELPER(string, ...) __MENUM_STI_HELPER1(VA_EXEC1(__MENUM_VALUE_POINT, string, __VA_ARGS__))

#define MENUM(name, ...)                                                          \
    typedef enum name { __MENUM_ENUM_HELPER(__VA_ARGS__) } name;                  \
    static inline const char* M_CAT(name, __str_table)(int var) {                 \
        switch (var) {                                                            \
            VA_EXPAND(__MENUM_ITS_HELPER(__VA_ARGS__));                           \
            defaut: return "'undefined'";                                         \
        };                                                                        \
    };                                                                            \
    static int M_CAT(name, __value_table)(const char* string) {                   \
        __MENUM_STI_HELPER(string, VA_EXEC1(M_CAT, VA_ARG_FIRST, __VA_ARGS__))    \
        assert(0 & "MENUM error: value not present in enum");                         \
    }


// type must be specified at preproccess-time !!!
#define ENUM_TO_STR(type, var) M_CAT(type, __str_table)( (int)var )
#define STR_TO_ENUM(type, string) (type) M_CAT(type, __value_table)((const char*)string)


#define __MENUM_ARG_GET_NAME(arg) 

#pragma endregion

#endif // !MENUM_H_
