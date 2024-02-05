#ifndef _RANDOM_H_
#define _RANDOM_H_

#pragma once

#include <time.h>
#include <stdlib.h>


void random_init();
int random(int, int);
void random_fill(int*, size_t);

#endif // !_RANDOM_H_