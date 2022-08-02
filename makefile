CC = gcc
CFLAGS = -Wall

all: mainapp

mainapp: main.o matrix.o
	$(CC) $(CFLAGS) main.o matrix.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c 

clean:
	rm matrix.o main.o main