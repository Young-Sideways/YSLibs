/*******************************************************************************
 *  @file      console.h
 *  @brief     Console utils
 *  @author    Young Sideways
 *  @date      11.05.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef CONSOLE_H_
#define CONSOLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <core.h>
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

typedef struct padding_t {
    int left;
    int right;
    int top;
    int bottom;
} padding_t;

typedef char* (enum_to_str_t)(int num, char* buffer, size_t buffer_size);
typedef enum_to_str_t *enum_to_str_pt;

#pragma endregion

#pragma region --- FUNCION ---

enum_to_str_t enum_to_arabic;
enum_to_str_t enum_to_roman;
enum_to_str_t enum_to_alpha;
enum_to_str_t enum_to_ALPHA;

char* con_enum_translate(int number, enum_to_str_pt translator, char* buffer, size_t buffer_size, size_t* ret_size);

void con_enum(const char* content, alignment_t align, enum_to_str_pt translator);

void con_box(char* content, alignment_t align, padding_t padding);

#pragma endregion

#pragma region --- FORMAT ---

#include "macro/exec.h"

#define M_FORMAT_OF(var) _Generic( (var)  , \
    signed char        : "%hhd"           , \
    signed short       : "%hd"            , \
    signed int         : "%d"             , \
    signed long        : "%ld"            , \
    signed long long   : "%lld"           , \
    unsigned char      : "%hhu"           , \
    unsigned short     : "%hu"            , \
    unsigned           : "%u"             , \
    unsigned long      : "%lu"            , \
    unsigned long long : "%llu"           , \
    float              : "%f"             , \
    double             : "%lf"            , \
    long double        : "%Lf"            , \
    signed char*       : "%s"             , \
    signed short*      : "%p"             , \
    signed int*        : "%p"             , \
    signed long*       : "%p"             , \
    signed long long*  : "%p"             , \
    unsigned char*     : "%p"             , \
    unsigned short*    : "%p"             , \
    unsigned*          : "%p"             , \
    unsigned long*     : "%p"             , \
    unsigned long long*: "%p"             , \
    float*             : "%p"             , \
    double*            : "%p"             , \
    long double*       : "%p"             , \
    void*              : "%p"             , \
    default            : "%X"             )


#define _fmt_print(format, arg_size, arg_fmt, ...)
#define fmt_print(format, ...)

#pragma endregion

#pragma region --- MENU ---

char menu_getc(void);

int file_from_filepath(const char* filepath, char* buffer);
int path_from_filepath(const char* filepath, char* buffer);
bool path_is_local(const char* path);
bool path_is_valid(const char* path);

#pragma endregion

#endif // !CONSOLE_H_
