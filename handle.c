#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "handle.h"
int HandleEvent1(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case(SDL_KEYDOWN):
				switch(event.key.keysym.sym){
					case(SDLK_RIGHT):
						return 1;
					break;
					case(SDLK_LEFT):
						return 2;
					break;
					case(SDLK_q):
						return 3;break;
					case(SDLK_d):
						return 4;break;
					case(SDLK_UP):
						return 5;break;
					case(SDLK_DOWN):
						return 6;break;
					case(SDLK_z):
						return 7;break;
					case(SDLK_s):
						return 8;break;
				}
			break;
		}

	}
}

