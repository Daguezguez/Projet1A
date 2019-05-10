#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy.h"

int affichage_enemy(SDL_Surface *screen, Enemy one)
{
	const int FPS = 30;
	Uint32 start;
	SDL_Rect wow[3];
	int frame=0;
	wow[0].x=0;
	wow[0].y=0;
	wow[0].w=136;
	wow[0].h=119;
	wow[1].x=136;
	wow[1].y=0;
	wow[1].w=136;
	wow[1].h=119;
	wow[2].x=272;
	wow[2].y=0;
	wow[2].w=136;
	wow[2].h=119;
	start = SDL_GetTicks();
        SDL_BlitSurface(one.image, &wow[frame], screen, &one.position);
                //frame++;
                /*if(frame == 3) 
                        frame = 0;
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay((1000/FPS-(SDL_GetTicks()-start))+100);
                }*/
return 0;
}
/*int affichage_enemy2(SDL_Surface *screen)
{
	Enemy two;
	two.image = IMG_Load("spriteE1G.png");
	if (two.image == NULL) {
	printf("Unable to load second enemy : %s\n",SDL_GetError());
	return 1;
	}
	two.position.x = 450;
	two.position.y=400;
        SDL_BlitSurface(two.image, NULL, screen, &two.position);
return 0;
}
*/












