/*******************************************************************************
 *  @file      ottable.h
 *  @brief     Object Tag Table
 *  @author    Young Sideways
 *  @date      30.05.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef OTTABLE_H_
#define OTTABLE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdbool.h>
#include <stdint.h>

#pragma endregion

#pragma region --- MACRO ---

#define OTT_MAX_NAME_SIZE 128

#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct uuid_t {
    uint64_t hi;
    uint64_t lo;
} uuid_t;

typedef char name_t[OTT_MAX_NAME_SIZE];

typedef enum tag_type_t {
    TAG_NONE       ,

    TAG_BOOL       ,

    TAG_INT8       ,
    TAG_INT16      ,
    TAG_INT32      ,
    TAG_INT64      ,

    TAG_UINT8      ,
    TAG_UINT16     ,
    TAG_UINT32     ,
    TAG_UINT64     ,

    TAG_FLOAT      ,
    TAG_DOUBLE     ,
                   
    TAG_CHAR       ,
    TAG_STRING     ,

    TAG_UUID       ,

    TAG_TAG        ,
    TAG_OBJECT     ,

    TAG_TAG_LIST   ,
    TAG_OBJECT_LIST
} tag_type_t;

typedef uint32_t tag_size_t;

typedef union tag_value_t {
    bool                  bool_v    ;

    int8_t                int8_v    ;
    int8_t                int16_t   ;
    int8_t                int32_t   ;
    int8_t                int64_t   ;

    uint8_t               uint8_t   ;
    uint8_t               uint16_t  ;
    uint8_t               uint32_t  ;
    uint8_t               uint64_t  ;

    float                 float_v   ;
    double                double_v  ;

    char                  char_v    ;
    char*                 string_v  ;

    uuid_t                uuid_v    ;

    struct tag_t*         tag_v     ;
    struct object_t*      entity_v  ;

    struct tag_list_t*    tag_list_v;
    struct object_list_t* entity_v  ;
} tag_value_t;



typedef struct tag_t {
    name_t      name ;
    tag_value_t value;
    tag_type_t  type ;
    tag_size_t  size ;
} tag_t;

typedef struct object_t {
    name_t            name;
    struct tag_list_t tags;
} object_t;



typedef struct tag_list_t {
    struct tag_t* tags;
    size_t        size;
} tag_list_t;

typedef struct object_list_t {
    struct object_t* objects;
    size_t           size   ;
} object_list_t;

#pragma endregion

#pragma region --- CONSTRUCTOR / DESTRUCTOR ---
#pragma endregion

#pragma region --- FUNCION ---
#pragma endregion

#pragma region ---  ---
#pragma endregion

#endif // !OTTABLE_H_
