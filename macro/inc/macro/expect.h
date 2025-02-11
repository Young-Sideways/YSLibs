/*******************************************************************************
 * @file      expect.h
 * @brief     MACRO static expectation lib
 * @author    Young Sideways
 * @date      11.02.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2025. All right reserved.
 ******************************************************************************/

#ifndef M_EXPECT_H_
#define M_EXPECT_H_

#pragma once

#pragma region --- MACRO ---

#define M_EXPECT_T_EQUAL(lhs, rhs)                        \
    static_assert(                                        \
        _Generic( ( (typeof_unqual(lhs))0 ) ,             \
            typeof_unqual(rhs) : 1,                       \
            default            : 0                        \
        ),                                                \
        "Expected type are unequal '"#lhs"' <-> '"#rhs"'" \
    )

#define M_EXPECT_T_EQUAL_SIZE(lhs, rhs)                                     \
    static_assert(                                                          \
        sizeof(lhs) == sizeof(rhs) ,                                        \
        "Expected type sizes are unequal sizeof("#lhs") <-> sizeof("#rhs")" \
    )


#pragma endregion

#endif //!M_EXPECT_H_