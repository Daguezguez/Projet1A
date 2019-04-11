#include <stdio.h> 
#include <stdlib.h>
#include "entite.h" 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 


int main() {
	entite1 E1 ; entite2 E2 ; 
	SDL_Surface *screen = NULL , *image = NULL ; 
	SDL_Rect positionecran ; 
	SDL_Init(SDL_INIT_VIDEO) ; 
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL : %s \n",SDL_GetError() ) ; 
		return 1 ; 
	 
	}
	screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ; 
	if (screen == NULL ) {
		printf("unable to set video mode : %s \n",SDL_GetError() ) ;
		return 1 ; 
	}

	image = SDL_LoadBMP("background.bmp") ; 
	if (image=NULL) {
		printf("unable to load bitmap : %s \n",SDL_GetError() ) ; 
	return 1 ; 
	}
	positionecran.x=0 ; 
	positionecran.y=0 ; 
	
	SDL_BlitSurface(image,NULL,screen, &positionecran) ; 
	SDL_flip(screen) ; 
	deplacement(E1,E2)  ; 
	SDL_FreeSurface(image) ; 
	SDL_Quit() ; 
	
return 0 ; 
} 
