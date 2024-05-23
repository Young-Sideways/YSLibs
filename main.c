/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#include "main.h"

int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);

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
    return 0;
}
