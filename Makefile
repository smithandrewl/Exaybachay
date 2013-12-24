CC        = clang++
CFLAGS    = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS = -j5

all: henley.cpp tests textgenerator.o util.o
	$(CC) $(CFLAGS) henley.cpp util.o textgenerator.o -o henley

tests: tests.cpp util.o textgenerator.o
	$(CC) $(CFLAGS) util.o textgenerator.o -lgtest tests.cpp -o tests

textgenerator.o: textgenerator.cpp textgenerator.h generator.h
	$(CC) $(CFLAGS) -c textgenerator.cpp

util.o: util.h util.cpp
	$(CC) $(CFLAGS) -c util.cpp

clean:
	rm -f henley tests util.o textgenerator.o