/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

//#include "main.h"


#define LOG_MODULE_NAME "general"
#include "util/log.h"

#include "util/console.h"

int main(int argc, char** argv) {
    char path[128] = { 0 };
    if (argc) {
        path_from_filepath(argv[0], path);
        log_system_init(path, "log");
    }

    return 0;
}
