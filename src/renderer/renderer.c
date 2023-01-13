#include "main.h"

void setBlack(t_env* env, int x, int y){
	int* pixels = (int*) env->screenSurface->pixels;
	pixels[y* env->parameters.width+x] = SDL_MapRGB(env->screenSurface->format, 0, 0, 0);
}

void setWhite(t_env* env, int x, int y){
	int* pixels = (int*) env->screenSurface->pixels;
	pixels[y* env->parameters.width+x] = SDL_MapRGB(env->screenSurface->format, 255, 255, 255);
}