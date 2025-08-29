#include <collection/array.h>

int main() {
    array_t a = arr_ctor(int);
    array_t b = arr_ctor(float, 1);
    array_t c = arr_ctor(float, INT32_MAX);

    arr_dtor(a);
    arr_dtor(b);
    arr_dtor(c);
}