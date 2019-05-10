#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"
void blitBackground(Background*Backg,SDL_Surface *screen)
{

	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); 
}
