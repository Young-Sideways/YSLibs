/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "core.h"

#include "macro/arg.h"
#include "macro/sequence.h"


int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);

    MS_EXPAND(M_DEFER(VA_SEQ)(;, M_SEQ_GEN(12, int b), int b));

    return 0;
}
