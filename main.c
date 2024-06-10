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
    timer_t tim;
    tim_start(&tim);
    
    printf("args: %d\n", 5);

    //_getch();
    return 0;
}
