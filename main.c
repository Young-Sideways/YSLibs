/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "main.h"
#include <stdlib.h>

void yslog_exit(void) {
    printf("terminating all tasks...\n");
    printf("all tasks terminated...\n");
}

int main(int argc, char** argv) {
    atexit(yslog_exit);
    return 0;
}