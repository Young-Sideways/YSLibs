/*******************************************************************************
 *  @file      log.h
 *  @brief     Utility for collect logs of project
 *  @author    Young Sideways
 *  @date      13.06.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef LOG_H_
#define LOG_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdarg.h>
#include <stdbool.h>

#pragma endregion

#pragma region --- MACRO ---

#define LOG_NONE     (0x0 )
#define LOG_WARNING  (0x1 )
#define LOG_CRITICAL (0x2 )
#define LOG_ERROR    (0x4 )
#define LOG_DEBUG    (0x8 )
#define LOG_INFO     (0x10)
#define LOG_ALL      (LOG_WARNING | LOG_CRITICAL | LOG_ERROR | LOG_DEBUG | LOG_INFO)

#define warn(...)                                   \
    log_system_handler__(                           \
        (LOG_MODULE_POLICY & LOG_WARNING),          \
        (log_exec_ctx_t){                           \
            (struct log_exec_ctx_s){                \
                .module    = LOG_MODULE_NAME,       \
                .submodule = LOG_SUBMODULE_NAME,    \
                .file      = __FILE__,              \
                .func      = __func__,              \
                .line      = __LINE__,              \
                .timestamp = LOG_MODULE_TIMESTAMP,  \
                .separate  = LOG_MODULE_SEPARATE    \
            }                                       \
        },                                          \
        ##__VA_ARGS__                               \
    )
#define info(...)                                   \
    log_system_handler__(                           \
        (LOG_MODULE_POLICY & LOG_INFO),             \
        (log_exec_ctx_t){                           \
            (struct log_exec_ctx_s){                \
                .module    = LOG_MODULE_NAME,       \
                .submodule = LOG_SUBMODULE_NAME,    \
                .file      = __FILE__,              \
                .func      = __func__,              \
                .line      = __LINE__,              \
                .timestamp = LOG_MODULE_TIMESTAMP,  \
                .separate  = LOG_MODULE_SEPARATE    \
            }                                       \
        },                                          \
        ##__VA_ARGS__                               \
    )
#define error(...)                                  \
    log_system_handler__(                           \
        (LOG_MODULE_POLICY & LOG_ERROR),            \
        (log_exec_ctx_t){                           \
            (struct log_exec_ctx_s){                \
                .module    = LOG_MODULE_NAME,       \
                .submodule = LOG_SUBMODULE_NAME,    \
                .file      = __FILE__,              \
                .func      = __func__,              \
                .line      = __LINE__,              \
                .timestamp = LOG_MODULE_TIMESTAMP,  \
                .separate  = LOG_MODULE_SEPARATE    \
            }                                       \
        },                                          \
        ##__VA_ARGS__                               \
    )
#define critical(...)                               \
    log_system_handler__(                           \
        (LOG_MODULE_POLICY & LOG_CRITICAL),         \
        (log_exec_ctx_t){                           \
            (struct log_exec_ctx_s){                \
                .module    = LOG_MODULE_NAME,       \
                .submodule = LOG_SUBMODULE_NAME,    \
                .file      = __FILE__,              \
                .func      = __func__,              \
                .line      = __LINE__,              \
                .timestamp = LOG_MODULE_TIMESTAMP,  \
                .separate  = LOG_MODULE_SEPARATE    \
            }                                       \
        },                                          \
        ##__VA_ARGS__                               \
    )
#define debug(...)                                  \
    log_system_handler__(                           \
        (LOG_MODULE_POLICY & LOG_DEBUG),            \
        (log_exec_ctx_t){                           \
            (struct log_exec_ctx_s){                \
                .module    = LOG_MODULE_NAME,       \
                .submodule = LOG_SUBMODULE_NAME,    \
                .file      = __FILE__,              \
                .func      = __func__,              \
                .line      = __LINE__,              \
                .timestamp = LOG_MODULE_TIMESTAMP,  \
                .separate  = LOG_MODULE_SEPARATE    \
            }                                       \
        },                                          \
        ##__VA_ARGS__                               \
    )

#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct log_exec_ctx_s {
    const char* module;
    const char* submodule;
    const char* file;
    const char* func;
    int line;
    bool timestamp;
    bool separate;
} log_exec_ctx_t[1];

typedef void (*log_handler_t)(int type, log_exec_ctx_t ctx, const char* format, va_list ap);

#pragma endregion

#pragma region --- MODULE ---

#ifndef LOG_MODULE_NAME
    #define LOG_MODULE_NAME         NULL
#endif // !LOG_MODULE_NAME

#ifndef LOG_SUBMODULE_NAME
    #define LOG_SUBMODULE_NAME      NULL
#endif // !LOG_SUBMODULE_NAME

#ifndef LOG_MODULE_POLICY
    #define LOG_MODULE_POLICY       (LOG_ALL)
#endif // !LOG_MODULE_POLICY

#ifndef LOG_MODULE_TIMESTAMP
    #define LOG_MODULE_TIMESTAMP    (true)
#endif // !LOG_MODULE_TIMESTAMP

#ifndef LOG_MODULE_SEPARATE
    #define LOG_MODULE_SEPARATE     (false)
#endif // !LOG_MODULE_SEPARATE

#pragma endregion

#pragma region --- FUNCION ---

extern void log_system_handler__(int type, log_exec_ctx_t ctx, const char* format, ...);

/**
 * @brief   initialize log system
 * @details registration main log file, validate settings
 * 
 * @param log_path      - path to the log directory (if 'NULL' then sets local executable directory)
 * @param log_filename  - default log filename (if 'NULL' then sets DEFAULT_LOG_FILENAME)
 * @param log_extension - default extension for log files (if 'NULL' then sets DEFAULT_LOG_EXTENSION)
 * @param handler       - custom message handler (if 'NULL' then sets default_log_handler)
 * @retval 0 - success
 * @retval 1 - log system already initialized
 * @retval 2 - log_path passed with value 'NULL', or empty string
 * @retval 3 - log_path-passed with string size > MAX_LOG_PATH_SIZE
 * @retval 4 - log_filename + extension string size greater than MAX_LOG_FILENAME_SIZE
 * @retval 5 - failed to open main log file
 */
int log_system_init(const char* log_path, const char* log_filename, const char* log_extension, log_handler_t handler);

int log_system_term();

int log_system_set_handler(log_handler_t handler);

#pragma endregion

#endif // !LOG_H_
