/*******************************************************************************
 *  @file      private.h
 *  @brief     private collection members definition
 *  @note      only for internal use
 *  @author    Young Sideways
 *  @date      10.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef COLLECTION_PRIVATE_H_
#define COLLECTION_PRIVATE_H_

#pragma once

#pragma region --- INCLUDES ---

#include <stdarg.h>

#include "general.h"

#include "algorithm/search.h"
#include "algorithm/sort.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

enum c_memory_tag_e {
    CM_TAG_HEADER_DETACHED = 1 << 49,
    CM_TAG_CUSTOM_VTABLE   = 1 << 50,
};

#define YSL_TAGGED_POINTERS
#ifdef YSL_TAGGED_POINTERS

#endif

typedef void* (*c_mem_mngr_t)(void** collection, int n, va_list list);

struct collection_vtable_s {
  // ctor/dtor
    const c_mem_mngr_t _copy        ; // copy(*)
    const c_mem_mngr_t _dtor        ; // delete(*)
    // also 'shadow', 'slice'
  // info
    const c_mem_mngr_t _element_size; // element_size(*), element_size(*, 0/1), element_size(*, index)
    const c_mem_mngr_t _size        ; // size(*)        , size(*, 0/1)        , size(*, dimension)
    const c_mem_mngr_t _capacity    ; // capacity(*)
//   const c_info_mngr_t _count       ; // count(*, value)
//   //          *--->   _contains    ; // contains(*, value) -> count(*, value) ? true : false
  // data
//    const c_data_mngr_t _data        ; // data(*)
//    const c_data_mngr_t _at          ; // at(*, index)   , at(*, key)          , at(*, dimension1, dimension2, ...)
//    const c_data_mngr_t _find        ; // data(*, value)
  // enumeration
    const c_mem_mngr_t _init        ; // iterate through collection
    const c_mem_mngr_t _next        ; // iterate through collection
    const c_mem_mngr_t _prev        ; // iterate through collection
  // internal
    comparator_t       _comparator  ; // only internal use
    search_t           _search      ; // only internal use
    sort_t             _sort        ; // only internal use
};

#pragma endregion

#pragma region --- MACRO ---



#pragma endregion

#pragma region --- PLACEHOLDER ---

/*
 * this function works as placeholder for some use cases
 * the function assigns to itself a certain publicly accessible address,
 * but does not perform any role. The function can be used as a reserved value such as NULL
 */
extern void function_placeholder__();

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

bool is_custom_vtable(void* ptr);

#pragma endregion

#pragma region --- STATIC ASSERTION BLOCK ---

#define TYPE_SIZE_ASSERT(expression) static_assert(expression, "Collection core error: default type pointers have different sizes")
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(char*)              );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(short*)             );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(int*)               );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long*)              );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long long*)         );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed char*)       );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed short*)      );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed int*)        );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long*)       );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(signed long long*)  );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned char*)     );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned short*)    );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned int*)      );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long*)     );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(unsigned long long*));
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(float*)             );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(double*)            );
TYPE_SIZE_ASSERT(sizeof(void*) == sizeof(long double*)       );

static_assert(sizeof(int32_t) == sizeof(uint32_t), "Collection core error: fixed size for signed and unsigned 32 bit integers are different");
#undef TYPE_SIZE_ASSERT

#pragma endregion

#endif // !COLLECTION_PRIVATE_H_
