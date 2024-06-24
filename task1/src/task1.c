/*******************************************************************************
 *  @file      task1.c
 *  @brief     Подпрограмма выполнения для темы 1
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "task1.h"

#include "util/timer.h"
#include "util/console.h"

#include "collection/btree.h"

#include <stdio.h>

int task1() {
    bool cycle = true;
    char mode = '\0';
    timer_t timer;

    puts("Starting \"task1\" module\n");

    while (cycle) {
        con_enum(
        "insert value" ENDL
        "erase value" ENDL
        "check value" ENDL
        "back" ENDL,
        ALIGN_HLEFT, enum_to_arabic);

        printf("Select mode: ");
        mode = menu_getc();
        putchar('\n');

        switch (mode)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                puts("exit \"task3\" module");
                cycle = false;
                system("cls||clear");
                continue;
            default:
                system("cls||clear");
                puts("Incorrect mode. Please repeat input");
                continue;
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