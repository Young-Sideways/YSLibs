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
#include "../utils/utils.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int task3() {
    bool cycle = true;
    char mode = '\0';
    timer_t timer;

    sort_pt sort = NULL;
    comparator_pt comp = NULL;

    printf("Starting \"task3\" module\n\n");

    while (cycle) {
        printf("\t1. selection_sort\n");
        printf("\t2. insertion_sort\n");
        printf("\t3. quick_sort\n");
        printf("\t4. default C q_sort\n");
        printf("\t5. back\n");
        printf("Select sorting algorithm: ");
        mode = getch_menu();
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
            sort = &qsort;
            break;
        case '5':
            printf("exit \"task3\" module\n");
            cycle = false;
            system("cls||clear");
            continue;
        default:
            system("cls||clear");
            printf("Incorrect mode. Please repeat input\n");
            continue;
        }

        puts("\t1. forward comparator");
        puts("\t2. reverse comparator");
        puts("\t3. back");
        printf("Select compare function: ");
        mode = getch_menu();
        putchar('\n');

        switch (mode)
        {
        case '1':
            comp = &i32_fcomp;
            break;
        case '2':
            comp = &i32_rcomp;
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

        printf("Filling array with random numbers...\n");
        tim_start(&timer);
        random_fill(array, count, NULL, INT_MIN, INT_MAX);
        tim_stop(&timer);
        char str[20];
        printf("Generated for: %s\n\n", tim_str(&timer, TIM_PRECISION_AUTO));

        printf("Sorting array...\n");
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