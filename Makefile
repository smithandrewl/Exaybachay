CC          = clang++
CFLAGS      = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS   = -j5
GTKMM_FLAGS := $(shell pkg-config gtkmm-3.0 --cflags)
GTKMM_LIBS  := $(shell pkg-config gtkmm-3.0 --libs)

all: henley.cpp tests
	$(CC) $(CFLAGS) $(GTKMM_FLAGS) $(GTKMM_LIBS) henley.cpp util.o -o henley

tests: tests.cpp util.o generator.h
	$(CC) $(CFLAGS) util.o -lgtest tests.cpp -o tests

util.o: util.h util.cpp
	$(CC) $(CFLAGS) -c util.cpp

clean:
	rm -f henley tests util.o
