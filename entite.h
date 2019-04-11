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

void deplacement(entite1 E1 , entite2 E2 ) ;
void animationD(entite E1 , int x , SDL_Surface *screen ) ;
void animationG(entite E2 , int a , SDL_Surface *screen ) ;  


#endif /*entite_H_ */ 
