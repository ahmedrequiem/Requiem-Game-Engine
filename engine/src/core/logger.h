#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

typedef enum {
  LOG_LEVEL_FATAL= 0,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARN,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_TRACE
} log_level;

bool8 logger_init();

RQ_API void log_output(log_level level, const char* message, const char* file_name, const char* function_name, int line_number, ...);

void logger_shutdown();

#define RQFATAL(msg, ...) log_output(LOG_LEVEL_FATAL, msg, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#define RQERROR(msg, ...) log_output(LOG_LEVEL_ERROR, msg, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#if LOG_WARN_ENABLED == 1
  #define RQWARN(msg, ...) log_output(LOG_LEVEL_WARN, msg, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define RQWARN(msg, ...) 
#endif

#if LOG_INFO_ENABLED == 1
  #define RQINFO(msg, ...) log_output(LOG_LEVEL_INFO, msg, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define RQINFO(msg, ...) 
#endif

#if LOG_DEBUG_ENABLED == 1
  #define RQDEBUG(msg, ...) log_output(LOG_LEVEL_DEBUG, msg, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define RQDEBUG(msg, ...)
#endif

#if LOG_TRACE_ENABLED == 1
  #define RQTRACE(msg, ...) log_output(LOG_LEVEL_TRACE, msg, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define RQTRACE(msg, ...)
#endif


#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"