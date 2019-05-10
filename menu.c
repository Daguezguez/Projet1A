#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "enemy.h"
#include "fct.h"
#include "enemy.h"
int show_menu(SDL_Surface *screen, int done)
{
SDL_Surface *background=NULL;
SDL_Surface *bouton1=NULL;
SDL_Surface *bouton2=NULL;
SDL_Surface *bouton3=NULL;
SDL_Surface *bouton4=NULL;
SDL_Surface *bouton5=NULL;
SDL_Surface *bouton6=NULL;
SDL_Surface *bouton7=NULL;
SDL_Surface *bouton8=NULL;
SDL_Surface *bouton9=NULL;
SDL_Surface *bouton10=NULL;
SDL_Surface *logo=NULL;
SDL_Rect pos_background;
SDL_Rect pos_bouton1;
SDL_Rect pos_bouton2;
SDL_Rect pos_bouton3;
SDL_Rect pos_bouton4;
SDL_Rect pos_bouton5;
SDL_Rect pos_bouton6;
SDL_Rect pos_bouton7;
SDL_Rect pos_bouton8;
SDL_Rect pos_bouton9;
SDL_Rect pos_bouton10;
SDL_Rect pos_logo;
SDL_Event event1,event2;
Mix_Chunk *music=NULL;
Mix_Chunk *bip=NULL;
int check=1;
int done2=0;
int game=0;
background = IMG_Load("buttons/background.jpg");
SDL_WM_SetCaption("Lost Soul",NULL);
SDL_SetColorKey(background,SDL_SRCCOLORKEY,SDL_MapRGB(background->format,255,255,255));
if (background == NULL) {
	printf("Unable to load background : %s\n",SDL_GetError());
return 1;
}
bouton1 = IMG_Load("buttons/play.png");
SDL_SetColorKey(bouton1,SDL_SRCCOLORKEY,SDL_MapRGB(bouton1->format,255,255,255));
if (bouton1 == NULL) {
	printf("Unable to load play : %s\n",SDL_GetError());
return 1;
}
bouton2 = IMG_Load("buttons/settings.png");
SDL_SetColorKey(bouton2,SDL_SRCCOLORKEY,SDL_MapRGB(bouton2->format,255,255,255));
if (bouton2 == NULL) {
	printf("Unable to load settings : %s\n",SDL_GetError());
return 1;
}
bouton3 = IMG_Load("buttons/help.png");
SDL_SetColorKey(bouton3,SDL_SRCCOLORKEY,SDL_MapRGB(bouton3->format,255,255,255));
if (bouton3 == NULL) {
	printf("Unable to load help : %s\n",SDL_GetError());
return 1;
}
bouton4 = IMG_Load("buttons/rankings.png");
SDL_SetColorKey(bouton4,SDL_SRCCOLORKEY,SDL_MapRGB(bouton4->format,255,255,255));
if (bouton4 == NULL) {
	printf("Unable to load rankings : %s\n",SDL_GetError());
return 1;
}
bouton5 = IMG_Load("buttons/quit.png");
SDL_SetColorKey(bouton5,SDL_SRCCOLORKEY,SDL_MapRGB(bouton5->format,255,255,255));
if (bouton5 == NULL) {
	printf("Unable to load quit : %s\n",SDL_GetError());
return 1;
}
bouton6 = IMG_Load("buttons/new.png");
SDL_SetColorKey(bouton6,SDL_SRCCOLORKEY,SDL_MapRGB(bouton6->format,255,255,255));
if (bouton6 == NULL) {
	printf("Unable to load new game : %s\n",SDL_GetError());
return 1;
}
bouton7 = IMG_Load("buttons/load.png");
SDL_SetColorKey(bouton7,SDL_SRCCOLORKEY,SDL_MapRGB(bouton7->format,255,255,255));
if (bouton7 == NULL) {
	printf("Unable to load continue : %s\n",SDL_GetError());
return 1;
}
bouton8 = IMG_Load("buttons/back.png");
SDL_SetColorKey(bouton8,SDL_SRCCOLORKEY,SDL_MapRGB(bouton8->format,255,255,255));
if (bouton8 == NULL) {
	printf("Unable to load back : %s\n",SDL_GetError());
return 1;
}
bouton9 = IMG_Load("buttons/audio.png");
SDL_SetColorKey(bouton9,SDL_SRCCOLORKEY,SDL_MapRGB(bouton9->format,255,255,255));
if (bouton9 == NULL) {
	printf("Unable to load audio : %s\n",SDL_GetError());
return 1;
}
bouton10 = IMG_Load("buttons/video.png");
SDL_SetColorKey(bouton10,SDL_SRCCOLORKEY,SDL_MapRGB(bouton10->format,255,255,255));
if (bouton10 == NULL) {
	printf("Unable to load video : %s\n",SDL_GetError());
return 1;
}
logo = IMG_Load("buttons/logo.png");
SDL_SetColorKey(logo,SDL_SRCCOLORKEY,SDL_MapRGB(logo->format,255,255,255));
if (logo == NULL) {
	printf("Unable to load video : %s\n",SDL_GetError());
return 1;
}
pos_background.x = 0;
pos_background.y = 0;
pos_background.w = background->w;
pos_bouton1.x = 275;
pos_bouton1.y = 190;
pos_bouton1.w = bouton1->w;
pos_bouton2.x = 275;
pos_bouton2.y = 250;
pos_bouton2.w = bouton2->w;
pos_bouton3.x = 275;
pos_bouton3.y = 310;
pos_bouton3.w = bouton3->w;
pos_bouton4.x = 275;
pos_bouton4.y = 370;
pos_bouton4.w = bouton4->w;
pos_bouton5.x = 275;
pos_bouton5.y = 430;
pos_bouton5.w = bouton5->w;
pos_bouton6.x = 275;
pos_bouton6.y = 190;
pos_bouton6.w = bouton6->w;
pos_bouton7.x = 275;
pos_bouton7.y = 250;
pos_bouton7.w = bouton7->w;
pos_bouton8.x = 275;
pos_bouton8.y = 310;
pos_bouton8.w = bouton8->w;
pos_bouton9.x = 275;
pos_bouton9.y = 190;
pos_bouton9.w = bouton9->w;
pos_bouton10.x = 275;
pos_bouton10.y = 250;
pos_bouton10.w = bouton10->w;
pos_logo.x = 130;
pos_logo.y = 50;
pos_logo.w = logo->w;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
	printf("%s",Mix_GetError());
}
Mix_AllocateChannels(5);
music=Mix_LoadWAV("music.wav");
if(!music) {
    printf("Mix_LoadWAV: %s\n", Mix_GetError());
}
bip=Mix_LoadWAV("bip.wav");
if(!bip) {
    printf("Mix_LoadWAV: %s\n", Mix_GetError());
}
Mix_PlayChannel(-1, music, -1);
if(Mix_PlayChannel(-1, music, -1)==-1){
	printf("%s",Mix_GetError());
}
while (done){
	SDL_BlitSurface(background,NULL,screen,&pos_background);
	SDL_BlitSurface(logo,NULL,screen,&pos_logo);
	SDL_BlitSurface(bouton1,NULL,screen,&pos_bouton1);
	SDL_BlitSurface(bouton2,NULL,screen,&pos_bouton2);
	SDL_BlitSurface(bouton3,NULL,screen,&pos_bouton3);
	SDL_BlitSurface(bouton4,NULL,screen,&pos_bouton4);
	SDL_BlitSurface(bouton5,NULL,screen,&pos_bouton5);
	SDL_Flip(screen);
	
	while(SDL_PollEvent(&event1)){
		switch (event1.type)
		{
			case (SDL_QUIT): 
			done =0;
			break;
			case (SDL_MOUSEMOTION):
				if(event1.motion.x>275 && event1.motion.x<434 && event1.motion.y>190 && event1.motion.y<248){
					if(check==1){
						Mix_PlayChannel(0, bip, 0);
						if(Mix_PlayChannel(0, bip, 0)==-1)
							{
							printf("%s",Mix_GetError());
						}
						check=0;
					}
				}
				else if(event1.motion.x>275 && event1.motion.x<434 && event1.motion.y>250 && event1.motion.y<308){
					if(check==1){
						Mix_PlayChannel(0, bip, 0);
						if(Mix_PlayChannel(0, bip, 0)==-1)
							{
							printf("%s",Mix_GetError());
						}
						check=0;
					}
				}
				else if(event1.motion.x>275 && event1.motion.x<434 && event1.motion.y>310 && event1.motion.y<368){
					if(check==1){
						Mix_PlayChannel(0, bip, 0);
						if(Mix_PlayChannel(0, bip, 0)==-1)
							{
							printf("%s",Mix_GetError());
						}
						check=0;
					}
				}
				else if(event1.motion.x>275 && event1.motion.x<434 && event1.motion.y>370 && event1.motion.y<428){
					if(check==1){
						Mix_PlayChannel(0, bip, 0);
						if(Mix_PlayChannel(0, bip, 0)==-1)
							{
							printf("%s",Mix_GetError());
						}
						check=0;
					}
				}
				else if(event1.motion.x>275 && event1.motion.x<434 && event1.motion.y>430 && event1.motion.y<488){
					if(check==1){
						Mix_PlayChannel(0, bip, 0);
						if(Mix_PlayChannel(0, bip, 0)==-1)
							{
							printf("%s",Mix_GetError());
						}
						check=0;
					}
				}
				else 
					check = 1;
				break;
			case (SDL_MOUSEBUTTONUP):
				if(event1.button.x>275 && event1.button.x<434 && event1.button.y>190 && event1.button.y<248){
					done2=1;
					while(done2){
						SDL_BlitSurface(background,NULL,screen,&pos_background);
						SDL_BlitSurface(logo,NULL,screen,&pos_logo);
						SDL_BlitSurface(bouton6,NULL,screen,&pos_bouton6);
						SDL_BlitSurface(bouton7,NULL,screen,&pos_bouton7);
						SDL_BlitSurface(bouton8,NULL,screen,&pos_bouton8);
						SDL_Flip(screen);
						while(SDL_PollEvent(&event2)){
						// insert code here
							switch (event2.type)
							{
								case (SDL_QUIT): 
									done2=0;
									done=0;
								break;
								case (SDL_MOUSEMOTION):
									if(event2.motion.x>275 && event2.motion.x<434 && event2.motion.y>190 && event2.motion.y<248)							{
										if(check==1){
											Mix_PlayChannel(0, bip, 0);
											if(Mix_PlayChannel(0, bip, 0)==-1)
											{
												printf("%s",Mix_GetError());
											}
											check=0;
										}
									}
									else if(event2.motion.x>275 && event2.motion.x<434 && event2.motion.y>250 && event2.motion.y<308)				{
										if(check==1){
											Mix_PlayChannel(0, bip, 0);
											if(Mix_PlayChannel(0, bip, 0)==-1)
											{
												printf("%s",Mix_GetError());
											}
											check=0;
										}
									}
									else if(event2.motion.x>275 && event2.motion.x<434 && event2.motion.y>310 && event2.motion.y<368)				{
										if(check==1){
											Mix_PlayChannel(0, bip, 0);
											if(Mix_PlayChannel(0, bip, 0)==-1)
											{
												printf("%s",Mix_GetError());
											}
											check=0;
										}
									}
									else
										check = 1;
								break;
								case (SDL_MOUSEBUTTONUP):
									if(event2.button.x>275 && event2.button.x<434 && event2.button.y>310 && event2.button.y<368)
										done2=0;
									else if(event2.button.x>275 && event2.button.x<434 && event2.button.y>190 && event2.button.y<248){
									done2=0;
									done=0;
									game=1;
									}
								break;
							}
						}
					}
				}
				else if(event1.button.x>275 && event1.button.x<434 && event1.button.y>250 && event1.button.y<308){
					done2=1;
					while(done2){
						SDL_BlitSurface(background,NULL,screen,&pos_background);
						SDL_BlitSurface(logo,NULL,screen,&pos_logo);
						SDL_BlitSurface(bouton9,NULL,screen,&pos_bouton9);
						SDL_BlitSurface(bouton10,NULL,screen,&pos_bouton10);
						SDL_BlitSurface(bouton8,NULL,screen,&pos_bouton8);
						SDL_Flip(screen);
						while(SDL_PollEvent(&event2)){
						// insert code here
							switch (event2.type)
							{
								case (SDL_QUIT): 
									done2=0;
									done=0;								
								break;
								case (SDL_MOUSEMOTION):
								if(event2.motion.x>275 && event2.motion.x<434 && event2.motion.y>190 && event2.motion.y<248)						{
									if(check==1){
										Mix_PlayChannel(0, bip, 0);
										if(Mix_PlayChannel(0, bip, 0)==-1)
										{
											printf("%s",Mix_GetError());
										}
										check=0;
									}
								}
								else if(event2.motion.x>275 && event2.motion.x<434 && event2.motion.y>250 && event2.motion.y<308)						{
									if(check==1){
										Mix_PlayChannel(0, bip, 0);
										if(Mix_PlayChannel(0, bip, 0)==-1)
										{
											printf("%s",Mix_GetError());
										}
										check=0;
									}
								}
								else if(event2.motion.x>275 && event2.motion.x<434 && event2.motion.y>310 && event2.motion.y<368)						{
									if(check==1){
										Mix_PlayChannel(0, bip, 0);
										if(Mix_PlayChannel(0, bip, 0)==-1)
										{
											printf("%s",Mix_GetError());
										}
										check=0;
									}
								}
								else
									check = 1;
								break;
								case (SDL_MOUSEBUTTONUP):
									if(event2.button.x>275 && event2.button.x<434 && event2.button.y>310 && event2.button.y<368)
										done2=0;
								break;
							}
						}
						
					}
				}
				else if(event1.button.x>275 && event1.button.x<434 && event1.button.y>430 && event1.button.y<488)
					done=0;
			break;
		}
	}
}
SDL_FreeSurface(bouton1);
SDL_FreeSurface(bouton2);
SDL_FreeSurface(bouton3);
SDL_FreeSurface(bouton4);
SDL_FreeSurface(bouton5);
SDL_FreeSurface(bouton6);
SDL_FreeSurface(bouton7);
SDL_FreeSurface(bouton8);
SDL_FreeSurface(bouton9);
SDL_FreeSurface(bouton10);
SDL_FreeSurface(logo);
Mix_FreeChunk(music);
Mix_FreeChunk(bip);
SDL_FreeSurface(background);
SDL_FreeSurface(screen);
SDL_CloseAudio();
SDL_Quit();
return game;
}
