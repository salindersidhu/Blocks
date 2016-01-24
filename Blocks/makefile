# Makefile for compiling on a linux operating system
CC=g++
CFLAGS=-std=c++0x -c
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lphysfs
OBJECTS=Logic/Clock.o Logic/Block.o Logic/Grid.o Objects/ButtonObject.o Objects/GridObject.o Objects/HUDObject.o Levels/GameLevel.o Levels/MenuLevel.o Engine/DialogManager.o Engine/Game.o Engine/PhysfsStream.o Engine/ResourceManager.o Engine/SoundAsset.o Engine/SpriteAsset.o Engine/TextAsset.o Main.o
SOURCES=$(OBJECTS:.cpp=.0)
EXECUTABLE=Blocks

# Build the project and configure
all: $(OBJECTS) $(EXECUTABLE) config

# Rules for compiling all sources and building the project
$(EXECUTABLE): $(SOURCES)
	@echo -n "BUILDING PROJECT..."
	@$(CC) $(SOURCES) $(LDFLAGS) -o $@
	@echo "DONE"

.cpp.o:
	@echo -n "COMPILING "$@"..."
	@$(CC) $(CFLAGS) $< -o $@
	@echo "DONE"

# Remove compiled files and copy resource file to executable's location
config:
	@echo -n "ADDING RESOURCE..."
	@rm -rf *.o */*.o && cp Resources/Data.7z .
	@echo "DONE\n\nPlease type ./Blocks to execute the program."

# Clean all compiled files, resources and executable
clean:
	@echo -n "CLEANING..."
	@rm -rf *.o */*.o *.7z $(EXECUTABLE)
	@echo "DONE"
