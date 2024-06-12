/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

//#include "main.h"

#include <stdio.h>
#include "util/timer.h"


int main(int argc, char** argv) {
    //UNUSED(argc);
    //UNUSED(argv);
    tim_t tim;
    tim_start(&tim);
    tim_stop(&tim);
    int a = 10;
    int b[a];
    printf("elapsed: %s\n", tim_str(&tim, TIM_PRECISION_AUTO));
    printf("b size: %lld\n", sizeof(b));

    //_getch();
    return 0;
}
