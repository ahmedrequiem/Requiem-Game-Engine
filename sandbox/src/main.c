#include <stdio.h>
#include <core/logger.h>
#include <core/assertions.h>

int main(void) {
  RQFATAL("test message %f", 6.9f);
  RQERROR("test message %f", 6.9f);
  RQWARN("test message %f", 6.9f);
  RQINFO("test message %f", 6.9f);
  RQDEBUG("test message %f", 6.9f);
  RQTRACE("test message %f", 6.9f);

  RQASSERT_MSG(1 == 2, "One doesn't equal two");

  getchar();
  return 0;
}