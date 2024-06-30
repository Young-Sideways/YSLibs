/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/random.h"

#pragma region --- INCLUDE ---

#include "core.h"
#include "debug.h"

// for UCHAR_MAX
#include <limits.h>
// for rand()
#include <stdlib.h>

#pragma endregion

#pragma region --- PRIVATE ---

static void private_random_generator__(void* dst, size_t size) {
    explain_assert(dst , "algorithm/random: invalid arg - 'dst' == NULL");
    explain_assert(size, "algorithm/random: invalid arg - 'size' == 0u" );

    ubyte* temp_ptr = (ubyte*)dst;

    for (size_t i = 0; i < size; i++)
        temp_ptr[i] = (ubyte)(rand() & UCHAR_MAX);
}

#pragma endregion

#pragma region --- FUNCTION ---

void rng_fill(void* ptr, size_t capacity, size_t element_size, rng_t generator) {
    explain_assert(ptr                           , "algorithm/memory: invalid arg - 'src' == NULL"                     );
    explain_assert(capacity                      , "algorithm/memory: invalid arg - 'capacity' == 0u"                  );
    explain_assert(element_size                  , "algorithm/memory: invalid arg - 'element_size' == 0u"              );
    explain_assert(element_size <= capacity      , "algorithm/memory: invalid arg - 'element_size' > 'capacity'"       );
    explain_assert((capacity % element_size) == 0, "algorithm/memory: invalid arg - ('capacity' % 'element_size') != 0");

    if (generator == NULL)
        generator = private_random_generator__;

    ubyte* temp_ptr = (ubyte*)ptr;
    for (; capacity; capacity -= element_size, temp_ptr += element_size)
        generator(temp_ptr, element_size);
}

#pragma endregion
