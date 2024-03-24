#include "core/core.h"
#include "core/metrics.h"
#include "task3/task3.h"

#include <stdlib.h>
#include <stdio.h>

DECLARE_EXTERN_METRIC(global);

int main(int argc, char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);
    
    METRIC_GLOBAL_POINT(1, 4.546, NULL);

    puts(METRIC_GET(global, file));
    // task3();

    return EXIT_SUCCESS;
}