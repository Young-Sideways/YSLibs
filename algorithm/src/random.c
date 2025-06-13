/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/random.h"

#pragma region --- INCLUDE ---

#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#pragma endregion

#pragma region --- PRIVATE ---

static void private_random_generator__(void* src, const size_t size) {
    assert(src != NULL); // algorithm/random: invalid arg - 'src' == NULL
    assert(size       ); // algorithm/random: invalid arg - 'size' == 0u

    ubyte* temp_ptr = (ubyte*)src;

    for (size_t i = 0; i < size; i++)
        temp_ptr[i] = (ubyte)(rand() & UBYTE_MAX);
}

#pragma endregion

#pragma region --- FUNCTION ---

void rng_fill(void* ptr, const size_t capacity, const size_t element_size, rng_t generator) {
    assert(ptr != NULL                   ); // algorithm/memory: invalid arg - 'src' == NULL
    assert(capacity                      ); // algorithm/memory: invalid arg - 'capacity' == 0u
    assert(element_size                  ); // algorithm/memory: invalid arg - 'element_size' == 0u
    assert(element_size <= capacity      ); // algorithm/memory: invalid arg - 'element_size' > 'capacity'
    assert((capacity % element_size) == 0); // algorithm/memory: invalid arg - ('capacity' % 'element_size') != 0

    if (generator == NULL)
        generator = private_random_generator__;

    ubyte* temp_ptr = (ubyte*)ptr;
    const size_t size = capacity * element_size;

    for (size_t i = 0; i < size; i+= element_size)
        generator(&(temp_ptr[i]), element_size);
}

#pragma endregion
