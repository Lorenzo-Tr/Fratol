#include "main.h"
int window(t_env* env) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    return (ERROR_SDL_INIT_VIDEO);

  if (SDL_GetCurrentDisplayMode(0, &env->display) != 0)
    return (ERROR_SDL_DISPLAY_MODE);

  env->pWindow = SDL_CreateWindow(
      "Fratol", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      env->parameters.width, env->parameters.height, SDL_WINDOW_HIDDEN);

  if (!env->pWindow)
    return (ERROR_SDL_INIT_WINDOW);

  SDL_Surface* screenSurface;
  screenSurface = SDL_GetWindowSurface(env->pWindow);
  SDL_FillRect(screenSurface, NULL,
               SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

  return (0);
}
