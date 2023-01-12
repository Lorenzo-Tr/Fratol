#include "main.h"

#define ITERATION_MAX 150

//Calculate suite
bool julia_square(t_complex *temp){
	const t_complex constant = {0.3, 0.5};
	temp->real = POW(temp->real) - POW(temp->immaginary) + constant.real;
	temp->immaginary = 2*temp->real*temp->immaginary + constant.immaginary;
	if(POW(temp->real) + POW(temp->immaginary) >= 4){
		return(false);
	}
	return(true);
}

//Pixel
static void julia_color_pixel(t_complex *position){
	int i;
	bool check;
	t_complex temp;
	temp.real = position->real;
	temp.immaginary = position->immaginary;
	i = 0;
	check = true;
	while(i < ITERATION_MAX && check){
		check = julia_square(&temp);
		if(!check){
			//printf("Pixel noir\n");
			printf(".");
		}
		i++;
	}
	//printf("%d\n", i);
	if(i == ITERATION_MAX){
		//printf("Pixel blanc\n");
		printf("x");
	}
}

//Screen
void julia(t_env *env){
	t_complex pixel = {0, 0};
	for(unsigned int i = 0; i < env->parameters.weight; i++){
		for(unsigned int j = 0; j < env->parameters.height; j++){
			pixel.real = i/env->parameters.weight;
			pixel.immaginary = j/env->parameters.height;
			julia_color_pixel(&pixel);
		}
		printf("\n");
	}
}