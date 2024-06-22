/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include <stdio.h>
#define LOG_MODULE_NAME "general"
#include "util/log.h"

#include "main.h"


#include "macro/macro.h"
#include "macro/arg.h"


int main(int argc, char** argv) {
    if (argc) {
        char path[128] = { 0 };
        path_from_filepath(argv[0], path);
        if (log_system_init(path, "log")) {
            fprintf(stderr, "error: log system can't be initialized\nTerminating");
            return 1;
        }
        info("Log system started successfully");
    }
    getchar();
    return 0;
}