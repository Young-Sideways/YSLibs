/*******************************************************************************
 *  @file      sort.c
 *  @brief     sort algorithms
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/


#include "sort.h"
#include "../core/types.h"

#include <assert.h>
#include <string.h>

void selection_sort(_IN void* array, _IN size_t count, _IN size_t element_size, _IN _NULLABLE comparator_pt _comparator, _IN _NULLABLE swap_pt _swap) {
	assert(array);
	assert(element_size);

	if (!_comparator)
		_comparator = &memcmp;
	if (!_swap)
		_swap = &swap;

	for (char* end = (char*)array + (count * element_size); array < (end - element_size); (char*)array += element_size) {
		void* min = array;
		for (char* ptr = (char*)array + element_size; ptr < end; ptr += element_size)
			if (comparator(ptr, min, element_size) < 0)
				min = ptr;
		if (array != min)
			_swap(array, min, element_size);
	}
}

void insertion_sort(_IN void* array, _IN size_t count, _IN size_t element_size, _IN _NULLABLE comparator_pt _comparator, _IN _NULLABLE swap_pt _swap) {
	assert(array);
	assert(element_size);


	if (!_comparator)
		_comparator = &memcmp;
	if (!_swap)
		_swap = &swap;

	char* begin = array;
	char* end = begin + (count * element_size);
	char* ptr = begin + element_size;


	for (; ptr < end;) {
		int temp, j;
		temp = a[i];
		j = i - 1;
		while ((temp < a[j]) && (j >= 0)) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = temp;
	}
}
void quick_sort(_IN void* array, _IN size_t count, _IN size_t element_size, _IN _NULLABLE comparator_pt _comparator, _IN _NULLABLE swap_pt _swap) {
	assert(array);
	assert(element_size);

	if (!_comparator)
		_comparator = &memcmp;
	if (!_swap)
		_swap = &swap;
}