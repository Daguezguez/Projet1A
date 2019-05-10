#ifndef scrolling_H_INCLUDED
#define scrolling_H_INCLUDED
struct Background{
	SDL_Surface *backgroundImg;
	SDL_Surface *backgroundCollide;
	SDL_Rect backgroundPos;
};
typedef struct Background Background;
void blitBackground(Background*Backg,SDL_Surface *screen);
#endif // scrolling_H_INCLUDED
