/*******************************************************************************
 *  @file      string.h
 *  @brief     C compatible dynamic string
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef STRING_H_
#define STRING_H_

#pragma once

#pragma region --- INCLUDE ---

#include "core/core.h"
#include "collection/general.h"

#pragma endregion

#pragma region --- MACRO ---

#define STRING_SIZE_MIN COLLECTION_SIZE_MIN
#define STRING_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

typedef const struct string_s {
    size_t size;
    size_t capacity;
    size_t elment_size;
    void* data;
    void* cstr;
} *string_t;
#pragma endregion

YSL_BEGIN_DECLS

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

string_t str_cinit(const char* str);
string_t str_winit(const wchar_t* str);

void str_delete(string_t* str);

#define str_init(str) _Generic( str    , \
    char*   : str_cinit((char*)str)    , \
    wchar_t*: str_winit((wchar_t*)str) , \
)((__typeof__(str))str)
#define str_delete(str) (str_delete)(&(str))

#pragma endregion

#pragma region --- FUNCION ---

void str_trim(string_t string);
void str_ctrim(string_t string, const void* chars);

void str_reverse(string_t string);

void str_cat(string_t dst, string_t src);
string_t str_dup(string_t src);

int str_chr(string_t string, int c);
int str_str(string_t string, string_t sub);
int str_cstr(string_t string, const void* sub);
size_t str_count(string_t string, int c);

string_t str_join(const string_t* strings, const void* delimiter);

#pragma endregion

YSL_END_DECLS

#endif // !STRING_H_
