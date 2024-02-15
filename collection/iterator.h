/*******************************************************************************
 *  @file      iterator.h
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#pragma once

#pragma region --- INCLUDES ---

#include "general.h"

#pragma endregion
#pragma region --- MACROS ---
#pragma endregion
#pragma region --- TYPEDEFS ---

typedef enum {
	IT_REVERSE = -1,
	IT_UNDEFINED = 0,
	IT_FORWARD = 1,
} it_direction_t;

typedef struct {
	struct collection_header* collection;
	byte* data;
	int stage;
	it_direction_t direction;
} iterator_t;

#pragma endregion
#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

iterator_t it_begin(void* collection);
iterator_t it_end(void* collection);

iterator_t it_rbegin(void* collection);
iterator_t it_rend(void* collection);

iterator_t it_first(void* collection);
iterator_t it_last(void* collection);

void it_delete(iterator_t* iterator);

#pragma endregion
#pragma region --- FUNCIONS ---

void* it_get(iterator_t* iterator);
void it_next(iterator_t* iterator);
void it_prev(iterator_t* iterator);

comparator_t it_comp;

#pragma endregion

#endif // !_ITERATOR_H_
