# Constants
SRC_PATH = src/
GCC = gcc
GCC_FLAGS = -Wall -ansi -pedantic

CC = $(GCC) $(GCC_FLAGS)

all : executable

executable : main.o labyrinth.o menu.o
		$(CC) -o executable main.o labyrinth.o menu.o

main.o : main.c
		$(CC) -c main.c

labyrinth.o : labyrinth.c labyrinth.h
		$(CC) -c labyrinth.c

menu.o : menu.c menu.h
		$(CC) -c menu.c

clean :
		rm main.o labyrinth.o executable core
