#include "main.h"

int main(int argc, char** argv) {
  t_env env;

  if (fractal(argc, argv, &env) != ERROR_NONE) {
    error_handler(&env);
    return (env.err_code);
  }

  return (0);
}