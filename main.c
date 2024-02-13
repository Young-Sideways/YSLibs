//#include "task1.h"
//#include "task2.h"
//#include "task3/task3.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char* argv[]) {
	//UNUSED(argc);
	//UNUSED(argv);


	int a = INT_MIN;
	int b = INT_MAX;

	int c = a - b;

	int ret = task3();

	return EXIT_SUCCESS;
}
