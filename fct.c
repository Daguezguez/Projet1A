#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fct.h"
SDL_Surface *ecran, *imageDeFond, *bechir;
SDL_Rect positionFond;

void init_perso(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("background.bmp");
	bechir = SDL_LoadBMP("bich1.jpg");
	

	positionFond.x = 0;
	positionFond.y = 0;

	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
}

void anime(void)
{
	SDL_Rect positionFond, positionBechir, oldpositionBechir;
	SDL_Rect positionFond_c, positionBechir_c;
	SDL_Rect clipe;
	int avanceX = 1, avanceY = 1;

	positionFond.x = 0;
	positionFond.y = 0;

	positionBechir.x = 0;
	positionBechir.y = 0;

	oldpositionBechir.x = 0;
	oldpositionBechir.y = 0;


	while (1) {
		
		clipe.x = oldpositionBechir.x;
		clipe.y = oldpositionBechir.y;
		clipe.h = bechir->h;
		clipe.w = bechir->w;
		SDL_SetClipRect(ecran,&clipe);

		positionFond_c.x = positionFond.x;
		positionFond_c.y = positionFond.y;

		positionBechir_c.x = positionBechir.x;
		positionBechir_c.y = positionBechir.y;


		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond_c);

                SDL_SetClipRect(ecran,NULL); // J'ai choisi cette solution
		SDL_BlitSurface(bechir, NULL, ecran, &positionBechir_c);

		oldpositionBechir.x = positionBechir.x;
		oldpositionBechir.y = positionBechir.y;
			
		if (avanceX) {
			positionBechir.x++;
		} else {
			positionBechir.x--;
		}

		if (avanceY) {
			positionBechir.y++;
		} else {
			positionBechir.y--;
		}

		if (positionBechir.x == ecran->w - bechir->w - 1)
			avanceX = 0;
		else if (positionBechir.x == 0)
			avanceX = 1;

		if (positionBechir.y == ecran->h - bechir->h - 1)
			avanceY = 0;
		else if (positionBechir.y == 0)
			avanceY = 1;

		SDL_Flip(ecran);
		input_handle();
		//SDL_Delay(10);
	}
}


void bool_collision (int curs_x,int curseur_y,AABB box)
{
if (curs_x >= box.x 
    && curse_x < box.x + box.w
    && curseur_y >= box.y 
    && curseur_y < box.y + box.h)
       return true;
   else
       return false;

}
}


void affichage perso()
{
 SDL_BlitSurface(ecran, 0, ecran, &positionFond);
        SDL_BlitSurface(bechir, 0, ecran, &positionBechir);

}


