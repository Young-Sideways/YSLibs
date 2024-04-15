/*******************************************************************************
 *  @file      string.h
 *  @brief     C compactible dynamic string
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _STRING_H_
#define _STRING_H_

#pragma once

#pragma region --- INCLUDES ---

#include "general.h"

#pragma endregion

#pragma region --- MACROS ---

#define STRING_SIZE_MIN COLLECTION_SIZE_MIN
#define STRING_SIZE_MAX COLLECTION_SIZE_MAX

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef char* string_t;

typedef struct {
    COLLECTION_HEADER()


} string_t;

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

string_t str_init();

string_t str_copy(_IN const string_t* array);
string_t str_move(_IN string_t* array);
string_t str_shadow(_IN const string_t* array);

void str_delete(_IN string_t* array);

#pragma endregion

#pragma region --- FUNCIONS ---



#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

char* trim(char* string);
char* ctrim(char* string, char* chars);

void str_reverse(char* string);

#pragma endregion

#pragma region ---  ---
#pragma endregion

#endif // !_STRING_H_
