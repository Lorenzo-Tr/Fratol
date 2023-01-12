#include "main.h"

int render(t_env* env) {
  bool render_flags;

  render_flags = true;
  while (render_flags) {
    SDL_Event event;
    SDL_ShowWindow(env->pWindow);
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          render_flags = false;
          break;
      }
    }
    SDL_UpdateWindowSurface(env->pWindow);
  }

  SDL_DestroyWindow(env->pWindow);
  SDL_Quit();

  return (0);
}