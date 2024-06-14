/*******************************************************************************
 *  @file      log.c
 *  @brief     Utility for collect logs of project
 *  @author    Young Sideways
 *  @date      13.06.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#pragma region --- PREDEFINITION ---

#define LOG_MODULE_NAME "log"

#pragma endregion

#include "util/log.h"

#pragma region --- INCLUDES ---

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "util/console.h"

#pragma endregion

#pragma region --- DEFAULT ---

#define DEFAULT_LOG_FILENAME "log"
#define DEFAULT_LOG_FILE_EXTENSION ".log"
#define MAX_LOG_FILENAME_SIZE (128)
#define MAX_LOG_PATH_SIZE (2048)

#pragma endregion

#pragma region --- STATIC ---

static bool log_system_initialized = false;

static char log_system_filename[MAX_LOG_FILENAME_SIZE] = { 0 };
static char log_system_path[MAX_LOG_PATH_SIZE] = { 0 };

static log_handler_t log_system_handler = NULL;

#pragma endregion

#pragma region --- FUNCIONS ---

void log_system_handler__(int type, log_exec_ctx_t ctx, const char* format, ...) {
    if (!log_system_initialized)
        return;
    va_list ap;
    va_start(ap, format);
    log_system_handler(type, ctx, format, ap);
    va_end(ap);
}

void default_log_handler(int type, log_exec_ctx_t ctx, const char* format, va_list ap) {
    if (!log_system_initialized)
        return;

    char filename[MAX_LOG_PATH_SIZE] = { 0 };
    snprintf(filename, MAX_LOG_PATH_SIZE, "%s%s%s", log_system_path, ctx->separate ? ctx->module : DEFAULT_LOG_FILENAME, DEFAULT_LOG_FILE_EXTENSION);
    FILE* logfile = fopen(filename, "a");
    if (logfile) {
        //const char* pre_format = "[ ${timestamp} ] '${module}' : [ ${type} ]";

        char date_buf[128] = { 0 };
        if (ctx->timestamp) {
            struct timespec ts;
            timespec_get(&ts, TIME_UTC);
            char time_buf[128] = {0};
            strftime(time_buf, sizeof(time_buf), "%d.%m.%Y %T", gmtime(&ts.tv_sec));
            snprintf(date_buf, sizeof(date_buf), "[ %s.%3ld ] ", time_buf, ts.tv_nsec);
        }
        char module_buf[128] = { 0 };
        if (!ctx->separate) {
            snprintf(module_buf, sizeof(module_buf), "'%s' ", ctx->module);
        }
        char* type_buf = NULL;
        switch (type) {
            case LOG_WARNING :
                fprintf(logfile, "%s%s%s[ WARNING ] ", date_buf, module_buf, (ctx->timestamp || !ctx->separate) ? ": " : "");
                break;
            case LOG_CRITICAL:
                fprintf(logfile, "%s%s%s[ CRITICAL ] ", date_buf, module_buf, (ctx->timestamp || !ctx->separate) ? ": " : "");
                break;
            case LOG_ERROR:
                fprintf(logfile, "%s%s%s[ ERROR ] ('%s':%d @%s) ", date_buf, module_buf, (ctx->timestamp || !ctx->separate) ? ": " : "", ctx->file, ctx->line, ctx->func);
                break;
            case LOG_DEBUG:
                fprintf(logfile, "%s%s%s[ DEBUG ] ('%s':%d @%s) ", date_buf, module_buf, (ctx->timestamp || !ctx->separate) ? ": " : "", ctx->file, ctx->line, ctx->func);
                break;
            case LOG_INFO:
                fprintf(logfile, "%s%s%s", date_buf, module_buf, (ctx->timestamp || !ctx->separate) ? ": " : "");
                break;
            default: {
                warn("undefined log type: %d ( file: '%s', line: %s)", type, ctx->file, ctx->line);
                return;
            }
        }
        vfprintf(logfile, format, ap);
        fputc('\n', logfile);
        fclose(logfile);
    }
    else
        fprintf(stderr, "[ log ] error: unable to open log file");
}

void log_system_init(const char* log_path, const char* log_filename) {
    if (log_system_initialized) {
        warn("log system already started!");
        return;
    }

    // Validating path
    size_t path_size = 0U;
    if (!log_path || ((path_size = strlen(log_path)) == 0U)) {
        fprintf(stderr, "[ log ] error: path must be initialized\n");
        return;
    }
    if (path_size >= MAX_LOG_PATH_SIZE) {
        fprintf(stderr, "[ log ] error: path size > %d\n", MAX_LOG_PATH_SIZE);
        return;
    }
    memcpy(log_system_path, log_path, path_size + 1);

    // Validating filename
    size_t name_size = 0U;
    if (!log_filename || ((name_size = strlen(log_filename)) == 0U)) {
        log_filename = DEFAULT_LOG_FILENAME;
        name_size = sizeof(DEFAULT_LOG_FILENAME) - 1;
    }
    if (name_size + sizeof(DEFAULT_LOG_FILE_EXTENSION) > MAX_LOG_FILENAME_SIZE) {
        fprintf(stderr, "[ log ] error: path size > %d\n", MAX_LOG_FILENAME_SIZE);
        return;
    }
    memcpy(log_system_filename, log_filename, name_size + 1);
    for (char *ch = log_system_filename; *ch; ch++)
        *ch = tolower(*ch);
    strcat(log_system_filename, DEFAULT_LOG_FILE_EXTENSION);

    char full_path[2048] = { 0 };
    strcat(full_path, log_system_path);
    strcat(full_path, log_filename);
    strcat(full_path, DEFAULT_LOG_FILE_EXTENSION);

    FILE* tmp = fopen(full_path, "a");
    if (tmp) {
        fprintf(tmp, "initializing log system.\n");
        log_system_handler = default_log_handler;
        log_system_initialized = true;
        fclose(tmp);
    }
    else
        fprintf(stderr, "[ log ] error: log system can't be initialized\n");

}

void log_set_handler(log_handler_t handler) {
    if (!log_system_initialized) {
        fprintf(stderr, "[ log ] error: log system must be initialized\n");
        return;
    }
    if (handler)
        log_system_handler = handler;
    else
        log_system_handler = default_log_handler;
}

#pragma endregion
