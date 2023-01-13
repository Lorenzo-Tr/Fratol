#include "main.h"

void update_event(t_env* env, bool render_flags) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        render_flags = false;
        break;
    }
  }
}