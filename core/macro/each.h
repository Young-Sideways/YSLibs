/*******************************************************************************
 *  @file      each.h
 *  @brief     
 *  @author    Young Sideways
 *  @date      1.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef _EACH_H_
#define _EACH_H_

#pragma once

#include "macro.h"

#pragma region --- MARCO GENERATOR ---
#ifdef _SEQ_PRINTERS

#include <math.h>
#include <string.h>
 // ARG_REVERSE
void _va_each_printer(int scale, int n) {
    char param_seq[128] = { 0 };
    char param_str[32] = { 0 };

    for (int i = 0; i < scale; ++i) {
        if (i > 0) {
            sprintf(param_str, "_p%d, ", i);
            strcat(param_seq, param_str);
        }
        if (n > -1)
            printf("#define M_EACH%d_0(_f, %s...) \\\n\t_f(%.*s)\n", i, param_seq, (uint32_t)(strlen(param_seq) > 1u ? strlen(param_seq) - 2u : 0u), param_seq);
        if (n > 0)
            printf("#define M_EACH%d_1(_f, %s_1, ...) \\\n\t_f(%s_1)\n", i, param_seq, param_seq);
        if (n > 1)
            printf("#define M_EACH%d_2(_f, %s_1, _2, ...) \\\n\t_f(%s_1) _f(%s_2)\n", i, param_seq, param_seq, param_seq);
        for (int j = 3; j < n; ++j) {
            printf("#define M_EACH%d_%d(_f, %s_1, ...) \\\n\t_f(%s_1) M_EACH%d_%d(_f, %s__VA_ARGS__)\n", i, j, param_seq, param_seq, i, j - 1, param_seq);
        }
    }

    memset(param_seq, '\0', sizeof(param_seq));

    printf("\n#ifdef _VARIDATIC_H_\n\n");
    for (int i = 0; i < scale; ++i) {
        if (i > 0) {
            sprintf(param_str, "_p%d, ", i);
            strcat(param_seq, param_str);
        }
        printf("#define VA_EACH%d(_f, %s...) M_CONCAT_LATER(M_EACH%d_, VA_NARG(__VA_ARGS__))(_f, %s__VA_ARGS__)\n", i, param_seq, i, param_seq);
    }
    printf("\n#endif // !_VARIDATIC_H_");
}

#endif
#pragma endregion

#pragma region --- MACROS ---

// @printer_setting : _va_each_printer(4, 32);
#define M_EACH0_0(_f, ...) \
        _f()
#define M_EACH0_1(_f, _1, ...) \
        _f(_1)
#define M_EACH0_2(_f, _1, _2, ...) \
        _f(_1) _f(_2)
#define M_EACH0_3(_f, _1, ...) \
        _f(_1) M_EACH0_2(_f, __VA_ARGS__)
#define M_EACH0_4(_f, _1, ...) \
        _f(_1) M_EACH0_3(_f, __VA_ARGS__)
#define M_EACH0_5(_f, _1, ...) \
        _f(_1) M_EACH0_4(_f, __VA_ARGS__)
#define M_EACH0_6(_f, _1, ...) \
        _f(_1) M_EACH0_5(_f, __VA_ARGS__)
#define M_EACH0_7(_f, _1, ...) \
        _f(_1) M_EACH0_6(_f, __VA_ARGS__)
#define M_EACH0_8(_f, _1, ...) \
        _f(_1) M_EACH0_7(_f, __VA_ARGS__)
#define M_EACH0_9(_f, _1, ...) \
        _f(_1) M_EACH0_8(_f, __VA_ARGS__)
#define M_EACH0_10(_f, _1, ...) \
        _f(_1) M_EACH0_9(_f, __VA_ARGS__)
#define M_EACH0_11(_f, _1, ...) \
        _f(_1) M_EACH0_10(_f, __VA_ARGS__)
#define M_EACH0_12(_f, _1, ...) \
        _f(_1) M_EACH0_11(_f, __VA_ARGS__)
#define M_EACH0_13(_f, _1, ...) \
        _f(_1) M_EACH0_12(_f, __VA_ARGS__)
#define M_EACH0_14(_f, _1, ...) \
        _f(_1) M_EACH0_13(_f, __VA_ARGS__)
#define M_EACH0_15(_f, _1, ...) \
        _f(_1) M_EACH0_14(_f, __VA_ARGS__)
#define M_EACH0_16(_f, _1, ...) \
        _f(_1) M_EACH0_15(_f, __VA_ARGS__)
#define M_EACH0_17(_f, _1, ...) \
        _f(_1) M_EACH0_16(_f, __VA_ARGS__)
#define M_EACH0_18(_f, _1, ...) \
        _f(_1) M_EACH0_17(_f, __VA_ARGS__)
#define M_EACH0_19(_f, _1, ...) \
        _f(_1) M_EACH0_18(_f, __VA_ARGS__)
#define M_EACH0_20(_f, _1, ...) \
        _f(_1) M_EACH0_19(_f, __VA_ARGS__)
#define M_EACH0_21(_f, _1, ...) \
        _f(_1) M_EACH0_20(_f, __VA_ARGS__)
#define M_EACH0_22(_f, _1, ...) \
        _f(_1) M_EACH0_21(_f, __VA_ARGS__)
#define M_EACH0_23(_f, _1, ...) \
        _f(_1) M_EACH0_22(_f, __VA_ARGS__)
#define M_EACH0_24(_f, _1, ...) \
        _f(_1) M_EACH0_23(_f, __VA_ARGS__)
#define M_EACH0_25(_f, _1, ...) \
        _f(_1) M_EACH0_24(_f, __VA_ARGS__)
#define M_EACH0_26(_f, _1, ...) \
        _f(_1) M_EACH0_25(_f, __VA_ARGS__)
#define M_EACH0_27(_f, _1, ...) \
        _f(_1) M_EACH0_26(_f, __VA_ARGS__)
#define M_EACH0_28(_f, _1, ...) \
        _f(_1) M_EACH0_27(_f, __VA_ARGS__)
#define M_EACH0_29(_f, _1, ...) \
        _f(_1) M_EACH0_28(_f, __VA_ARGS__)
#define M_EACH0_30(_f, _1, ...) \
        _f(_1) M_EACH0_29(_f, __VA_ARGS__)
#define M_EACH0_31(_f, _1, ...) \
        _f(_1) M_EACH0_30(_f, __VA_ARGS__)
#define M_EACH1_0(_f, _p1, ...) \
        _f(_p1)
#define M_EACH1_1(_f, _p1, _1, ...) \
        _f(_p1, _1)
#define M_EACH1_2(_f, _p1, _1, _2, ...) \
        _f(_p1, _1) _f(_p1, _2)
#define M_EACH1_3(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_2(_f, _p1, __VA_ARGS__)
#define M_EACH1_4(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_3(_f, _p1, __VA_ARGS__)
#define M_EACH1_5(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_4(_f, _p1, __VA_ARGS__)
#define M_EACH1_6(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_5(_f, _p1, __VA_ARGS__)
#define M_EACH1_7(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_6(_f, _p1, __VA_ARGS__)
#define M_EACH1_8(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_7(_f, _p1, __VA_ARGS__)
#define M_EACH1_9(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_8(_f, _p1, __VA_ARGS__)
#define M_EACH1_10(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_9(_f, _p1, __VA_ARGS__)
#define M_EACH1_11(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_10(_f, _p1, __VA_ARGS__)
#define M_EACH1_12(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_11(_f, _p1, __VA_ARGS__)
#define M_EACH1_13(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_12(_f, _p1, __VA_ARGS__)
#define M_EACH1_14(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_13(_f, _p1, __VA_ARGS__)
#define M_EACH1_15(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_14(_f, _p1, __VA_ARGS__)
#define M_EACH1_16(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_15(_f, _p1, __VA_ARGS__)
#define M_EACH1_17(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_16(_f, _p1, __VA_ARGS__)
#define M_EACH1_18(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_17(_f, _p1, __VA_ARGS__)
#define M_EACH1_19(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_18(_f, _p1, __VA_ARGS__)
#define M_EACH1_20(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_19(_f, _p1, __VA_ARGS__)
#define M_EACH1_21(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_20(_f, _p1, __VA_ARGS__)
#define M_EACH1_22(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_21(_f, _p1, __VA_ARGS__)
#define M_EACH1_23(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_22(_f, _p1, __VA_ARGS__)
#define M_EACH1_24(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_23(_f, _p1, __VA_ARGS__)
#define M_EACH1_25(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_24(_f, _p1, __VA_ARGS__)
#define M_EACH1_26(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_25(_f, _p1, __VA_ARGS__)
#define M_EACH1_27(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_26(_f, _p1, __VA_ARGS__)
#define M_EACH1_28(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_27(_f, _p1, __VA_ARGS__)
#define M_EACH1_29(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_28(_f, _p1, __VA_ARGS__)
#define M_EACH1_30(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_29(_f, _p1, __VA_ARGS__)
#define M_EACH1_31(_f, _p1, _1, ...) \
        _f(_p1, _1) M_EACH1_30(_f, _p1, __VA_ARGS__)
#define M_EACH2_0(_f, _p1, _p2, ...) \
        _f(_p1, _p2)
#define M_EACH2_1(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1)
#define M_EACH2_2(_f, _p1, _p2, _1, _2, ...) \
        _f(_p1, _p2, _1) _f(_p1, _p2, _2)
#define M_EACH2_3(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_2(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_4(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_3(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_5(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_4(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_6(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_5(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_7(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_6(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_8(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_7(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_9(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_8(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_10(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_9(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_11(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_10(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_12(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_11(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_13(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_12(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_14(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_13(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_15(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_14(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_16(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_15(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_17(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_16(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_18(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_17(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_19(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_18(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_20(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_19(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_21(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_20(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_22(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_21(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_23(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_22(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_24(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_23(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_25(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_24(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_26(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_25(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_27(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_26(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_28(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_27(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_29(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_28(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_30(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_29(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH2_31(_f, _p1, _p2, _1, ...) \
        _f(_p1, _p2, _1) M_EACH2_30(_f, _p1, _p2, __VA_ARGS__)
#define M_EACH3_0(_f, _p1, _p2, _p3, ...) \
        _f(_p1, _p2, _p3)
#define M_EACH3_1(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1)
#define M_EACH3_2(_f, _p1, _p2, _p3, _1, _2, ...) \
        _f(_p1, _p2, _p3, _1) _f(_p1, _p2, _p3, _2)
#define M_EACH3_3(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_2(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_4(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_3(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_5(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_4(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_6(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_5(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_7(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_6(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_8(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_7(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_9(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_8(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_10(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_9(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_11(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_10(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_12(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_11(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_13(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_12(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_14(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_13(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_15(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_14(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_16(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_15(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_17(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_16(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_18(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_17(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_19(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_18(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_20(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_19(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_21(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_20(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_22(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_21(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_23(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_22(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_24(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_23(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_25(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_24(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_26(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_25(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_27(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_26(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_28(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_27(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_29(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_28(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_30(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_29(_f, _p1, _p2, _p3, __VA_ARGS__)
#define M_EACH3_31(_f, _p1, _p2, _p3, _1, ...) \
        _f(_p1, _p2, _p3, _1) M_EACH3_30(_f, _p1, _p2, _p3, __VA_ARGS__)

#ifdef _VARIDATIC_H_

#define VA_EACH0(_f, ...) M_CONCAT_LATER(M_EACH0_, VA_NARG(__VA_ARGS__))(_f, __VA_ARGS__)
#define VA_EACH1(_f, _p1, ...) M_CONCAT_LATER(M_EACH1_, VA_NARG(__VA_ARGS__))(_f, _p1, __VA_ARGS__)
#define VA_EACH2(_f, _p1, _p2, ...) M_CONCAT_LATER(M_EACH2_, VA_NARG(__VA_ARGS__))(_f, _p1, _p2, __VA_ARGS__)
#define VA_EACH3(_f, _p1, _p2, _p3, ...) M_CONCAT_LATER(M_EACH3_, VA_NARG(__VA_ARGS__))(_f, _p1, _p2, _p3, __VA_ARGS__)

#endif // !_VARIDATIC_H_

#pragma endregion

#endif // !_EACH_H_
