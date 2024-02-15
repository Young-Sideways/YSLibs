#include "general.h"
#include "iterator.h"

#include "../core/types.h"

;

it_t it_init(void* block, size_t capacity, size_t element_size, it_type type) {
	assert(block);
	assert(element_size);
	struct it_header* result = (struct it_header*)malloc(sizeof(struct it_header));
	if (result)
		*result = (struct it_header){ .data = block, .capacity = capacity, .element_size = element_size, type == FORWARD ? 0 : -1 };
	return result;
}
void it_delete(it_t iterator) {
	assert(iterator);
	free(iterator);
}
// ----------------- INTERNAL FUNCTIONS ----------------- //

#define _data(it) ((struct it_header*)it)->data
#define _capacity(it) ((struct it_header*)it)->capacity
#define _element_size(it) ((struct it_header*)it)->element_size
#define _stage(it) ((struct it_header*)it)->stage

// ------------------------------------------------------ //
void* it_get(it_t iterator) {
	assert(iterator);
	return _data(iterator) + (it_gettype(iterator) == FORWARD ? _stage(iterator) : _capacity(iterator) - _stage(iterator))
}
void* it_next(it_t iterator) {

}
void* it_prev(it_t iterator) {

}

it_type it_gettype(it_t iterator) {
	assert(iterator);
	return ((struct it_header*)iterator)->stage < 0 ? REVERSE : FORWARD;
}