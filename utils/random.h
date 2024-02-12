#ifndef _RANDOM_H_
#define _RANDOM_H_

#pragma once

#include <time.h>
#include <stdlib.h>

/**
 * @brief Initilizes a PRNG with curren time stamp
 */
void random_init();

typedef (random_t)(int, int);
typedef random_t* random_pt;

/**
 * @brief default random function
 * @param min - minimum value of generated range
 * @param max - maximum value of generated range
 * @return generated value via [min; max]
 */
random_t random;

/**
 * @brief fills int array with predicated PRNG
 * @param array - pointer to int array
 * @param size - size of input array
 * @param generator - pointer to PRNG (can be NULL)
 * @param min - minimum value of generated range
 * @param max - maximum value of generated range
 */
void random_fill(int*, size_t, random_pt, int, int);

#endif // !_RANDOM_H_


