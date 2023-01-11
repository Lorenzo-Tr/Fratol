#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_parameters{
	unsigned int height;
	unsigned int weight;
	char *name;
} t_params;


int fractal(t_params params);