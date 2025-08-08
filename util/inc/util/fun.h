//
// Created by pc on 8/8/25.
//

/*********************************************************
 *                                                       *
 * ╦ ╦ ╔═╗ ╦ ╦ ╔╗╔ ╔═╗     ╔═╗ ╦ ╔╦╗ ╔═╗ ╦ ╦ ╔═╗ ╦ ╦ ╔═╗ *
 * ╚╦╝ ║ ║ ║ ║ ║║║ ║ ╦     ╚═╗ ║  ║║ ║╣  ║║║ ╠═╣ ╚╦╝ ╚═╗ *
 *  ╩  ╚═╝ ╚═╝ ╝╚╝ ╚═╝     ╚═╝ ╩ ╚╩╝ ╚═╝ ╚╩╝ ╩ ╩  ╩  ╚═╝ *
 *                                                       *
 *********************************************************/

#ifndef FUN_H
#define FUN_H

#include <stdlib.h>

extern const char* logo_anim_set[];

void animate(const char** list, size_t list_size, int latency_ms, int times);
void animate_reverse(const char** list, int list_size, int latency_ms, int times);

#endif //FUN_H
