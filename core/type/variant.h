/*******************************************************************************
 *  @file      variant.h
 *  @brief     variant type
 *  @author    Young Sideways
 *  @date      8.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _VARIANT_H_
#define _VARIANT_H_

#pragma once

#pragma region --- INCLUDES ---
#pragma endregion

#pragma region --- MACROS ---
#pragma endregion

#pragma region --- TYPEDEFS ---

typedef union {
    char               V_CHAR  ;
    short              V_SHORT ;
    int                V_INT   ;
    long               V_LONG  ;
    long long          V_LLONG ;

    unsigned char      V_UCHAR  ;
    unsigned short     V_USHORT ;
    unsigned int       V_UINT   ;
    unsigned long      V_ULONG  ;
    unsigned long long V_ULLONG ;

    float              V_FLOAT  ;
    double             V_DOUBLE ;
    long double        V_LDOUBLE;

    char*              V_STRING ;
    void*              V_POINTER;
} variant_t;

typedef int (variant_to_str)(variant_t)

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---
#pragma endregion
#pragma region --- FUNCIONS ---
#pragma endregion
#pragma region ---  ---
#pragma endregion
#pragma region ---  ---
#pragma endregion
#pragma region --- GENERICS ---
#pragma endregion
#endif // !_VARIANT_H_
