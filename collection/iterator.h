#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "general.h"

comparator_t it_comp;


typedef enum {
	FORWARD = 1,
	REVERSE = -1
} it_type;

typedef struct {
	struct collection_header* collection;
	byte* data;
	int stage;
} iterator_t;

iterator_t it_init(void* collection, it_type type);
void it_delete(iterator_t iterator);

void* it_get(iterator_t iterator);
void it_next(iterator_t* iterator);
void it_prev(iterator_t* iterator);


it_type it_gettype(iterator_t iterator);

#endif // !ITERATOR_H