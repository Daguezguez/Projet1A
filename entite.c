#include <stdio.h> 
#include <stdlib.h>
#include "entite.h" 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 



void init(SDL_Surface *screen) 
{	
	SDL_Surface  *BOSS=NULL ; 
	SDL_Rect posboss ; 
	

	SDL_Init(SDL_INIT_VIDEO ) ;
 
	BOSS = IMG_LOAD("BOSS.jpg") ; 

	if (!BOSS) 
		printf("unable to load BOSS \n " ) ; 
	return 1 ; 

	posboss.x =  800 ;
	posboss.y = 600 ;

	SDL_BlitSurface(BOSS,NULL,screen, &posboss) ;
	SDL_Flip(screen) ; 
	
}
void deplacement(entite1 E1 , entite2 E2 ) 
{
    int val,val1 ; int D1=0 , G1=0,D2=0,G2=0 ; 
	 E1.pos.y= 200  ; E1.pos.y = 200 ;
	while (E1.pos.x >0 && E2.pos.x >0 ) 
	
		{
			val = rand() % 3 + 1 ; 
			if (val) {
				E1.pos.x+=10 ;  /*dep a droite si val = 1 */ 
				D1++ ; 
				animationG(D1,E1,&screen) ; 
				}
			
			else {
				E1.pos.x-=10 ;  /* dep a gauche si val = 2 */ 
				G1++ ; 
				animationG(G1,E1,&screen) ; 
			} 					
		
			
			val1 = rand() % 3 + 1 ; 
			if(val1){
				E2.pos.x+=10 ; 
				D2++ ; 
				animationD(D2,E2,&screen) ;
				}
			else {
				E2.pos.x-=10 ;
				G2++ ; 
				animationD(G2,E2,&screen) ; 
				}
		}
							
	
}
void animationD(int x , entite1 E1 , SDL_Surface screen ) 
{
	E1.ID=IMG_Load("droite1.jpg") ; 
	E1.IG=IMG_Load("gauche1.jpg") ; 	
	
	
	if (x % 2 ) {
		SDL_BlitSurface(E1.IG,NULL,screen,&E1.pos);
		SDL_flip(screen) ; 
		}
	else {
		SDL_BlitSurface(E1.ID,NULL,screen,&E1.pos) ; 		
		SDL_flip(screen) ; 
		}
 
}
void animationG(int a , entite2 E2 , SDL_Surface *screen ) 
{
	E2.ID=IMG_Load("droite2.jpg") ; 
	E2.IG=IMG_Load("gauche2.jpg") ;

	if (a % 2 ) {
		SDL_BlitSurface(E2.IG,NULL,screen,&E2.pos) ; 
		SDL_flip(screen) ; 
		}
	else {
		SDL_BlitSurface(E2.ID,NULL,screen,&E2.pos) ;
		SDL_flip(screen) ; 
		
}
}
