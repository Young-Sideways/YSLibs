/*******************************************************************************
 *  @file      private_variadic.h
 *  @author    Young Sideways
 *  @date      10.06.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef M_PRIVATE_VARIADIC_H_
#define M_PRIVATE_VARIADIC_H_

#pragma once

#pragma region --- MACRO GENERATOR ---

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

 // VA_ARG_N printer
void _va_arg_n_printer(int n, const char* name, int separate) {
    int padding = log10(n) + 1;
    printf("#define %s(", name);
    if (separate)
        printf(" \\\n\t");
    for (int i = 1; i < n; i++) {
        char num[16];
        snprintf(num, 16, "_%d,", i);
        printf("%*s", padding, num);
        if (separate && ((i % separate) == 0))
            printf(" \\\n\t");
    }
    printf(" %*c, ...) %c\n", padding - 2, 'N', 'N');
}

// VA_RSEQ_N printer
void _va_rseq_n_printer(int n, const char* name, int separate) {
    int padding = log10(n) + 1;
    printf("#define %s()", name);
    if (separate)
        printf(" \\\n\t");
    while (--n) {
        printf("%*d,", padding, n);
        if (separate && ((n % separate) == 0))
            printf(" \\\n\t");
    }
    printf("%*c", padding, '0');
}

// VA_COMMASEQ_N printer
void _va_commaseq_n_printer(int n, const char* name, int separate) {
    printf("#define %s()", name);
    if (separate)
        printf(" \\\n\t");
    n -= 2;
    for (; n > 0; --n) {
        printf(" 1,");
        if (separate && (((n + 1) % separate) == 0))
            printf(" \\\n\t");
    }
    printf(" 0, 0\n");
}

#pragma endregion

#endif // !M_PRIVATE_VARIADIC_H_
