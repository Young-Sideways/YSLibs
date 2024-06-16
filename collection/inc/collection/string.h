/*******************************************************************************
 *  @file      string.h
 *  @brief     C compatible dynamic string
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef STRING_H_
#define STRING_H_

#pragma once

#pragma region --- INCLUDE ---

#include "collection/general.h"

#pragma endregion

#pragma region --- MACRO ---

#define STRING_SIZE_MIN COLLECTION_SIZE_MIN
#define STRING_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

typedef const struct string_t {
    struct collection_universal_header;
    void* data;
}* string_t;
#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

string_t str_init(const char* str);
string_t str_winit(const wchar_t* wstr);

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

#endif // !STRING_H_
