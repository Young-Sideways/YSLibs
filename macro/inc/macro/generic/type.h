/*******************************************************************************
 *  @file      type.h
 *  @brief     generic type macros
 *  @author    Young Sideways
 *  @date      18.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef G_TYPE_H_
#define G_TYPE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <limits.h>
#include <float.h>

#pragma endregion

#pragma region --- MACRO ---

#define G_TMIN(type) _Generic( ((type)0)          , \
    signed char        : SCHAR_MIN                , \
    signed short       : SHRT_MIN                 , \
    signed int         : INT_MIN                  , \
    signed long        : LONG_MIN                 , \
    signed long long   : LLONG_MIN                , \
    unsigned char      : (unsigned char)0u        , \
    unsigned short     : (unsigned short)0u       , \
    unsigned           : 0u                       , \
    unsigned long      : 0ul                      , \
    unsigned long long : 0ull                     , \
    float              : FLT_MIN                  , \
    double             : DBL_MIN                  , \
    long double        : LDBL_MIN                 , \
    signed char*       :        (signed char*)NULL, \
    signed short*      :       (signed short*)NULL, \
    signed int*        :         (signed int*)NULL, \
    signed long*       :        (signed long*)NULL, \
    signed long long*  :   (signed long long*)NULL, \
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

#define G_TMAX(type) _Generic( ((type)0)              , \
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
    signed char*       :        (signed char*)SIZE_MAX, \
    signed short*      :       (signed short*)SIZE_MAX, \
    signed int*        :         (signed int*)SIZE_MAX, \
    signed long*       :        (signed long*)SIZE_MAX, \
    signed long long*  :   (signed long long*)SIZE_MAX, \
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

#pragma endregion

#endif // !G_TYPE_H_
