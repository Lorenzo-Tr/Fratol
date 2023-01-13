#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <error.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define POW(X) ((X) * (X))

typedef struct s_parameters {
  unsigned int height;
  unsigned int width;
  char* name;
} t_params;

typedef struct s_fractal_coordinates {
  float x_min;
  float x_max;
  float y_min;
  float x_max;
  float zoom_w;
  float zoom_h;
} t_fractal;

typedef struct s_env {
  t_params parameters;
  unsigned char err_code;
  SDL_Window* pWindow;
  SDL_DisplayMode display;
  t_fractal coordinates;
} t_env;

typedef struct s_complex {
  float real;
  float immaginary;
} t_complex;

void error_handler(t_env* env);
int check_parameters(t_env* env);
int fractal(int argc, char** argv, t_env* env);
int init(int argc, char** argv, t_env* env);
int render(t_env* env);
int window(t_env* env);
void julia(t_env* env);
void mandelbrot(t_env* env);

#endif
