/*******************************************************************************
 *  @file      console.h
 *  @brief     Console utils
 *  @author    Young Sideways
 *  @date      11.05.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include "../core/core.h"
#include <stddef.h>
#include <stdbool.h>

#pragma endregion

#pragma region --- MACRO ---

#define HTAB "\t"
#define VTAB "\v"
#define BING "\a"

#ifdef _WIN32
    #define ENDL "\r\n"
#else
    #define ENDL "\n"
#endif

#define DEFAULT_PADDING (padding_t){ 0, 0, 0, 0 }

#pragma endregion

#pragma region --- TYPEDEF ---

typedef enum {
    ALIGN_NONE    = 0x0,

    ALIGN_HLEFT   = 0x1,
    ALIGN_HRIGHT  = 0x2,
    ALIGN_HCENTER = 0x3,
    ALIGN_HMASK   = ALIGN_HLEFT | ALIGN_HRIGHT | ALIGN_HCENTER,

    ALIGN_VLEFT   = 0x4,
    ALIGN_VRIGHT  = 0x8,
    ALIGN_VCENTER = 0xC,
    ALIGN_VMASK   = ALIGN_VLEFT | ALIGN_VRIGHT | ALIGN_VCENTER,

    ALIGN_MASK    = ALIGN_HMASK | ALIGN_VMASK
} alignment_t;

typedef enum {
    ARABIC_NUMERALS    = 0x1,
    ROMAN_NUMERALS     = 0x2,
    ALPHABET_LOWERCASE = 0x4,
    ALPHABET_UPPERCASE = 0x8
} enumeration_t;

typedef struct padding_t {
    int left;
    int right;
    int top;
    int bottom;
} padding_t;

typedef const char* (enumerator_to_str_t)(int num, char* buffer, size_t buffer_size);

#pragma endregion

#pragma region --- FUNCION ---

char* enum_to_arabic(int num, char* buffer, size_t buffer_size);
char* enum_to_roman(int num, char* buffer, size_t buffer_size);
char* enum_to_alphabet(int num, char* buffer, size_t buffer_size, bool is_upper);

char* con_enum_translate(int number, enumeration_t enumeration, char* buffer, size_t buffer_size, _NULLABLE size_t* ret_size);

void con_enum(const char* content, alignment_t align, enumeration_t enumeration);

void con_box(char* content, alignment_t align, padding_t padding);

#pragma endregion

#pragma region --- MENU ---

void menu_selector(const char* items[], int item_count) {}

#pragma endregion

#endif // !_CONSOLE_H_
