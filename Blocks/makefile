# Makefile for compiling on a linux operating system
CC=g++
CFLAGS=-std=c++0x -c
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -lphysfs
SOURCES=Clock.o Grid.o Block.o tinyfiledialogs.o DialogManager.o PhyfsStream.o DrawManager.o Button.o LevelManager.o  BlocksGame.o Main.o
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Blocks

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
