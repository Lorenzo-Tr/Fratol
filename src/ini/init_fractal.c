#include "main.h"

static void init_mandelbrot(t_env* env){
	env->coordinates.x_min = -2.1;
	env->coordinates.x_max = 0.6;
	env->coordinates.y_min = -1.2;
	env->coordinates.y_max = 1.2;
	env->coordinates.temp.real = 0;
	env->coordinates.temp.imaginary = 0;
}

static void init_julia(t_env* env){
	env->coordinates.x_min = -1;
	env->coordinates.x_max = 1;
	env->coordinates.y_min = -1.2;
	env->coordinates.y_max = 1.2;
	env->coordinates.temp.real = 0.285;
	env->coordinates.temp.imaginary = 0.01;
}

static void init_zoom(t_env* env){
	env->coordinates.zoom_w = env->parameters.width/(env->coordinates.x_max-env->coordinates.x_min);	
	env->coordinates.zoom_h = env->parameters.height/(env->coordinates.y_max-env->coordinates.y_min);
}

static void init_colors(t_env *env){
	unsigned char palette[6][3] = {
		{179, 205, 224} ,
		{100, 151, 177} ,
		{0, 91, 150} ,
		{3, 57, 108} ,
		{1, 31, 75}
	};
	env->colors.rgb = &palette;
	env->colors.nb_colors = 6;
}

void init_fractal(t_env* env){
	if(!strcmp(env->parameters.name, "Mandelbrot")){
		init_mandelbrot(env);
	} else if(!strcmp(env->parameters.name, "Julia")){
		init_julia(env);
	} else {
		//Nothing
	}
	init_colors(env);
	init_zoom(env);
}