prog:main.o menu.o game.o fct.o enemy.o collision.o Minimap.o handle.o
	gcc main.o menu.o game.o fct.o enemy.o Minimap.o handle.o collision.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
enemy.o:enemy.c
	gcc -c enemy.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
game.o:game.c
	gcc -c game.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
fct.o:fct.c
	gcc -c fct.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
Minimap.o:Minimap.c
	gcc -c Minimap.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
handle.o:handle.c
	gcc -c handle.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
collision.o:collision.c
	gcc -c collision.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
