/*******************************************************************************
 *  @file      private.c
 *  @brief     private collection members definition
 *  @note      only for internal use
 *  @author    Young Sideways
 *  @date      19.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "private.h"

#pragma region --- INCLUDE ---

#include <string.h>

#include "../algorithm/swap.h"
#include "../core/macro/macro.h"

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
    const void* _comp,
    const void* _swap,
    const void* _srch,
    const void* _sort)
{
    return (struct collection_algorithm_adapter) {
        ._comp = M_ISNULL((void*)_comp, memcmp),
        ._swap = M_ISNULL((void*)_swap, swap),
        ._srch = (void*)_srch,
        ._sort = (void*)_sort
    };
}

struct collection_iterator_adapter alloc_cia(
    const u_acc_t _init,
    const u_acc_t _next,
    const u_acc_t _prev)
{
    explain_assert(_init, "collection error: invalid arg");
    explain_assert(_next, "collection error: invalid arg");
    explain_assert(_prev, "collection error: invalid arg");
    return (struct collection_iterator_adapter) {
        ._init = _init,
        ._next = _next,
        ._prev = _prev
    };
}

struct collection_manager_adapter alloc_cma(
    const u_mgr_t _copy,
    const u_mgr_t _dtor)
{
    assert(_copy);
    return (struct collection_manager_adapter) {
        ._copy = _copy,
        ._dtor = _dtor
    };
}

struct collection_private_header alloc_cph(
    struct collection_algorithm_adapter caa,
    struct collection_iterator_adapter cia,
    struct collection_manager_adapter cma,
    void* _data)
{
    return (struct collection_private_header) {
        .caa   = caa,
        .cia   = cia,
        .cma   = cma,
        ._data = _data
    };
}

#pragma endregion
