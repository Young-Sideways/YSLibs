/*******************************************************************************
 * @file      version.c
 * @brief     Version controlling utility library
 * @author    Young Sideways
 * @date      16.01.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2025. All right reserved.
 *******************************************************************************/

#pragma region --- INCLUDE ---

#include "util/version.h"

#include <stdint.h>

#pragma endregion

#pragma region --- STATIC ---

static const char* __build_type_names[] = {
    "dev"    ,
    "debug"  ,
    "test"   ,
    "alpha"  ,
    "beta"   ,
    "rc"     ,
    "release"
};

#pragma endregion

#pragma region --- FUNCTION ---

#pragma endregion
