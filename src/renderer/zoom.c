#include "main.h"

void zoom(t_env* env, int zoom_direction) {
  float nx, ny;
  float new_rangex, new_rangey;
  float zoom_percentage;

  printf("Sx = %d\n", env->input.mousex);
  printf("Sy = %d\n", env->input.mousey);

  printf("%d\n", zoom_direction);

  zoom_percentage = zoom_direction * 5.0f / 100.0f;
  printf("%f\n", zoom_percentage);

  nx = ((float)env->input.mousex / (float)env->parameters.width) +
       env->coordinates.x_min;
  ny = ((float)env->input.mousey / (float)env->parameters.height) +
       env->coordinates.y_min;

  printf("nx = %f\n", nx);
  printf("ny = %f\n", ny);

  new_rangex =
      (env->coordinates.x_max - env->coordinates.x_min) * zoom_percentage;
  new_rangey =
      (env->coordinates.y_max - env->coordinates.y_min) * zoom_percentage;

  printf("new_rangex = %f\n", new_rangex);
  printf("new_rangey = %f\n", new_rangey);

  env->coordinates.x_max += nx + (new_rangex / 2);
  env->coordinates.x_min -= nx - (new_rangex / 2);
  env->coordinates.y_max += ny + (new_rangey / 2);
  env->coordinates.y_min -= ny - (new_rangey / 2);

  printf("x_max = %f | x_min = %f\ny_max = %f | y_min = %f\n",
         env->coordinates.x_max, env->coordinates.x_min, env->coordinates.y_max,
         env->coordinates.y_min);
}