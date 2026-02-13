#include "RQwindow.h"

#include "core/logger.h"


bool8 RQwindowCreate(RQwindow* w, u32 width, u32 height, i32 x, i32 y, const char* title) {

  w->width = width;
  w->height = height;
  w->title = title;
  w->x = x;
  w->y = y;

  if (!glfwInit()) {
    RQFATAL("Failed to Initialize GLFW");
    return false;
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  w->window = glfwCreateWindow(width, height, title, NULL, NULL);
  glfwSetWindowPos(w->window, x, y);
  return true;
}
void RQwindowDestroy(RQwindow* w) {
  glfwDestroyWindow(w->window);
  glfwTerminate();
}