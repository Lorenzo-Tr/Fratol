#include "main.h"

int init(int argc, char** argv, t_env* env) {
  if (argc != 4) {
    printf("Invalid arguments\n");
    return (1);
  }

  env->parameters.height = (unsigned int)atoi(argv[1]);
  env->parameters.weight = atoi(argv[2]);
  env->parameters.name = argv[3];

  if ((env->err_code = check(&env->parameters)) != ERROR_NONE) {
    return (env->err_code);
  }

  window();

  return (0);
}