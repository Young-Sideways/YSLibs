#include "core/core.h"
//#include "core/metrics.h"
//#include "task3/task3.h"

#include <stdlib.h>
#include <stdio.h>

#include "core/macro/varidatic.h"
#include "core/macro/reverse.h"

int main(int argc, char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    printf("args: %d %d %d %d\n", VA_ARG_REVERSE(1, 2, 3, 4, 5, 6, 7));

    //METRIC_GLOBAL_POINT(1, 4.546, NULL);
    //puts(METRIC_GET(global, file));
    // task3();

    return EXIT_SUCCESS;
}