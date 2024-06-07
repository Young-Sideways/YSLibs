/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "main.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <limits.h>
#include <uchar.h>
#include <stdlib.h>
#include <locale.h>

#include "core/macro/arg.h"
#include "collection/collections.h"



int main(int argc, char** argv) {
    //UNUSED(argc);
    //UNUSED(argv);

    for (int i = 0; i < argc; i++) {
        printf("%d arg: '%s'\n", i, argv[i]);
    }
    setlocale(LC_ALL, "ru_RU.utf8");

    
    _getch();
    return 0;
}
