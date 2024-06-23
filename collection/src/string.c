/*******************************************************************************
 *  @file      string.c
 *  @brief     C compatible dynamic string
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "collection/string.h"

#pragma region --- INCLUDE ---

#include <string.h>
#include <ctype.h>

#pragma endregion

#pragma region --- MACRO ---
#pragma endregion

#pragma region --- TYPEDEF ---



#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---
#pragma endregion

#pragma region --- FUNCION ---
#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---
/*
char* trim(char* string) {
    if (string && *string) {
        char* left = string, * right = string + strlen(string) - 1;
        while (isspace(*left))
            left++;
        while (isspace(*right) && left < right)
            right--;
        right[1] = '\0';
        memcpy(string, left, right - left + 2);
    }
    return string;
}
char* ctrim(char* string, char* chars) {
    if (!chars || !*chars)
        return trim(string);
    if (string && *string) {
        char* iter = string;
        for (int i = 0; i < strlen(string); i++)
            if (!strchr(chars, string[i]))
                *(iter++) = string[i];
        *iter = '\0';
    }
    return string;
}

void str_reverse(char* string) {
    for (char* last = string + strlen(string) - 1; string < last; --string, --last) {
        *string ^= *last;
        *last ^= *string;
        *string ^= *last;
    }
}
*/

#pragma endregion
