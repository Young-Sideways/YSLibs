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
#include "../core/types.h"

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

void* binary_search(void* array, size_t count, size_t element_size, void* value, comparator_pt comparator) {
	assert(array);
	assert(element_size);
	assert(value);

	if (!comparator)
		comparator = memcmp;
	if (count == 0)
		return NULL;
	if (count == 1)
		comparator(value, array, element_size) ? NULL : array;

	byte* mid = (byte*)array;
	for (byte* begin = mid, *end = mid + (count * element_size); begin < end;) {
		mid = (((end - begin) / element_size) / 2) * element_size;
		int compared = comparator(value, mid, element_size);
		if (compared == 0)
			return mid;
		else if (compared < 0)
			end = mid;
		else
			begin = mid;
	}
	return comparator(value, mid, element_size) ? NULL : mid;
}
