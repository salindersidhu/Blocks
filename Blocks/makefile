# Compiler and compiler flag settings
CC=g++
CFLAGS=-std=c++0x -c
# Coditional LDFLAGS based on Operating System
OS := $(shell uname)
ifeq ($(OS), Darwin)
	# Mac OS X LDFLAGS
	LDFLAGS=-framework sfml-graphics -framework sfml-audio -framework sfml-window -framework sfml-system -lphysfs
else
	# Linux LDFLAGS
	LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lphysfs
endif
# Sources for compiling
SOURCES=Logic/MinuteClock.cpp Logic/Block.cpp Logic/Grid.cpp Objects/WinInfo.cpp Objects/GameGrid.cpp Objects/Button.cpp Objects/FadeEffect.cpp Objects/HUD.cpp Objects/BGMusic.cpp Levels/CoreLevel.cpp Levels/MenuLevel.cpp Levels/GameLevel.cpp Levels/WinLevel.cpp Engine/SaveObject.cpp Engine/LevelObject.cpp Engine/ErrorDialog.cpp Engine/Game.cpp Engine/PhysfsStream.cpp Engine/ResourceManager.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
# Name of the compiled binary
EXECUTABLE=Blocks

# Build the project and configure
all: $(OBJECTS) $(EXECUTABLE)

# Rules for compiling all sources, building the project and adding the resource archive file
$(EXECUTABLE): $(OBJECTS)
	@printf "BUILDING PROJECT..."
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@printf "DONE\n"
	@printf "ADDING RESOURCE..."
	@cp Resources/data.7z .
	@printf "DONE\n\nPlease type ./Blocks to start the game.\n"

.cpp.o:
	@printf "COMPILING "$@"..."
	@$(CC) $(CFLAGS) $< -o $@
	@printf "DONE\n"

# Clean all compiled files, resources and executable
clean:
	@printf "CLEANING..."
	@rm -rf *.o */*.o *.7z $(EXECUTABLE)
	@printf "DONE\n"
