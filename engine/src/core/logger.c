#include "logger.h"

#include <memory.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

static const char* colors[6] = {
  PURPLE,
  RED,
  YELLOW,
  WHITE,
  GREEN,
  BLUE,
};

bool8 logger_init() {
  // TODO: Create a file to output all the logs into
  return TRUE;
}

void log_output(log_level level, const char* message, const char* file_name, const char* function_name, int line_number, ...) {
  const char* level_strings[6] = { "[FATAL]", "[ERROR]", "[WARN]", "[INFO]", "[DEBUG]", "[TRACE]" };
  bool8 is_error = level < 2;

  char out_message[32000];
  memset(out_message, 0, sizeof(out_message));

  __builtin_va_list arg_ptr;
  va_start(arg_ptr, line_number);
  vsnprintf(out_message, sizeof(out_message), message, arg_ptr);
  va_end(arg_ptr);
}

void logger_shutdown() {
  // TODO: Cleanup any resources created in the logger_init
}