/*******************************************************************************
 *  @file      random.c
 *  @brief     random algorithm
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/


#include <assert.h>
#include <stdint.h>

#include "../inc/algorithm/random.h"


#pragma region --- PRIVATE ---

static uint64_t rngstate[4] = {
    UINT64_C(0x8241604243DF59A4),
    UINT64_C(0x055D1E696AC9692B),
    UINT64_C(0x528C25F6508F0364),
    UINT64_C(0x4D563DB544124AF8)
};

static YSL_ALWAYS_INLINE uint64_t __ysl_private_rotl(uint64_t v, int k) { return (v << k) | (v >> (64 - k)); }

// Returns a Uint64 random number
uint64_t __ysl_private_rand(void) {
    const uint64_t result = __ysl_private_rotl(rngstate[0] + rngstate[3], 23) + rngstate[0];
    const uint64_t t = rngstate[1] << 17;
    rngstate[2] ^= rngstate[0];
    rngstate[3] ^= rngstate[1];
    rngstate[1] ^= rngstate[2];
    rngstate[0] ^= rngstate[3];
    rngstate[2] ^= t;
    rngstate[3] = __ysl_private_rotl(rngstate[3], 45);
    return result;
}

#pragma endregion

#pragma region --- FUNCTION ---

void rng_fill(void* ptr, const size_t size, rng_t generator) {
    assert(ptr != NULL); // algorithm/memory: invalid arg - 'src' == NULL
    assert(size       ); // algorithm/memory: invalid arg - 'capacity' == 0u

    if (generator == NULL) {
        size_t i = 0;
        for (; i < (size - sizeof(uint64_t)); i += sizeof(uint64_t))
            *(uint64_t*)(&(((uint8_t*)ptr)[i])) = __ysl_private_rand();

        uint64_t temp = __ysl_private_rand();

        switch (size - i) {
            case 7: ((uint8_t*)ptr)[i + 7] = (temp >> 8 ) & 0xFF;
            case 6: ((uint8_t*)ptr)[i + 6] = (temp >> 16) & 0xFF;
            case 5: ((uint8_t*)ptr)[i + 5] = (temp >> 24) & 0xFF;
            case 4: ((uint8_t*)ptr)[i + 4] = (temp >> 32) & 0xFF;
            case 3: ((uint8_t*)ptr)[i + 3] = (temp >> 40) & 0xFF;
            case 2: ((uint8_t*)ptr)[i + 2] = (temp >> 48) & 0xFF;
            case 1: ((uint8_t*)ptr)[i + 1] = (temp >> 56) & 0xFF;
        };
    }
    else
        for (size_t i = 0; i < size; i++)
        /* For compactibility with rand() worst case distribution when RAND_MAX = 32767 */
            ((uint8_t*)ptr)[i] = (uint8_t)(generator() & 0xFF);
}

#pragma endregion
