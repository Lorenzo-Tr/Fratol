#include "main.h"

int init(int argc, char** argv, t_env* env) {
  if (argc != 4)
    return (ERROR_INVALID_ARGC);

  env->parameters.height = (unsigned int)atoi(argv[1]);
  env->parameters.width = atoi(argv[2]);
  env->parameters.name = argv[3];

  window(env);

  if ((env->err_code = check_parameters(env)) != ERROR_NONE) {
    return (env->err_code);
  }

  return (0);
}