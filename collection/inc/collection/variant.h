/*******************************************************************************
 *  @file      variant.h
 *  @brief     variant type
 *  @author    Young Sideways
 *  @date      8.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef VARIANT_H_
#define VARIANT_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stddef.h>

#pragma endregion

#pragma region --- MACRO ---
#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct variant_s {
    size_t size;
    char data[1];
} *variant_t;

#pragma endregion

#pragma region --- FUNCION ---

variant_t var_init(size_t size) {
    
}

#pragma endregion

#endif // !VARIANT_H_
