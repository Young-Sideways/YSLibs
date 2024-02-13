#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include "general.h"

typedef void* array_t;

#define ARRAY_SIZE_MIN 0u
#define ARRAY_SIZE_MAX INT32_MAX

array_t array_init(size_t size, size_t element_size);
array_t array_copy(array_t array);
array_t array_shadow(array_t array);
void array_delete(array_t array);

void* array_at(array_t array, int position);
void* array_first(array_t array);
void* array_last(array_t array);
void* array_end(array_t array);

int array_capacity(array_t array);
int array_element_size(array_t array);

#ifdef ITERATOR_H // Adaptor for iterators
#include "iterator.h"
it_t array_get_it(array_t array);
#endif // !ITERATOR_H

#endif // !ARRAY_H