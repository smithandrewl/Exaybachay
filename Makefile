CC        = clang++
CFLAGS    = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS = -j5

all: henley.cpp tests
	$(CC) $(CFLAGS) henley.cpp -o henley

generator.h: generator.h
	$(CC) $(CFLAGS) -c generator.h

tests: tests.cpp
	$(CC) $(CFLAGS) -lgtest tests.cpp -o tests

clean:
	rm -f henley tests