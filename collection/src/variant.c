/*******************************************************************************
 *  @file      variant.c
 *  @brief     variant type
 *  @author    Young Sideways
 *  @date      8.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "collection/variant.h"

#pragma region --- INCLUDE ---

#include <string.h>
#include <stdlib.h>

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

variant_t (var_init)(size_t size) {
    variant_t result = (variant_t)calloc(sizeof(struct variant_s) + size, 1);
    if (result) {
        result->size = size;
    }
    return result;
}

#pragma endregion

#pragma region --- FUNCION ---

void (var_set)(variant_t variant, size_t size, void* value) {
    if (!variant || !size || !value)
        return;
    memcpy(variant->data, value, size);
}
void* (var_get)(variant_t variant, size_t size) {
    if (!variant || !size)
        return NULL;
    return (void*)variant->data;
}

#pragma endregion
