# Makefile for compiling on a linux operating system
CC=g++
CFLAGS=-std=c++0x -c
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lphysfs
SOURCES= Engine/DialogManager.o Engine/Game.o Engine/PhysfsStream.o Engine/ResourceManager.o Engine/SoundAsset.o Engine/SpriteAsset.o Engine/TextAsset.o Clock.o Main.o
OBJECTS=$(SOURCES:.cpp=.0)
EXECUTABLE=Blocks

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
