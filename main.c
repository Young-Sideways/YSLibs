#include <stdio.h>
#include <stdlib.h>

#include "core/core.h"
#include "core/macro/macro.h"
//#include "task3/task3.h"

#include "collection/hashtable/hashtable.h"


int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);

    //task3();

    hashtable_t ht = ht_init(16, sizeof(int), sizeof(char*), NULL);

    int key1 = 3567245;
    int key2 = 924;

    ht_insert(ht, &key1, (char*) { "Hello" });
    ht_insert(ht, &key2, (char*) { "world" });

    printf("at key '%d' : %s\n", key1, ht_contains(ht, &key1) ? "true" : "false");
    printf("at key '%d' : %s\n", 26534, ht_contains(ht, (int[]) { 26534 }) ? "true" : "false");
    printf("at key '%d' : %s\n", key2, ht_contains(ht, &key2) ? "true" : "false");

    return 0;
}

#if (0)

int array_test() {
    array_t arr = new(array_t, int, size);
    if (arr) {
        int i = 1;
        set_sort(arr, quick_sort);


        for_each(int, it, arr) {
            printf("%d: %d\n", i, *it = i);
            i++;
        }

        iterator_t value = it_find(it_begin(arr), it_end(arr), (int[1]) { 3 });
        if (!it_equal(value, it_end(arr))) {
            printf("found value '%d' at stage '%d'\n", *(int*)it_get(value), value.stage);
        }

        it_sort(it_rbegin(arr), it_rend(arr));
        i = 1;
        for_each(int, it, arr) {
            printf("%d: %d\n", i++, *it);
        }

        value = it_find(it_begin(arr), it_end(arr), (int[1]) { 3 });
        if (!it_equal(value, it_end(arr))) {
            printf("found value '%d' at stage '%d'\n", *(int*)it_get(value), value.stage);
        }

        it_sort(it_begin(arr), it_end(arr));
        i = 1;
        for_each(int, it, arr) {
            printf("%d: %d\n", i++, *it);
        }

        value = it_find(it_begin(arr), it_end(arr), (int[1]) { 3 });
        if (!it_equal(value, it_end(arr))) {
            printf("found value '%d' at stage '%d'\n", *(int*)it_get(value), value.stage);
        }

        delete(&arr);
    }
}

#endif

#if (0)
#include "core/macro/generic/print.h"
#include <string.h>

#define T_PRINTER(foo, type)                    \
do {                                            \
    char format[48] = "%";                      \
    char buf[128] = { 0 };                       \
    strcat(format, M_FORMAT_OF((type)0));       \
    sprintf(buf, format, foo(type));            \
    printf("%s (%-19s) : %s\n", #foo, #type, buf); \
} while(0)

void __print_type_sizes(void) {
    T_PRINTER(G_TMIN, char);
    T_PRINTER(G_TMIN, short);
    T_PRINTER(G_TMIN, int);
    T_PRINTER(G_TMIN, long);
    T_PRINTER(G_TMIN, long long);
    T_PRINTER(G_TMIN, signed char);
    T_PRINTER(G_TMIN, signed short);
    T_PRINTER(G_TMIN, signed int);
    T_PRINTER(G_TMIN, signed long);
    T_PRINTER(G_TMIN, signed long long);
    T_PRINTER(G_TMIN, unsigned char);
    T_PRINTER(G_TMIN, unsigned short);
    T_PRINTER(G_TMIN, unsigned int);
    T_PRINTER(G_TMIN, unsigned long);
    T_PRINTER(G_TMIN, unsigned long long);
    T_PRINTER(G_TMIN, float);
    T_PRINTER(G_TMIN, double);
    T_PRINTER(G_TMIN, long double);
    putchar('\n');
    T_PRINTER(G_TMIN, char*);
    T_PRINTER(G_TMIN, short*);
    T_PRINTER(G_TMIN, int*);
    T_PRINTER(G_TMIN, long*);
    T_PRINTER(G_TMIN, long long*);
    T_PRINTER(G_TMIN, signed char*);
    T_PRINTER(G_TMIN, signed short*);
    T_PRINTER(G_TMIN, signed int*);
    T_PRINTER(G_TMIN, signed long*);
    T_PRINTER(G_TMIN, signed long long*);
    T_PRINTER(G_TMIN, unsigned char*);
    T_PRINTER(G_TMIN, unsigned short*);
    T_PRINTER(G_TMIN, unsigned int*);
    T_PRINTER(G_TMIN, unsigned long*);
    T_PRINTER(G_TMIN, unsigned long long*);
    T_PRINTER(G_TMIN, float*);
    T_PRINTER(G_TMIN, double*);
    T_PRINTER(G_TMIN, long double*);
    putchar('\n');
    T_PRINTER(G_TMAX, char);
    T_PRINTER(G_TMAX, short);
    T_PRINTER(G_TMAX, int);
    T_PRINTER(G_TMAX, long);
    T_PRINTER(G_TMAX, long long);
    T_PRINTER(G_TMAX, signed char);
    T_PRINTER(G_TMAX, signed short);
    T_PRINTER(G_TMAX, signed int);
    T_PRINTER(G_TMAX, signed long);
    T_PRINTER(G_TMAX, signed long long);
    T_PRINTER(G_TMAX, unsigned char);
    T_PRINTER(G_TMAX, unsigned short);
    T_PRINTER(G_TMAX, unsigned int);
    T_PRINTER(G_TMAX, unsigned long);
    T_PRINTER(G_TMAX, unsigned long long);
    T_PRINTER(G_TMAX, float);
    T_PRINTER(G_TMAX, double);
    T_PRINTER(G_TMAX, long double);
    putchar('\n');
    T_PRINTER(G_TMAX, char*);
    T_PRINTER(G_TMAX, short*);
    T_PRINTER(G_TMAX, int*);
    T_PRINTER(G_TMAX, long*);
    T_PRINTER(G_TMAX, long long*);
    T_PRINTER(G_TMAX, signed char*);
    T_PRINTER(G_TMAX, signed short*);
    T_PRINTER(G_TMAX, signed int*);
    T_PRINTER(G_TMAX, signed long*);
    T_PRINTER(G_TMAX, signed long long*);
    T_PRINTER(G_TMAX, unsigned char*);
    T_PRINTER(G_TMAX, unsigned short*);
    T_PRINTER(G_TMAX, unsigned int*);
    T_PRINTER(G_TMAX, unsigned long*);
    T_PRINTER(G_TMAX, unsigned long long*);
    T_PRINTER(G_TMAX, float*);
    T_PRINTER(G_TMAX, double*);
    T_PRINTER(G_TMAX, long double*);
    putchar('\n');
}
#endif