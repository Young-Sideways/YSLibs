/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/


//#define YSL_API
//#define YSL_BEGIN_DECLS
//#define YSL_END_DECLS
//#define YSL_LIKELY(...)

#include "../inc/collection/array.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "private.h"

#include <algorithm/search.h>
#include <algorithm/sort.h>
#include <algorithm/memory.h>


#pragma region --- PRIVATE ---

struct array {
    c_size_t size;
    c_size_t element_size;
};
#define HEADER_SIZE (sizeof(struct array))
#define HEADER_GET(ptr) ((struct array*)(((uint8_t*)ptr) - HEADER_SIZE - C_MNGR_SIZE))

#pragma endregion


#pragma region --- PRIVATE ---

static void* __mngr(void* collection, c_mngr_ctx_t context, void** data, c_index_t* index) {
    c_size_t element_size = HEADER_GET(collection)->element_size;
    c_size_t size         = HEADER_GET(collection)->size;

    array_t array = (array_t)collection;

    if (context == C_MNGR_CTX_INVALID || context == C_MNGR_CTX_NONE) {
        *data  = NULL           ;
        *index = C_INDEX_INVALID;
        return NULL;
    }
}


#pragma endregion


array_t (arr_ctor)  (const c_size_t element_size, const c_size_t size) {
    assert(element_size          ); // collection/array: invalid arg 'element_size' == 0u
    assert(size <= ARRAY_SIZE_MAX); // collection/array: invalid arg 'size' > ARRAY_SIZE_MAX

    array_t array = malloc(HEADER_SIZE + C_MNGR_SIZE + element_size * size);

    if ( YSL_LIKELY(array) ) {
        struct array         *arr_ptr   = (struct array*)array;
        struct c_mngr_hdlr_t *mngr_ptr  = (struct c_mngr_hdlr_t*)(arr_ptr + 1);

        arr_ptr->element_size = element_size;
        arr_ptr->size         = size;

        mngr_ptr->mngr = &__mngr;

        array = (array_t)(mngr_ptr + 1);
    }

    return array;
}

array_t arr_copy    (const array_t array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    c_size_t element_size = HEADER_GET(array)->element_size;
    c_size_t size         = HEADER_GET(array)->size;

    array_t new_array = (arr_ctor)(element_size, size);

    if (new_array)
        memcpy(new_array, array, element_size * size);

    return new_array;
}
array_t arr_shadow  (const array_t array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    c_size_t element_size = HEADER_GET(array)->element_size;
    c_size_t size         = HEADER_GET(array)->size;
    
    return (arr_ctor)(element_size, size);
}
array_t arr_slice   (const array_t array, c_index_t from, c_index_t count) {
    assert(array != NULL);                                    // collection/array: invalid arg 'array' == 'NULL'
    assert(from  != C_INDEX_INVALID);                         // collection/array: invalid arg 'from' == 'C_INDEX_INVALID'
    assert(count != C_INDEX_INVALID);                         // collection/array: invalid arg 'count' == 'C_INDEX_INVALID'
    c_size_t element_size = HEADER_GET(array)->element_size;
    c_size_t size         = HEADER_GET(array)->size;

    assert(from >= 0);                                        // collection/array: invalid arg 'from' < 0

    c_index_t absolute_from  = (count < 0) ? from + count + 1 : from;
    c_index_t absolute_count = (count < 0) ? -count           : count;

    assert(absolute_from >= 0);                               // collection/array: invalid bound - slice lies on lower bound
    assert((c_size_t)absolute_count <= size);                 // collection/array: invalid arg 'count' > array->size
    assert((c_size_t)absolute_from + absolute_count <= size); // collection/array: invalid bound - slice lies on upper bound

    array_t new_array = (arr_ctor)(element_size, absolute_count);

    if (new_array) {
        if (count < 0) {
            for (uint8_t *arr_ptr = ((uint8_t*)array) + (from * element_size),
                         *new_ptr = ((uint8_t*)new_array);
                    count != 0; 
                    arr_ptr -= element_size, new_ptr += element_size, count++)
                memcpy(new_ptr, arr_ptr, element_size);
        }
        else {
            memcpy(new_array, ((uint8_t*)array) + (absolute_from * element_size), absolute_count * element_size);
        }
    }

    return new_array;
}

array_t (arr_move)  (array_t *array) {
    assert(array != NULL);  // collection/array: invalid arg 'array' == 'NULL'
    assert(*array != NULL); // collection/array: invalid arg '*array' == 'NULL'

    array_t ret = *array;
    *array      = NULL  ;

    return ret;
}
void    (arr_dtor)  (array_t *array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    
    if (*array != NULL)
        free(GET_HEADER(*array));
}


c_size_t  arr_element_size(const array_t array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'

    return GET_HEADER(array)->element_size;
}
c_size_t  arr_size        (const array_t array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'

    return GET_HEADER(array)->size;
}

bool      (arr_contains)  (const array_t array, const void* value, comparator_s_t comparator) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    assert(value != NULL); // collection/array: invalid arg 'value' == 'NULL'
    c_size_t element_size = GET_HEADER(array)->element_size;
    c_size_t size         = GET_HEADER(array)->size;

    return !!linear_search(array, size, element_size, value, comparator);
}
c_index_t (arr_find)      (const array_t array, const void* value, comparator_s_t comparator) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    assert(value != NULL); // collection/array: invalid arg 'value' == 'NULL'
    c_size_t element_size = GET_HEADER(array)->element_size;
    c_size_t size         = GET_HEADER(array)->size;

    c_index_t ret = C_INDEX_INVALID;

    void* found = linear_search(array, size, element_size, value, comparator);
    if (found != NULL)
        ret = ((uint8_t*)found - (uint8_t*)array) / element_size;

    return ret;
}
void*     arr_at          (const array_t array, c_index_t index) {
    assert(array != NULL);            // collection/array: invalid arg 'array' == 'NULL'
    assert(index != C_INDEX_INVALID); // collection/array: invalid arg 'index' == 'C_INDEX_INVALID'
    c_size_t element_size = GET_HEADER(array)->element_size;
    c_size_t size         = GET_HEADER(array)->size;

    assert(index > -(c_index_t)size);
    assert(index < size);
    if (index < 0)
        index += size;

    return (void*)((uint8_t*)array + (index * element_size));
}
void*     arr_front       (const array_t array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    c_size_t size = GET_HEADER(array)->size;
    assert(size);          // collection/array: invalid array size == 0

    return (void*)array;
}
void*     arr_back        (const array_t array) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'
    c_size_t element_size = GET_HEADER(array)->element_size;
    c_size_t size = GET_HEADER(array)->size;
    assert(size);          // collection/array: invalid array size == 0

    return (void*)(((uint8_t*)array) + (size - 1) * element_size);
}


void* (arr_emplace)       (array_t array, c_index_t index, const void* value) {
    assert(array != NULL);            // collection/array: invalid arg 'array' == 'NULL'
    assert(value != NULL);            // collection/array: invalid arg 'value' == 'NULL'
    assert(index != C_INDEX_INVALID); // collection/array: invalid arg 'index' == 'C_INDEX_INVALID'

    c_size_t element_size = GET_HEADER(array)->element_size;
    c_size_t size         = GET_HEADER(array)->size;

    assert(index > -(c_index_t)size);
    assert(index < size);
    if (index < 0)
        index += size;

    return memcpy((void*)((uint8_t*)array + (index * element_size)), value, element_size);
}

void  (arr_sort)          (array_t array, const comparator_s_t comparator) {
    assert(array != NULL); // collection/array: invalid arg 'array' == 'NULL'

    c_size_t element_size = GET_HEADER(array)->element_size;
    c_size_t size         = GET_HEADER(array)->size;

    quick_sort(array, size, element_size, comparator);
}
