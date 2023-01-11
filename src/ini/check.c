#include "main.h"

#define HEIGTH_MAX 1000
#define WEIGHT_MAX 1000

static bool check_heigth(unsigned int height){
	return(height <= HEIGTH_MAX);
}

static bool check_weigth(unsigned int weight){
	return(weight <= WEIGHT_MAX);
}

static bool check_name(char* name){
	unsigned int len;
	const char* list[] = {"Mandelbrot" , "Julia"};
	len = sizeof(list)/sizeof(list[0]);
	for(unsigned int i = 0; i < len; i++){
		if(!strcmp(list[i], name)){
			return(true);
		}
	}
	return(false);
}

int check(t_params *params){
	//printf("%d, %d, et %s", params.weight, params.height, params.name);
	if(!check_weigth(params.weight)){
		printf("Error with weight\n");
		return(1);
	}
	if(!check_heigth(params.height)){
		printf("Error with height\n");
		return(1);
	}
	if(!check_name(params.name)){
		printf("Error with name\n");
		return(1);
	}
	printf("Youhou, it's working\n");
	return(0);
}