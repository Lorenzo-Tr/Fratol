int mandelbrot()
{
	float  x1 = -2.1;
	float x2 = 0.6;
	float  y1 = -1.2;
	float y2 = 1.2;
	int image_width = 270;
	int image_height = 240;
	int nb_iteration = 50;

	float zoom_width = (float)image_width/(x2-x1);
	float zoom_height = (float)image_height/(y2-y1);

	for(int i=0; i<image_width; i++)
	{
		for(int j=0; j<image_height;j++)
		{
			float c_reel = (float)i/zoom_width + x1;
			float c_im = 
		}
	}
}
