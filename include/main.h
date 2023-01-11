#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_parameters{
	unsigned int height;
	unsigned int weight;
	char *name;
} t_params;

int fractal(t_params params);

#endif