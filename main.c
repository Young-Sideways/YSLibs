/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

//#include "main.h"

#include <stdio.h>
#include "macro/variadic.h"



int main(int argc, char** argv) {
    //UNUSED(argc);
    //UNUSED(argv);

    printf("args: %d\n", VA_NARG(1, 2, 3, 4));

    //_getch();
    return 0;
}
