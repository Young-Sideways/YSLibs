/*******************************************************************************
 *  @file      private_reverse.h
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef M_PRIVATE_REVERSE_H_
#define M_PRIVATE_REVERSE_H_

#pragma once

#pragma region --- MACRO GENERATOR ---

#include <math.h>
#include <string.h>
#include <stdio.h>

void _va_arg_reverse_printer(int n) {
    int padding = log10(n) + 1;
    if (n > 0)
        printf("#define M_ARG_REVERSE_1(_1) _1\n");
    if (n > 1)
        printf("#define M_ARG_REVERSE_2(_1, _2) _2, _1\n");
    for (int i = 3; i < n; ++i) {
        printf("#define M_ARG_REVERSE_%d(_1, ...) M_ARG_REVERSE_%d(__VA_ARGS__), _1\n", i, i - 1);
    }
    printf("\n#ifdef _VADIDATIC_H_\n\n#define VA_ARG_REVERSE(...) M_CONCAT(M_ARG_REVERSE_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)\n\n#endif // !_VADIDATIC_H_");
}

#pragma endregion

#endif // !M_PRIVATE_REVERSE_H_
