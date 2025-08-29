/*******************************************************************************
 *  @file      manager.h
 *  @brief     manager collection members definition
 *  @note      only for internal use
 *  @author    Young Sideways
 *  @date      10.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_MANAGER_H_
#define C_MANAGER_H_


#include "../inc/collection/general.h"


enum : uint32_t {
    C_MNGR_CTX_STATE_NONE          = 0b00 << 0,
    C_MNGR_CTX_STATE_NEW           = 0b01 << 0,
    C_MNGR_CTX_STATE_CONSTRUCTED   = 0b10 << 0,
    C_MNGR_CTX_STATE_INVALID       = 0b11 << 0,
    C_MNGR_CTX_STATE_MASK          = C_MNGR_CTX_STATE_NEW         |
                                     C_MNGR_CTX_STATE_CONSTRUCTED |
                                     C_MNGR_CTX_STATE_INVALID         ,

    C_MNGR_CTX_SITE_NONE           = 0b00 << 2                        ,
    C_MNGR_CTX_SITE_BEGIN          = 0b01 << 2                        ,
    C_MNGR_CTX_SITE_END            = 0b10 << 2                        ,
    C_MNGR_CTX_SITE_FIRST          = C_MNGR_CTX_SITE_BEGIN            ,
    C_MNGR_CTX_SITE_LAST           = 0b11 << 2                        ,
    C_MNGR_CTX_SITE_MASK           = C_MNGR_CTX_SITE_BEGIN |
                                     C_MNGR_CTX_SITE_END   |
                                     C_MNGR_CTX_SITE_FIRST |
                                     C_MNGR_CTX_SITE_LAST             ,

    C_MNGR_CTX_DIRECTION_NONE      = 0b00 << 4                        ,
    C_MNGR_CTX_DIRECTION_FORWARD   = 0b01 << 4                        ,
    C_MNGR_CTX_DIRECTION_REVERSE   = 0b10 << 4                        ,
    C_MNGR_CTX_DIRECTION_ASSOCIATE = 0b11 << 4                        ,
    C_MNGR_CTX_DIRECTION_MASK      = C_MNGR_CTX_DIRECTION_FORWARD   |
                                     C_MNGR_CTX_DIRECTION_REVERSE   |
                                     C_MNGR_CTX_DIRECTION_ASSOCIATE   ,

    C_MNGR_CTX_NONE                = C_MNGR_CTX_STATE_NONE     |
                                     C_MNGR_CTX_SITE_NONE      |
                                     C_MNGR_CTX_DIRECTION_NONE        ,

    C_MNGR_CTX_MASK                = C_MNGR_CTX_STATE_MASK     |
                                     C_MNGR_CTX_SITE_MASK      |
                                     C_MNGR_CTX_DIRECTION_MASK        ,

    C_MNGR_CTX_INVALID = -1
};

#define c_mngr_ctx_state(ctx)     ((ctx) & C_MNGR_CTX_STATE_MASK    )
#define c_mngr_ctx_site(ctx)      ((ctx) & C_MNGR_CTX_SITE_MASK     )
#define c_mngr_ctx_direction(ctx) ((ctx) & C_MNGR_CTX_DIRECTION_MASK)

#define c_mngr_ctx_set_state(ctx, state)         (((ctx) & ((~C_MNGR_CTX_STATE_MASK    ) & C_MNGR_CTX_MASK)) | state    )
#define c_mngr_ctx_set_site(ctx, site)           (((ctx) & ((~C_MNGR_CTX_SITE_MASK     ) & C_MNGR_CTX_MASK)) | site     )
#define c_mngr_ctx_set_direction(ctx, direction) (((ctx) & ((~C_MNGR_CTX_DIRECTION_MASK) & C_MNGR_CTX_MASK)) | direction)

static inline bool c_mngr_ctx_is_valid(uint32_t context) {
    if (context == C_MNGR_CTX_INVALID)
}

/**
 * @typedef   c_mngr_t
 * @brief     declares a function prototype for universal access to any presented collections
 * @param[in]      collection pointer to collection
 * @param[in]      context    given context to construct/modify iterator structure
 * @param[in,out]  data       saved internal data
 * @param[in, out] index      saved internal index
 * @param[out]     value      return value for this accessor
 */
typedef void* (*c_mngr_t)(void* collection, int context, void** data, c_index_t* index);

struct c_mngr_hdlr_t {
    c_mngr_t mngr;
};

#define C_MNGR_SIZE       (sizeof(struct c_mngr_hdlr_t))
#define C_MNGR_DEFAULT    NULL
#define C_MNGR_GET(c_ptr) (((struct c_mngr_hdlr_t*)c_ptr) - 1)

#define C_MNGR_HDLR_PTR(name, c_ptr) const struct c_mngr_hdlr_t* const name = C_MNGR_GET(c_ptr)


#endif // !C_MANAGER_H_
