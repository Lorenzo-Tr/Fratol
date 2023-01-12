#include "main.h"

#define ITERATION_MAX 150

bool julia_square(t_complex *temp){
	const t_complex constant = {0.3, 0.5};
	temp->real = POW(temp->real) - POW(temp->immaginary) + constant.real;
	temp->immaginary = 2*temp->real*temp->immaginary + constant.immaginary;
	printf("%f, %f", temp->real, temp->immaginary);
	if(POW(temp->real) - POW(temp->immaginary) + constant.real > 4){
		return(false);
	}
	return(true);
}

static void julia_color_pixel(t_complex *position){
	int i;
	bool check;
	t_complex temp;
	temp.real = position->real;
	temp.immaginary = position->immaginary;
	check = julia_square(&temp);
	for(i = 0; i < ITERATION_MAX && check; i++){
		check = julia_square(&temp);
		if(check){
			//printf("Pixel noir\n");
		}
	}
	if(i == ITERATION_MAX){
		//printf("Pixel blanc\n");
	}
}


void julia(t_env *env){
	t_complex pixel = {0, 0};
	for(unsigned int i = 0; i < env->parameters.height; i++){
		for(unsigned int j = 0; j < env->parameters.weight; j++){
			pixel.real = i;
			pixel.immaginary = j;
			julia_color_pixel(&pixel);
		}
	}
}