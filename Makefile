CC        = clang++
CFLAGS    = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS = -j5

all: henley.cpp
	$(CC) $(CFLAGS) henley.cpp -o henley

clean:
	rm -f henley