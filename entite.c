#include <stdio.h> 
#include "SDL/SDL.h"
#include <SDL/SDL_image.h> 
#include "entite.h" 

			
void animation1D(int x , entite1 E1 , SDL_Surface * screen ) 
{
	E1.ID=IMG_Load("droite1D.jpg") ; 
	E1.IG=IMG_Load("gauche1D.jpg") ; 	
	
	
	if (x % 2) {
		SDL_BlitSurface(E1.IG,NULL,screen,&E1.pos);
		SDL_Flip(screen) ; 
		}
	else {
		SDL_BlitSurface(E1.ID,NULL,screen,&E1.pos) ; 		
		SDL_Flip(screen) ; 
		}
 
}
void animation1G(int a , entite1 E1 , SDL_Surface * screen ) 
{
	E1.ID=IMG_Load("droite1G.jpg") ; 
	E1.IG=IMG_Load("gauche1G.jpg") ;

	if (a % 2 ) {
		SDL_BlitSurface(E1.IG,NULL,screen,&E1.pos) ; 
		SDL_Flip(screen) ; 
		}
	else {
		SDL_BlitSurface(E1.ID,NULL,screen,&E1.pos) ;
		SDL_Flip(screen) ; 
		
		}
}void animation2D(int k , entite2 E2 , SDL_Surface * screen ) 
{
	E2.ID=IMG_Load("droite2D.jpg") ; 
	E2.IG=IMG_Load("gauche2D.jpg") ; 	
	
	
	if (k % 2) {
		SDL_BlitSurface(E2.IG,NULL,screen,&E2.pos);
		SDL_Flip(screen) ; 
		}
	else {
		SDL_BlitSurface(E2.ID,NULL,screen,&E2.pos) ; 		
		SDL_Flip(screen) ; 
		}
 
}
void animation2G(int b , entite2 E2 , SDL_Surface * screen ) 
{
	E2.ID=IMG_Load("droite2G.jpg") ; 
	E2.IG=IMG_Load("gauche2G.jpg") ;

	if (b % 2 ) {
		SDL_BlitSurface(E2.IG,NULL,screen,&E2.pos) ; 
		SDL_Flip(screen) ; 
		}
	else {
		SDL_BlitSurface(E2.ID,NULL,screen,&E2.pos) ;
		SDL_Flip(screen) ; 
		
		}
}
void deplacement(entite1 E1 , entite2 E2, SDL_Surface *screen ) 
{
    int val,val1 ; int D1=0 , G1=0,D2=0,G2=0 ; 
	 E1.pos.y= 200  ; E1.pos.y = 200 ;
	while (E1.pos.x >0 && E2.pos.x >0 ) 
	
		{
			val = rand() % 3 + 1 ; 
			if (val) {
				E1.pos.x+=10 ;  /*dep a droite si val = 1 */ 
				D1++ ; 
				animation1D(D1,E1,screen) ; 
				}
			
			else {
				E1.pos.x-=10 ;  /* dep a gauche si val = 2 */ 
				G1++ ; 
				animation1G(G1,E1,screen) ; 
			} 					
		
			
			val1 = rand() % 3 + 1 ; 
			if(val1){
				E2.pos.x+=10 ; 
				D2++ ; 
				animation2D(D2,E2,screen) ;
				}
			else {
				E2.pos.x-=10 ;
				G2++ ; 
				animation2G(G2,E2,screen) ; 
				}
		}
							
	
}


