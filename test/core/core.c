#include "test.h"

#include "core.h"

int main(int argc, char** argv) {
    INT_EQ(sizeof(byte), sizeof(signed char));
    INT_EQ(sizeof(ubyte), sizeof(unsigned char));
    INT_EQ(sizeof(byte*), sizeof(signed char*));
    INT_EQ(sizeof(ubyte*), sizeof(unsigned char*));
    INT_EQ(sizeof(byte), sizeof(ubyte));

    return EXIT_SUCCESS;
}