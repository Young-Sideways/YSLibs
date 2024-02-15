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

#include <assert.h>

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

iterator_t it_begin(void* collection) {
	assert(collection);

	iterator_t result = (iterator_t) {
		.collection = collection,
		.data = NULL,
		.stage = 0,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return result;
}
iterator_t it_end(void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = ((struct collection_header*)collection)->size,
		.direction = IT_UNDEFINED
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return result;
}

iterator_t it_rbegin(void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = ((struct collection_header*)collection)->size - 1,
		.direction = IT_REVERSE
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return result;
}
iterator_t it_rend(void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = -1,
		.direction = IT_UNDEFINED
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return result;
}

iterator_t it_first(void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = 0,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return result;
}
iterator_t it_last(void* collection) {
	assert(collection);

	iterator_t result = (iterator_t){
		.collection = collection,
		.data = NULL,
		.stage = ((struct collection_header*)collection)->size - 1,
		.direction = IT_FORWARD
	};
	result.collection->random_access(collection, &(result.data), &(result.stage));
	return result;
}

void it_delete(iterator_t* iterator) {
	assert(iterator);

	*iterator = (iterator_t){
		.collection = NULL,
		.data = NULL,
		.stage = 0,
		.direction = IT_UNDEFINED
	};
}

#pragma endregion

#pragma region --- FUNCIONS ---

void* it_get(iterator_t* iterator) {
	assert(iterator);
	if (iterator->direction = IT_UNDEFINED)
		return NULL;
	return iterator->data;
}
void it_next(iterator_t* iterator) {
	assert(iterator);
	iterator->collection->next(iterator->collection, &iterator->data, &iterator->stage);
}
void it_prev(iterator_t* iterator) {
	assert(iterator);
	iterator->collection->prev(iterator->collection, &iterator->data, &iterator->stage);
}

int it_comp(iterator_t* lhs, iterator_t* rhs, size_t size) {
	UNUSED(size);

	assert(lhs);
	assert(rhs);

	assert(lhs->collection == rhs->collection); // different collection iterators!

	return lhs->stage - rhs->stage;
}
#pragma endregion
