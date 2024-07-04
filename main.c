/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "macro/logic.h"

#define M_ARG_TAKE_HELPER1() M_ARG_TAKE_HELPER
#define M_ARG_TAKE_HELPER(n, _1, ...) M_IF(n)(_1 __VA_OPT__(, M_DEFER(M_ARG_TAKE_HELPER1)(M_DEC(n), ##__VA_ARGS__)))
#define M_ARG_TAKE(n, ...) __VA_OPT__(M_EVAL(M_ARG_TAKE_HELPER(n, ##__VA_ARGS__)))

int main(int argc, char** argv) {

    int a1[] = { M_ARG_TAKE(4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9) };

    return 0;
}
