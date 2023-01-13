#include "main.h"

int render(t_env* env) {
  bool render_flags;

  render_flags = true;
  while (render_flags) {
    SDL_ShowWindow(env->pWindow);
    update_event(env, render_flags);
    SDL_UpdateWindowSurface(env->pWindow);
  }

  SDL_DestroyWindow(env->pWindow);
  SDL_Quit();

  return (0);
}