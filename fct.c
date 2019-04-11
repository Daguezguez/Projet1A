#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fct.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
SDL_Surface *ecran, *imageDeFond, *bechir;
SDL_Rect positionFond,positionbechir;

void init_perso(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("background.bmp");
	bechir = SDL_LoadBMP("bich1.jpg");
	

}
void affichage_perso(SDL_Rect positionBechir,SDL_Rect positionFond)
{
SDL_Surface *ecran, *imageDeFond, *bechir;


	positionFond.x = 0;
	positionFond.y = 0;

	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 SDL_BlitSurface(ecran, 0, ecran, &positionFond);
        SDL_BlitSurface(bechir, 0, ecran, &positionBechir);

}
int gameover;

/* source and destination rectangles */
SDL_Rect positionFond, positionsprite;

void HandleEvent(SDL_Event event)
{
  switch (event.type) {
    /* close button clicked */
    case SDL_QUIT:
      gameover = 1;
      break;

    /* handle the keyboard */
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
        case SDLK_q:
          gameover = 1;
          break;
        case SDLK_LEFT:
          if ( positionFond.x == 192 )
            positionFond.x = 224;
          else
            positionFond.x = 192;
          positionsprite.x -= 5;
          break;
        case SDLK_RIGHT:
          if ( positionFond.x == 64 )
            positionFond.x = 96;
          else
            positionFond.x = 64;
          positionsprite.x += 5;
          break;
        case SDLK_UP:
          if ( positionFond.x == 0 )
            positionFond.x = 32;
          else
            positionFond.x = 0;
          positionsprite.y -= 5;
          break;
        case SDLK_DOWN:
          if ( positionFond.x == 128 )
            positionFond.x = 160;
          else
            positionFond.x = 128;
          positionsprite.y += 5;
          break;
      }
      break;
  }
}
void anime (void){
 SDL_Surface *screen, *temp, *sprite, *grass;
  SDL_Rect positionFond, positionsprite;
 int colorkey;

  /* set keyboard repeat */
  SDL_EnableKeyRepeat(70, 70);
/* load sprite */
  temp   = SDL_LoadBMP("sprite.bmp");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup sprite colorkey */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* load grass */
  temp  = SDL_LoadBMP("perso.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* set sprite position */
  positionsprite.x = 150;
  positionsprite.y = 150;

  /* set animation frame */
  positionFond.x = 128;
  positionFond.y = 0;
  positionFond.w = SPRITE_SIZE;
  positionFond.h = SPRITE_SIZE;

  gameover = 0;

  /* message pump */
  while (!gameover)
  {
    SDL_Event event;

    /* look for an event */
    if (SDL_PollEvent(&event)) {
      HandleEvent(event);
    }

    /* collide with edges of screen */
    if ( positionsprite.x < 0 ) {
      positionsprite.x = 0;
    }
    else if ( positionsprite.x > SCREEN_WIDTH-SPRITE_SIZE ) {
      positionsprite.x = SCREEN_WIDTH-SPRITE_SIZE;
    }
    if ( positionsprite.y < 0 ) {
      positionsprite.y = 0;
    }
    else if ( positionsprite.y > SCREEN_HEIGHT-SPRITE_SIZE ) {
      positionsprite.y = SCREEN_HEIGHT-SPRITE_SIZE;
    }

    /* draw the grass */
    for (int x = 0; x < SCREEN_WIDTH / SPRITE_SIZE; x++) {
      for (int y = 0; y < SCREEN_HEIGHT / SPRITE_SIZE; y++) {
        positionFond.x = x * SPRITE_SIZE;
        positionFond.y = y * SPRITE_SIZE;
        SDL_BlitSurface(grass, NULL, screen, &positionFond);
      }
    }
}
	

int bool_collision (int x,int y,AABB box)
{
int curs_x,curseur_y;
if (curs_x >= box.x 
    && curs_x < box.x + box.w
    && curseur_y >= box.y 
    && curseur_y < box.y + box.h)
       return 1;
   else
       return 0;

}
}



