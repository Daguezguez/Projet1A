#ifndef fct_H_INCLUDED
#define fct_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
struct perso
{
	SDL_Surface *image;
	SDL_Surface *imageG;
	SDL_Rect position;
	int Vie,Mana,Score,PS;
};
typedef struct perso Perso;
int affichage_perso(SDL_Surface *screen, Perso *Maro,int ch);
int affichage_perso2(SDL_Surface *screen, Perso *Maro2);

#endif // fct_H_INCLUDED
