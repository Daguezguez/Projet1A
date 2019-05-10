#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "game.h"
#include "fct.h"
#include "enemy.h"
#include "Minimap.h"
#include "handle.h"
#include "collision.h"
int show_map(SDL_Surface *screen, int done)
{
	SDL_Surface *map=NULL;
	SDL_Surface *calque=NULL;
	SDL_Rect pos_calque;
	SDL_Rect pos_map;
	SDL_Rect scroll;
	SDL_Event event;
	Mix_Chunk *music=NULL;
	int ch=0;
	Perso perso1,perso2;
	perso1.PS=1;
	perso1.position.x=51;
	perso1.position.y=350;
	perso1.image=IMG_Load("maro.png");
	perso1.imageG=IMG_Load("maroG.png");
	if (perso1.image == NULL) {
	printf("Unable to load bechir : %s\n",SDL_GetError());
	return 1;
	}
	if (perso1.imageG == NULL) {
	printf("Unable to load bechir : %s\n",SDL_GetError());
	return 1;
	}
	perso1.Vie=3;
	perso1.Score=0;
	perso1.Mana=0;
	perso2.PS=1;
	perso2.position.x=100;
	perso2.position.y=350;
	perso2.image=IMG_Load("maro.png");
	perso2.imageG=IMG_Load("maroG.png");
	if (perso2.image == NULL) {
	printf("Unable to load bechir : %s\n",SDL_GetError());
	return 1;
	}
	if (perso2.imageG == NULL) {
	printf("Unable to load bechir : %s\n",SDL_GetError());
	return 1;
	}
	perso2.Vie=3;
	perso2.Score=0;
	perso2.Mana=0;
	Enemy one;
	one.image = IMG_Load("spriteE1G.png");
	if (one.image == NULL) {
	printf("Unable to load first enemy : %s\n",SDL_GetError());
	return 1;
	}
	one.position.x = 800;
	one.position.y=370;		
	map = IMG_Load("map.png");
	SDL_SetColorKey(map,SDL_SRCCOLORKEY,SDL_MapRGB(map->format,255,255,255));
	if (map == NULL) {
	printf("Unable to load map : %s\n",SDL_GetError());
	return 1;
	}
	calque = IMG_Load("calque.png");
	if (calque == NULL) {
	printf("Unable to load calque : %s\n",SDL_GetError());
	return 1;
	}
	SDL_WM_SetCaption("Lost Soul",NULL);
	SDL_SetColorKey(map,SDL_SRCCOLORKEY,SDL_MapRGB(map->format,255,255,255));
	if (map == NULL) {
		printf("Unable to load map : %s\n",SDL_GetError());
	return 1;
	}

pos_map.x = 0;
pos_map.y = 0;
pos_map.w = map->w;
scroll.x = 0;
scroll.y = 0;
scroll.w = 1300;
scroll.h = 563;
pos_calque.x = 0;
pos_calque.y = 0;
pos_calque.w = calque->w;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
Mix_AllocateChannels(5);
music=Mix_LoadWAV("music.wav");
if(!music) 
	{
   		printf("Mix_LoadWAV: %s\n", Mix_GetError());
	}
Mix_PlayChannel(-1, music, -1);
if(Mix_PlayChannel(-1, music, -1)==-1){
	printf("%s",Mix_GetError());
}
SDL_EnableKeyRepeat(20,20);

while(done)
{	
	if (perso1.position.x>750){
		perso1.position.x -= 10;
		scroll.x +=10;
	} else if (perso1.position.x<20){
		perso1.position.x += 10;
		scroll.x -=10;
	} else if (perso1.position.y>500)
			perso1.position.y=500;
	if  (scroll.x < 0)
		scroll.x = 0;
	SDL_BlitSurface(calque,&scroll,screen,&pos_calque);
	SDL_BlitSurface(map,&scroll,screen,&pos_map);
	ch=collision_Parfaite(calque,perso1.image,perso1.position);
	affichage_perso(screen,&perso1,ch);
	affichage_perso2(screen,&perso2);
	minimap(screen,map,perso1.position,perso2.position);
	affichage_enemy(screen,one);
	SDL_Flip(screen);
}
return 0;
}
