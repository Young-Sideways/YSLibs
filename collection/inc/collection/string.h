/*******************************************************************************
 *  @file      string.h
 *  @brief     C compatible dynamic string
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _STRING_H_
#define _STRING_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../general.h"

#pragma endregion

#pragma region --- MACROS ---

#define STRING_SIZE_MIN COLLECTION_SIZE_MIN
#define STRING_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEFS ---

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

void str_cat(string_t dst, const string_t src);
string_t str_dup(const string_t src);

int str_chr(string_t string, int c);
int str_str(string_t string, const string_t sub);
int str_cstr(string_t string, const void* sub);
size_t str_count(const string_t string, int c);

string_t str_join(const string_t* strings, const void* delimeter);

#pragma endregion

#pragma region ---  ---
#pragma endregion

#endif // !_STRING_H_
