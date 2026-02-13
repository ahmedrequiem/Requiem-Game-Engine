#pragma once

#include "defines.h"

#include <GLFW/glfw3.h>

typedef struct RQwindow {
  GLFWwindow* window;
  u32 width;
  u32 height;
  i32 x;
  i32 y;
  const char* title;
} RQwindow;

RQ_API bool8 RQwindowCreate(u32 width, u32 height, i32 x, i32 y, const char* title);
RQ_API void RQwindowDestroy(RQwindow* w);