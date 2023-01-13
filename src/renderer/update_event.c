#include "main.h"

void update_event(t_env* env) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        env->input.quit = true;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
          env->input.key[KEY_ESCAPE] = true;
        if (event.key.keysym.sym == SDLK_SPACE)
          env->input.key[KEY_SPACE] = true;
        break;
      case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_ESCAPE)
          env->input.key[KEY_ESCAPE] = false;
        if (event.key.keysym.sym == SDLK_SPACE)
          env->input.key[KEY_SPACE] = false;
        break;
      case SDL_MOUSEWHEEL:
        if(event.wheel.y == 1){
          //zoom +1
        }
        if(event.wheel.y == -1){
          //zoom -1
        }
    }
  }
}