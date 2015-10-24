# Constants
SRC_PATH = src/
GCC_COMP = gcc
GCC_FALGS = -Wall -ansi -pedantic
CC = $(GCC_COMP) $(GCC_FLAGS)

all : executable

executable : labyrinthe.o affichage.o
	        $(CC) -o executable labyrinthe.o affichage.o

labyrinthe.o : labyrinthe.c
			$(CC) -c labyrinthe.c
affichage.o : affichage.c affichage.h
	        $(CC) -c affichage.c
clean :
	        rm labyrinthe.o affichage.o executable core
