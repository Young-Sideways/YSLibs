#pragma once

#include "../utils/utils.h"
#include "../utils/random.h"

#include <stdio.h>
#include <ctype.h>


/*
 * @brief Forward compare function for int type with overflow protection
 * @param lhs - pointer to left value
 * @param rhs - pointer to right value
 * @return difference over lhs and rhs values
 */
comp_t int_fcomp;

/*
 * @brief Reverse compare function for int type with overflow protection
 * @param lhs - pointer to left value
 * @param rhs - pointer to right value
 * @return difference over lhs and rhs values
 */
comp_t int_rcomp;


sort_t selection_sort;
sort_t insertion_sort;
sort_t quick_sort;

int task3();
