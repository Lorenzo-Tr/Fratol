#include"main.h"

void generator(t_env* env){
	int iteration;
	float z_r;
	t_complex c;
	t_complex z;

	for(unsigned int i=0; i<env->parameters.height; i++){
		for(unsigned int j=0; j<env->parameters.width;j++){
			if(!strcmp(env->parameters.name, "Mandelbrot")){
				c.real = (float)j/env->coordinates.zoom_w + env->coordinates.x_min;
				c.imaginary = (float)i/env->coordinates.zoom_h + env->coordinates.y_min;
				z.real = 0;
				z.imaginary = 0;
			} else if (!strcmp(env->parameters.name, "Julia")){
				z.real = (float)j/env->coordinates.zoom_w + env->coordinates.x_min;
				z.imaginary = (float)i/env->coordinates.zoom_h + env->coordinates.y_min;
				c.real = env->coordinates.temp.real;
				c.imaginary = env->coordinates.temp.imaginary;
			} else {
				//Nothing
			}
			
			iteration = 0;
			while((POW(z.real)+POW(z.imaginary))<4 && (iteration < ITERATION_MAX)){
				z_r = z.real;
				z.real = POW(z.real)-POW(z.imaginary) + c.real;
				z.imaginary = 2*z.imaginary*z_r + c.imaginary;
				iteration++;
			}

			if(iteration==ITERATION_MAX){
				setBlack(env, j, i);
			}
			else{
				setWhite(env, j, i);
			}
		}
	}
}
