/*******************************************************************************
 *  @file      core.h
 *  @brief     General types, macros, functions etc.
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _CORE_H_
#define _CORE_H_

#pragma once

#pragma region --- INCLUDES ---

#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#pragma endregion

#pragma region --- MACROS ---

/**
 *  @def   _IN
 *  @brief input parameter
 */
#define _IN
/**
 *  @def   _OUT
 *  @brief ouput parameter
 */
#define _OUT
/**
 *  @def   _INOUT
 *  @brief input/output parameter
 */
#define _INOUT
/**
 *  @def   _NULLABLE
 *  @brief parameter can be NULL
 */
#define _NULLABLE
/**
 *  @def   UNUSED
 *  @brief mark parameter as unused
 *  @param variable - parameter
 */
#define UNUSED(variable) ((void)variable)

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef signed char   byte;
typedef unsigned char ubyte;

#pragma endregion

#pragma region --- DEBUG ---
#ifdef NDEBUG
    #define explain_assert(expression, msg) ((void)0)
#else
    #define explain_assert(expression, msg) assert((expression) && msg)
#endif
#pragma endregion

#pragma region --- GENERICS ---
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)

#define MIN(type) _Generic( (type)0               , \
    signed char        : SCHAR_MIN                , \
    signed short       : SHRT_MIN                 , \
    signed int         : INT_MIN                  , \
    signed long        : LONG_MIN                 , \
    signed long long   : LLONG_MIN                , \
    unsigned char      : 0ui8                     , \
    unsigned short     : 0ui16                    , \
    unsigned           : 0u                       , \
    unsigned long      : 0ul                      , \
    unsigned long long : 0ull                     , \
    float              : FLT_MIN                  , \
    double             : DBL_MIN                  , \
    long double        : LDBL_MIN                 , \
    signed char*       :               (char*)NULL, \
    signed short*      :              (short*)NULL, \
    signed int*        :                (int*)NULL, \
    signed long*       :               (long*)NULL, \
    signed long long*  :          (long long*)NULL, \
    unsigned char*     :      (unsigned char*)NULL, \
    unsigned short*    :     (unsigned short*)NULL, \
    unsigned*          :           (unsigned*)NULL, \
    unsigned long*     :      (unsigned long*)NULL, \
    unsigned long long*: (unsigned long long*)NULL, \
    float*             :              (float*)NULL, \
    double*            :             (double*)NULL, \
    long double*       :        (long double*)NULL, \
    void*              :               (void*)NULL, \
    default            : NULL                       )

#define MAX(type) _Generic( (type)0                   , \
    signed char        : SCHAR_MAX                    , \
    signed short       : SHRT_MAX                     , \
    signed int         : INT_MAX                      , \
    signed long        : LONG_MAX                     , \
    signed long long   : LLONG_MAX                    , \
    unsigned char      : UCHAR_MAX                    , \
    unsigned short     : USHRT_MAX                    , \
    unsigned           : UINT_MAX                     , \
    unsigned long      : ULONG_MAX                    , \
    unsigned long long : ULLONG_MAX                   , \
    float              : FLT_MAX                      , \
    double             : DBL_MAX                      , \
    long double        : LDBL_MAX                     , \
    signed char*       :               (char*)SIZE_MAX, \
    signed short*      :              (short*)SIZE_MAX, \
    signed int*        :                (int*)SIZE_MAX, \
    signed long*       :               (long*)SIZE_MAX, \
    signed long long*  :          (long long*)SIZE_MAX, \
    unsigned char*     :      (unsigned char*)SIZE_MAX, \
    unsigned short*    :     (unsigned short*)SIZE_MAX, \
    unsigned*          :       (unsigned int*)SIZE_MAX, \
    unsigned long*     :      (unsigned long*)SIZE_MAX, \
    unsigned long long*: (unsigned long long*)SIZE_MAX, \
    float*             :              (float*)SIZE_MAX, \
    double*            :             (double*)SIZE_MAX, \
    long double*       :        (long double*)SIZE_MAX, \
    void*              :               (void*)SIZE_MAX, \
    default            : NULL                           )

#endif
#pragma endregion

// Легаси...
#if (0)

#include <stdio.h>

#define _t_min_print(type) printf("min (%.19s) : 0x%llX\n", #type, MIN(type))
#define _t_max_print(type) printf("max (%.19s) : 0x%llX\n", #type, MAX(type))

void __print_type_sizes(void) {
    _t_min_print(char);
    _t_min_print(short);
    _t_min_print(int);
    _t_min_print(long);
    _t_min_print(long long);
    _t_min_print(signed char);
    _t_min_print(signed short);
    _t_min_print(signed int);
    _t_min_print(signed long);
    _t_min_print(signed long long);
    _t_min_print(unsigned char);
    _t_min_print(unsigned short);
    _t_min_print(unsigned int);
    _t_min_print(unsigned long);
    _t_min_print(unsigned long long);
    _t_min_print(float);
    _t_min_print(double);
    _t_min_print(long double);
    putchar('\n');
    _t_min_print(char*);
    _t_min_print(short*);
    _t_min_print(int*);
    _t_min_print(long*);
    _t_min_print(long long*);
    _t_min_print(signed char*);
    _t_min_print(signed short*);
    _t_min_print(signed int*);
    _t_min_print(signed long*);
    _t_min_print(signed long long*);
    _t_min_print(unsigned char*);
    _t_min_print(unsigned short*);
    _t_min_print(unsigned int*);
    _t_min_print(unsigned long*);
    _t_min_print(unsigned long long*);
    _t_min_print(float*);
    _t_min_print(double*);
    _t_min_print(long double*);
    putchar('\n');
    _t_max_print(char);
    _t_max_print(short);
    _t_max_print(int);
    _t_max_print(long);
    _t_max_print(long long);
    _t_max_print(signed char);
    _t_max_print(signed short);
    _t_max_print(signed int);
    _t_max_print(signed long);
    _t_max_print(signed long long);
    _t_max_print(unsigned char);
    _t_max_print(unsigned short);
    _t_max_print(unsigned int);
    _t_max_print(unsigned long);
    _t_max_print(unsigned long long);
    _t_max_print(float);
    _t_max_print(double);
    _t_max_print(long double);
    putchar('\n');
    _t_max_print(char*);
    _t_max_print(short*);
    _t_max_print(int*);
    _t_max_print(long*);
    _t_max_print(long long*);
    _t_max_print(signed char*);
    _t_max_print(signed short*);
    _t_max_print(signed int*);
    _t_max_print(signed long*);
    _t_max_print(signed long long*);
    _t_max_print(unsigned char*);
    _t_max_print(unsigned short*);
    _t_max_print(unsigned int*);
    _t_max_print(unsigned long*);
    _t_max_print(unsigned long long*);
    _t_max_print(float*);
    _t_max_print(double*);
    _t_max_print(long double*);
    putchar('\n');
}

#undef _t_min_print
#undef _t_max_print

#endif

#endif // !_CORE_H_
