all: main

main: main.c tp2.o 
	gcc -O3 tp2.o main.c -o main  -w

tp2.o: tp2.c tp2.h
	gcc -O3 -c  tp2.c  -w

clear:
	rm *.o