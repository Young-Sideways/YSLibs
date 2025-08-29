/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

/***********************
 * ╦ ╦═╗ ╦   ╦ ╦═╗ ╔═╗ *
 * ╚╦╝═╗ ║   ║ ╠═╣ ╚═╗ *
 *  ╩╚═╝ ╚═╝ ╩ ╩═╝ ╚═╝ *
 ***********************/


#include "core/inc/core/core.h"
#include "collection/inc/collection/array.h"
#include "algorithm/inc/algorithm/memory.h"
#include "macro/inc/macro/arg.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


//typedef struct __tpl_arg { void* arg; size_t size; } __tpl_args[];
//
//#define tpl_ctor(...)                                         \
//    (tpl_ctor)(                                               \
//        VA_COUNT(__VA_ARGS__),                                \
//        (__tpl_args){                                         \
//            VA_EXEC(0, __TPL_CTOR_TRANSFORM_ARG, __VA_ARGS__) \
//        }                                                     \
//    )
//
//
//#define __TPL_CTOR_TRANSFORM_ARG(arg) { (void*)(YSL_TYPEOF_UNQUAL(arg)[1]){ arg } , sizeof(arg) }
//
//
//void (tpl_ctor)(size_t count, __tpl_args values) {
//    for (int i = 0; i < count; i++) {
//        printf("arg: %d | size: %zu\n", i, values[i].size);
//    }
//}

#include "collection/inc/collection/iterator.h"


#define c_for(it, collection) \
    for (iterator_t __iter = it_begin(collection), __end = it_end(collection); !it_equal(__iter, __end); it_next(&__iter)) \
        for (it##_temp, *__temp = (YSL_TYPEOF(__temp))it_get(__iter); __temp != NULL;) \
            for (it = *__temp; __temp != NULL; __temp = NULL)



void arr_print_generic(array_t array) {
    char buf[32] = { 0 };

    if (array == NULL) {
        puts("Invalid array!");
        return;
    }

    printf("size        : %d\nelement_size: %d\n", 
        arr_size(array), 
        arr_element_size(array)
    );

    for (int i = 0; i < arr_size(array); i++) {
        printf("p: %zu | ", memthex(buf, arr_at(array, i), arr_element_size(array)));
        printf("%d: 0x%s\n", i, buf);
    }
}


int main(int argc, char** argv) {
    YSL_UNUSED(argc);
    YSL_UNUSED(argv);

    int *array = arr_ctor(int, 10);

    arr_print_generic(array);

    arr_emplace(array, 1, 13);
    arr_emplace(array, 9, 726354);
    arr_emplace(array, 3, -326);

    array[2] = 0x12345678;
    array[0] = 0xABCDEF98;

    arr_print_generic(array);

    int *new_slice = arr_slice(array, 9, -2);

    arr_print_generic(new_slice);

    int value = 726354;
    printf("value %d found on index %d\n", value, arr_find(array, value));

    arr_sort(array);


    arr_print_generic(array);

    arr_dtor(array);
    arr_dtor(new_slice);


    array_t my_array;

    c_for(int i, my_array) {}

    return 0;
}
