/*******************************************************************************
 *  @file      log.c
 *  @brief     Utility for collect logs of project
 *  @author    Young Sideways
 *  @date      13.06.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/


#define LOG_MODULE_NAME "log"
#include "../inc/util/log.h"


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>


#pragma region --- DEFAULT ---

#define DEFAULT_LOG_PATH      ""
#define DEFAULT_LOG_FILE_NAME  "log"
#define DEFAULT_LOG_EXTENSION "log"

#pragma endregion

#pragma region --- LIMIT ---

#define MAX_LOG_SIZE_PATH        (0x3FF)
#define MAX_LOG_SIZE_FILE_NAME   (0x3F)
#define MAX_LOG_SIZE_MODULE_NAME MAX_LOG_SIZE_FILE_NAME
#define MAX_LOG_SIZE_EXTENSION   (0xF)
#define MAX_LOG_SIZE_FULL_PATH   (MAX_LOG_SIZE_PATH + MAX_LOG_SIZE_FILE_NAME + MAX_LOG_SIZE_EXTENSION)
#define MAX_LOG_SIZE_FILE        (INT32_MAX)

#define MAX_LOG_MODULES          (0x3F)

#pragma endregion

#pragma region --- TYPEDEF ---

// NOTE: Deprecated?
typedef enum log_err_e {
    LOG_ERR_NO,
    LOG_ERR_FILE,
    LOG_ERR_FILENAME,
    LOG_ERR_PATH,
    LOG_ERR_LOOKUP,
    LOG_ERR_MODULE
} log_err_t;

typedef struct module_s {
    FILE*    file                              ;
    int64_t  written                           ;
    uint32_t namehash                          ;
    char     name[MAX_LOG_SIZE_MODULE_NAME + 1];
} log_module_t;

typedef struct log_system_settings_s {
    log_module_t  modules[MAX_LOG_MODULES]   ;
    log_module_t  mainfile                   ;
    log_handler_t handler                    ;
    char          path[MAX_LOG_SIZE_PATH + 1];
    bool          initialized                ;
} log_system_settings_t;

#pragma endregion

#pragma region --- STATIC ---

static log_system_settings_t system_settings = { 0 };

#pragma endregion

#pragma region --- PRIVATE ---

static uint32_t module_name_hash(const char* name) {
    uint32_t hash = 5381;
    while (*name)
        hash = ((hash << 5) + hash) ^ *(name++);
    return hash;
}

static int64_t log_file_size(const char *filename) {
    int64_t size = 0L;

    FILE *file = fopen(filename, "rb");

    if (!file) {
        perror("[ log ] fopen() failed");
        goto ERR_FILE;
    }
    if (fseek(file, 0L, SEEK_END)) {
        perror("[ log ] fseek() failed");
        goto ERR_FOP;
    }
    if ((size =
#if defined(_MSC_VER)
                 (int64_t)_ftelli64(file)
#else
                 (int64_t)ftell(file)
#endif
    ) == -1L)
        perror("[ log ] ftell() failed");

ERR_FOP:
    fclose(file);
ERR_FILE:
    return size;
}

static int module_open(log_module_t* module, const char* name) {
    if (!module || !name)
        return 1;
    if (module->file)
        return 2;
    size_t name_size;
    if ((name_size = strlen(name)) == 0 || name_size > MAX_LOG_SIZE_MODULE_NAME)
        return 3;

    char filename[MAX_LOG_SIZE_FULL_PATH] = { 0 };

    snprintf(filename, MAX_LOG_SIZE_FULL_PATH, "%s%s.%s", system_settings.path, name, DEFAULT_LOG_EXTENSION);

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
    uint32_t index = hash % MAX_LOG_MODULES;
    for (int overlap = MAX_LOG_MODULES; overlap; overlap--, index++) {
        if (index >= MAX_LOG_MODULES)
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
    return NULL;
}

static void default_log_handler(int type, log_exec_ctx_t ctx, const char* format, va_list ap) {
    char filename[MAX_LOG_SIZE_FULL_PATH] = { 0 };
    snprintf(filename, MAX_LOG_SIZE_FULL_PATH, "%s%s.%s", system_settings.path, ctx->separate ? ctx->module : DEFAULT_LOG_FILE_NAME, DEFAULT_LOG_EXTENSION);
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

#pragma endregion

#pragma region --- PUBLIC ---

void log_system_handler__(int type, log_exec_ctx_t ctx, const char* format, ...) {
    if (!system_settings.initialized) {
        fprintf(stderr, "[ log ] error: system does not initialized yet.");
        return;
    }

    va_list ap;
    va_start(ap, format);
    system_settings.handler(type, ctx, format, ap);
    va_end(ap);
}

#pragma  endregion

#pragma region --- FUNCION ---

int log_system_init(const char* log_path, const char* log_filename, const char* extension, log_handler_t handler) {
    if (system_settings.initialized) {
        warn("log system already started!");
        return 1;
    }

    // skip all checks, if custom handler given
    if (handler) {
        system_settings.handler = handler;
        system_settings.initialized = true;
        return 0;
    }

    // Validating path
    if (!log_path)
        log_path = DEFAULT_LOG_PATH;       // set local path in executable dir
    size_t path_size = strlen(log_path);
    if (path_size > MAX_LOG_SIZE_PATH) {
        fprintf(stderr, "[ log ] error: path size > %d\n", MAX_LOG_SIZE_PATH);
        return 2;
    }
    memcpy(system_settings.path, log_path, path_size + 1);

    // Validating filename
    if (!log_filename || (strlen(log_filename) == 0))
        log_filename = DEFAULT_LOG_FILE_NAME;
    size_t name_size = strlen(log_filename);
    if (name_size > MAX_LOG_SIZE_FILE_NAME) {
        fprintf(stderr, "[ log ] error: name size > %d\n", MAX_LOG_SIZE_FILE_NAME);
        return 2;
    }

    //if (module_open(&(system_settings.main_file), log_file_name)) {
    //    system_settings.handler = &default_log_handler;
    //    system_settings.initialized = true;
    //    return 0;
    //}
    return 0;
    fprintf(stderr, "[ log ] error: log system can't be initialized\n");
    return 5;
}

int log_system_term() {
    return 1;
}

int log_system_set_handler(log_handler_t handler) {
    if (!system_settings.initialized) {
        fprintf(stderr, "[ log ] error: log system must be initialized\n");
        return 1;
    }
    system_settings.handler = (handler ? handler : default_log_handler);
    return 0;
}

#pragma endregion
