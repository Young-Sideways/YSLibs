/*******************************************************************************
 *  @file      print.h
 *  @brief     Generic print function
 *  @author    Young Sideways
 *  @date      8.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef G_PRINT_H_
#define G_PRINT_H_

#pragma once

#pragma region --- INCLUDE ---

#include "../variadic.h"
#include "../exec.h"

#pragma endregion

#pragma region --- TYPEDEF ---

struct {
    const char* const format;
};

#pragma endregion

#pragma region --- GENERIC ---

#define M_FORMAT_OF(var) _Generic( (var) , \
    signed char        : "hhd"           , \
    signed short       : "hd"            , \
    signed int         : "d"             , \
    signed long        : "ld"            , \
    signed long long   : "lld"           , \
    unsigned char      : "hhu"           , \
    unsigned short     : "hu"            , \
    unsigned           : "u"             , \
    unsigned long      : "lu"            , \
    unsigned long long : "llu"           , \
    float              : "g"             , \
    double             : "lg"            , \
    long double        : "Lg"            , \
    signed char*       : "s"             , \
    signed short*      : "p"             , \
    signed int*        : "p"             , \
    signed long*       : "p"             , \
    signed long long*  : "p"             , \
    unsigned char*     : "p"             , \
    unsigned short*    : "p"             , \
    unsigned*          : "p"             , \
    unsigned long*     : "p"             , \
    unsigned long long*: "p"             , \
    float*             : "p"             , \
    double*            : "p"             , \
    long double*       : "p"             , \
    void*              : "p"             , \
    default            : "X"             )

#define VA_GPRINT_ARGFORMAT(...) VA_EXEC0(M_FORMAT_OF, __VA_ARGS__)

#pragma endregion

#endif // !G_PRINT_H_
