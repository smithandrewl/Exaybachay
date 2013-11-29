CC        = clang++
CFLAGS    = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS = -j5

all: henley.cpp tests
	$(CC) $(CFLAGS) henley.cpp -o henley

tests: tests.cpp generator.h
	$(CC) $(CFLAGS) -lboost_system -lboost_unit_test_framework tests.cpp -o tests

generator.h: generator.h
	$(CC) $(CFLAGS) -c generator.h
clean:
	rm -f henley tests