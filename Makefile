CC        = clang++
CFLAGS    = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS = -j5

all: henley.cpp tests
	$(CC) $(CFLAGS) henley.cpp util.o -o henley

tests: tests.cpp util.o generator.h
	$(CC) $(CFLAGS) util.o -lgtest tests.cpp -o tests

util.o: util.h util.cpp
	$(CC) $(CFLAGS) -c util.cpp

clean:
	rm -f henley tests util.o
