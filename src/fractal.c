#include "main.h"

#define HEIGTH_MAX 1000
#define WEIGHT_MAX 1000
#define LIST_OF_NAME {"Mandelbrot", "Julia"}

static bool check_heigth(unsigned int height){
	return(height <= HEIGTH_MAX);
}

static bool check_weigth(unsigned int weight){
	return(weight <= WEIGHT_MAX);
}

int fractal(t_params params){
	//printf("%d, %d, et %s", params.weight, params.height, params.name);
	if(!check_weigth(params.weight)){
		printf("Error with weight\n");
		return(1);
	}
	if(!check_heigth(params.height)){
		printf("Error with height\n");
		return(1);
	}
	printf("Youhou, it's working\n");
	return(0);
}