#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "general.h"

typedef enum {
	FORWARD = 0,
	REVERSE = 1
} it_type;

typedef void* it_t;

it_t it_init(void* block, size_t capacity, size_t element_size, it_type type);
void it_delete(it_t iterator);

void* it_get(it_t iterator);
void* it_next(it_t iterator);
void* it_prev(it_t iterator);

it_type it_gettype(it_t iterator);

#endif // !ITERATOR_H