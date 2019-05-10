#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "game.h"
#include "fct.h"
#include "enemy.h"
#include "Minimap.h"
#include "collision.h"
int main(void){
SDL_Surface *screen=NULL;
int done=1;
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
screen = SDL_SetVideoMode(704,704,32, SDL_HWSURFACE | SDL_DOUBLEBUF);	
if(screen == NULL) {
	printf("Unable to set video mode: %s\n",SDL_GetError());
	return 1;
}
done = show_menu(screen,done);
if (done == 1){
SDL_Init(SDL_INIT_EVERYTHING);
if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
screen = SDL_SetVideoMode(1300,563,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);	
if(screen == NULL) {
	printf("Unable to set video mode: %s\n",SDL_GetError());
	return 1;
}
}
show_map(screen,done);
return 0;
}
