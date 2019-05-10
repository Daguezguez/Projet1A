#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "collision.h"
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso)
{
	int d=0;
  	SDL_Color col;
  do
  {
	if (d==0){
    		col=GetPixel(calque,posperso.x+perso->w,posperso.y+(perso->h/2));
  		if ((col.r==255)&&(col.b==0)&&(col.g==0))
  			return 1;
		}
	else  if(d==1){
    		col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  		if ((col.r==255)&&(col.b==0)&&(col.g==0))
  			return 2;
		}
	else  if(d==2){
    		col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y);
  		if ((col.r==255)&&(col.b==0)&&(col.g==0))
  			return 5;
		}
	else  if(d==3){
    		col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h);
		if ((col.r==255)&&(col.b==0)&&(col.g==0))
  			return 6;
	}
	d++;
  }while(d<4);
return 0;
}
