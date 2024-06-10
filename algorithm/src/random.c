/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright � young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "algorithm/random.h"

#pragma region --- INCLUDE ---

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#pragma endregion

#pragma region --- FUNCTION ---

void random_init() { srand((unsigned int)time(NULL)); }

static inline int _random() { return (int)(((unsigned)rand() << 30) | ((unsigned)rand() << 15) | (unsigned)rand()); }

int random(int min, int max) {
    assert(min <= max);
    return (int)((long long)_random() % ((long long)min - (long long)max) + (long long)min);
}

void random_fill(int* array, size_t size, random_pt generator, int min, int max) {
    if (!generator)
        generator = &random;
    for (int i = 0; i < (int)size; ++i)
        array[i] = generator(min, max);
}

#pragma endregion
