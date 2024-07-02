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

#include "general.h"

#pragma endregion

#pragma region --- TYPEDEFS ---

/**
 *  @typedef u_acc_t
 *  @brief   function prototype typedef for unifying access to container memory
 *  @param[in]     collection - Pointer to main collection structure
 *  @param[in,out] block      - init/processed block
 *  @param[in,out] stage      - init/processed stage
 */
typedef void (*u_acc_t)(struct collection_universal_header* collection, void** block, int* stage);

/**
 *  @typedef u_mgr_t
 *  @brief   function prototype typedef for unifying collection managing
 *  @param[in]     collection - Pointer to main collection structure
 */
typedef void* (*u_mgr_t)(void* collection);

/**
 *  @struct collection_algorithm_adapter
 *  @brief  algorithm adapter header
 * 
 *  default field policy:
 *      NULL   : this algorithm can NOT be applied
 *      POINTER: this algorithm can be applied to the container, and function pointer can be replaced to another function
 */
struct collection_algorithm_adapter {
    void* comparator_;
    void* swap_      ;
    void* search_    ;
    void* sort_      ;
};

/**
 *  @struct collection_iterator_adapter
 *  @brief  iterator adapter header
 */
struct collection_iterator_adapter {
    u_acc_t init_;
    u_acc_t next_;
    u_acc_t prev_;
};

/**
 *  @struct collection_manager_adapter
 *  @brief  collection manager adapter
 *  default field policy:
 *      _copy: can NOT be NULL
 *      _dtor:
 *          NULL: data memory block places after container specific header, and no need to deallocate separately
 */
struct collection_manager_adapter {
    u_mgr_t copy_;
    u_mgr_t dtor_;
};

/**
 *  @struct collection_private_header
 *  @brief  private header, that's contain info about collection
 */
struct collection_private_header {
    struct collection_algorithm_adapter caa  ;
    struct collection_iterator_adapter  cia  ;
    struct collection_manager_adapter   cma  ;
    void*                               data_;
};

#pragma endregion

#pragma region --- MACRO ---

#define CPH_EXTRACT(collection) (((struct collection_private_header*)(collection)) - 1)

#define CPH_REF(collection, name) struct collection_private_header* name = CPH_EXTRACT(collection)
#define CPH_CREF(collection, name) const struct collection_private_header* const name = CPH_EXTRACT(collection)

#pragma endregion

#pragma region --- PLACEHOLDER ---
/*
 * this function works as placeholder for some use cases
 * the function assigns to itself a certain publicly accessible address,
 * but does not perform any role. The function can be used as a reserved value such as NULL
 */
extern void private_collection_function_placeholder_();

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---

struct collection_universal_header alloc_cuh(
    size_t capacity    ,
    size_t size        ,
    size_t element_size
);

struct collection_algorithm_adapter alloc_caa(
    const void* comparator_,
    const void* swap_      ,
    const void* search_    ,
    const void* sort_
);

struct collection_iterator_adapter alloc_cia(
    u_acc_t init_,
    u_acc_t next_,
    u_acc_t prev_
);

struct collection_manager_adapter alloc_cma(
    u_mgr_t copy_,
    u_mgr_t dtor_
);

struct collection_private_header alloc_cph(
    struct collection_algorithm_adapter caa  ,
    struct collection_iterator_adapter  cia  ,
    struct collection_manager_adapter   cma  ,
    void*                               data_
);

#pragma endregion

typedef struct private_collection_type_info {
    uint32_t size ;
    uint32_t align;
} private_collection_type_info;

typedef struct {

} collection_private_header;

typedef struct {

} collection_private_iterator_adapter_header;

typedef struct {

} collection_private_algorithm_adapter_header;

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
