#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


void SDL_GL_GetDrawableSize(SDL_Window * window, int *w,int *h);

int main(int argc, char *argv[])
{
	int w, h ;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
	{
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
	}
  SDL_DisplayMode dm;
        if( SDL_GetCurrentDisplayMode( 0, &dm ) != 0 ) {
            //save log
        }
        printf("%dx%d\n", dm.h, dm.w);
}



