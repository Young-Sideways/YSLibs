/*******************************************************************************
 *  @file      task3.c
 *  @brief     Ответы на 3 задание
 *  @author    Young Sideways
 *  @date      14.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "task3.h"

#define _COMPARATOR_DECLARATOR_
#define _SWAP_DECLARATOR_
#include "../algorithm/algorithm.h"

#include "../utils/timer.h"
#include "../utils/console.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int task3() {
    bool cycle = true;
    char mode = '\0';
    timer_t timer;

    sort_pt sort = NULL;
    comparator_pt comp = NULL;

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
            sort = (sort_pt)&qsort;
            break;
        case '5':
            puts("exit \"task3\" module");
            cycle = false;
            system("cls||clear");
            continue;
        default:
            system("cls||clear");
            puts("Incorrect mode. Please repeat input");
            continue;
        }

        con_enum(
            "forward comparator" ENDL
            "reverse comparator" ENDL
            "back" ENDL,
            ALIGN_HLEFT, enum_to_arabic);
        printf("Select compare function: ");
        printf("%c\n\n", mode = menu_getc());

        switch (mode)
        {
        case '1':
            comp = i32_fcomp;
            break;
        case '2':
            comp = i32_rcomp;
            break;
        case '3':
            system("cls||clear");
            continue;
        default:
            system("cls||clear");
            puts("Incorrect mode. Please repeat input");
            continue;
        }

        printf("enter number of sorting elements: ");
        unsigned count = 0;
        if (!scanf("%u", &count)) {
            system("cls||clear");
            puts("Incorrect number of sorting elements. Please repeat input");
            continue;
        }
        putchar('\n');

        int* array = (int*)malloc(count * sizeof(int));
        if (!array) {
            system("cls||clear");
            puts("Error via allocating memory for array");
            return 1;
        }

        puts("Filling array with random numbers...");
        tim_start(&timer);
        random_fill(array, count, NULL, INT_MIN, INT_MAX);
        tim_stop(&timer);
        printf("Generated for: %s\n\n", tim_str(&timer, TIM_PRECISION_AUTO));

        puts("Sorting array...");
        tim_start(&timer);
        sort(array, count, sizeof(int), comp, &i32_swap);
        tim_stop(&timer);
        printf("Sorting done! Sorted for: %s\n", tim_str(&timer, TIM_PRECISION_AUTO));

        puts("\n------------------------------------------------------------------------\n");
        free(array);
        array = NULL;
    }
    return 0;
}