/*******************************************************************************
 * @file      memory.c
 * @author    Young Sideways
 * @brief     tools, that controls memory
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/


#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "../inc/algorithm/memory.h"
#include "../inc/algorithm/swap.h"


void* memreverse(void* src, const size_t count, const size_t element_size) {
    assert(src != NULL ); // algorithm/memory: invalid arg - 'src' == NULL
    assert(count       ); // algorithm/memory: invalid arg - 'count' == 0u
    assert(element_size); // algorithm/memory: invalid arg - 'element_size' == 0u

    for (uint8_t *first = (uint8_t*)src, *last  = (uint8_t*)(first + ((count - 1) * element_size)); first < last; first += element_size, last -= element_size)
        swap_s((void*)first, (void*)last, element_size);
    return src;
}

void* memdup(const void* src, const size_t size) {
    assert(src != NULL); // algorithm/memory: invalid arg 'src' == NULL
    assert(size       ); // algorithm/memory: invalid arg 'size' == 0u

    void* dst = malloc(size);
    if (dst != NULL)
        memcpy(dst, src, size);
    return dst;
}

size_t memthex(char* buf, const void* src, const size_t size) {
    assert(buf  != NULL); // algorithm/memory: invalid arg 'buf' == NULL
    assert(src  != NULL); // algorithm/memory: invalid arg 'src' == NULL
    assert(size        ); // algorithm/memory: invalid arg 'size' == 0u


    size_t ret = 0u;
    size_t i = 0u;

    // to minimize 'snprintf' calls - using block printing
    for (; ((size - i) / sizeof(uint_fast64_t)) != 0u; i += sizeof(uint_fast64_t))
        ret += snprintf(&(buf[i * 2]), sizeof(uint_fast64_t) * 2 + 1, "%" PRIXFAST64, *(uint_fast64_t*)&(((uint8_t*)src)[size - i - sizeof(uint_fast64_t)]));
    for (; i < size; i++)
        ret += snprintf(&(buf[i * 2]), sizeof(uint8_t) * 2 + 1, "%" PRIX8, ((uint8_t*)src)[size - i - sizeof(uint8_t)]);
    
    return ret;
}
