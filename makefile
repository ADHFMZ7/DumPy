CC = gcc-12
CFLAGS = -Wall -g -O3 -ffast-math 

all: mainapp

mainapp: main.o matrix.o matrix.so
	$(CC) $(CFLAGS) main.o matrix.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o 

matrix.so: matrix.o
	$(CC) $(CFLAGS) -shared -o matrix.so matrix.o

clean:
	rm matrix.o main.o main matrix.so
