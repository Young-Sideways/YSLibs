/*******************************************************************************
 *  @file      task2.c
 *  @brief     Ответы на 2 задание
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

/// dev comment: Да, я знаю что имена пользователей вызывают memory leak

#include "task2.h"

#define _COMPARATOR_DECLARATOR_
#define _SWAP_DECLARATOR_

#include "../core/core.h"

#include "../algorithm/algorithm.h"
#include "../collection/collections.h"

#include "../utils/timer.h"
#include "../utils/console.h"

#include "../core/macro/macro.h"
#include "../core/macro/exec.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_NAME 64
#define INVALID_CUSTOMER (customer_t) { .name = "Invalid name", .money = NAN }

typedef struct customer_t {
    char* name;
    float money;
} customer_t;

static const customer_t customers[] = {
    { "Bob"      , 2834765 },
    { "Rob"      , 234     },
    { "Danny"    , 7567    },
    { "Simon"    , -278    },
    { "Lucy"     , 28345   },
    { "Maria"    , 258900  },
    { "Franklin" , 1       },
    { "Mary"     , -26735  }
};

void print_customer(customer_t customer) {
    printf("name : %s\nmoney: %f\n", customer.name, customer.money);
}

customer_t enter_customer() {
    char buf[MAX_NAME] = { 0 };
    float money = 0.0f;
    int retval = EOF;

    printf("enter name: ");

    retval = scanf(" %" M_EXEC(M_STRINGIFY, MAX_NAME) "[^\n]s ", buf);
    if (retval < 1 || retval == EOF) {
        puts("Invalid customer name. Repeat");
        return INVALID_CUSTOMER;
    }
    printf("\nenter money: ");
    retval = scanf(" %f", &money);
    if (retval < 1 || retval == EOF) {
        puts("Invalid customer money. Repeat");
        return INVALID_CUSTOMER;
    }
    printf("[ DEBUG ]: money %f\n", money);
    putchar('\n');
    size_t name_size = strlen(buf);
    char* name = malloc(name_size + 1);
    if (!name)
        return (customer_t) { .name = "Invalid name", .money = NAN };
    memcpy(name, buf, name_size + 1);

    return (customer_t) { .name = name, .money = money };
}

int str_comp(const void* lhs, const void* rhs, size_t size) {
    UNUSED(size);
    char* str_lhs = *(char**)lhs;
    char* str_rhs = *(char**)rhs;
    return strcmp(str_lhs, str_rhs);
}
const char* const enter_name() {
    static char buf[MAX_NAME] = { 0 };

    printf("enter name: ");
    int retval = scanf(" %" M_EXEC(M_STRINGIFY, MAX_NAME) "[^\n]s ", buf);
    if (retval < 1 || retval == EOF) {
        puts("Invalid customer name. Repeat");
        return NULL;
    }
    putchar('\n');
    return buf;
}

typedef struct kv_pair {
    char* name;
    float money;
} kv_pair;

int task2() {
    bool cycle = true;
    char mode = '\0';
    timer_t timer;
    char* name;

    puts("Starting \"task2\" module\n");

    hashtable_t table = ht_init(0U, sizeof(char*), sizeof(float), &str_hash);  //!< Минимальное значение размера будет 7
    set_comp(table, &str_comp);

    for (int i = 0; i < sizeof(customers) / sizeof(*customers); i++)
        ht_insert(table, &(customers[i].name), &(customers[i].money));

    while (cycle) {
        

        con_enum(
            "find customer" ENDL
            "add customer" ENDL
            "remove customer" ENDL
            "customer list" ENDL
            "back" ENDL,
            ALIGN_HLEFT, enum_to_arabic);
        printf("Select action: ");
        mode = menu_getc();
        putchar('\n');

        switch (mode)
        {
        case '1':
            name = enter_name();
            if (!name) {
                puts("Invalid customer name");
                break;
            }
            float* money = NULL;
            if (money = (float*)ht_lookup(table, &name))
                printf("Customer with name '%s' exists with money %f\n", name, *money);
            else
                printf("No customer with name '%s'\n", name);
            break;
        case '2':
            customer_t customer = enter_customer();
            print_customer(customer);
            if (isnan(customer.money))
                break;
            if (ht_contains(table, &(customer.name))) {
                puts("Customer already exist. Repeat input");
                break;
            }
            printf("    [ DEBUG ] size %llu\n", table->size);
            ht_insert(table, &(customer.name), &(customer.money));
            printf("    [ DEBUG ] size %llu\n", table->size);
            if (!ht_contains(table, &(customer.name)))
                puts("Can't add customer to table");
            else
                puts("Customer successfuly added!");
            break;
        case '3':
            name = enter_name();
            if (name && ht_contains(table, &name))
                ht_erase(table, &name);
            else
                printf("no customer with name '%s'\n", name);
            break;
        case '4':
            printf("    [ DEBUG ] size %llu\n", table->size);
            for_each(kv_pair, it, table) {
                print_customer((customer_t) { .name = it->name, .money = it->money });
            }
            break;
        case '5':
            puts("exit \"task2\" module");
            cycle = false;
            system("cls||clear");
            break;
        default:
            system("cls||clear");
            puts("Incorrect mode. Please repeat input");
            break;
        }

        putchar('\n');

    
    }
    delete(&table);
    return 0;
}
