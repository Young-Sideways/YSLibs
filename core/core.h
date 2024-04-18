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

#pragma region --- MACRO ---

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

#pragma region --- TYPEDEF ---

typedef signed char   byte;
typedef unsigned char ubyte;

#pragma endregion

#endif // !_CORE_H_
