#include "logger.h"
#include "assertions.h"

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

  char out_message2[32000];

  sprintf(out_message2, "%s: file(%s) - function(%s) - line(%i)\n\t|-> %s", level_strings[level], file_name, function_name, line_number, out_message);

  // TODO: platform specific code
  printf("%s%s\033[0m\n", colors[level], out_message2);
}

void logger_shutdown() {
  // TODO: Cleanup any resources created in the logger_init
}



void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
  char out_message[32000];
  memset(out_message, 0, sizeof(out_message));

  sprintf(out_message, "[Assertion]: file(%s) - line(%i)\n\t|-> expression(%s) : %s", file, line, expression, message);

  printf("%s%s\033[0m\n", colors[0], out_message);
}