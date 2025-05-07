/*******************************************************************************
 * @file      type.h
 * @author    Young Sideways
 * @brief     Common types for RPC system
 * @date      07.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef RPC_TYPE_H_
#define RPC_TYPE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdint.h>
#include <stddef.h>
#include <threads.h>

#pragma endregion

#pragma region --- MACRO ---

#define RPC_BS_MAX_SIZE (4096 * 8)

#pragma endregion

#pragma region --- TYPEDEF ---

/**
 * @typedef RPC_bs_t defines struct, to hold bytestream of translated data
 */
typedef struct RPC_bs_t {
    uint8_t* data   ;
    uint8_t* start  ;
    uint8_t* end    ;
    size_t allocated;
} *RPC_bs_t;

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

RPC_bs_t RPC_bs_ctor(size_t size);
void RPC_bs_dtor(RPC_bs_t* bs);

#pragma endregion

#pragma region --- FUNCTION ---

/**
 * @brief            Writes \p n bytes of \p data in stream \p bs
 * @param bs[in,out] Stream
 * @param data[in]   Data pointer
 * @param n[in]      Number of bytes
 * @return           size_t Number of bytes successfully written
 */
size_t RPC_bs_write(RPC_bs_t bs, const void* data, size_t n);

/**
 * @brief            Reads \p n bytes of stream \p bs , and writes to \p data
 * @param bs[in,out] Stream
 * @param data[out]  Data pointer
 * @param n[in]      Number of bytes
 * @return           size_t Number of bytes successfully read
 */
size_t RPC_bs_read(RPC_bs_t bs, void* data, size_t n);

/**
 * @brief            Flushes stream \p bs
 * @param bs[in,out] Stream
 * @return           size_t Number of bytes successfully flushed
 */
size_t RPC_bs_flush(RPC_bs_t bs);

size_t RPC_bs_merge(RPC_bs_t lhs, RPC_bs_t rhs);

size_t RPC_bs_size(const RPC_bs_t bs);
size_t RPC_bs_allocated(const RPC_bs_t bs);

#pragma endregion

#endif // !RPC_TYPE_H_
