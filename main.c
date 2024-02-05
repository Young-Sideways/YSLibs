#include <stdio.h>
#include <stdlib.h>

#define _USE_HIGH_PRECISION_TIMER
#include "utils/utils.h"

//#include "task1.h"
//#include "task2.h"
//#include "task3.h"


static int a = 0;
int main(int argc, char* argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	timer_t timer;
	timer_start(&timer);
	// Some code...
	timer_elapsed(&timer);

	char str[24] = { 0 };
	timer_str(&timer, str);
	printf("Time for 1m iters: %s\n", str);
	return EXIT_SUCCESS;
}
