/*******************************************************************************
 *  @file      task3.c
 *  @brief     Подпрограмма выполнения для темы 3
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "task3/task3.h"

#include "algorithm/algorithm.h"

#include "util/timer.h"
#include "util/console.h"

#include "debug.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static inline int i32_fcomp(const void* lhs, const void* rhs, size_t size) {
    UNUSED(size);
    assert(lhs);
    assert(rhs);
    return *(int32_t*)lhs - *(int32_t*)rhs;
}
static inline int qsort_i32_fcomp(const void* lhs, const void* rhs) {
    assert(lhs);
    assert(rhs);
    return *(int32_t*)lhs - *(int32_t*)rhs;
}
static inline int i32_rcomp(const void* lhs, const void* rhs, size_t size) {
    UNUSED(size);
    assert(lhs);
    assert(rhs);
    return *(int32_t*)rhs - *(int32_t*)lhs;
}
static inline int qsort_i32_rcomp(const void* lhs, const void* rhs) {
    assert(lhs);
    assert(rhs);
    return *(int32_t*)rhs - *(int32_t*)lhs;
}
static inline void i32_swap(void* lhs, void* rhs, size_t size) {
    UNUSED(size);
    assert(lhs);
    assert(rhs);
    int32_t temp = *(int32_t*)lhs;
    *(int32_t*)lhs = *(int32_t*)rhs;
    *(int32_t*)rhs = temp;
}

int task3() {
    bool cycle = true;
    char mode = '\0';
    tim_t timer;

    sort_t sort = NULL;
    comparator_t comp = NULL;

    puts("Starting \"task3\" module\n");

    while (cycle) {
        con_enum(
            "selection_sort" ENDL
            "insertion_sort" ENDL
            "quick_sort" ENDL
            "default C q_sort" ENDL
            "back" ENDL,
            ALIGN_HLEFT, enum_to_arabic);
        printf("Select sorting algorithm: ");
        mode = menu_getc();
        putchar('\n');

        switch (mode)
        {
        case '1':
            sort = &selection_sort;
            break;
        case '2':
            sort = &insertion_sort;
            break;
        case '3':
            sort = &quick_sort;
            break;
        case '4':
            sort = NULL;
            break;
        case '5':
            puts("exit \"task3\" module");
            cycle = false;
            system("clear");
            continue;
        default:
            system("clear");
            puts("Incorrect mode. Please repeat input");
            continue;
        }
        char ex_mode = '\0';
        con_enum(
            "forward comparator" ENDL
            "reverse comparator" ENDL
            "back" ENDL,
            ALIGN_HLEFT, enum_to_arabic);
        printf("Select compare function: ");
        printf("%c\n\n", ex_mode = menu_getc());

        switch (ex_mode)
        {
        case '1':
            comp = i32_fcomp;
            break;
        case '2':
            comp = i32_rcomp;
            break;
        case '3':
            system("clear");
            continue;
        default:
            system("clear");
            puts("Incorrect mode. Please repeat input");
            continue;
        }

        printf("enter number of sorting elements: ");
        unsigned count = 0;
        if (!scanf("%u", &count)) {
            system("clear");
            puts("Incorrect number of sorting elements. Please repeat input");
            continue;
        }
        putchar('\n');

        int* array = (int*)malloc(count * sizeof(int));
        if (!array) {
            system("clear");
            puts("Error via allocating memory for array");
            return 1;
        }

        puts("Filling array with random numbers...");
        tim_start(&timer);
        random_fill(array, count, NULL, INT32_MIN, INT32_MAX);
        tim_stop(&timer);
        printf("Generated for: %s\n\n", tim_str(&timer, TIM_PRECISION_AUTO));

        puts("Sorting array...");
        tim_start(&timer);
        if (mode == '4')
            qsort(array, count, sizeof(int), ex_mode == '1' ? qsort_i32_fcomp : qsort_i32_rcomp);
        else
            sort(array, count, sizeof(int), comp, &i32_swap);
        tim_stop(&timer);
        printf("Sorting done! Sorted for: %s\n", tim_str(&timer, TIM_PRECISION_AUTO));

        puts("\n------------------------------------------------------------------------\n");
        free(array);
        array = NULL;
    }
    return 0;
}