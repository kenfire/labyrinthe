SRC_PATH = src/
all : executable
executable : labyrinthe.o affichage.o
	        gcc -Wall -o executable labyrinthe.o affichage.o
labyrinthe.o : labyrinthe.c
			gcc -c labyrinthe.c
affichage.o : affichage.c affichage.h
	        gcc -c affichage.c
clean :
	        rm labyrinthe.o affichage.o executable core
