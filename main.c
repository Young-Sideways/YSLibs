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

#if (0) // Зачатки tuple
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



#include <stdio.h>
#include <stdlib.h>

#include "core/core.h"
#include "utils/timer.h"
#include "task3/task3.h"


int main(int argc, char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    timer_t timer;
    tim_start(&timer);
    tim_stop(&timer);
    printf("%s\n", tim_str(&timer, TIM_PRECISION_AUTO));

    //task3();

    return EXIT_SUCCESS;
}