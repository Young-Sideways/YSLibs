/*******************************************************************************
 * @file      version.h
 * @brief     Version controlling utility library
 * @author    Young Sideways
 * @date      16.01.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2025. All right reserved.
 *******************************************************************************/

#ifndef VERSION_H_
#define VERSION_H_


#include <stdint.h>
#include <stdbool.h>
#include <time.h>


#pragma region --- MACRO ---

#define VERSION_INVALID                \
    (version_t) {                      \
        .time  = 0                 ,   \
        .major = 0                 ,   \
        .minor = 0                 ,   \
        .patch = 0                 ,   \
        .type  = BUILD_TYPE_RELEASE,   \
        .build = 0                     \
    }

#pragma endregion

#pragma region --- TYPEDEF ---

typedef enum : uint8_t {
    BUILD_TYPE_RELEASE           = 0,
    BUILD_TYPE_RELEASE_CANDIDATE = 1,
    BUILD_TYPE_BETA              = 2,
    BUILD_TYPE_ALPHA             = 3,

    BUILD_TYPE_MASK              = BUILD_TYPE_ALPHA | BUILD_TYPE_BETA | BUILD_TYPE_RELEASE_CANDIDATE | BUILD_TYPE_RELEASE ,

    BUILD_TYPE_ATTRIBUTE_DEV     = 1 << 2,
    BUILD_TYPE_ATTRIBUTE_DEBUG   = 1 << 3,
    BUILD_TYPE_ATTRIBUTE_VERBOSE = 1 << 4,
    BUILD_TYPE_ATTRIBUTE_TEST    = 1 << 5,

    BUILD_TYPE_ATTRIBUTE_MASK    = BUILD_TYPE_ATTRIBUTE_DEV | BUILD_TYPE_ATTRIBUTE_DEBUG | BUILD_TYPE_ATTRIBUTE_VERBOSE | BUILD_TYPE_ATTRIBUTE_TEST,

    BUILD_TYPE_REVISION_0    = 0 << 6, // e.g. 'rc' - stains for 'release candidate'
    BUILD_TYPE_REVISION_1    = 1 << 6, // e.g. 'rc1' - stains for 'release candidate 1'
    BUILD_TYPE_REVISION_2    = 2 << 6, // e.g. 'rc2' - stains for 'release candidate 2'
    BUILD_TYPE_REVISION_3    = 3 << 6, // e.g. 'rc3' - stains for 'release candidate 3'

    BUILD_TYPE_REVISION_MASK = BUILD_TYPE_REVISION_1 | BUILD_TYPE_REVISION_2 | BUILD_TYPE_REVISION_3
} build_type_t;


typedef struct {
    time_t time;
    uint32_t build;
    union {
        uint8_t version[3];
        struct { uint8_t major, minor, patch; };
    };
    build_type_t type;
} version_t;

#pragma endregion


#pragma region --- FUNCTION ---

version_t ver_from_str(const char* string);

// TODO: change sig to int (*ver_to_str)(...) and accept 'buffer' NULL promotion
/**
 * @brief converts \p version object to a string representation
 * @details Function works with \p buffer with in given \p format \n
 *  %_M - major\n
 *  %_m - minor\n
 *  %_p - patch\n
 *  %_t - build type\n
 *  %_a - build attributes\n
 *  %_T - build type with attributes '%_t %_a'\n
 *  %_v - build version\n
 *  default format string = "%_M.%_m.%_p %_T:%_v %F %T"
 * @param version     version object
 * @param buffer      pointer to buffer
 * @param buffer_size size of given pointer
 * @param format      format string
 * @return \p buffer if success, otherwise NULL
 */
char* ver_to_str(const version_t version, char* buffer, size_t buffer_size, const char* restrict format);

#pragma endregion

#endif // !VERSION_H_
