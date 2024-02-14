/*******************************************************************************
 *  @file      search.c
 *  @brief     search algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#include "search.h"

#include <assert.h>
#include <string.h>
#include "types.h"

void* linear_search(void* array, size_t count, size_t element_size, void* value, comparator_pt comparator) {
	assert(array);
	assert(element_size);
	assert(value);

	if (!comparator)
		comparator = memcmp;
	
	for (char *begin = array, *end = begin + (count * element_size); begin < end; begin += element_size)
		if (comparator(begin, value, element_size))
			return array;
	return NULL;
}

void* _b_search_partition(byte* begin, byte* end, size_t element_size, void* value, comparator_pt comparator) {
	if (begin == end)
		return NULL;
	if ((begin + element_size) == end)
		return comparator(begin, value, element_size) ? NULL : begin;

	byte* mid = begin + ((end - begin) / element_size / 2) * element_size;
	int compared = comparator(value, mid, element_size);
	if (compared < 0)
		return _b_search_partition(begin, mid, element_size, value, comparator);
	else if (compared > 0)
		return _b_search_partition(mid, end, element_size, value, comparator);
	else
		return mid;
}
void* binary_search(void* array, size_t count, size_t element_size, void* value, comparator_pt comparator) {
	assert(array);
	assert(element_size);
	assert(value);

	if (!comparator)
		comparator = memcmp;

	return _b_search_partition(array, (byte*)array + (count * element_size), element_size, value, comparator);
}
