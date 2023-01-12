#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_parameters {
  unsigned int height;
  unsigned int weight;
  char* name;
} t_params;

typedef struct s_env {
  t_params parameters;
  unsigned char err_code;
} t_env;

typedef struct s_complex {
  float real;
  float immaginary;
} t_complex;

int check(t_params params);
int fractal(t_env* env);
int init(t_env* env);

#endif