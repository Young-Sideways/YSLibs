#include "random.h"

#include <stdint.h>
#include <assert.h>

void random_init() { srand(time(NULL)); }

int random(int from, int to) {
	assert(from >= 0 && from <= INT32_MAX);
	assert(to >= 0 && to <= INT32_MAX);
	
	return (rand() % (to - from)) + from;
}
