/*******************************************************************************
 * @file      version.c
 * @brief     Version controlling utility library
 * @author    Young Sideways
 * @date      16.01.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2025. All right reserved.
 *******************************************************************************/


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../inc/util/version.h"

// <major>.<minor>.<patch> - <build version> <space> <hours>:<minutes>:<seconds> <space> <year>.<month>.<day>
// (0-255).(0-255).(0-255)-(0x00000000-0xFFFFFFFF)[(rele)] (0-24):(0-59):(0-59) (0-9999).(1-12).(1-31)


#pragma region --- IMPL ---

enum parser_state {
    STATE_NONE,
    STATE_FMT,
    STATE_FMT_SIGN
};

int format_build_type(const build_type_t type, char* buf) {
    const build_type_t build_type     = type & BUILD_TYPE_MASK;
    const build_type_t build_revision = type & BUILD_TYPE_REVISION_MASK;

    switch (build_type) {
        case BUILD_TYPE_RELEASE:
            return sprintf(buf, "release");
        case BUILD_TYPE_RELEASE_CANDIDATE:
            return sprintf(buf, "rc%s",
                (build_revision == BUILD_TYPE_REVISION_0 ? ""  :
                (build_revision == BUILD_TYPE_REVISION_1 ? "1" :
                (build_revision == BUILD_TYPE_REVISION_2 ? "2" :
                (build_revision == BUILD_TYPE_REVISION_3 ? "3" : ""))))
            );
        case BUILD_TYPE_BETA:
            return sprintf(buf, "beta");
        case BUILD_TYPE_ALPHA:
            return sprintf(buf, "alpha");
        default:
            return 0;
    }
}

int format_attribute(build_type_t type, char* buf) {
    type &= BUILD_TYPE_ATTRIBUTE_MASK;

    int shift = 0;

    if (type) {
        if ( (shift = sprintf(buf, "%s%s%s%s",
            (type & BUILD_TYPE_ATTRIBUTE_DEV     ? "dev,"     : ""), (type & BUILD_TYPE_ATTRIBUTE_DEBUG   ? "debug," : ""),
            (type & BUILD_TYPE_ATTRIBUTE_VERBOSE ? "verbose," : ""), (type & BUILD_TYPE_ATTRIBUTE_TEST    ? "test"   : "")
        )) ) {
            if (buf[shift - 1] == ',')
                buf[--shift] = '\0';
        }
    };
    return shift;
}

#pragma endregion

#pragma region --- FUNCTION ---

version_t ver_from_str(const char* string) {
    return (version_t){ .major = 0, .minor = 0, .patch = 0, .type = 0, .build = 0, .time = 0 };
}

char* ver_to_str(const version_t version, char* buffer, size_t buffer_size, const char* restrict format) {
    static const char* const __default_format = "%_M.%_m.%_p %_A-%_v %F %T";

    char* ret_buf = NULL;

    if (buffer == NULL)
        return ret_buf;

    if (format == NULL)
        format = __default_format;


    enum parser_state state = STATE_NONE;
    size_t temp_fmt_buf_size = 0;


    // count intermediate format buffer size approximately
    // use worst case for all scenarios
    for (const char* format_ptr = format; *format_ptr != '\0'; format_ptr++) {
        switch (state) {
            case STATE_NONE:
                if (*format_ptr == '%' && format_ptr[1] != '\0') {
                    state = STATE_FMT_SIGN;
                    continue;
                }
                temp_fmt_buf_size++;
                state = STATE_NONE;
                break;
            case STATE_FMT_SIGN:
                if (*format_ptr == '_' && format_ptr[1] != '\0') {
                    state = STATE_FMT;
                    continue;
                }
                temp_fmt_buf_size += 2;
                state = STATE_NONE;
                break;
            case STATE_FMT:
                switch (*format_ptr) {
                    case 'M':
                    case 'm':
                    case 'p':
                        temp_fmt_buf_size += 3;
                        break;
                    case 't':
                        temp_fmt_buf_size += 7;
                        break;
                    case 'a':
                        temp_fmt_buf_size += 23;
                        break;
                    case 'T':
                        temp_fmt_buf_size += 31; // build type + ' ' + build attributes
                        break;
                    case 'v':
                        temp_fmt_buf_size += 8;
                        break;
                    default:
                        temp_fmt_buf_size += 3; // "%_" + current '*format_ptr' symbol
                }
                state = STATE_NONE;
        };
    }
    temp_fmt_buf_size++;
    state = STATE_NONE;

    char* temp_fmt_buf = malloc(temp_fmt_buf_size);
    if (temp_fmt_buf == NULL)
        return ret_buf;

    char* temp_fmt_buf_ptr = temp_fmt_buf;
    for (const char *format_ptr = format; *format_ptr != '\0'; format_ptr++) {
        switch (state) {
            case STATE_NONE:
                if (*format_ptr == '%' && format_ptr[1] != '\0') {
                    state = STATE_FMT_SIGN;
                    continue;
                }
                *(temp_fmt_buf_ptr++) = *format_ptr;
                state = STATE_NONE;
                break;

            case STATE_FMT_SIGN:
                if (*format_ptr == '_' && format_ptr[1] != '\0') {
                    state = STATE_FMT;
                    continue;
                }
                *(temp_fmt_buf_ptr++) = '%';
                *(temp_fmt_buf_ptr++) = *format_ptr;
                state = STATE_NONE;
                break;

            case STATE_FMT:
                switch (*format_ptr) {
                    case 'M':
                        temp_fmt_buf_ptr += sprintf(temp_fmt_buf_ptr, "%hhu", version.major);
                        break;
                    case 'm':
                        temp_fmt_buf_ptr += sprintf(temp_fmt_buf_ptr, "%hhu", version.minor);
                        break;
                    case 'p':
                        temp_fmt_buf_ptr += sprintf(temp_fmt_buf_ptr, "%hhu", version.patch);
                        break;
                    case 't':
                        temp_fmt_buf_ptr += format_build_type(version.type, temp_fmt_buf_ptr);
                        break;
                    case 'a':
                        temp_fmt_buf_ptr += format_attribute(version.type, temp_fmt_buf_ptr);
                        break;
                    case 'T':
                        temp_fmt_buf_ptr += format_build_type(version.type, temp_fmt_buf_ptr);
                        *(temp_fmt_buf_ptr++) = ' ';
                        temp_fmt_buf_ptr += format_attribute(version.type, temp_fmt_buf_ptr);
                        break;
                    case 'v':
                        temp_fmt_buf_ptr += sprintf(temp_fmt_buf_ptr, "%08X", version.build);
                        break;
                    default:
                        temp_fmt_buf_ptr += sprintf(temp_fmt_buf_ptr, "%%_%c", *format_ptr);
                }
                state = STATE_NONE;
        };
    }
    *temp_fmt_buf_ptr = '\0';

    if(strftime(buffer, buffer_size, temp_fmt_buf, localtime(&(version.time))))
        ret_buf = buffer;

    free(temp_fmt_buf);
    return ret_buf;
}

#pragma endregion
