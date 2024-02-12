/**
 * @file utils.h
 * @author Young Sideways (young.sideways@mail.ru)
 * @brief Библиотека полезных утилит для тестирования и отладки
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _UTILS_H_
#define _UTILS_H_

#pragma once

#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define UNUSED(var) ((void)var)

void swap(void* lhs, void* rhs, size_t size);

#if (__STDC_VERSION__ >= 201112L)
	typedef struct {
		struct timespec;
		bool started;
	} timer_t;
#else
	typedef struct {
		clock_t time;
		bool started;
	} timer_t;
#endif // OS Related


void timer_start(timer_t* timer);
void timer_elapsed(timer_t* timer);
char* timer_str(timer_t* timer, char* str);


typedef int (comp_t)(const void* lhs, const void* rhs);
typedef comp_t* comp_pt;

typedef void (sort_t)(void*, size_t, size_t, comp_pt);
typedef sort_t* sort_pt;

char getch_menu();

#endif // !_UTILS_H_
