#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "handle.h"
#include "fct.h"
int affichage_perso(SDL_Surface *screen,Perso *Maro, int ch)
{
	int i=0;
	i=HandleEvent1();
	if (i==1){
		if (ch!=1)
			Maro->position.x+=10;
        SDL_BlitSurface(Maro->image, NULL, screen, &(Maro->position));
	Maro->PS=1;
	}
	else if (i==2){
		if (ch!=2)
			Maro->position.x-=10;
        	SDL_BlitSurface(Maro->imageG, NULL, screen, &(Maro->position));
		Maro->PS=2;
	}
	else if (i==5){
		if (ch!=5)
			Maro->position.y-=10;
		if (Maro->PS==1)
			SDL_BlitSurface(Maro->image, NULL, screen, &(Maro->position));
		else if (Maro->PS==2)
			SDL_BlitSurface(Maro->imageG, NULL, screen, &(Maro->position));
	}
	else if (i==6){
		if (ch!=6)
			Maro->position.y+=10;
		if (Maro->PS==1)
			SDL_BlitSurface(Maro->image, NULL, screen, &(Maro->position));
		else if (Maro->PS==2)
			SDL_BlitSurface(Maro->imageG, NULL, screen, &(Maro->position));
	}
	else if (Maro->PS==1)
		SDL_BlitSurface(Maro->image, NULL, screen, &(Maro->position));
	else if (Maro->PS==2)
		SDL_BlitSurface(Maro->imageG, NULL, screen, &(Maro->position));
return 0;
}
int affichage_perso2(SDL_Surface *screen,Perso *Maro2)
{
	int i=0;
	i=HandleEvent1();
	if (i==3){
	Maro2->position.x+=10;
        SDL_BlitSurface(Maro2->image, NULL, screen, &(Maro2->position));
	Maro2->PS=1;
	}
	else if (i==4){
		Maro2->position.x-=10;
        	SDL_BlitSurface(Maro2->imageG, NULL, screen, &(Maro2->position));
		Maro2->PS=2;
	}
	else if (Maro2->PS==1)
		SDL_BlitSurface(Maro2->image, NULL, screen, &(Maro2->position));
	else if (Maro2->PS==2)
		SDL_BlitSurface(Maro2->imageG, NULL, screen, &(Maro2->position));
	else if (i==7){
		Maro2->position.y-=10;
		SDL_BlitSurface(Maro2->image, NULL, screen, &(Maro2->position));
		}
	else if (i==8){
		Maro2->position.y+=10;
		SDL_BlitSurface(Maro2->image, NULL, screen, &(Maro2->position));
		}
return 0;
}




