#pragma once
#include <limits.h>

#define MAX(C) _Generic((C)0, \
    char: CHAR_MAX, \
    short: SHORT_MAX, \
    int: INT_MAX, \
    long: LONG_MAX, \
    long long: LLONG_MAX, \
    unsigned char: UCHAR_MAX, \
    unsigned short: USHRT_MAX, \
    unsigned: UINT_MAX, \
    unsigned long: ULONG_MAX, \
    unsigned long long: ULLONG_MAX, \
    char*: SIZE_MAX, \
    short*: SIZE_MAX, \
    int*: SIZE_MAX, \
    long*: SIZE_MAX, \
    long long*: SIZE_MAX, \
    unsigned char*: SIZE_MAX, \
    unsigned short*: SIZE_MAX, \
    unsigned*: SIZE_MAX, \
    unsigned long*: SIZE_MAX, \
    unsigned long long*: SIZE_MAX, \
    void* : SIZE_MAX, \
	default: NULL)
#define MIN(C) _Generic((C)0, \
    char: CHAR_MIN, \
    short: SHORT_MIN, \
    int: INT_MIN, \
    long: LONG_MIN, \
    long long: LLONG_MIN, \
    unsigned char: 0, \
    unsigned short: 0, \
    unsigned: 0, \
    unsigned long: 0, \
    unsigned long long: 0, \
    char*: (char*)0, \
    short*: (short*)0, \
    int*: (int*)0, \
    long*: (long*)0, \
    long long*: (long long*)0, \
    unsigned char*: (unsigned char*)0, \
    unsigned short*: (unsigned short*)0, \
    unsigned*: (unsigned*)0, \
    unsigned long*: (unsigned long*)0, \
    unsigned long long*: (unsigned long long*)0, \
    void* : (void*)0, \
	default: NULL)

#if (0)
printf("0x%llX\n", MAX(char));
printf("0x%llX\n", MAX(short));
printf("0x%llX\n", MAX(int));
printf("0x%llX\n", MAX(long));
printf("0x%llX\n", MAX(long long));
printf("0x%llX\n", MAX(signed char));
printf("0x%llX\n", MAX(signed short));
printf("0x%llX\n", MAX(signed int));
printf("0x%llX\n", MAX(signed long));
printf("0x%llX\n", MAX(signed long long));
printf("0x%llX\n", MAX(unsigned char));
printf("0x%llX\n", MAX(unsigned short));
printf("0x%llX\n", MAX(unsigned int));
printf("0x%llX\n", MAX(unsigned long));
printf("0x%llX\n", MAX(unsigned long long));
printf("\n");
printf("0x%llX\n", MAX(char*));
printf("0x%llX\n", MAX(short*));
printf("0x%llX\n", MAX(int*));
printf("0x%llX\n", MAX(long*));
printf("0x%llX\n", MAX(long long*));
printf("0x%llX\n", MAX(signed char*));
printf("0x%llX\n", MAX(signed short*));
printf("0x%llX\n", MAX(signed int*));
printf("0x%llX\n", MAX(signed long*));
printf("0x%llX\n", MAX(signed long long*));
printf("0x%llX\n", MAX(unsigned char*));
printf("0x%llX\n", MAX(unsigned short*));
printf("0x%llX\n", MAX(unsigned int*));
printf("0x%llX\n", MAX(unsigned long*));
printf("0x%llX\n", MAX(unsigned long long*));
printf("\n");
printf("0x%llX\n", MIN(char));
printf("0x%llX\n", MIN(short));
printf("0x%llX\n", MIN(int));
printf("0x%llX\n", MIN(long));
printf("0x%llX\n", MIN(long long));
printf("0x%llX\n", MIN(signed char));
printf("0x%llX\n", MIN(signed short));
printf("0x%llX\n", MIN(signed int));
printf("0x%llX\n", MIN(signed long));
printf("0x%llX\n", MIN(signed long long));
printf("0x%llX\n", MIN(unsigned char));
printf("0x%llX\n", MIN(unsigned short));
printf("0x%llX\n", MIN(unsigned int));
printf("0x%llX\n", MIN(unsigned long));
printf("0x%llX\n", MIN(unsigned long long));
printf("\n");
printf("0x%llX\n", MIN(char*));
printf("0x%llX\n", MIN(short*));
printf("0x%llX\n", MIN(int*));
printf("0x%llX\n", MIN(long*));
printf("0x%llX\n", MIN(long long*));
printf("0x%llX\n", MIN(signed char*));
printf("0x%llX\n", MIN(signed short*));
printf("0x%llX\n", MIN(signed int*));
printf("0x%llX\n", MIN(signed long*));
printf("0x%llX\n", MIN(signed long long*));
printf("0x%llX\n", MIN(unsigned char*));
printf("0x%llX\n", MIN(unsigned short*));
printf("0x%llX\n", MIN(unsigned int*));
printf("0x%llX\n", MIN(unsigned long*));
printf("0x%llX\n", MIN(unsigned long long*));
printf("\n");
#endif