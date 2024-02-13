#pragma once
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define stack_init(name, type, size) \
type* name = (type*)malloc(size * sizeof(type) + (sizeof(int) << 1)); \
*(((int*)name)++) = size; \
*(((int*)name)++) = -1; \
void name ## _push(type value) { \
	if (*((int*)name - 1) >= *((int*)name - 2)) { \
		type* newblock = (type*)realloc((int*)name - 2, *((int*)name - 2) > 0 ? *((int*)name - 2) + 1 : *((int*)name - 2) * 2); \
		if (newblock) { \
			name = newblock; \
			*(int*)name = *(int*)name > 0 ? *(int*)name + 1 : *(int*)name * 2; \
			(int*)name += 2; \
		} \
	} \
	name[++*((int*)name - 1)] = value; \
}; \
type name ## _pop() { \
	if (*((int*)name - 1) >= 0) \
		(*((int*)name - 1))--; \
}; \
type name ## _top() { \
	return name[*((int*)name - 1)]; \
}; \

void stack_delete(void* stack) {
	free(((int*)stack) - 2);
};
#endif // !STACK_H
