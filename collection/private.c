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

#pragma region --- MACRO ---
#pragma endregion

#pragma region --- TYPEDEF ---
#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

struct collection_universal_header alloc_cuh(
    _IN _NULLABLE const size_t capacity,
    _IN _NULLABLE const size_t size,
    _IN           const size_t element_size)
{
    explain_assert(element_size, "collection error: size of element can't be zero");
    explain_assert(size <= capacity, "collection error: size greater than capacity");

    return (struct collection_universal_header) {
        .capacity = capacity,
        .size = size,
        .element_size = element_size
    };
}

struct collection_algorithm_adapter alloc_caa(
    _IN _NULLABLE const void* _comp,
    _IN _NULLABLE const void* _swap,
    _IN _NULLABLE const void* _srch,
    _IN _NULLABLE const void* _sort)
{
    return (struct collection_algorithm_adapter) {
        ._comp = M_ISNULL(_comp, &memcmp),
        ._swap = M_ISNULL(_swap, &swap),
        ._srch = _srch,
        ._sort = _sort
    };
}

struct collection_iterator_adapter alloc_cia(
    _IN const u_acc_t _init,
    _IN const u_acc_t _next,
    _IN const u_acc_t _prev)
{
    assert(_init);
    assert(_next);
    assert(_prev);
    return (struct collection_iterator_adapter) {
        ._init = _init,
        ._next = _next,
        ._prev = _prev
    };
}

struct collection_manager_adapter alloc_cma(
    _IN           const u_mgr_t _copy,
    _IN _NULLABLE const u_mgr_t _dtor)
{
    assert(_copy);
    return (struct collection_manager_adapter) {
        ._copy = _copy,
        ._dtor = _dtor
    };
}

struct collection_private_header alloc_cph(
    _IN           struct collection_algorithm_adapter caa,
    _IN           struct collection_iterator_adapter cia,
    _IN           struct collection_manager_adapter cma,
    _IN _NULLABLE void* _data)
{
    return (struct collection_private_header) {
        .caa   = caa,
        .cia   = cia,
        .cma   = cma,
        ._data = _data
    };
}

#pragma endregion
