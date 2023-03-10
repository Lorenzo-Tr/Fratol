#include "main.h"

int render(t_env* env) {
  while (!env->input.key[KEY_ESCAPE] && !env->input.quit) {
    SDL_ShowWindow(env->pWindow);
    update_event(env);
    SDL_UpdateWindowSurface(env->pWindow);
    mandelbrot(env);
  }

  SDL_DestroyWindow(env->pWindow);
  SDL_Quit();

  return (0);
}