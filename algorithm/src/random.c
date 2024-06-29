/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/random.h"

#pragma region --- INCLUDE ---

#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#pragma endregion

#pragma region --- STATIC ---

static inline ubyte rnd_() {
    return rand() >> (rand() % ((ubyte)log2((double)RAND_MAX) - CHAR_BIT));
}

#pragma endregion

#pragma region --- FUNCTION ---

void random_init() { srand((unsigned int)time(NULL)); }

void random_fill(void* block, size_t size, rng_t generator) {
    if (!generator)
        generator = &rnd_;
    ubyte* array = (ubyte*)block; 
    while(size)
        array[--size] = generator();
}

#pragma endregion
