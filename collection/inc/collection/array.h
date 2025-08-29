/*******************************************************************************
 *  @file      array.h
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef C_ARRAY_H_
#define C_ARRAY_H_


#ifdef C_GENERIC_H_
#   error Container library headers must be placed before <collection/generic.h> header
#endif


#include "general.h"

#include <core/core.h>
#include <macro/arg.h>
#include <algorithm/comparator.h>


#define ARRAY_SIZE_MIN C_SIZE_MIN
#define ARRAY_SIZE_MAX C_SIZE_MAX


YSL_BEGIN_DECLS


typedef struct {}* array_t;


#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

YSL_API array_t (arr_ctor)  (const c_size_t element_size, const c_size_t size);
#define          arr_ctor(type, ...) (arr_ctor)(sizeof(type), VA_MERGE((__VA_ARGS__), 0))

YSL_API array_t arr_copy    (const array_t array);
YSL_API array_t arr_shadow  (const array_t array);
YSL_API array_t arr_slice   (const array_t array, c_index_t from, c_index_t count);

YSL_API array_t (arr_move)  (array_t *array);
#define          arr_move(array)  (arr_move)(&array)

YSL_API void    (arr_dtor)  (array_t *array);
#define          arr_dtor(array)     (arr_dtor)((array_t*)&array)


#pragma endregion


#pragma region --- ACCESSOR ---

YSL_API c_size_t  arr_element_size(const array_t array);
YSL_API c_size_t  arr_size        (const array_t array);

YSL_API bool      (arr_contains)  (const array_t array, const void* value, comparator_s_t comparator);
YSL_API c_index_t (arr_find)      (const array_t array, const void* value, comparator_s_t comparator);

YSL_API void*     arr_at          (const array_t array, c_index_t index);
YSL_API void*     arr_front       (const array_t array);
YSL_API void*     arr_back        (const array_t array);

#define arr_contains(array, value, ...) (arr_contains)(array, (const void*)(YSL_TYPEOF_UNQUAL(value)[1]){ value }, VA_MERGE((__VA_ARGS__), NULL))
#define arr_find(array, value, ...)     (arr_find)    (array, (const void*)(YSL_TYPEOF_UNQUAL(value)[1]){ value }, VA_MERGE((__VA_ARGS__), NULL))

#pragma endregion


#pragma region --- MODIFIERS ---

YSL_API void* (arr_emplace)(array_t array, c_index_t index, const void* value);

#define arr_emplace(array, index, value) (arr_emplace)(array, index, (void*)((YSL_TYPEOF_UNQUAL(value)[1]){ value }))

#pragma endregion


#pragma region --- FUNCTIONS ---

YSL_API void  (arr_sort)   (array_t array, const comparator_s_t comparator);

#define arr_sort(array, ...) (arr_sort)(array, VA_MERGE((__VA_ARGS__), NULL))

#pragma endregion

YSL_END_DECLS

#endif // !C_ARRAY_H_
