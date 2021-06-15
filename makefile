all: main

main: main.o tp1.o
	gcc -o main main.o tp1.o

main.o: main.c
	gcc -c main.c

tp1.o: tp1.c
	gcc -c tp1.c