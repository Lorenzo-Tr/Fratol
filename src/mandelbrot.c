#include"main.h"

void mandelbrot(t_env* env)
{
	int nb_iteration = 50;
	int iteration;
	float z_r;
	t_complex c;
	t_complex z;

	/*float zoom_width = (float)image_width/(x2-x1);
	float zoom_height = (float)image_height/(y2-y1);*/

	for(unsigned int i=0; i<env->parameters.height; i++)
	{
		for(unsigned int j=0; j<env->parameters.width;j++)
		{

			c.real = (float)j/env->coordinates.zoom_w + env->coordinates.x_min;
			c.imaginary = (float)i/env->coordinate.zoom_h + env->coordinates.y_min;
			z.real = 0;
			z.imaginary = 0;
			iteration = 0;

			while((POW(z.real)+POW(z.imaginary))<4 && (iteration < nb_iteration))
			{
				z_r = z.real;
				z.real = POW(z.real)-POW(z.imaginary) + c.real;
				z.imaginary = 2*z.imaginary*z_r + c.imaginary;
				iteration++;
			}

			if(iteration==nb_iteration)
			{
				//dessiner le pixel de coordonnees (i,j)
				printf("x");
				//printf("pixel noir sur %d %d \n",i,j);
			}
			else
			{
				printf(".");
				//printf("pixel blanc sur %d %d \n",i,j);
			}
		}
		printf("\n");
	}
}
