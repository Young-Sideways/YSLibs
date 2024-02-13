#pragma once
#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#ifndef COLLECTIONS_NO_INLINE
	#define _inl_ extern inline
#else
	#define _inl_
#endif

#define GROWTH(n) (n < 2u ? n + 1 : n + (n >> 1))

typedef uint8_t byte;
typedef int8_t sbyte;

typedef int (*comparer_t)(const void* a, const void* b);

typedef uint64_t hash_t;
#endif // !GENERAL_H
