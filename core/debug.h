/*******************************************************************************
 *  @file      debug.h
 *  @brief     debug module helps debuging your code
 *  @author    Young Sideways
 *  @date      18.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#pragma once

#pragma region --- INCLUDE ---

#include <assert.h>

#pragma endregion

#pragma region --- MACRO ---

#ifdef NDEBUG
    #define explain_assert(expression, msg) ((void)0)
#else
    #define explain_assert(expression, msg) assert((expression) && msg)
#endif

#pragma endregion

#endif // !_DEBUG_H_
