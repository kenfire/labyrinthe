# Constants
SRC_PATH = src/
GCC_COMP = gcc
GCC_FALGS = -Wall -ansi -pedantic
GCC = $(GCC_COMP) $(GCC_FLAGS)

all : executable

executable : labyrinthe.o affichage.o
	        $(GCC)-o executable labyrinthe.o affichage.o

labyrinthe.o : labyrinthe.c
			$(GCC) -c labyrinthe.c
affichage.o : affichage.c affichage.h
	        $(GCC) -c affichage.c
clean :
	        rm labyrinthe.o affichage.o executable core
