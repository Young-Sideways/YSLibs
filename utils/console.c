/*******************************************************************************
 *  @file      console.c
 *  @brief     Console utils
 *  @author    Young Sideways
 *  @date      11.05.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "console.h"

#pragma region --- INCLUDE ---

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#pragma endregion

#pragma region --- MACRO ---
#pragma endregion
#pragma region --- TYPEDEF ---
#pragma endregion

#pragma region --- FUNCION ---

char* enum_to_arabic(int num, char* buffer, size_t buffer_size) {
    if (!buffer || buffer_size == 0)
        return NULL;
    snprintf(buffer, buffer_size, "%d", num);
    return buffer;
}

char* enum_to_roman(int num, char* buffer, size_t buffer_size) {
    if (!buffer || buffer_size == 0)
        return NULL;
    if (num <= 0 || num >= 4000)
        return enum_to_arabic(num, buffer, buffer_size);

    static const char* const ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    static const char* const tens[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
    static const char* const hrns[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
    static const char* const  ths[] = { "","M","MM","MMM" };

    static const size_t ones_weight[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };
    static const size_t tens_weight[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };
    static const size_t hrns_weight[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };
    static const size_t ths_weight[] = { 0, 1, 2, 3 };

    size_t total_size = ths_weight[num / 1000] + hrns_weight[(num % 1000) / 100] + tens_weight[(num % 100) / 10] + ones_weight[num % 10] + 1;
    if (total_size >= buffer_size)
        return NULL;

    memset(buffer, '\0', buffer_size);
    strcat(buffer, ths[num / 1000]);
    strcat(buffer, hrns[(num % 1000) / 100]);
    strcat(buffer, tens[(num % 100) / 10]);
    strcat(buffer, ones[num % 10]);
    return buffer;
}

char* enum_to_alphabet(int num, char* buffer, size_t buffer_size, bool is_upper) {
    if (!buffer)
        return NULL;
    if (num <= 0)
        return enum_to_arabic(num, buffer, buffer_size);
    int i = 0;
    do {
        num--;
        buffer[i++] = is_upper ? 'A' : 'a' + num % 26;
        num /= 26;
    } while (num > 0);
    buffer[i--] = '\0';
    for (int j = 0; j < i; j++, i--) {
        char temp = buffer[j];
        buffer[j] = buffer[i];
        buffer[i] = temp;
    }
    return buffer;
}

char* con_enum_translate(int number, enumeration_t enumeration, char* buffer, size_t buffer_size) {
    switch (enumeration)
    {
    case ARABIC_NUMERALS:
        return enum_to_arabic(number, buffer, buffer_size);
    case ROMAN_NUMERALS:
        return enum_to_roman(number, buffer, buffer_size);
    case ALPHABET_LOWERCASE:
        return enum_to_alphabet(number, buffer, buffer_size, false);
    case ALPHABET_UPPERCASE:
        return enum_to_alphabet(number, buffer, buffer_size, true);
    default:
        break;
    }
    return NULL;
}

void con_enum(const char* content, alignment_t align, enumeration_t enumeration) {
    if (!content || !*content)
        return;
    size_t max_size = 0,
           total_size = 0,
           current_size = 0,
           rows = 0;

    char buf[128] = { 0 };

    for (int retval = 0; (retval = sscanf(content + total_size, "%*[^\r\n]%n", &current_size)) != EOF;) {
        if (retval == 0) {
            total_size++;
            continue;
        }
        if (current_size) {
            total_size += current_size;
            rows++;
            if (max_size < current_size)
                max_size = current_size;
        }
        current_size = 0;
    }
    total_size = 0;
    for (int i = 1, retval = 0; (retval = sscanf(content + total_size, "%128[^\r\n]%n", buf, &current_size)) != EOF;) {
        if (retval == 0) {
            total_size++;
            continue;
        }
        if (current_size) {
            total_size += current_size;
            char num_buf[32] = { 0 };
            switch (align & ALIGN_HMASK)
            {
            case ALIGN_HRIGHT:
                printf("%s: %-*s\n", con_enum_translate(i, enumeration, num_buf, 32), (unsigned)max_size, buf);
                break;
            case ALIGN_HCENTER:
                printf("%s: %*s\n", con_enum_translate(i, enumeration, num_buf, 32), (unsigned)((max_size - current_size) / 2 + current_size), buf);
                break;
            case ALIGN_HLEFT:
            default:
                printf("%s: %s\n", con_enum_translate(i, enumeration, num_buf, 32), buf);
                break;
            }
            i++;
            current_size = 0;
        }
    }
}

void con_box(char* content, alignment_t align, int padding) {

}

#pragma endregion

#pragma region ---  ---
#pragma endregion
#pragma region --- GENERIC ---
#pragma endregion
