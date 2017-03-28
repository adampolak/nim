CC=g++
CFLAGS=-O2 -Wall
SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

all: play

play: $(SOURCES) $(HEADERS)
	g++ $(SOURCES) -o play

clean:
	rm -f play

.PHONY: clean
