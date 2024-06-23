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
#include <stddef.h>

#include "macro/macro.h"

#include "collection/variant.h"

int main(int argc, char** argv) {
    if (argc) {
        char path[128] = { 0 };
        path_from_filepath(argv[0], path);
        if (log_system_init(NULL, NULL, NULL, NULL)) {
            fprintf(stderr, "error: log system can't be initialized\nTerminating");
            return 1;
        }
        info("Log system started successfully");
    }

    variant_t var = var_init(5);
    var_set(var, 5);

    __auto_type fromvar = var_get(var, int);
    free(var);
    return 0;
}