#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
struct enemy
{
	SDL_Surface *image;
	SDL_Rect position;
	int Vie;
};
typedef struct enemy Enemy;
int affichage_enemy(SDL_Surface *screen, Enemy one);
int affichage_enemy2(SDL_Surface *screen);

#endif // fct_H_INCLUDED
