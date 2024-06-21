/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#define LOG_MODULE_NAME "general"
#include "util/log.h"

#include "main.h"


#include "macro/macro.h"
#include "macro/arg.h"


int main(int argc, char** argv) {
    if (argc) {
        char path[128] = { 0 };
        path_from_filepath(argv[0], path);
        log_system_init(path, "log");
        info("Log system started successfully");
    }

    int a[] = { VA_ARG_FIRST(0,1,2,3,4,5,6,7,8,9,10) };
    return 0;
}
