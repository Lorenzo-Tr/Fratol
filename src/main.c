#include "main.h"

int main(int argc, char** argv) {
  t_env env;

  if (argc != 4) {
    printf("Invalid arguments\n");
    return (1);
  }

  env.parameters.height = (unsigned int)atoi(argv[1]);
  env.parameters.weight = atoi(argv[2]);
  env.parameters.name = argv[3];

  fractal(&env);


  return (0);
}
