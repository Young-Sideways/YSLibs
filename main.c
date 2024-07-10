/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "core.h"

#include <stdio.h>
#include <time.h>


    // current ticks
    // future ticks
    // clock resolution [ obolete | relative ] -> nanosecs step per tick
    //    1. get last timestamp [ arg ]
    //    2. --- do work ---
    //    3. get new time stamp
    //    4. diff expected timestamp with current
    //    5. --- wait --
    //    6. return new current timestamp



int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);

    //M_EXPAND(M_DEFER(VA_SEQ)(;, M_SEQ_GEN(12, int b), int b));

    return 0;
}
