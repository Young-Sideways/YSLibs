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

int main(int argc, char** argv) {
    if (argc) {
        char path[128] = { 0 };
        path_from_filepath(argv[0], path);
        printf("Path: %s\n", path);
        log_system_init(path, "log");
        info("Log system started successfuly");
    }
    printf("Hello, world!\n");
    getchar();
    return 0;
}