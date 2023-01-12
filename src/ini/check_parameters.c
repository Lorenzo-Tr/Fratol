#include "main.h"

static bool check_heigth(unsigned int height, unsigned int max_height) {
  return (height <= max_height);
}

static bool check_width(unsigned int width, unsigned int max_width) {
  return (width <= max_width);
}

static bool check_name(char* name) {
  unsigned int len;
  const char* list[] = {"Mandelbrot", "Julia"};
  len = sizeof(list) / sizeof(list[0]);
  for (unsigned int i = 0; i < len; i++) {
    if (!strcmp(list[i], name)) {
      return (true);
    }
  }
  return (false);
}

int check_parameters(t_env* env) {
  // printf("%d, %d, et %s", params.width, params.height, params.name);
  if (!check_width(env->parameters.width, env->display.w)) {
    return (ERROR_WIDTH);
  }
  if (!check_heigth(env->parameters.height, env->display.h)) {
    return (ERROR_HEIGTH);
  }
  if (!check_name(env->parameters.name)) {
    return (ERROR_NAME);
  }
  return (0);
}