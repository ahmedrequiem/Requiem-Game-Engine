#pragma once

#include "defines.h"

#define RQ_ASSERTIONS_ENABLED 1

#if RQ_ASSERTIONS_ENABLED == 1
  #if _MSC_VER
    #include <intrin.h>
    #define debugBreak() __debugbreak()
  #else
    #define debugBreak() __builtin_trap()
  #endif

  RQ_API void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

  #define RQASSERT(expr)                                                         \
    {                                                                             \
      if (expr) {                                                                 \
      } else {                                                                    \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);                  \
        debugBreak();                                                             \
      }                                                                           \
    }

  #define RQASSERT_MSG(expr, msg)                                                \
    {                                                                             \
      if (expr) {                                                                 \
      } else {                                                                    \
        report_assertion_failure(#expr, msg, __FILE__, __LINE__);                 \
        debugBreak();                                                             \
      }                                                                           \
    }

  #ifdef RQ_BUILD_DEBUG
    #define RQASSERT_DEBUG(expr)                                                   \
      {                                                                             \
        if (expr) {                                                                 \
        } else {                                                                    \
          report_assertion_failure(#expr, "", __FILE__, __LINE__);                  \
          debugBreak();                                                             \
        }                                                                           \
      }
  #else
    #define RQ_ASSERT_DEBUG(expr)
  #endif

#else
  #define RQ_ASSERT(expr)
  #define RQ_ASSERT_MSG(expr, msg)
  #define RQ_ASSERT_DEBUG(expr, msg)
#endif