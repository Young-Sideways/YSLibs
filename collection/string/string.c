/*******************************************************************************
 *  @file      string.c
 *  @brief     C compactible dynamic string
 *  @author    Young Sideways
 *  @date      14.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "string.h"

#pragma region --- INCLUDES ---

#include <string.h>
#include <ctype.h>

#pragma endregion

#pragma region --- MACROS ---
#pragma endregion

#pragma region --- TYPEDEFS ---



#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---
#pragma endregion

#pragma region --- FUNCIONS ---
#pragma endregion

#pragma region --- ALGORITHM ADAPTER ---

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

#pragma endregion

#pragma region ---  ---
#pragma endregion

#pragma region --- GENERICS ---
#pragma endregion
