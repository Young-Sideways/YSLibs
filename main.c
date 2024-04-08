#include "core/core.h"
//#include "core/metrics.h"
//#include "task3/task3.h"

#include <stdlib.h>
#include <stdio.h>

#if (0) // Легаси
#define _SEQ_PRINTERS

#include "core/macro/varidatic.h"
#include "core/macro/reverse.h"
#include "core/macro/sequence.h"
#include "core/macro/exec.h"




typedef struct { intptr_t offset; size_t size; } field_spec_t;

#define FOLD_ADD_PARAM__(container_type, type, name) { (intptr_t)M_OFFSETOF(container_type, name), sizeof(type) }
#define FOLD_ADD_PARAM_(container_type, ...) FOLD_ADD_PARAM__(container_type, __VA_ARGS__)
#define FOLD_ADD_PARAM(container_type, field) FOLD_ADD_PARAM_(container_type, M_CONCAT(SPEC_,field))

#define FIELD_ADD_PARAM(type, name) type name
#define SPEC_ADD_PARAM(type, name) type, name

#define SETTINGS_TYPEDEF(name, ...)                                                         \
typedef struct {                                                                            \
    VA_SEQ_SEMI(VA_EXEC1(M_CONCAT, FIELD_, __VA_ARGS__))                                    \
} name;                                                                                     \
                                                                                            \
const field_spec_t name##_field_specs[] = {                                                 \
    VA_EXEC1(FOLD_ADD_PARAM, name, __VA_ARGS__)                                             \
};                                                                                          \
                                                                                            \
const size_t name##_field_specs_size = VA_NARG(__VA_ARGS__) // ; static_assert(VA_NARG(__VA_ARGS__) < FLASH_RW_CODE, "too many params (> 255) for settings")



SETTINGS_TYPEDEF(setting_t,
    ADD_PARAM(float, p1),
    ADD_PARAM(int, p2)
);
#endif

#include "core/macro/generic/print.h"
#include <string.h>

#define T_PRINTER(foo, type)                    \
do {                                            \
    char format[48] = "%";                      \
    char buf[128] = { 0 };                       \
    strcat(format, M_FORMAT_OF((type)0));       \
    sprintf(buf, format, foo(type));            \
    printf("%s (%s) : %s\n", #foo, #type, buf); \
} while(0)

void __print_type_sizes(void) {
    do {
        char format[32] = "%";
        char buf[64] = { 0 };
        strcat(format, _Generic(((char)0), signed char : "hhd", signed short : "hd", signed int : "d", signed long : "ld", signed long long : "lld", unsigned char : "hhu", unsigned short : "hu", unsigned : "u", unsigned long : "lu", unsigned long long : "llu", float : "g", double : "lg", long double : "Lg", signed char* : "s", signed short* : "p (signed short*)", signed int* : "p (signed int*)", signed long* : "p (signed long*)", signed long long* : "p (signed long long*)", unsigned char* : "p (unsigned char*)", unsigned short* : "p (unsigned short*)", unsigned* : "p (unsigned*)", unsigned long* : "p (unsigned long*)", unsigned long long* : "p (unsigned long long*)", float* : "p (float*)", double* : "p (double*)", long double* : "p (long double*)", void* : "p (void*)", default: "X"));
        sprintf(buf, format, _Generic(((char)0), signed char : (-128), signed short : (-32768), signed int : (-2147483647 - 1), signed long : (-2147483647L - 1), signed long long : (-9223372036854775807i64 - 1), unsigned char : 0ui8, unsigned short : 0ui16, unsigned : 0u, unsigned long : 0ul, unsigned long long : 0ull, float : 1.175494351e-38F, double : 2.2250738585072014e-308, long double : 2.2250738585072014e-308, signed char* : (signed char*)((void*)0), signed short* : (signed short*)((void*)0), signed int* : (signed int*)((void*)0), signed long* : (signed long*)((void*)0), signed long long* : (signed long long*)((void*)0), unsigned char* : (unsigned char*)((void*)0), unsigned short* : (unsigned short*)((void*)0), unsigned* : (unsigned*)((void*)0), unsigned long* : (unsigned long*)((void*)0), unsigned long long* : (unsigned long long*)((void*)0), float* : (float*)((void*)0), double* : (double*)((void*)0), long double* : (long double*)((void*)0), void* : (void*)((void*)0), default: ((void*)0)));
        printf("%s (%.19s) : %s\n", "MIN", "char", buf);
    } while (0);
    T_PRINTER(MIN, short);
    T_PRINTER(MIN, int);
    T_PRINTER(MIN, long);
    T_PRINTER(MIN, long long);
    T_PRINTER(MIN, signed char);
    T_PRINTER(MIN, signed short);
    T_PRINTER(MIN, signed int);
    T_PRINTER(MIN, signed long);
    T_PRINTER(MIN, signed long long);
    T_PRINTER(MIN, unsigned char);
    T_PRINTER(MIN, unsigned short);
    T_PRINTER(MIN, unsigned int);
    T_PRINTER(MIN, unsigned long);
    T_PRINTER(MIN, unsigned long long);
    T_PRINTER(MIN, float);
    T_PRINTER(MIN, double);
    T_PRINTER(MIN, long double);
    putchar('\n');
    T_PRINTER(MIN, char*);
    T_PRINTER(MIN, short*);
    T_PRINTER(MIN, int*);
    T_PRINTER(MIN, long*);
    T_PRINTER(MIN, long long*);
    T_PRINTER(MIN, signed char*);
    T_PRINTER(MIN, signed short*);
    T_PRINTER(MIN, signed int*);
    T_PRINTER(MIN, signed long*);
    T_PRINTER(MIN, signed long long*);
    T_PRINTER(MIN, unsigned char*);
    T_PRINTER(MIN, unsigned short*);
    T_PRINTER(MIN, unsigned int*);
    T_PRINTER(MIN, unsigned long*);
    T_PRINTER(MIN, unsigned long long*);
    T_PRINTER(MIN, float*);
    T_PRINTER(MIN, double*);
    T_PRINTER(MIN, long double*);
    putchar('\n');
    T_PRINTER(MAX, char);
    T_PRINTER(MAX, short);
    T_PRINTER(MAX, int);
    T_PRINTER(MAX, long);
    T_PRINTER(MAX, long long);
    T_PRINTER(MAX, signed char);
    T_PRINTER(MAX, signed short);
    T_PRINTER(MAX, signed int);
    T_PRINTER(MAX, signed long);
    T_PRINTER(MAX, signed long long);
    T_PRINTER(MAX, unsigned char);
    T_PRINTER(MAX, unsigned short);
    T_PRINTER(MAX, unsigned int);
    T_PRINTER(MAX, unsigned long);
    T_PRINTER(MAX, unsigned long long);
    T_PRINTER(MAX, float);
    T_PRINTER(MAX, double);
    T_PRINTER(MAX, long double);
    putchar('\n');
    T_PRINTER(MAX, char*);
    T_PRINTER(MAX, short*);
    T_PRINTER(MAX, int*);
    T_PRINTER(MAX, long*);
    T_PRINTER(MAX, long long*);
    T_PRINTER(MAX, signed char*);
    T_PRINTER(MAX, signed short*);
    T_PRINTER(MAX, signed int*);
    T_PRINTER(MAX, signed long*);
    T_PRINTER(MAX, signed long long*);
    T_PRINTER(MAX, unsigned char*);
    T_PRINTER(MAX, unsigned short*);
    T_PRINTER(MAX, unsigned int*);
    T_PRINTER(MAX, unsigned long*);
    T_PRINTER(MAX, unsigned long long*);
    T_PRINTER(MAX, float*);
    T_PRINTER(MAX, double*);
    T_PRINTER(MAX, long double*);
    putchar('\n');
}

int main(int argc, char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    __print_type_sizes();

    return EXIT_SUCCESS;
}

// legacy
#if (0)

#include <stdarg.h>

double poli(double x, int argc, ...) {
    double result = 0.0;
    double x1 = 1.0;
    va_list opt;
    va_start(opt, argc);
    while (argc--) {
        double coef = (double)va_arg(opt, double);
        result += x1 * coef;
        x1 *= x;
    }
    va_end(opt);
    return result;
}

#define gpoli(x, ...) poli(x, VA_NARG(__VA_ARGS__), VA_ARG_REVERSE(__VA_ARGS__))

#include "utils/timer.h"


double y = 0.0;
char str[128];
timer_t timer;

tim_start(&timer);
for (double x = -6.5; x < 55; x += 0.0000001)
    y = gpoli(x, 0.0015, -0.0919, 25.419, 0);
tim_stop(&timer);
//tim_elapsed(&timer);
printf("time: %s", tim_str(&timer, str));

double x = 0.0;
x = gpoli(8.298, 5e-8, -9e-6, 0.0006, -0.0177, 0.1938, 23.91, 0);
x = gpoli(54.886, 0.0015, -0.0919, 25.419, 0);
#endif