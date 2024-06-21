/*******************************************************************************
 *  @file      core.h
 *  @brief     General types, macros, functions etc.
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef CORE_H_
#define CORE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdlib.h>

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   UNUSED
 *  @brief mark parameter as unused
 *  @param variable - parameter
 */
#define UNUSED(variable) ((void)variable)

#pragma endregion

#pragma region --- TYPEDEF ---

typedef signed char   byte;
typedef unsigned char ubyte;

#pragma endregion

#pragma region --- FUNCTION ---

//static inline void* memdup(const void* src, size_t size) {
//    if (!src || !size)
//        return NULL;
//    void* dst = malloc(size);
//    if (dst)
//        memcpy(dst, src, size);
//    return dst;
//}

#pragma endregion

#endif // !CORE_H_
