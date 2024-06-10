/*******************************************************************************
 *  @file      variadic.h
 *  @brief     Variadic macro definition
 *  @author    Young Sideways
 *  @date      25.03.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _M_VARIADIC_H_
#define _M_VARIADIC_H_

#pragma once

#pragma region --- MACRO ---

#include "macro/private_variadic.h"

#define VA_NARG(...)                                \
          VA_NARG_HELPER(                           \
              VA_HASCOMMA(__VA_ARGS__),             \
              VA_HASCOMMA(VA_COMMA __VA_ARGS__ ()), \
              VA_ARG_N_(__VA_ARGS__, VA_RSEQ_N())   \
        )

#pragma endregion

#endif // !_M_VARIADIC_H_
