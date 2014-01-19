CC          = clang++
CFLAGS      = -std=c++11 -Wall -pedantic -Weffc++
MAKEFLAGS   = -j5
GTKMM_FLAGS := $(shell pkg-config gtkmm-3.0 --cflags)
GTKMM_LIBS  := $(shell pkg-config gtkmm-3.0 --libs)

all: gui.cpp tests textgenerator.o util.o
	$(CC) $(CFLAGS) $(GTKMM_FLAGS) $(GTKMM_LIBS) gui.cpp util.o textgenerator.o -o exaybachay

tests: tests.cpp util.o textgenerator.o
	$(CC) $(CFLAGS) util.o textgenerator.o -lgtest tests.cpp -o tests

textgenerator.o: textgenerator.cpp textgenerator.h generator.h
	$(CC) $(CFLAGS) -c textgenerator.cpp

util.o: util.h util.cpp
	$(CC) $(CFLAGS) -c util.cpp

clean:
	rm -f exaybachay tests util.o textgenerator.o
