#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Minimap.h"
#include "fct.h"
int minimap(SDL_Surface *screen,SDL_Surface * background,SDL_Rect pos1,SDL_Rect pos2){
	SDL_Surface *red,*blue,*bar;
	float jred,jblue;
	SDL_Rect red_pos,blue_pos,bar_pos;
red = IMG_Load("red.png");
	if (red == NULL) {
	printf("Unable to load red : %s\n",SDL_GetError());
	return 1;
	}
blue = IMG_Load("blue.png");
	if (blue == NULL) {
	printf("Unable to load blue : %s\n",SDL_GetError());
	return 1;
	}
bar = IMG_Load("bar.png");
	if (bar == NULL) {
	printf("Unable to load bar : %s\n",SDL_GetError());
	return 1;
	}
bar_pos.x=400;
bar_pos.y=30;
jred=pos1.x / 4000;
red_pos.x=(int)(400 + ((jred)*538));
red_pos.y=30;
jblue=pos2.x / 4000;
blue_pos.x=(int)(400 + ((jblue)*538));
blue_pos.y=30;

SDL_BlitSurface(bar,NULL,screen,&bar_pos);
SDL_BlitSurface(blue,NULL,screen,&blue_pos);
SDL_BlitSurface(red,NULL,screen,&red_pos);
return 0;
}
