#include<SDL2/SDL.h>
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int window()
{
	bool en_marche = true ;
	SDL_Event ev ; // on créer une variable evenement
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return (-1);
    }   
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Fenetre",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,500,SDL_WINDOW_SHOWN);

        if( pWindow )
        {
			SDL_Surface* screenSurface = NULL;
			screenSurface = SDL_GetWindowSurface(pWindow);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		
        }
else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    
    while(en_marche)
	{
		while(SDL_PollEvent(&ev) != 0 )
		{

			if(ev.type == SDL_QUIT)
			{
				en_marche = false ;
			}

		SDL_UpdateWindowSurface(pWindow);

		}
	SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return (0);
}
