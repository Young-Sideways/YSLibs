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

#include <core/core.h>
#include <util/fun.h>

int main(int argc, char** argv) {
    YSL_UNUSED(argc);
    YSL_UNUSED(argv);

    animate_reverse(logo_anim_set, 54, 100, 100);

    return 0;
}
// ╦ ╦═╗ ╦   ╦ ╦═╗ ╔═╗
// ╚╦╝═╗ ║   ║ ╠═╣ ╚═╗
//  ╩╚═╝ ╚═╝ ╩ ╩═╝ ╚═╝