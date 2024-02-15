/*******************************************************************************
 *  @file      types.h
 *  @brief     General types
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _TYPES_H_
#define _TYPES_H_

#pragma once

#pragma region --- INCLUDES ---

#include <stdint.h>
#include <limits.h>

#pragma endregion

#pragma region --- MACROS ---

 /**
  *  @def   _IN
  *  @brief input parametr
  */
#define _IN
  /**
   *  @def   _OUT
   *  @brief ouput parametr
   */
#define _OUT
   /**
    *  @def   _INOUT
    *  @brief input/output parametr
    */
#define _INOUT
    /**
     *  @def   _NULLABLE
     *  @brief parametr can be NULL
     */
#define _NULLABLE

#define UNUSED(variable) ((void)variable)

#pragma endregion

#pragma region --- TYPEDEFS ---

typedef signed char byte;
typedef unsigned char ubyte;

#pragma endregion

#pragma region --- GENERICS ---

#define MAX(type) _Generic( (type)0, \
    signed char        : SCHAR_MAX , \
    signed short       : SHRT_MAX  , \
    signed int         : INT_MAX   , \
    signed long        : LONG_MAX  , \
    signed long long   : LLONG_MAX , \
    unsigned char      : UCHAR_MAX , \
    unsigned short     : USHRT_MAX , \
    unsigned           : UINT_MAX  , \
    unsigned long      : ULONG_MAX , \
    unsigned long long : ULLONG_MAX, \
    char*              : SIZE_MAX  , \
    short*             : SIZE_MAX  , \
    int*               : SIZE_MAX  , \
    long*              : SIZE_MAX  , \
    long long*         : SIZE_MAX  , \
    unsigned char*     : SIZE_MAX  , \
    unsigned short*    : SIZE_MAX  , \
    unsigned*          : SIZE_MAX  , \
    unsigned long*     : SIZE_MAX  , \
    unsigned long long*: SIZE_MAX  , \
    void*              : SIZE_MAX  , \
	default            : NULL)

#define MIN(type) _Generic( (type)0            , \
    signed char        : SCHAR_MIN             , \
    signed short       : SHRT_MIN              , \
    signed int         : INT_MIN               , \
    signed long        : LONG_MIN              , \
    signed long long   : LLONG_MIN             , \
    unsigned char      : (char)0               , \
    unsigned short     : (short)0              , \
    unsigned           : 0U                    , \
    unsigned long      : 0UL                   , \
    unsigned long long : 0ULL                  , \
    char*              : (char*)0              , \
    short*             : (short*)0             , \
    int*               : (int*)0               , \
    long*              : (long*)0              , \
    long long*         : (long long*)0         , \
    unsigned char*     : (unsigned char*)0     , \
    unsigned short*    : (unsigned short*)0    , \
    unsigned*          : (unsigned*)0          , \
    unsigned long*     : (unsigned long*)0     , \
    unsigned long long*: (unsigned long long*)0, \
    void*              : (void*)0              , \
	default: NULL)

#pragma endregion

// Легаси...
#if (0)
#include <stdio.h>
void print_type_sizes(void) {
    printf("0x%llX\n", MAX(char));
    printf("0x%llX\n", MAX(short));
    printf("0x%llX\n", MAX(int));
    printf("0x%llX\n", MAX(long));
    printf("0x%llX\n", MAX(long long));
    printf("0x%llX\n", MAX(signed char));
    printf("0x%llX\n", MAX(signed short));
    printf("0x%llX\n", MAX(signed int));
    printf("0x%llX\n", MAX(signed long));
    printf("0x%llX\n", MAX(signed long long));
    printf("0x%llX\n", MAX(unsigned char));
    printf("0x%llX\n", MAX(unsigned short));
    printf("0x%llX\n", MAX(unsigned int));
    printf("0x%llX\n", MAX(unsigned long));
    printf("0x%llX\n", MAX(unsigned long long));
    printf("\n");
    printf("0x%llX\n", MAX(char*));
    printf("0x%llX\n", MAX(short*));
    printf("0x%llX\n", MAX(int*));
    printf("0x%llX\n", MAX(long*));
    printf("0x%llX\n", MAX(long long*));
    printf("0x%llX\n", MAX(signed char*));
    printf("0x%llX\n", MAX(signed short*));
    printf("0x%llX\n", MAX(signed int*));
    printf("0x%llX\n", MAX(signed long*));
    printf("0x%llX\n", MAX(signed long long*));
    printf("0x%llX\n", MAX(unsigned char*));
    printf("0x%llX\n", MAX(unsigned short*));
    printf("0x%llX\n", MAX(unsigned int*));
    printf("0x%llX\n", MAX(unsigned long*));
    printf("0x%llX\n", MAX(unsigned long long*));
    printf("\n");
    printf("0x%llX\n", MIN(char));
    printf("0x%llX\n", MIN(short));
    printf("0x%llX\n", MIN(int));
    printf("0x%llX\n", MIN(long));
    printf("0x%llX\n", MIN(long long));
    printf("0x%llX\n", MIN(signed char));
    printf("0x%llX\n", MIN(signed short));
    printf("0x%llX\n", MIN(signed int));
    printf("0x%llX\n", MIN(signed long));
    printf("0x%llX\n", MIN(signed long long));
    printf("0x%llX\n", MIN(unsigned char));
    printf("0x%llX\n", MIN(unsigned short));
    printf("0x%llX\n", MIN(unsigned int));
    printf("0x%llX\n", MIN(unsigned long));
    printf("0x%llX\n", MIN(unsigned long long));
    printf("\n");
    printf("0x%llX\n", MIN(char*));
    printf("0x%llX\n", MIN(short*));
    printf("0x%llX\n", MIN(int*));
    printf("0x%llX\n", MIN(long*));
    printf("0x%llX\n", MIN(long long*));
    printf("0x%llX\n", MIN(signed char*));
    printf("0x%llX\n", MIN(signed short*));
    printf("0x%llX\n", MIN(signed int*));
    printf("0x%llX\n", MIN(signed long*));
    printf("0x%llX\n", MIN(signed long long*));
    printf("0x%llX\n", MIN(unsigned char*));
    printf("0x%llX\n", MIN(unsigned short*));
    printf("0x%llX\n", MIN(unsigned int*));
    printf("0x%llX\n", MIN(unsigned long*));
    printf("0x%llX\n", MIN(unsigned long long*));
    printf("\n");
}
#endif

#endif // !_TYPES_H_
