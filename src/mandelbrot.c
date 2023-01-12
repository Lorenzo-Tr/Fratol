#include"main.h"

int mandelbrot()
{
	float  x1 = -2.1;
	float x2 = 0.6;
	float  y1 = -1.2;
	float y2 = 1.2;
	unsigned int image_width = 40;
	unsigned int image_height = 40;
	int nb_iteration = 50;

	float zoom_width = (float)image_width/(x2-x1);
	float zoom_height = (float)image_height/(y2-y1);

	for(unsigned int i=0; i<image_width; i++)
	{
		for(unsigned int j=0; j<image_height;j++)
		{
			float c_reel = (float)i/zoom_width + x1;
			float c_im = j/zoom_height + y1;
			float z_reel = 0;
			float z_im = 0;
			int iteration = 0;

			while((z_reel*z_reel+z_im*z_im)<4 && (iteration < nb_iteration))
			{
				float z_r = z_reel;
				z_reel = (z_reel*z_reel)-(z_im*z_im) + c_reel;
				z_im = 2*z_im*z_r + c_im;
				iteration++;
			}

			if(iteration==nb_iteration)
			{
				//dessiner le pixel de coordonnees (i,j)
				printf("pixel noir sur %d %d \n",i,j);
			}
			else
			{
				printf("pixel blanc sur %d %d \n",i,j);
			}
		}
	}
	return 0;
}
