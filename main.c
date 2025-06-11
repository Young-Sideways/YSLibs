/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

/*********************************************************
 *                                                       *
 * ╦ ╦ ╔═╗ ╦ ╦ ╔╗╔ ╔═╗     ╔═╗ ╦ ╔╦╗ ╔═╗ ╦ ╦ ╔═╗ ╦ ╦ ╔═╗ *
 * ╚╦╝ ║ ║ ║ ║ ║║║ ║ ╦     ╚═╗ ║  ║║ ║╣  ║║║ ╠═╣ ╚╦╝ ╚═╗ *
 *  ╩  ╚═╝ ╚═╝ ╝╚╝ ╚═╝     ╚═╝ ╩ ╚╩╝ ╚═╝ ╚╩╝ ╩ ╩  ╩  ╚═╝ *
 *                                                       *
 *********************************************************/


#include <core/core.h>

#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int memthex(char* buf, const void* src, const size_t size) {
    assert(buf  != NULL);
    assert(src  != NULL);
    assert(size != 0u);

    int ret = 0;
    int i = 0;

    // minimize 'snprintf' calls

    for (; ((size - i) / sizeof(uintmax_t)) != 0u; i += sizeof(uintmax_t))
        ret += snprintf(&(buf[i * 2]), sizeof(uintmax_t) * 2 + 1, "%" PRIXMAX, *(uintmax_t*)&(((uint8_t*)src)[size - i - sizeof(uintmax_t)]));
    for (; i < size; i++)
        ret += snprintf(&(buf[i * 2]), sizeof(uint8_t) * 2 + 1, "%" PRIX8, ((uint8_t*)src)[size - i - sizeof(uint8_t)]);
    
    return ret;
}

#define decl_test(type, init) \
void type##_test() { \
    type value = init; \
    const size_t size = sizeof(type); \
    char buf[size * 2 + 1]; \
    int ret = memthex(buf, (const void*)&value, size); \
    printf("size: %zu, value[%d]\t: '%s'\n", size, ret, buf); \
}
#define run_test(type) \
    type##_test()

typedef long double ldouble;

decl_test(int8_t  ,   INT8_C(0x12              ));
decl_test(int16_t ,  INT16_C(0x1234            ));
decl_test(int32_t ,  INT32_C(0x12345678        ));
decl_test(int64_t ,  INT64_C(0x1234567890ABCDEF));
decl_test(uint8_t ,  UINT8_C(0x12              ));
decl_test(uint16_t, UINT16_C(0x1234            ));
decl_test(uint32_t, UINT32_C(0x12345678        ));
decl_test(uint64_t, UINT64_C(0x1234567890ABCDEF));
decl_test(float   , 1.4563456f);
decl_test(double  , 56.321345 );
decl_test(ldouble , 18374567235468.0000000200345L);

#define array_t(type, n)  \
    type [n]

#define arr_ctor(type, n) \
    (array_t(type, n)) {0}

#define arr_size(arr) (sizeof(arr)/sizeof(*arr))

#define YSL_AUTO __auto_type


int main(int argc, char** argv) {
    YSL_UNUSED(argc);
    YSL_UNUSED(argv);


    YSL_AUTO my_arr = arr_ctor(int, 10);

    for (int i = 0; i < arr_size(my_arr); i++)
        my_arr[i] = i+1;
    for (int i = 0; i < arr_size(my_arr); i++)
        printf("%i ", my_arr[i]);
    putc('\n', stdout);
    

    int a[10];
    int b = sizeof(a);

    run_test(int8_t  );
    run_test(int16_t );
    run_test(int32_t );
    run_test(int64_t );
    run_test(uint8_t );
    run_test(uint16_t);
    run_test(uint32_t);
    run_test(uint64_t);
    run_test(float   );
    run_test(double  );
    run_test(ldouble );

    return 0;
}