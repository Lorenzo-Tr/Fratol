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
void error_handler();
int check(t_params* params);
int fractal(int argc, char** argv, t_env* env);
int init(int argc, char** argv, t_env* env);
int render(t_env* env);
int window();
void julia(t_env *env);

#endif