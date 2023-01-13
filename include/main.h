#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <error.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define POW(X) ((X) * (X))
#define ITERATION_MAX 150

typedef struct s_complex {
  float real;
  float imaginary;
} t_complex;

typedef struct s_parameters {
  unsigned int height;
  unsigned int width;
  char* name;
} t_params;

typedef struct s_fractal_coordinates {
  float x_min;
  float x_max;
  float y_min;
  float y_max;
  float zoom_w;
  float zoom_h;
  t_complex temp;
} t_fractal;

enum e_input {
  KEY_MIN,
  KEY_ESCAPE,
  KEY_SPACE,
  KEY_RIGHT,
  KEY_LEFT,
  KEY_UP,
  KEY_DOWN,
  KEY_C,
  KEY_MAX
};

typedef struct s_input {
  bool key[KEY_MAX];
  int mousex, mousey;
  int mousexrel, mouseyrel;
  char mousebuttons[8];
  char quit;
} t_input;

typedef struct s_env {
  t_params parameters;
  unsigned char err_code;
  SDL_Window* pWindow;
  SDL_Surface* screenSurface;
  SDL_DisplayMode display;
  t_fractal coordinates;
  t_input input;
} t_env;

//src/init
int check_parameters(t_env* env);
void init_fractal(t_env* env);
int window(t_env* env);

//src/renderer
void setBlack(t_env* env, int x, int y);
void setWhite(t_env* env, int x, int y);
void update_event(t_env* env);

//src
void error_handler(t_env* env);
int fractal(int argc, char** argv, t_env* env);
int init(int argc, char** argv, t_env* env);
void generator(t_env* env);
int render(t_env* env);

#endif
