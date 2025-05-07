/*******************************************************************************
 * @file      type.c
 * @author    Young Sideways
 * @brief     Common types for RPC system
 * @date      07.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include <cstring>
#include <sys/types.h>
#include <threads.h>
#pragma region --- INCLUDE ---

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../../inc/RPC/core/type.h"
#include "../../../core/inc/core/core.h"

#pragma endregion

#pragma region --- MACRO ---

#define RPC_BS_IS_VALID(bs) (                         \
        (bs            != NULL                      ) \
     && (bs->data      != NULL                      ) \
     && (bs->start     != NULL                      ) \
     && (bs->end       != NULL                      ) \
     && (bs->allocated != 0u                        ) \
     && (bs->end       <= (bs->data + bs->allocated)) \
     && (bs->start     <= bs->end                   ) \
    )
#define RPC_BS_GET_START_OFFSET(bs) (bs->start - bs->data)
#define RPC_BS_GET_END_OFFSET(bs) (bs->end - bs->data)
#define RPC_BS_AVAILABLE_SPACE(bs) (bs->end - bs->start)
#define RPC_BS_GET_DATA(bs) (((uint8_t*)bs) + sizeof(struct RPC_bs_t) + (size_t)(bs->offset))

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

RPC_bs_t RPC_bs_ctor(size_t size) {
    assert(size != 0u);
    assert(size <= RPC_BS_MAX_SIZE);

    RPC_bs_t bs = (RPC_bs_t)malloc(sizeof(struct RPC_bs_t) + size);
    if (YSL_LIKELY( bs != NULL )) {
        bs->data = (uint8_t*)malloc()
        bs->size      = size;
        bs->offset    = 0   ;
    }

    return bs;
}

void RPC_bs_dtor(RPC_bs_t* stream) {
    assert(stream != NULL);
    assert(*stream != NULL);
    assert((*stream)->size != 0);

    free(*stream);
    *stream = NULL;
}

#pragma endregion

#pragma region --- FUNCTION ---

size_t RPC_bs_write(RPC_bs_t bs, const void* data, size_t n) {
    assert(RPC_BS_IS_VALID(bs));
    assert(data != NULL);
    assert(n != 0);

    if (n > (bs->size - bs->offset))
        n = (size_t)(bs->size - bs->offset);

    uint8_t* memory = RPC_BS_GET_DATA(bs);
    memcpy(memory, data, n);
    bs->offset += n;

    return n;
}

size_t RPC_bs_read(RPC_bs_t bs, void* data, size_t n) {
    assert(RPC_BS_IS_VALID(bs));
    assert(data != NULL);
    assert(n != 0);


}

size_t RPC_bs_flush(RPC_bs_t bs) {
    assert(bs != NULL);
    assert(bs->size > 0);

}


size_t RPC_bs_merge(RPC_bs_t lhs, RPC_bs_t rhs) {
    
}

size_t RPC_bs_size(const RPC_bs_t bs) {

}

size_t RPC_bs_allocated(const RPC_bs_t bs) {

}

#pragma endregion