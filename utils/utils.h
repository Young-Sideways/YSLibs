/**
 * @file utils.h
 * @author Young Sideways (young.sideways@mail.ru)
 * @brief Small utils library with useful types for developing, testing and debuging
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _UTILS_H_
#define _UTILS_H_

#pragma once

#pragma region --- INCLUDE ---

#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#pragma endregion

#pragma region --- MACRO ---

/* UNUSED macro to diable statements */
#define UNUSED(var) ((void)var)

#pragma endregion


char getch_menu();

#endif // !_UTILS_H_
