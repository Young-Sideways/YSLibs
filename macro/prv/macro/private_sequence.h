/*******************************************************************************
 *  @file      private_sequence.h
 *  @author    Young Sideways
 *  @date      13.06.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef M_PRIVATE_SEQUENCE_H_
#define M_PRIVATE_SEQUENCE_H_

#pragma once

#pragma region --- MACRO GENERATOR ---

#include <math.h>
#include <string.h>
#include <stdio.h>

void _va_seq_semi_printer(int n) {
    printf("#define M_SEQ_SEMI_0()\n");
    printf("#define M_SEQ_SEMI_1(_1) _1;\n");
    printf("#define M_SEQ_SEMI_2(_1, _2) _1; _2;\n");
    for (int i = 3; i < n; ++i)
        printf("#define M_SEQ_SEMI_%d(_1, ...) _1; M_SEQ_UNFOLD_%d(__VA_ARGS__)\n", i, i - 1);

    printf("#define M_SEQ_UNFOLD_0()\n");
    printf("#define M_SEQ_UNFOLD_1(_1) _1\n");
    printf("#define M_SEQ_UNFOLD_2(_1, _2) _1 _2\n");
    for (int i = 3; i < n; ++i)
        printf("#define M_SEQ_UNFOLD_%d(_1, ...) _1 M_SEQ_UNFOLD_%d(__VA_ARGS__)\n", i, i - 1);

    printf(
            "\n#ifdef _VARIADIC_H_\n\n"
            "#define VA_SEQ_SEMI(...) M_CONCAT_LATER(M_SEQ_SEMI_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)\n"
            "#define VA_SEQ_UNFOLD(...) M_CONCAT_LATER(M_SEQ_UNFOLD_, VA_NARG(__VA_ARGS__))(__VA_ARGS__)\n\n"
            "#endif // !_VARIADIC_H_\n\n"
            "#define VA_SEQ_COMMA(...) __VA_ARGS__\n"
    );
}

#pragma endregion

#endif // !M_PRIVATE_SEQUENCE_H_
