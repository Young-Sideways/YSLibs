/*******************************************************************************
 *  @file      general.c
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "general.h"

#include <string.h>

struct collection_header header_allocator(
    _IN _NULLABLE const size_t size,
    _IN const size_t element_size,
    _IN _NULLABLE const comparator_pt _comp,
    _IN _NULLABLE const search_pt _search,
    _IN _NULLABLE const swap_pt _swap,
    _IN _NULLABLE const sort_pt _sort,
    _IN const internal_memory_access_t next,
    _IN const internal_memory_access_t prev,
    _IN _NULLABLE const internal_memory_access_t data_block,
    _IN _NULLABLE const internal_memory_access_t random_access)
{
    assert(next);
    assert(prev);

    struct collection_header result = {
        .size = size,
        .element_size = element_size,
        ._comp = _comp ? _comp : &memcmp,
        ._search = _search,
        ._swap = _swap ? _swap : &swap,
        ._sort = _sort,
        .next = next,
        .prev = prev,
        .data_block = data_block,
        .random_access = random_access
    };
    return result;
}