/*******************************************************************************
 *  @file      main.h
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright � Young Sideways, 2024. All right reserved.
 ******************************************************************************/

/**
 * Добро пожаловать в мой проект.
 * Реализация заданий лежит по путям:
 *     папка task1/ - реализация задания 1
 *     папка task2/ - реализация задания 2
 *     папка task3/ - реализация задания 3
 *
 * Было реализовано множество вспомогательных элементов
 * Большинство элементов хорошо документированы
 * Приятного просмотра © Young Sideways (Басыров Дмитрий)
 */

#pragma region --- INCLUDE ---

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/core.h"

//#include "utils/console.h"

#if defined(_TISBI_)
#include "task1/task1.h"
#include "task2/task2.h"
#include "task3/task3.h"

int task_processor() {
    bool cycle = true;
    char mode = '\0';

    puts("Welcome to YS Libs");

    while (cycle) {
        con_enum(
            "task1 module\n"
            "task2 module\n"
            "task3 module\n"
            "exit"
            , ALIGN_HLEFT, enum_to_arabic);
        printf("Enter task number: ");
        mode = menu_getc();
        switch (mode)
        {
        case '1':
            task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            task3();
            break;
        case '4':
            puts("Exiting...");
            cycle = false;
            break;
        default:
            puts("Invalid input");
            break;
        }
    }
}
#endif // !_TISBI_

#pragma endregion