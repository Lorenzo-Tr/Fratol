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
	(void) env;

	t_complex pixel = {0, 0};
	float x_start = -1;
	float x_end = 1;
	float y_start = -1.2;
	float y_end = 1.2;
	float zoom = 100;

	float image_x = (x_end - x_start) * zoom;
	float image_y = (y_end - y_start) * zoom;

	for(unsigned int i = 0; i < image_x; i++){
		for(unsigned int j = 0; j < image_y; j++){
			pixel.real = i/zoom + 1;
			pixel.immaginary = j/zoom + 1;
			julia_color_pixel(&pixel);
		}
		printf("\n");
	}
}