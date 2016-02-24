CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++11 -lncurses -c $(DEBUG)
LFLAGS = -Wall -lncurses -g


all: p1

p1: p1.o
	$(CC) $(LFLAGS) -o p1 p1.o

p1.o: p1.cpp
	$(CC) $(CFLAGS) p1.cpp

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf p1
