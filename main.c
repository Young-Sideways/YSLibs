/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

//#include "main.h"

#include <stdio.h>
#include <string.h>
#include "core.h"
#include "util/console.h"



#define LOG_MODULE_NAME "general"
#define LOG_MODULE_SEPARATE (true)
#include "util/log.h"


int main(int argc, char** argv) {
    char path[128] = { 0 };
    if (argc) {
        path_from_filepath(argv[0], path);
    }
    log_system_init(path, "log");

    warn("test warn    '%s'", "hi");
    info("test info    '%d'", 346);
    debug("test debug   '%c'", 'G');
    critical("test critical '%f'", 6.23);
    error("test error   '%%'");


    //_getch();
    return 0;
}
