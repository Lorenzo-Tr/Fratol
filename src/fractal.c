#include "main.h"

#define HEIGTH_MAX = 1000;
#define WEIGHT_MAX = 1000;
#define LIST_OF_NAME = {Mandelbrot, Julia};

bool check_heigth(unsigned int height){
	return(height <= HEIGTH_MAX);
}

bool check_weigth(unsigned int weight){
	return(weight <= WEIGHT_MAX);
}

int fractal(t_params params){
	if(!check_weigth(params->weight)){
		printf("Error with weight");
		return(1);
	}
	if(!check_heigth(params->height)){
		printf("Error with height");
		return(1);
	}
	return(0);
}