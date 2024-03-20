/*******************************************************************************
 *  @file      utils.c
 *  @brief     Small utils library with useful types for developing, testing and debuging
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "utils.h"

#include <stdio.h>
#include <ctype.h>
#include <assert.h>


char getch_menu() {
    char mode = '\0';
    do { mode = getchar(); } while (isspace(mode));
    while (getchar() != '\n');
    return mode;
}