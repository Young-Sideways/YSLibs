/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

/*********************************************************
 *                                                       *
 * ╦ ╦ ╔═╗ ╦ ╦ ╔╗╔ ╔═╗     ╔═╗ ╦ ╔╦╗ ╔═╗ ╦ ╦ ╔═╗ ╦ ╦ ╔═╗ *
 * ╚╦╝ ║ ║ ║ ║ ║║║ ║ ╦     ╚═╗ ║  ║║ ║╣  ║║║ ╠═╣ ╚╦╝ ╚═╗ *
 *  ╩  ╚═╝ ╚═╝ ╝╚╝ ╚═╝     ╚═╝ ╩ ╚╩╝ ╚═╝ ╚╩╝ ╩ ╩  ╩  ╚═╝ *
 *                                                       *
 *********************************************************/


//#include "core.h"

#include <stdio.h>

#include <stdint.h>


int main(int argc, char** argv) {
    //UNUSED(argc);
    //UNUSED(argv);

    //M_EXPAND(M_DEFER(VA_SEQ)(;, M_SEQ_GEN(12, int b), int b));

    printf("sizeof(version_t): %zu\n", sizeof(version_t));
    version_t version = (version_t){
        .major     = 0u              ,
        .minor     = 12u             ,
        .patch     = 71u             ,
        .type      = BUILD_TYPE_ALPHA,
        .build     = __BUILD_NUMBER__,
        .timestamp = __TIMESTAMP__
    };
    return 0;
}
