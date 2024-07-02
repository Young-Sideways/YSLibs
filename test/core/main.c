#include <stdlib.h>

#include "core.h"
#include "debug.h"

int main(int argc, char** argv) {
    if (sizeof(byte) != sizeof(signed char))
        return EXIT_FAILURE;
    if (sizeof(ubyte) != sizeof(unsigned char))
        return EXIT_FAILURE;
    if (sizeof(byte*) != sizeof(signed char*))
        return EXIT_FAILURE;
    if (sizeof(ubyte*) != sizeof(unsigned char*))
        return EXIT_FAILURE;
    if (sizeof(byte) != sizeof(ubyte))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}