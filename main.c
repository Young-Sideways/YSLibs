/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

//#include "core.h"

#include <stdio.h>


#include <stdint.h>
typedef struct {
    uint32_t size;
    char* name;
    char value[];
} *value_t;

typedef struct {
    uint32_t size_;
    char*    name_;
    void*    dflt_;
    void*    ctor_;
    void*    dtor_;
    void*    copy_;
} const type_t;

#define declare_type(type, dflt, ctor, dtor, copy)          \
(type_t){                                                   \
    .size_ = sizeof(type)                                 , \
    .name_ = #type                                        , \
    .dflt_ = memdup((type[1]){ (type)dflt }, sizeof(type)), \
    .ctor_ = ctor                                         , \
    .dtor_ = dtor                                         , \
    .copy_ = copy                                           \
}


typedef enum {
    BUILD_TYPE_MIN               = 0,
    BUILD_TYPE_MAX               = 6,

    BUILD_TYPE_DEV               = 0,
    BUILD_TYPE_DEBUG             = 1,
    BUILD_TYPE_TEST              = 2,

    BUILD_TYPE_ALPHA             = 3,
    BUILD_TYPE_BETA              = 4,
    BUILD_TYPE_RELEASE_CANDIDATE = 5,
    BUILD_TYPE_RELEASE           = 6
} build_type_t;

static const char* build_type_names[] = {
    "dev"  ,
    "debug",
    "test" ,
    "a"    ,
    "b"    ,
    "rc"   ,
    ""
};

// 1.2.5-rc3-273645 04:32:17 16.04.2024 
typedef struct {
    union {
        uint8_t version[3];
        struct { uint8_t major, minor, patch; };
    };
    build_type_t type : 8;
    uint32_t build;
    const char* timestamp;
} version_t;

#define __BUILD_NUMBER__ (7263)
int main(int argc, char** argv) {
    //UNUSED(argc);
    //UNUSED(argv);

    //M_EXPAND(M_DEFER(VA_SEQ)(;, M_SEQ_GEN(12, int b), int b));

    printf("sizeof(version_t): %zu\n", sizeof(version_t));
    version_t version = (version_t){
        .major     = 0u              ,
        .minor     = 12u             ,
        .patch     = 71u             ,
        .type      = BUILD_TYPE_ALPHA,
        .build     = __BUILD_NUMBER__,
        .timestamp = __TIMESTAMP__
    };
    return 0;
}
