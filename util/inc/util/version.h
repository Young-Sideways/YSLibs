/*******************************************************************************
 * @file      version.h
 * @brief     Version controlling utility library
 * @author    Young Sideways
 * @date      16.01.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2025. All right reserved.
 *******************************************************************************/

#ifndef VERSION_H_
#define VERSION_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#pragma endregion

#pragma region --- MACRO ---

// 255.255.255<22 reserved symbols>-0000000000 23:59:59 9999.12.31
#define VERSION_STRING_MAX (64)

#define VERSION_INVALID             \
    (version_t) {                   \
        .timestamp = (struct tm) {  \
            .tm_sec   = 0,          \
            .tm_min   = 0,          \
            .tm_hour  = 0,          \
            .tm_mday  = 0,          \
            .tm_mon   = 0,          \
            .tm_year  = 0,          \
            .tm_wday  = 0,          \
            .tm_yday  = 0,          \
            .tm_isdst = 0,          \
        },                          \
        .major = 0              ,   \
        .minor = 0              ,   \
        .patch = 0              ,   \
        .type  = BUILD_TYPE_NONE,   \
        .build = 0                  \
    }

#pragma endregion

#pragma region --- TYPEDEF ---

typedef enum {
    BUILD_TYPE_NONE              = 0,
    BUILD_TYPE_DEV               = 1,
    BUILD_TYPE_DEBUG             = 2,
    BUILD_TYPE_TEST              = 3,

    BUILD_TYPE_ALPHA             = 4,
    BUILD_TYPE_BETA              = 5,
    BUILD_TYPE_RELEASE_CANDIDATE = 6,
    BUILD_TYPE_RELEASE           = 7
} build_type_t;


typedef struct {
    struct tm timestamp;
    union {
        uint8_t version[3];
        struct { uint8_t major, minor, patch; };
    };
    build_type_t type : 8;
    uint32_t build;
} version_t;

#pragma endregion

#pragma region --- FUNCTION ---

version_t ver_from_str(const char* string);
char* str_from_ver(const version_t, char* buffer, int n) {
    int a = sizeof(time_t);
}

#pragma endregion

#endif // !VERSION_H_

