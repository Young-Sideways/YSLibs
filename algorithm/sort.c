/*********************************************************************
 * \file   sort.c
 * \brief  sort algorithms
 * 
 * \author Young Sideways
 * \date   February 2024
 *********************************************************************/

#include "sort.h"

void selection_sort(void* array, size_t count, size_t element_size, comp_pt comparator, swap_pt _swap) {
	for (char* end = (char*)array + (count * element_size); array < (end - element_size); (char*)array += element_size) {
		void* min = array;
		for (char* ptr = (char*)array + element_size; ptr < end; ptr += element_size)
			if (comparator(ptr, min) < 0)
				min = ptr;
		if (array != min)
			_swap(array, min, element_size);
	}
}

void insertion_sort(void* array, size_t count, size_t element_size, comp_pt comparator, swap_pt _swap) {

}
void quick_sort(void* array, size_t count, size_t element_size, comp_pt comparator, swap_pt _swap) {

}