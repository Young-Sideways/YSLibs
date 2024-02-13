/**
 * @file utils.c
 * @author Young Sideways (young.sideways@mail.ru)
 * @brief Small utils library with useful types for developing, testing and debuging
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 */

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