#include "core/core.h"
//#include "core/metrics.h"
//#include "task3/task3.h"

#include <stdlib.h>
#include <stdio.h>

#define _SEQ_PRINTERS

#include "core/macro/varidatic.h"
#include "core/macro/reverse.h"
#include "core/macro/sequence.h"
#include "core/macro/exec.h"


#define FLASH_RW_CODE UINT8_MAX

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


setting_t set;

typedef enum {
    A_READ = 0x64,
    A_WRITE = 0x65
} a_mode;


void process_param(int8_t srv_c, int8_t msg_c, void* msg_data) {
    switch (srv_c)
    {
    case A_READ:
        if (msg_c == FLASH_RW_CODE) {
            // Чтение структуры с флешки во внутреннюю память
            break;
        }
        break;
    case A_WRITE:
        if (msg_c == FLASH_RW_CODE) {
            // Запись структуры во флешку во внутреннюю память
            break;
        }
        break;
    default:
        break;
    }
}




int main(int argc, char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    _va_exec_printer(4, 256);

    // task3();

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