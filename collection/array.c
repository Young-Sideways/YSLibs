/*******************************************************************************
 *  @file      array.c
 *  @brief     array - collection, with fixed memory allocation
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "array.h"
#include "iterator.h"

struct _array_header {
	size_t
		capacity,
		element_size;
};
// ------------------------------------------------------------------- //

_inl_ array_t array_init(size_t capacity, size_t element_size) {
	assert(element_size);
	assert(capacity <= ARRAY_SIZE_MAX);
	struct _array_header* result = (struct _array_header*)malloc(sizeof(struct _array_header) + capacity * element_size);
	if (result) {
		*result = (struct _array_header){ .capacity = capacity, .element_size = element_size };
		result++;
	}
	return (array_t)result;
}
_inl_ array_t array_shadow(array_t array) {
	assert(array);
	struct _array_header* header = (struct _array_header*)array - 1;
	return array_init(header->capacity, header->element_size);
}
_inl_ array_t array_copy(array_t array) {
	assert(array);
	struct _array_header* header = (struct _array_header*)array - 1;
	size_t size = sizeof(struct _array_header) + header->capacity * header->element_size;
	struct _array_header* result = (struct _array_header*)malloc(size);
	if (result) {
		memcpy(result, header, size);
		result++;
	}
	return (array_t)result;
}
_inl_ void array_delete(array_t array) {
	assert(array);
	free(((struct _array_header*)array) - 1);
}

// ------------------------------------------------------------------- //

_inl_ void* array_at(array_t array, int position) {
	assert(array);
	struct _array_header* header = ((struct _array_header*)array) - 1;
	if (position < 0)
		if (-position - 1 > header->capacity)
			return NULL;
	else
		if (position > header->capacity)
			return NULL;
		//position = (int)header->capacity + position;
	return (byte*)array + position * header->element_size;
}
_inl_ void* array_first(array_t array) {
	return array_capacity(array) ? array : NULL;
}
_inl_ void* array_last(array_t array) {
	struct _array_header* header = ((struct _array_header*)array) - 1;
	return array_capacity(array) ? (byte*)array + header->element_size * (header->capacity - 1) : NULL;
}
_inl_ void* array_end(array_t array) {
	struct _array_header* header = ((struct _array_header*)array) - 1;
	return array_capacity(array) ? (byte*)array + header->element_size * header->capacity : NULL;
}

// ------------------------------------------------------------------- //

_inl_ size_t array_capacity(array_t array) {
	assert(array);
	return ((struct _array_header*)array - 1)->capacity;
}
_inl_ size_t array_element_size(array_t array) {
	assert(array);
	return ((struct _array_header*)array - 1)->element_size;
}

// ------------------------------------------------------------------- //

it_t array_get_it(array_t array, it_type type) {
	return it_init(array, array_capacity(array), array_element_size(array), type);
}