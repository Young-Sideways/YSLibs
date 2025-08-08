/*******************************************************************************
 *  @file      test.h
 *  @brief     YSLibs testing framework
 *  @author    Young Sideways
 *  @date      08.07.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#pragma region --- INLUDE ---

#pragma STDC FENV_ACCESS ON

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <fenv.h>
#include <wchar.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#pragma endregion

#pragma region --- MACRO ---

#define LOG_ERR(emsg) fprintf(stderr, emsg " failed at line %d in file '%s'\n", __LINE__, __FILE__)
#define LOG_WARN(wmsg, ...) fprintf(stderr, wmsg " .line: %d\n", __VA_ARGS__, __LINE__)

#define INT_EQ(lhs, rhs)   \
    if(lhs != rhs) {       \
        LOG_ERR("INT_EQ"); \
        exit(1);           \
    }


#define MAX(lhs, rhs) \
    (((lhs) > (rhs)) ? (lhs) : (rhs))
#define MIN(lhs, rhs) \
    (((lhs) < (rhs)) ? (lhs) : (rhs)) 


#define FLT_FLT_EQ_HELPER(lhs, rhs)                                           \
{                                                                             \
    if (fabsf(a - b) > FLT_EPSILON * MAX(fabsf(a), fabsf(b))) {               \
        LOG_ERR("FLT_EQ");                                                    \
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}
#define FLT_DBL_EQ_HELPER(lhs, rhs)                                           \
{                                                                             \
    LOG_WARN("floats have different types 'float' <-> 'double'");             \
    if (fabs(a - b) > DBL_EPSILON * MAX(fabs(a), fabs(b))) {                  \
        LOG_ERR("DBL_EQ");                                                    \
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}
#define FLT_LDBL_EQ_HELPER(lhs, rhs)                                          \
{                                                                             \
    LOG_WARN("floats have different types 'float' <-> 'long double'");        \
    if (fabsl((long double)a - b) > LDBL_EPSILON * MAX(fabsl(a), fabsl(b))) { \
        LOG_ERR("LDBL_EQ");                                                   \
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}

#define DBL_DBL_EQ_HELPER(lhs, rhs)                                           \
{                                                                             \
    if (fabs(a - b) > DBL_EPSILON * MAX(fabs(a), fabs(b))) {                  \
        LOG_ERR("DBL_EQ");                                                    \
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}
#define DBL_LDBL_EQ_HELPER(lhs, rhs)                                          \
{                                                                             \
    LOG_WARN("floats have different types 'double' <-> 'long double'");       \
    if (fabsl((long double)a - b) > LDBL_EPSILON * MAX(fabsl(a), fabsl(b))) { \
        LOG_ERR("LDBL_EQ");                                                   \
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}

#define LDBL_LDBL_EQ_HELPER(lhs, rhs)                                         \
{                                                                             \
    if (fabsl(a - b) > LDBL_EPSILON * MAX(fabsl(a), fabsl(b))) {              \
        LOG_ERR("LDBL_EQ");                                                   \
        exit(EXIT_FAILURE);                                                   \
    }                                                                         \
}

#define FLT_EQ_HELPER(lhs, rhs)                     \
    _Generic( (rhs)                               , \
        float      : FLT_FLT_EQ_HELPER(lhs, rhs)  , \
        double     : FLT_DBL_EQ_HELPER(lhs, rhs)  , \
        long double: FLT_LDBL_EQ_HELPER(lhs, rhs) , \
    )
#define DBL_EQ_HELPER(lhs, rhs)                     \
    _Generic( (rhs)                               , \
        float      : FLT_DBL_EQ_HELPER(rhs, lhs)  , \
        double     : DBL_DBL_EQ_HELPER(lhs, rhs)  , \
        long double: DBL_LDBL_EQ_HELPER(lhs, rhs) , \
    )
#define LDBL_EQ_HELPER(lhs, rhs)                    \
    _Generic( (rhs)                               , \
        float      : FLT_LDBL_EQ_HELPER(rhs, lhs) , \
        double     : DBL_LDBL_EQ_HELPER(rhs, lhs) , \
        long double: LDBL_LDBL_EQ_HELPER(lhs, rhs), \
    )
#define FLT_EQ(lhs, rhs)                            \
    _Generic( (lhs)                               , \
        float      : FLT_EQ_HELPER(lhs, rhs)      , \
        double     : DBL_EQ_HELPER(lhs, rhs)      , \
        long double: LDBL_EQ_HELPER(lhs, rhs)     , \
    )

#pragma endregion

#pragma region --- FUNCTION ---

#pragma endregion