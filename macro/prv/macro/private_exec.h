/*******************************************************************************
 *  @file      private_exec.h
 *  @author    Young Sideways
 *  @date      1.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef M_PRIVATE_EXEC_H_
#define M_PRIVATE_EXEC_H_

#pragma once

#pragma region --- MACRO GENERATOR ---

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

// VA_EXEC
void _va_exec_printer(int scale, int n) {

    const char macro_name[]             = "EXEC";
    const char macro_prefix[]           = "M_"  ;
    const char macro_variadic_prefix[] = "VA_" ;

    char param_seq[128] = ", ";
    char param_str[32] = { 0 };

    for (int i = 0; i < scale; ++i) {
        for (int j = 0; j < n; ++j) {
            uint32_t param_str_size = strlen(param_seq) - 2;
            switch (j) {
                case 0:  printf("#define %s%s%d_0(_f%.*s) _f(%.*s)\n", macro_prefix, macro_name, i, param_str_size, param_seq, param_str_size - 2, param_seq + 2); break;
                case 1:  printf("#define %s%s%d_1(_f%s_1) _f(%s_1)\n", macro_prefix, macro_name, i, param_seq, param_seq + 2); break;
                case 2:  printf("#define %s%s%d_2(_f%.*s, _1, _2) _f(%s_1), _f(%s_2)\n", macro_prefix, macro_name, i, param_str_size, param_seq, param_seq + 2, param_seq + 2); break;
                default: printf("#define %s%s%d_%d(_f%.*s, _1, ...) _f(%s_1), %s%s%d_%d(_f%.*s, __VA_ARGS__)\n", macro_prefix, macro_name, i, j, param_str_size, param_seq, param_seq + 2, macro_prefix, macro_name, i, j - 1, param_str_size, param_seq); break;
            }
        }
        putchar('\n');
        sprintf(param_str, "_p%d, ", i + 1);
        strcat(param_seq, param_str);
    }

    memset(param_seq, '\0', sizeof(param_seq));
    sprintf(param_seq, ", ");

    puts("#define M_EXEC(_f, ...) _f(__VA_ARGS__)");
    puts("\n#ifdef _VARIADIC_H_\n");
    for (int i = 0; i < scale; ++i) {
        printf("#define %s%s%d(_f%s...) M_CONCAT_LATER(%s%s%d_, VA_NARG(__VA_ARGS__))(_f%s__VA_ARGS__)\n", macro_variadic_prefix, macro_name, i, param_seq, macro_prefix, macro_name, i, param_seq);
        sprintf(param_str, "_p%d, ", i + 1);
        strcat(param_seq, param_str);
    }
    puts("\n#endif // !_VARIADIC_H_");
}

#pragma endregion

#endif // !M_PRIVATE_EXEC_H_
