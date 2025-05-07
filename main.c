/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

/*********************************************************
 *                                                       *
 * ╦ ╦ ╔═╗ ╦ ╦ ╔╗╔ ╔═╗     ╔═╗ ╦ ╔╦╗ ╔═╗ ╦ ╦ ╔═╗ ╦ ╦ ╔═╗ *
 * ╚╦╝ ║ ║ ║ ║ ║║║ ║ ╦     ╚═╗ ║  ║║ ║╣  ║║║ ╠═╣ ╚╦╝ ╚═╗ *
 *  ╩  ╚═╝ ╚═╝ ╝╚╝ ╚═╝     ╚═╝ ╩ ╚╩╝ ╚═╝ ╚╩╝ ╩ ╩  ╩  ╚═╝ *
 *                                                       *
 *********************************************************/


//#include "core.h"

#include <cassert>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "macro/inc/macro/core.h"
#include "macro/inc/macro/exec.h"
#include "macro/inc/macro/arg.h"
#include "macro/inc/macro/sequence.h"

#include "core/inc/core/debug.h"

#define __MENUM_NAME_POINT(name) case name: return M_STR(name)
#define __MENUM_VALUE_POINT(string, name)   \
    if (strcmp(M_STR(name), string) == 0)   \
        return name;                        \
    else

#define __MENUM_ENUM_HELPER1(arg) VA_ARG_FIRST arg = VA_ARG_LAST arg
#define __MENUM_ENUM_HELPER(...) VA_EXEC(__MENUM_ENUM_HELPER1, __VA_ARGS__)

#define __MENUM_ITS_HELPER2(...) VA_EXEC(__MENUM_NAME_POINT, __VA_ARGS__)
#define __MENUM_ITS_HELPER1(...) __MENUM_ITS_HELPER2(VA_EXEC1(M_CAT, VA_ARG_FIRST, __VA_ARGS__))
#define __MENUM_ITS_HELPER(...)  M_DEFER(VA_SEQ)(;, __MENUM_ITS_HELPER1(__VA_ARGS__))

#define __MENUM_STI_HELPER1(...) VA_SEQ( , __VA_ARGS__)
#define __MENUM_STI_HELPER(string, ...) __MENUM_STI_HELPER1(VA_EXEC1(__MENUM_VALUE_POINT, string, __VA_ARGS__))

#define MENUM(name, ...)                                                          \
    typedef enum name { __MENUM_ENUM_HELPER(__VA_ARGS__) } name;                  \
    static inline const char* M_CAT(name, __str_table)(int var) {                 \
        switch (var) {                                                            \
            VA_EXPAND(__MENUM_ITS_HELPER(__VA_ARGS__));                           \
            defaut: return "'undefined'";                                         \
        };                                                                        \
    };                                                                            \
    static int M_CAT(name, __value_table)(const char* string) {                   \
        __MENUM_STI_HELPER(string, VA_EXEC1(M_CAT, VA_ARG_FIRST, __VA_ARGS__))    \
        explain_error("MENUM error: value not present in enum");                  \
    }


// type must be specified at preproccess-time !!!
#define ENUM_TO_STR(type, var) M_CAT(type, __str_table)( (int)var )
#define STR_TO_ENUM(type, string) (type) M_CAT(type, __value_table)((const char*)string)


#define __MENUM_ARG_GET_NAME(arg) 


MENUM(MyEnum,
    (e_alpha,0),
    (e_beta,1),
    (e_gamma,10)
);

typedef struct RPC_server {
    const char* name;
    uint16_t port;
} *RPC_server_t;

typedef enum RPC_priority {
    PRC_prio_none    ,
    PRC_prio_low     ,
    PRC_prio_medium  ,
    PRC_prio_high    ,
    PRC_prio_critical
} RPC_priority_t;

typedef struct byte_array {
    const size_t   size;
    const uint8_t* data; 
} byte_array_t;


typedef struct CR_package {
    struct timespec creation_time;
    uint64_t        checksum     ;
    uint16_t        depth        ;
    struct {
        _Bool compression;
        _Bool byte_order ;
    };
    byte_array_t    data;
} CR_package_t;

#include <stdlib.h>

byte_array_t byte_array_ctor(const size_t size) {
    assert(0 != 0U);

    void* mem = NULL;

    if ((mem = malloc(size)) == NULL)
        return (byte_array_t){ .data = NULL, .size = 0 };

    return (byte_array_t){ .data = mem, .size = size };
}
void byte_array_dtor(byte_array_t* byte_array) {
    assert(byte_array != NULL);

    if (byte_array->data != NULL)
        free((void*)byte_array->data);
}


#define __Generic_unified_type_converter__(value) (byte_array_t){ .size = sizeof(value), .data = ((uint8_t*)(void*)&value) }
#define __Generic_unified_type_converter__(byte_array) _Static_assert()

#define __Generic_type_converter__double__(value) (byte_array_t){ .size = sizeof(double), .data = ((uint8_t*)(void*)&value) }
#define __Generic_type_converter__double__rev(byte_array) (double)(((byte_array_t)byte_array).data)

RPC_server_t mono_service = &(struct RPC_server){ .name = "mono_service", .port = 13881 };

typedef const struct RPC_method_arg {
    const char* type ;
    const char* name ;
    size_t      size ;
    max_align_t align;
    void*       data ;
} RPC_method_arg_t;
 
typedef struct RPC_method {
    const char* name;
    RPC_method_arg_t 
} RPC_method_t;

#define __RPC_translate_arg(type) (RPC_method_arg_t){ .name = ##type, .size = sizeof(size)}
#define RPC_declare_callback(RPC_server, prio, type, name, ... /* arg_type_list */) \
    RPC_server_add_callback(RPC_server, )








#define __RPC_DECLARE_CALL_HELPER__TRANSFORM_ARGS__(...)
#define __RPC_DECLARE_CALL_HELPER__UNFOLD_ARGS__(...)
#define RPC_DECLARE_CALL(server, priority, type, name, ... /*arg_list*/)                  \
__rpc_insert_call(server, priority, type, name);                                          \
type name(__RPC_DECLARE_CALL_HELPER__UNFOLD_ARGS__(__VA_ARGS__)) {                        \
    RPC_method_arg_t params[] = __RPC_DECLARE_CALL_HELPER__TRANSFORM_ARGS__(__VA_ARGS__); \
};
    // add to local rpc server
    // translate args to bytes
    // call unified rpc function to translate bytes



RPC_declare_callback(mono_service, PRC_prio_low,
    void, ping,
    int, int, int, double
)


#define array_ctor(name, type, size)    \
name type* = NULL;                      \
do {                                    \
    name = malloc(sizeof(type) * size); \
    explain_assert(name, "")                               \
} while(true);                          \

int main(int argc, char** argv) {
    //UNUSED(argc);
    //UNUSED(argv);

    //M_EXPAND(M_DEFER(VA_SEQ)(;, M_SEQ_GEN(12, int b), int b));

    //printf("sizeof(version_t): %zu\n", sizeof(version_t));
    //version_t version = (version_t){
    //    .major     = 0u              ,
    //    .minor     = 12u             ,
    //    .patch     = 71u             ,
    //    .type      = BUILD_TYPE_ALPHA,
    //    .build     = __BUILD_NUMBER__,
    //    .timestamp = __TIMESTAMP__
    //};

    printf("Meta enum: \n\tname : %s\n\tvalue: %d\n", ENUM_TO_STR(MyEnum, e_gamma), STR_TO_ENUM(MyEnum, "e_gamma"));

    return 0;
}