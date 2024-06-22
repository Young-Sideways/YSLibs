/*******************************************************************************
 *  @file      log.c
 *  @brief     Utility for collect logs of project
 *  @author    Young Sideways
 *  @date      13.06.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#pragma region --- PREDEFINITION ---

#define LOG_MODULE_NAME "log"

#pragma endregion

#include "util/log.h"

#pragma region --- INCLUDE ---

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>

#include "util/console.h"

#pragma endregion

#pragma region --- MACRO ---

#define DEFAULT_LOG_FILENAME "log"
#define DEFAULT_LOG_FILE_EXTENSION ".log"

#pragma endregion

#pragma region --- LIMIT ---

#define MAX_LOG_FILENAME_SIZE      (128)
#define MAX_LOG_PATH_SIZE          (2048)

#define MAX_MODULES                (64)
#define MAX_MODULE_NAME_SIZE       (128)

#pragma endregion

#pragma region --- TYPEDEF ---

typedef enum log_err_e {
    LOG_ERR_NO,
    LOG_ERR_FILE,
    LOG_ERR_FILNAME,
    LOG_ERR_PATH,
    LOG_ERR_LOOKUP,
    LOG_ERR_MODULE
} log_err_t;

typedef struct module_s {
    char name[MAX_MODULE_NAME_SIZE];
    uint32_t namehash;
    FILE* file;
} log_module_t;

typedef struct log_system_settings_s {
    log_module_t modules[MAX_MODULES];
    log_module_t main;
    log_handler_t handler;
    char path[MAX_LOG_PATH_SIZE];
    bool initialized;
} log_system_settings_t;

#pragma endregion

#pragma region --- STATIC ---

static log_system_settings_t system_settings = { 0 };

#pragma endregion

#pragma region --- PRIVATE ---

// All private log function does not check input args, be careful

static uint32_t module_name_hash(const char* name) {
    uint32_t hash = 5381;
    while (*name)
        hash = ((hash << 5) + hash) ^ *(name++);
    return hash;
}

static bool module_open(log_module_t* module, const char* name) {
    if (!module || !name || module->file)
        return false;

    char filename[MAX_LOG_PATH_SIZE] = { 0 };
    strcat(filename, system_settings.path);
    strcat(filename, name);
    strcat(filename, DEFAULT_LOG_FILE_EXTENSION);
    module->file = fopen(filename, "a");
    if (!module->file)
        return false;
    module->namehash = module_name_hash(name);
    strcpy(module->name, name);
    return true;
}
static void module_close(log_module_t* module) {
    if (!module || !module->file)
        return;
    fflush(module->file);
    fclose(module->file);
    module->file = NULL;
}

static log_module_t* module_table_lookup(const char* name) {
    if (!name)
        return NULL;

    uint32_t hash  = module_name_hash(name);
    uint32_t index = hash % MAX_MODULES;
    for (int overlap = MAX_MODULES; overlap; overlap--, index++) {
        if (index >= MAX_MODULES)
            index = 0;
        if (system_settings.modules[index].file == NULL)
            continue;
        if (system_settings.modules[index].namehash == hash)
            if (strcmp(name, system_settings.modules[index].name) == 0)
                return &(system_settings.modules[index]);
    }
    return NULL;
}

static log_module_t* module_table_add(const char* name) {
    char filename[MAX_LOG_PATH_SIZE] = { 0 };

    uint32_t index = module_name_hash(name) % MAX_MODULES;
    for (int overlap = MAX_MODULES; overlap; overlap--, index++) {
        if (index >= MAX_MODULES)
            index = 0;
        if (system_settings.modules[index].file)
            continue;

        module
    }
    goto ERR_LOOKUP;


ERR_FILE:
ERR_LOOKUP:
    return NULL;
}

#pragma endregion

#pragma region --- FUNCIONS ---

void log_system_handler__(int type, log_exec_ctx_t ctx, const char* format, ...) {
    if (!system_settings.initialized) {
        fprintf(stderr, "[ log ] error: system does not initilized yet.");
        return;
    }

    va_list ap;
    va_start(ap, format);
    system_settings.handler(type, ctx, format, ap);
    va_end(ap);
}

void default_log_handler(int type, log_exec_ctx_t ctx, const char* format, va_list ap) {
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
            snprintf(date_buf, sizeof(date_buf), "[ %s.%0.3ld ] ", time_buf, ts.tv_nsec / 1000000);
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

int log_system_init(const char* log_path, const char* log_filename) {
    if (system_settings.initialized) {
        warn("log system already started!");
        return 1;
    }

    // Validating path
    size_t path_size = 0U;
    if (!log_path || ((path_size = strlen(log_path)) == 0U)) {
        fprintf(stderr, "[ log ] error: path must be initialized\n");
        return 2;
    }
    if (path_size >= MAX_LOG_PATH_SIZE) {
        fprintf(stderr, "[ log ] error: path size > %d\n", MAX_LOG_PATH_SIZE);
        return 3;
    }
    memcpy(system_settings.path, log_path, path_size + 1);

    // Validating filename
    size_t name_size = 0U;
    if (!log_filename || ((name_size = strlen(log_filename)) == 0U)) {
        log_filename = DEFAULT_LOG_FILENAME;
        name_size = sizeof(DEFAULT_LOG_FILENAME) - 1;
    }
    if (name_size + sizeof(DEFAULT_LOG_FILE_EXTENSION) > MAX_LOG_FILENAME_SIZE) {
        fprintf(stderr, "[ log ] error: path size > %d\n", MAX_LOG_FILENAME_SIZE);
        return 4;
    }

    if (module_open(&(system_settings.main), log_filename)) {
        system_settings.handler = &default_log_handler;
        system_settings.initialized = true;
        return 0;
    }
    
    fprintf(stderr, "[ log ] error: log system can't be initialized\n");
    return 5;
}

int log_system_term() {

}

int log_set_handler(log_handler_t handler) {
    if (!log_system_initialized) {
        fprintf(stderr, "[ log ] error: log system must be initialized\n");
        return 1;
    }
    log_system_handler = (handler ? handler : default_log_handler);
    return 0;
}

#pragma endregion
