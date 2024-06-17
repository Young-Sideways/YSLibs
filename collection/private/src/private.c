/*******************************************************************************
 *  @file      private.c
 *  @brief     private collection members definition
 *  @note      only for internal use
 *  @author    Young Sideways
 *  @date      19.04.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "collection/private.h"

#pragma region --- INCLUDE ---

#include <string.h>

#include "debug.h"

#include "algorithm/swap.h"
#include "macro/macro.h"

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

struct collection_universal_header alloc_cuh(
    const size_t capacity,
    const size_t size,
    const size_t element_size)
{
    explain_assert(element_size, "collection error: size of element can't be zero");
    explain_assert(size <= capacity, "collection error: size greater than capacity");
    explain_assert(size <= COLLECTION_SIZE_MAX, "collection error: size greater than COLLECTION_SIZE_MAX");

    return (struct collection_universal_header) {
        .capacity = capacity,
        .size = size,
        .element_size = element_size
    };
}

struct collection_algorithm_adapter alloc_caa(
    const void* comparator_,
    const void* swap_      ,
    const void* search_    ,
    const void* sort_       )
{
    return (struct collection_algorithm_adapter) {
        .comparator_ = (void*)M_ISNULL(comparator_, (const void*)memcmp),
        .swap_       = (void*)M_ISNULL(swap_      , (const void*)swap  ),
        .search_     = (void*)search_                                   ,
        .sort_       = (void*)sort_
    };
}

struct collection_iterator_adapter alloc_cia(
    const u_acc_t init_,
    const u_acc_t next_,
    const u_acc_t prev_)
{
    explain_assert(init_, "collection error: invalid arg 'init_'");
    explain_assert(next_, "collection error: invalid arg 'next_'");
    explain_assert(prev_, "collection error: invalid arg 'prev_'");
    return (struct collection_iterator_adapter) {
        .init_ = init_,
        .next_ = next_,
        .prev_ = prev_
    };
}

struct collection_manager_adapter alloc_cma(
    const u_mgr_t copy_,
    const u_mgr_t dtor_)
{
    explain_assert(copy_, "collection error: invalid arg 'copy_'");
    return (struct collection_manager_adapter) {
        .copy_ = copy_,
        .dtor_ = dtor_
    };
}

struct collection_private_header alloc_cph(
    struct collection_algorithm_adapter caa,
    struct collection_iterator_adapter cia,
    struct collection_manager_adapter cma,
    void* data_)
{
    return (struct collection_private_header) {
        .caa   = caa  ,
        .cia   = cia  ,
        .cma   = cma  ,
        .data_ = data_
    };
}

#pragma endregion
