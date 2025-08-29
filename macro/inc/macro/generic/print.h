/*******************************************************************************
 *  @file      print.h
 *  @brief     Generic print function
 *  @author    Young Sideways
 *  @date      8.04.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#ifndef G_PRINT_H_
#define G_PRINT_H_


#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

#include <core/core.h>

#include "../sequence.h"
#include "../arg.h"
#include "../exec.h"


#pragma region --- GENERIC ---

#define G_FORMAT_OF(x) _Generic( (*((YSL_TYPEOF_UNQUAL(x)*)NULL)) , \
    char                     : "%c" , \
    signed char              : "%hhd" , \
    signed short             : "%hd"  , \
    signed int               : "%d"   , \
    signed long              : "%ld"  , \
    signed long long         : "%lld" , \
    unsigned char            : "%hhu" , \
    unsigned short           : "%hu"  , \
    unsigned int             : "%u"   , \
    unsigned long            : "%lu"  , \
    unsigned long long       : "%llu" , \
    float                    : "%g"   , \
    double                   : "%lg"  , \
    long double              : "%Lg"  , \
                                        \
    char*                    : "%s"   , \
    signed char*             : "%p"   , \
    signed short*            : "%p"   , \
    signed int*              : "%p"   , \
    signed long*             : "%p"   , \
    signed long long*        : "%p"   , \
    unsigned char*           : "%p"   , \
    unsigned short*          : "%p"   , \
    unsigned int*            : "%p"   , \
    unsigned long*           : "%p"   , \
    unsigned long long*      : "%p"   , \
    float*                   : "%p"   , \
    double*                  : "%p"   , \
    long double*             : "%p"   , \
                                        \
    const char*              : "%s"   , \
    const signed char*       : "%p"   , \
    const signed short*      : "%p"   , \
    const signed int*        : "%p"   , \
    const signed long*       : "%p"   , \
    const signed long long*  : "%p"   , \
    const unsigned char*     : "%p"   , \
    const unsigned short*    : "%p"   , \
    const unsigned*          : "%p"   , \
    const unsigned long*     : "%p"   , \
    const unsigned long long*: "%p"   , \
    const float*             : "%p"   , \
    const double*            : "%p"   , \
    const long double*       : "%p"   , \
                                        \
    void*                    : "%p"   , \
    const void*              : "%p"   , \
                                        \
    default                  : "%X"     \
)
#define G_FORMAT_SIZE_OF(x) (sizeof(G_FORMAT_OF(x)) - 1)


#define __G_FORMAT_CONSTRUCT(x) { .fmt = G_FORMAT_OF(x) , .size = G_FORMAT_SIZE_OF(x) }
#define __G_FORMATS_TOTAL_SIZE(...) VA_SEQ( + , VA_EXEC(0, G_FORMAT_SIZE_OF, __VA_ARGS__))

struct __g_format_of_handler_t {const char* fmt; const size_t size; };

static int __g_print_fprintf(struct __g_format_of_handler_t const fmts[], size_t fmts_count, size_t format_size, FILE* restrict stream,  ...) {
    int ret = 0;

    char* format = malloc(format_size);
    if (format == NULL)
        goto MALLOC_FAIL;

    char* ptr_i = format;
    for (size_t i = 0; i < fmts_count; i++) {
        if (memcpy(ptr_i, fmts[i].fmt, fmts[i].size) == NULL)
            goto MEMCPY_FAIL;
        ptr_i += fmts[i].size;
    }
    *ptr_i = '\0';

    va_list args;
    va_start(args, stream);

    ret = vfprintf(stream, format, args);

    va_end(args);

    MEMCPY_FAIL:
    free(format);
    MALLOC_FAIL:
    return ret;
}

static int __g_print_snprintf(struct __g_format_of_handler_t const fmts[], size_t fmts_count, size_t format_size, char* buf, size_t buf_size,  ...) {
    int ret = 0;

    char* format = malloc(format_size);
    if (format == NULL)
        goto MALLOC_FAIL;

    char* ptr_i = format;
    for (size_t i = 0; i < fmts_count; i++) {
        if (memcpy(ptr_i, fmts[i].fmt, fmts[i].size) == NULL)
            goto MEMCPY_FAIL;
        ptr_i += fmts[i].size;
    }
    *ptr_i = '\0';

    va_list args;
    va_start(args, stream);

    ret = vsnprintf(buf, buf_size, format, args);

    va_end(args);
    free(format);

    MEMCPY_FAIL:
    free(format);
    MALLOC_FAIL:
    return ret;
}



#define G_PRINTF(...) G_FPRINTF(stdout, __VA_ARGS__)
#define G_FPRINTF(stream, ...) __g_print_fprintf( (struct __g_format_of_handler_t[]){ VA_EXEC(0, __G_FORMAT_CONSTRUCT, __VA_ARGS__) }, VA_COUNT(__VA_ARGS__), __G_FORMATS_TOTAL_SIZE(__VA_ARGS__) + 1, stream, __VA_ARGS__ )

#define G_SPRINTF(buf, ...) G_SNPRINTF(buf, SIZE_MAX, ...)
#define G_SNPRINTF(buf, buf_size, ...) __g_print_snprintf( (struct __g_format_of_handler_t[]){ VA_EXEC(0, __G_FORMAT_CONSTRUCT, __VA_ARGS__) }, VA_COUNT(__VA_ARGS__), __G_FORMATS_TOTAL_SIZE(__VA_ARGS__) + 1, buf, buf_size, __VA_ARGS__ )

#pragma endregion

#endif // !G_PRINT_H_
