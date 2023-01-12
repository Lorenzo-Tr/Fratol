#include "main.h"

void error_handler(t_env* env) {  // Usage message
  const char* msg;

  msg = &errors[env->err_code].msg[0];  // Get the current error message

  // Display it
  if (write(2, "Fratol : ", 10) == 0 || write(2, msg, strlen(msg)) == 0 ||
      write(2, "\n", 1) == 0)
    return;
}