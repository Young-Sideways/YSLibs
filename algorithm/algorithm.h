/*******************************************************************************
 *  @file      algorithm.h
 *  @brief     universal algorithm lib
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#pragma once

#include "comparator.h"
#include "swap.h"
#include "search.h"
#include "sort.h"
#include "random.h"

#include <string.h>
#include <ctype.h>

char* trim(char* string) {
    if (string && *string) {
        char* left = string, *right = string + strlen(string) - 1;
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

void reverse(void* block, size_t capacity, size_t element_size) {
    for (byte* first = block, *last = (byte*)block + (capacity - 1) * element_size; first < last; first += element_size, last -= element_size)
        swap(first, last, element_size);
}

#endif // !_ALGORITHM_H_
