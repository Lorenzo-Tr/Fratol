#include "main.h"

int fractal(int argc, char** argv, t_env* env) {
  if((env->err_code=init(argc, argv, env)) != ERROR_NONE){
    return (env->err_code);
  }

  if((env->err_code=render(env)) != ERROR_NONE){
    return (env->err_code);
  }

  return (0);
}