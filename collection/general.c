/*******************************************************************************
 *  @file      general.c
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "general.h"

#pragma region --- INCLUDE ---

#include <string.h>
#include "../algorithm/swap.h"

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

struct collection_header header_allocator(
    _IN _NULLABLE const size_t                   capacity,
    _IN           const size_t                   element_size,
    _IN _NULLABLE const void*                    _comp,
    _IN _NULLABLE const void*                    _search,
    _IN _NULLABLE const void*                    _swap,
    _IN _NULLABLE const void*                    _sort,
    _IN           const internal_memory_access_t next,
    _IN           const internal_memory_access_t prev,
    _IN _NULLABLE const internal_memory_access_t data_block,
    _IN           const internal_memory_access_t random_access)
{
    explain_assert(capacity <= COLLECTION_SIZE_MAX, "Collection core error: maximum container size has been exceeded");
    explain_assert(element_size, "Collection core error: size of element can't be null");
    assert(next);
    assert(prev);
    assert(random_access);

    struct collection_header result = {
        .capacity       = capacity,
        .size           = 0u,
        .element_size   = element_size,
        ._comp          = (_comp ? _comp : &memcmp),
        ._search        = _search,
        ._swap          = (_swap ? _swap : &swap),
        ._sort          = _sort,
        .next           = next,
        .prev           = prev,
        .data_block     = data_block,
        .random_access  = random_access
    };
    return result;
}

#pragma endregion
