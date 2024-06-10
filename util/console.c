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
#include <ctype.h>
#include <stdbool.h>

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
char* enum_to_alpha(int num, char* buffer, size_t buffer_size) {
    if (!buffer)
        return NULL;
    if (num <= 0)
        return enum_to_arabic(num, buffer, buffer_size);
    int i = 0;
    do {
        num--;
        buffer[i++] = 'a' + (num % 26);
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
char* enum_to_ALPHA(int num, char* buffer, size_t buffer_size) {
    if (!buffer)
        return NULL;
    if (num <= 0)
        return enum_to_arabic(num, buffer, buffer_size);
    int i = 0;
    do {
        num--;
        buffer[i++] = 'A' + (num % 26);
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

char* con_enum_translate(int number, const enum_to_str_pt translator, char* buffer, size_t buffer_size, size_t* ret_size) {
    if (!translator)
        return NULL;
    char* str = translator(number, buffer, buffer_size);
    if (ret_size) 
        *ret_size = str ? strlen(str) : 0U;
    return str;
}

void con_enum(const char* content, alignment_t align, enum_to_str_pt translator) {
    if (!content || !*content || !translator)
        return;

    size_t max_size = 0;
    size_t max_enum_size = 0;

    int i = 1;
    for (const char* str = content; *str;) {
        size_t current_size = strcspn(str, "\r\n");
        if (current_size) {
            if (max_size < current_size)
                max_size = current_size;
            str += current_size;

            char num_buf[32] = { 0 };
            size_t enum_size = 0;
            translator(i, num_buf, sizeof(num_buf));
            enum_size = strlen(num_buf);
            if (max_enum_size < enum_size)
                max_enum_size = enum_size;
            i++;
        }
        else
            str++;
    }
    i = 1;
    for (const char* str = content; *str;) {
        size_t current_size = strcspn(str, "\r\n");
        if (current_size) {
            char num_buf[32] = { 0 };
            translator(i, num_buf, sizeof(num_buf));
            switch (align & ALIGN_HMASK)
            {
            case ALIGN_HRIGHT:
                printf("%-*s: %*.*s\n", (unsigned)max_enum_size, num_buf, (unsigned)max_size, (unsigned)current_size, str);
                break;
            case ALIGN_HCENTER:
                printf("%-*s: %*.*s\n", (unsigned)max_enum_size, num_buf, (unsigned)((max_size - current_size) / 2 + current_size), (unsigned)current_size, str);
                break;
            case ALIGN_HLEFT:
            default:
                printf("%-*s: %.*s\n", (unsigned)max_enum_size, num_buf, (unsigned)current_size, str);
                break;
            }
            i++;
            str += current_size;
        }
        else
            str++;
    }
}

void con_box(char* content, alignment_t align, padding_t padding) {

}

char menu_getc(void) {
    char mode = '\0';
    do {
        mode = _getch();
    } while (isspace(mode));
    printf("%c\n", mode);
    return mode;
}

#pragma endregion
