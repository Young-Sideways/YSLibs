/*******************************************************************************
 *  @file      type.h
 *  @brief     generic type macros
 *  @author    Young Sideways
 *  @date      18.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef G_TYPE_H_
#define G_TYPE_H_


#include <limits.h>
#include <float.h>

#include <core/core.h>


#pragma region --- MACRO ---

#define G_TCOMPATIBLE(x, y) ( _Generic( *((YSL_TYPEOF_UNQUAL(x)*)NULL) ), \
    YSL_TYPEOF_UNQUAL(y) : (true) ,                                       \
    default              : (false))

#define G_TMIN(x) _Generic((*((YSL_TYPEOF_UNQUAL(x)*)NULL))      , \
    signed char              : (SCHAR_MIN                       ), \
    signed short             : (SHRT_MIN                        ), \
    signed int               : (INT_MIN                         ), \
    signed long              : (LONG_MIN                        ), \
    signed long long         : (LLONG_MIN                       ), \
    unsigned char            : ((unsigned char)0u               ), \
    unsigned short           : ((unsigned short)0u              ), \
    unsigned                 : (0u                              ), \
    unsigned long            : (0ul                             ), \
    unsigned long long       : (0ull                            ), \
    float                    : (FLT_MIN                         ), \
    double                   : (DBL_MIN                         ), \
    long double              : (LDBL_MIN                        ), \
    signed char*             : ((signed char*)       NULL       ), \
    signed short*            : ((signed short*)      NULL       ), \
    signed int*              : ((signed int*)        NULL       ), \
    signed long*             : ((signed long*)       NULL       ), \
    signed long long*        : ((signed long long*)  NULL       ), \
    unsigned char*           : ((unsigned char*)     NULL       ), \
    unsigned short*          : ((unsigned short*)    NULL       ), \
    unsigned*                : ((unsigned*)          NULL       ), \
    unsigned long*           : ((unsigned long*)     NULL       ), \
    unsigned long long       : ((unsigned long long*)NULL       ), \
    float*                   : ((float*)             NULL       ), \
    double*                  : ((double*)            NULL       ), \
    long double*             : ((long double*)       NULL       ), \
    void*                    : ((void*)              NULL       ), \
    const signed char*       : ((signed char*)       NULL       ), \
    const signed short*      : ((signed short*)      NULL       ), \
    const signed int*        : ((signed int*)        NULL       ), \
    const signed long*       : ((signed long*)       NULL       ), \
    const signed long long*  : ((signed long long*)  NULL       ), \
    const unsigned char*     : ((unsigned char*)     NULL       ), \
    const unsigned short*    : ((unsigned short*)    NULL       ), \
    const unsigned*          : ((unsigned*)          NULL       ), \
    const unsigned long*     : ((unsigned long*)     NULL       ), \
    const unsigned long long : ((unsigned long long*)NULL       ), \
    const float*             : ((float*)             NULL       ), \
    const double*            : ((double*)            NULL       ), \
    const long double*       : ((long double*)       NULL       ), \
    const void*              : ((void*)              NULL       ), \
    default                  : ({ 0 }                           ))


#define G_TMAX(x) _Generic( *((YSL_TYPEOF_UNQUAL(x)*)NULL)       , \
    signed char              : (SCHAR_MAX                       ), \
    signed short             : (SHRT_MAX                        ), \
    signed int               : (INT_MAX                         ), \
    signed long              : (LONG_MAX                        ), \
    signed long long         : (LLONG_MAX                       ), \
    unsigned char            : (UCHAR_MAX                       ), \
    unsigned short           : (USHRT_MAX                       ), \
    unsigned                 : (UINT_MAX                        ), \
    unsigned long            : (ULONG_MAX                       ), \
    unsigned long long       : (ULLONG_MAX                      ), \
    float                    : (FLT_MAX                         ), \
    double                   : (DBL_MAX                         ), \
    long double              : (LDBL_MAX                        ), \
    signed char*             : ((signed char*)       UINTPTR_MAX), \
    signed short*            : ((signed short*)      UINTPTR_MAX), \
    signed int*              : ((signed int*)        UINTPTR_MAX), \
    signed long*             : ((signed long*)       UINTPTR_MAX), \
    signed long long*        : ((signed long long*)  UINTPTR_MAX), \
    unsigned char*           : ((unsigned char*)     UINTPTR_MAX), \
    unsigned short*          : ((unsigned short*)    UINTPTR_MAX), \
    unsigned*                : ((unsigned int*)      UINTPTR_MAX), \
    unsigned long*           : ((unsigned long*)     UINTPTR_MAX), \
    unsigned long long*      : ((unsigned long long*)UINTPTR_MAX), \
    float*                   : ((float*)             UINTPTR_MAX), \
    double*                  : ((double*)            UINTPTR_MAX), \
    long double*             : ((long double*)       UINTPTR_MAX), \
    void*                    : ((void*)              UINTPTR_MAX), \
    const signed char*       : ((signed char*)       UINTPTR_MAX), \
    const signed short*      : ((signed short*)      UINTPTR_MAX), \
    const signed int*        : ((signed int*)        UINTPTR_MAX), \
    const signed long*       : ((signed long*)       UINTPTR_MAX), \
    const signed long long*  : ((signed long long*)  UINTPTR_MAX), \
    const unsigned char*     : ((unsigned char*)     UINTPTR_MAX), \
    const unsigned short*    : ((unsigned short*)    UINTPTR_MAX), \
    const unsigned*          : ((unsigned int*)      UINTPTR_MAX), \
    const unsigned long*     : ((unsigned long*)     UINTPTR_MAX), \
    const unsigned long long*: ((unsigned long long*)UINTPTR_MAX), \
    const float*             : ((float*)             UINTPTR_MAX), \
    const double*            : ((double*)            UINTPTR_MAX), \
    const long double*       : ((long double*)       UINTPTR_MAX), \
    const void*              : ((void*)              UINTPTR_MAX), \
    default                  : ({ 0 }                           ))


#pragma endregion

#endif // !G_TYPE_H_
