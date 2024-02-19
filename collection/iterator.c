/*******************************************************************************
 *  @file      iterator.c
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#pragma region --- INCLUDES ---

#include "iterator.h"
#include "../core/types.h"

#include <stdbool.h>
#include <assert.h>

#pragma endregion

#define INVALID_ITERATOR (iterator_t) { \
	.collection = NULL,					\
	.data = NULL,						\
	.stage = NULL,						\
	.direction = IT_UNDEFINED			\
}

inline bool is_valid(iterator_t* iterator) {
	assert(iterator);

	if (iterator->collection == NULL)
		return false;

	switch (iterator->direction)
	{
	case IT_REVERSE: {
		if (iterator->stage < -1 || iterator->stage >= iterator->collection->size)
			return false;
		if ((iterator->stage == -1) ^ !!iterator->data)
			return false;
		break;
	}
	case IT_UNDEFINED:
		return false;
	case IT_FORWARD: {
		if (iterator->stage < 0 || iterator->stage > iterator->collection->size)
			return false;
		if ((iterator->stage == iterator->collection->size) ^ !!iterator->data)
			return false;
		break;
	}
	default:
		return false;
	}

	return true;
}

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---


iterator_t it_begin(_IN void* collection) {
	assert(collection);

	iterator_t result = (iterator_t) {
		.collection = collection,
		.data = NULL,
		.stage = 0,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return is_valid(&result) ? result : INVALID_ITERATOR;
}

iterator_t it_end(_IN void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = ((struct collection_header*)collection)->size,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return is_valid(&result) ? result : INVALID_ITERATOR;
}


iterator_t it_rbegin(_IN void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = ((struct collection_header*)collection)->size - 1,
		.direction = IT_REVERSE
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return is_valid(&result) ? result : INVALID_ITERATOR;
}

iterator_t it_rend(_IN void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = -1,
		.direction = IT_REVERSE
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return is_valid(&result) ? result : INVALID_ITERATOR;
}


iterator_t it_first(_IN void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = 0,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return is_valid(&result) ? result : INVALID_ITERATOR;
}

iterator_t it_last(_IN void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = ((struct collection_header*)collection)->size - 1,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return is_valid(&result) ? result : INVALID_ITERATOR;
}


void it_delete(_IN iterator_t* iterator) {
	assert(iterator);

	*iterator = INVALID_ITERATOR;
}

#pragma endregion

#pragma region --- FUNCIONS ---


void* it_get(_IN iterator_t* iterator) {
	return is_valid(iterator) ? iterator->data : NULL;
}
void it_next(_IN iterator_t* iterator) {
	if (is_valid(iterator))
		return;
	iterator->collection->next(iterator->collection, &iterator->data, &iterator->stage);
}
void it_prev(_IN iterator_t* iterator) {
	if (is_valid(iterator))
		return;
	iterator->collection->prev(iterator->collection, &iterator->data, &iterator->stage);
}

int it_comp(_IN iterator_t* lhs, _IN iterator_t* rhs, _IN size_t size) {
	UNUSED(size);

	assert(is_valid(lhs) && is_valid(rhs));
	assert(lhs->collection != rhs->collection);

	return lhs->stage - rhs->stage;
}

#pragma endregion
