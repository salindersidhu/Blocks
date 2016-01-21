# Makefile for compiling on a linux operating system
CC=g++
CFLAGS=-std=c++0x -c
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lphysfs
OBJECTS=Logic/Clock.o Logic/Block.o Logic/Grid.o Objects/Button.o Objects/GameGrid.o Objects/HUD.o Levels/EndLevel.o Levels/GameLevel.o Levels/MenuLevel.o Levels/VictoryLevel.o Engine/DialogManager.o Engine/Game.o Engine/PhysfsStream.o Engine/ResourceManager.o Engine/SoundAsset.o Engine/SpriteAsset.o Engine/TextAsset.o Main.o
SOURCES=$(OBJECTS:.cpp=.0)
EXECUTABLE=Blocks

all: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o */*.o $(EXECUTABLE)
