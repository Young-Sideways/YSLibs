/*******************************************************************************
 * @file      type.c
 * @author    Young Sideways
 * @brief     Common types for RPC system
 * @date      07.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#pragma region --- INCLUDE ---

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../../inc/RPC/core/type.h"
#include "../../../core/inc/core/core.h"

#pragma endregion

#pragma region --- MACRO ---

#define RPC_BS_IS_VALID(bs) (((bs) != NULL) && ((bs)->allocated) && ((bs)->offset <= (bs)->allocated))

#define RPC_BS_AVAILABLE_SPACE(bs) ((bs)->allocated - (bs)->offset)
#define RPC_BS_GET_DATA(bs) (((uint8_t*)(bs)) + sizeof(struct RPC_bs))

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

RPC_bs_t RPC_bs_ctor(size_t size) {
    assert(size);
    assert(size <= RPC_BS_MAX_SIZE);

    RPC_bs_t bs = (RPC_bs_t)malloc(sizeof(struct RPC_bs) + size);
    if (YSL_LIKELY( bs != NULL )) {
        bs->allocated  = size;
        bs->offset     = 0u  ;
    }

    return bs;
}

void RPC_bs_dtor(RPC_bs_t* stream) {
    assert(stream != NULL);
    assert(RPC_BS_IS_VALID(*stream));

    free(*stream);
    *stream = NULL;
}

#pragma endregion

#pragma region --- FUNCTION ---

size_t RPC_bs_write(RPC_bs_t bs, const void* data, size_t n) {
    assert(RPC_BS_IS_VALID(bs));
    assert(data != NULL);
    assert(n);

    if ((n + bs->offset) > bs->allocated)
        n = RPC_BS_AVAILABLE_SPACE(bs);

    memcpy(RPC_BS_GET_DATA(bs) + bs->offset, data, n);
    bs->offset += n;

    return n;
}

size_t RPC_bs_read(RPC_bs_t bs, void* data, size_t n) {
    assert(RPC_BS_IS_VALID(bs));
    assert(data != NULL);
    assert(n);

    if (!bs->offset)
        return 0u;

    if (n > bs->offset)
        n = bs->offset;

    memcpy(data, RPC_BS_GET_DATA(bs) + bs->offset - n, n);
    bs->offset -= n;
    
    return n;
}

void RPC_bs_flush(RPC_bs_t bs) {
    assert(RPC_BS_IS_VALID(bs));

    bs->offset = 0u;
}


size_t RPC_bs_merge(RPC_bs_t lhs, RPC_bs_t rhs) {
    assert(RPC_BS_IS_VALID(lhs));
    assert(RPC_BS_IS_VALID(rhs));

    size_t n = rhs->offset;

    if ((n + lhs->offset) > lhs->allocated)
        n = lhs->allocated - lhs->offset;

    void* memory = (void*)(RPC_BS_GET_DATA(lhs) + lhs->offset);
    RPC_bs_read(rhs, memory, n);
    lhs->offset += n;
    
    return n;
}

size_t RPC_bs_size(const RPC_bs_t bs) {
    assert(RPC_BS_IS_VALID(bs));
    return bs->offset;
}

size_t RPC_bs_allocated(const RPC_bs_t bs) {
    assert(RPC_BS_IS_VALID(bs));
    return bs->allocated;
}

#pragma endregion