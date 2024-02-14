/*******************************************************************************
 *  @file      sort.c
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#include "sort.h"

#include <assert.h>
#include <string.h>

void selection_sort(void* array, size_t count, size_t element_size, comparator_pt comparator, swap_pt _swap) {
	assert(array);
	assert(element_size);

	if (!_swap)
		_swap = &swap;
	if (!comparator)
		comparator = memcmp;

	for (char* end = (char*)array + (count * element_size); array < (end - element_size); (char*)array += element_size) {
		void* min = array;
		for (char* ptr = (char*)array + element_size; ptr < end; ptr += element_size)
			if (comparator(ptr, min, element_size) < 0)
				min = ptr;
		if (array != min)
			_swap(array, min, element_size);
	}
}

void insertion_sort(void* array, size_t count, size_t element_size, comparator_pt _comparator, swap_pt _swap) {

}
void quick_sort(void* array, size_t count, size_t element_size, comparator_pt _comparator, swap_pt _swap) {

}