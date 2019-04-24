#ifndef entite_H_ 
#define entite_H_ 

typedef struct 
{
	SDL_Rect pos ; 
	SDL_Surface ID,IG ; 
}entite1 ; 
typedef struct 
{
	SDL_Rect pos ; 
	SDL_Surface ID,IG ; 
}entite2 ; 


void animation1D(int x ,  entite1 E1 , SDL_Surface *screen ) ;
void animation1G(int a ,entite1 E1, SDL_Surface *screen ) ;  
void animation2D(int k ,  entite2 E2 , SDL_Surface *screen ) ;
void animation2G(int b ,entite2 E2, SDL_Surface *screen ) ; 
void deplacement(entite1 E1, entite2 E2,SDL_Surface *screen )  ;


#endif /*entite_H_ */ 
