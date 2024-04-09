/*******************************************************************************
 *  @file      print.h
 *  @brief     Generic print function
 *  @author    Young Sideways
 *  @date      8.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _GPRINT_H_
#define _GPRINT_H_

#pragma once

#pragma region --- INCLUDES ---

#include "../varidatic.h"
#include "../exec.h"

#pragma endregion

#pragma region --- MACROS ---

#pragma endregion

#pragma region --- GENERICS ---

#define M_FORMAT_OF(var) _Generic( (var)           , \
    signed char        : "hhd"                     , \
    signed short       : "hd"                      , \
    signed int         : "d"                       , \
    signed long        : "ld"                      , \
    signed long long   : "lld"                     , \
    unsigned char      : "hhu"                     , \
    unsigned short     : "hu"                      , \
    unsigned           : "u"                       , \
    unsigned long      : "lu"                      , \
    unsigned long long : "llu"                     , \
    float              : "g"                       , \
    double             : "lg"                      , \
    long double        : "Lg"                      , \
    signed char*       : "s (signed char*)"        , \
    signed short*      : "p (signed short*)"       , \
    signed int*        : "p (signed int*)"         , \
    signed long*       : "p (signed long*)"        , \
    signed long long*  : "p (signed long long*)"   , \
    unsigned char*     : "p (unsigned char*)"      , \
    unsigned short*    : "p (unsigned short*)"     , \
    unsigned*          : "p (unsigned*)"           , \
    unsigned long*     : "p (unsigned long*)"      , \
    unsigned long long*: "p (unsigned long long*)" , \
    float*             : "p (float*)"              , \
    double*            : "p (double*)"             , \
    long double*       : "p (long double*)"        , \
    void*              : "p (void*)"               , \
    default            : "X"                       )

#define VA_GPRINT_ARGFORMAT(...) VA_EXEC0(M_FORMAT_OF, __VA_ARGS__)

#pragma endregion


#pragma region --- FUNCIONS ---

int gprintf(const char* format, int argc, ...) {

}

#pragma endregion

#endif // !_GPRINT_H_
