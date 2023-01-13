#ifndef ERROR_H
#define ERROR_H

#include <stdbool.h>

enum e_error_id {
  ERROR_NONE,
  ERROR_INVALID_ARGC,
  ERROR_HEIGTH,
  ERROR_WIDTH,
  ERROR_NAME,
  ERROR_SDL_INIT_VIDEO,
  ERROR_SDL_INIT_WINDOW,
  ERROR_SDL_DISPLAY_MODE,
  ERROR_MAX
};

typedef struct s_error {
  char msg[64];  // Error message
  bool usage;
  bool sdl_error;
} t_error;

static const t_error errors[ERROR_MAX] = {
    [ERROR_INVALID_ARGC] = {"Invalid number of arguments.\n", true, false},
    [ERROR_HEIGTH] = {"This heigth is not allowed\n", true, false},
    [ERROR_WIDTH] = {"This width is not allowed\n", true, false},
    [ERROR_NAME] = {"This name is unknown\n", true, false},
    [ERROR_SDL_INIT_VIDEO] = {"Initialization of SDL failed\n", false, true},
    [ERROR_SDL_INIT_WINDOW] = {"Initialization of SDL Window failed\n", false,
                               true},
    [ERROR_SDL_DISPLAY_MODE] = {"SDL Display Mode failed\n", false, true}};

#endif