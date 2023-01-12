#include "main.h"

void error_handler(t_env* env) {  // Usage message
  const char* usage;
  const char* msg;

  if (env->err_code >=
      ERROR_MAX)  // If the code does not correspond to any existing code
    return;

  msg = &errors[env->err_code].msg[0];  // Get the current error message
  usage =
      "  Usage : ./fratol heigth width name\n\
      heigth : numbers between 0 and your screen heigth resolution\n\
      width : numbers between 0 and your screen width resolution\n\
      name : Julia | Mandelbort\n";

  // Display it
  if (write(2, "Fratol : \n", 11) == 0 || write(2, "  Error : ", 11) == 0 ||
      write(2, msg, strlen(msg)) == 0 || write(2, "\n", 1) == 0)
    return;
  // Display usage if needed
  if (errors[env->err_code].usage && write(2, usage, strlen(usage)))
    return;

  if (errors[env->err_code].sdl_error &&
      write(2, SDL_GetError(), strlen(SDL_GetError())))
    return;
}