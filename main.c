//#include "task1.h"
//#include "task2.h"
#include "task3/task3.h"


int main(int argc, char* argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	//int ret = task3();
	int arr[] = { 2,1,0 };
	selection_sort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), int_fcomp);
	printf("done!");
	return EXIT_SUCCESS;
}
