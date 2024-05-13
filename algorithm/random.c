/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "random.h"

#pragma region --- INCLUDE ---

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#pragma endregion

#pragma region --- FUNCTION ---

void random_init() { srand(time(NULL)); }

inline int _random() { return (int)(((unsigned)rand() << 30) | ((unsigned)rand() << 15) | (unsigned)rand()); }

int random(int from, int to) {
    assert(from <= to);
    return (int)((long long)_random() % ((long long)to - (long long)from) + (long long)from);
}

void random_fill(int* array, size_t size, _NULLABLE random_pt generator, int min, int max) {
    if (!generator)
        generator = &random;
    for (int i = 0; i < size; ++i)
        array[i] = generator(min, max);
}

#pragma endregion
