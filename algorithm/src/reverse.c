/*******************************************************************************
 * @file      reverse.c
 * @author    Young Sideways
 * @brief     tools, that reverse memory order bytes
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/reverse.h"

#pragma region --- INCLUDE ---

#include "algorithm/swap.h"
#include "core.h"

#pragma endregion

#pragma region --- FUNCTION ---

void reverse(void* block, const size_t capacity, const size_t element_size) {
    for (byte* first = block, *last = (byte*)block + (capacity - 1) * element_size; first < last; first += element_size, last -= element_size)
        swap(first, last, element_size);
}

#pragma endregion
