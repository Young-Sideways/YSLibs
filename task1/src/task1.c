/*******************************************************************************
 *  @file      task1.c
 *  @brief     Подпрограмма выполнения для темы 1
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "task1/task1.h"

#include "util/timer.h"
#include "util/console.h"

#include "collection/btree.h"

#include "collection/iterator.h"
#include "macro/foreach.h"

#include <stdio.h>

int task1() {
    bool cycle = true;
    char mode = '\0';

    btree_t tree = btree_init(sizeof(int));
    if (!tree) {
        fprintf(stderr, "error via allocating memory for tree");
        return 1;
    }

    puts("Starting \"task1\" module\n");

    while (cycle) {


        con_enum(
        "insert value" ENDL
        "erase value" ENDL
        "check value" ENDL
        "count value" ENDL
        "print all values" ENDL
        "back" ENDL,
        ALIGN_HLEFT, enum_to_arabic);

        printf("Select mode: ");
        mode = menu_getc();
        putchar('\n');

        switch (mode)
        {
            case '1': {
                printf("enter value: ");
                int value = 0;
                if (!scanf("%d", &value)) {
                    system("cls||clear");
                    puts("Invalid input. Repeat");
                    continue;
                }
                btree_insert(tree, &value);
                printf("\nvalue '%d' inserted to tree\n", value);
                break;
            }
            case '2': {
                printf("enter value: ");
                int value = 0;
                if (!scanf("%d", &value)) {
                    system("cls||clear");
                    puts("Invalid input. Repeat");
                    continue;
                }
                btree_erase(tree, &value);
                printf("\nvalue '%d' erased from tree\n", value);
                break;
            }
            case '3': {
                printf("enter value: ");
                int value = 0;
                if (!scanf("%d", &value)) {
                    system("cls||clear");
                    puts("Invalid input. Repeat");
                    continue;
                }
                printf("\nvalue '%d' %scontains in tree\n", value, btree_contains(tree, &value) ? "" : "does not " );
                break;
            }
            case '4': {
                printf("enter value: ");
                int value = 0;
                if (!scanf("%d", &value)) {
                    system("cls||clear");
                    puts("Invalid input. Repeat");
                    continue;
                }
                int count = btree_count(tree, &value);
                printf("\ncount value '%d' in tree: %d\n", value, count);
                break;
            }
            case '5': {
                int counter = 0;
                for_each(int, i, tree) {
                    printf("value '%d' with index '%d'\n", *i, counter++);
                }
                break;
            }
            case '6':
                puts("exit \"task3\" module");
                cycle = false;
                system("cls||clear");
                continue;
            default:
                system("cls||clear");
                puts("Incorrect mode. Please repeat input");
                continue;
        }
        puts("\n------------------------------------------------------------------------\n");
    }
    delete(&tree);
    return 0;
}