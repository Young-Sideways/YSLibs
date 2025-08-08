/*******************************************************************************
 * @file      expect.h
 * @brief     MACRO static expectation lib
 * @author    Young Sideways
 * @date      11.02.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2025. All right reserved.
 ******************************************************************************/

#ifndef M_EXPECT_H_
#define M_EXPECT_H_


#include <assert.h>

#include "generic/type.h"

#define M_EXPECT_T_EQUAL(lhs, rhs)                        \
    static_assert(                                        \
        G_TCOMPATIBLE(lhs, rhs),                          \
        "Expected type are unequal '"#lhs"' <-> '"#rhs"'" \
    )

#define M_EXPECT_T_EQUAL_SIZE(lhs, rhs)                                     \
    static_assert(                                                          \
        sizeof(lhs) == sizeof(rhs) ,                                        \
        "Expected type sizes are unequal sizeof("#lhs") <-> sizeof("#rhs")" \
    )


#endif //!M_EXPECT_H_
